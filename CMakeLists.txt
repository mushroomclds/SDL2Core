#https://www.youtube.com/watch?v=7sg88N_bDI0 video for cmake and SDL2
# only for cmake --version >= 3.5.1
cmake_minimum_required(VERSION 3.24.2)

# project name
project(SDL2-project) #${PROJECT_NAME} 

set(CMAKE_CXX_STANDARD 17)

file( GLOB LIB_SOURCES src/*.cpp )
file( GLOB LIB_HEADERS lib/*.hpp )
file( GLOB INCLUDE_HEADERS include/*.hpp )
file( GLOB INCLUDE_IMAGES images/*.png)
add_executable(${PROJECT_NAME} ${LIB_SOURCES} ${LIB_HEADERS} ${INCLUDE_HEADERS} ${INCLUDE_IMAGES}) 
# set(HEADER_FILES )
# add_library(headers ${LIB_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include build/_deps/sdl_image-src images)
#*=============================================================================
#                         EGL 
#=============================================================================*/
# include(FetchContent)
# FetchContent_Declare(
#   egl #has to be lowercase? 
#   GIT_REPOSITORY https://github.com/KhronosGroup/EGL-Registry.git
#   GIT_TAG        main
# )
# FetchContent_MakeAvailable(egl)
# include_directories(${egl_SOURCE_DIR}/api)
# message(${egl_SOURCE_DIR})
#*=============================================================================
#                         OpenGL
#=============================================================================*/
# include(FetchContent)
# FetchContent_Declare(
#   opengl #has to be lowercase? 
#   GIT_REPOSITORY https://github.com/KhronosGroup/OpenGL-Registry.git
#   GIT_TAG        main
# )
# # After the following call, the CMake targets defined by opengl and
# # opengl will be available to the rest of the build
# FetchContent_MakeAvailable(opengl)
# include_directories(${opengl_SOURCE_DIR}/api)
# message(${opengl_SOURCE_DIR})
#*=============================================================================
#                         SDL2 
#=============================================================================*/
include_directories(C:/SDL2-devel-2.26.1-mingw/SDL2-2.26.1/x86_64-w64-mingw32/include) 
set(SDL2_ROOT C:/SDL2-devel-2.26.1-mingw)
find_package(SDL2 REQUIRED SDL2)
if (SDL2_FOUND)
    include_directories(${SDL2_INCLUDE_DIR})
    message(${SDL2_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
    message(${SDL2_LIBRARIES})
endif()
#*=============================================================================
#                         SDL_Image
#=============================================================================*/
# Add SDL2 CMake modules
# set(CMAKE_MODULE_PATH  "build/_deps/sdl_image-build")
# list(APPEND CMAKE_MODULE_PATH ${SDL2_ROOT}/SDL2-2.26.1/x86_64-w64-mingw32/lib/cmake)
# list(APPEND CMAKE_MODULE_PATH "./cmake_modules/FindSDL2_image.cmake")
# message("thissss " ${SDL2_ROOT})
# message("thissss " ${CMAKE_MODULE_PATH})
# set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
# message(${CMAKE_MODULE_PATH})

include(FetchContent)
FetchContent_Declare(
  sdl_image #has to be lowercase? 
  GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
  GIT_TAG        1515e208511e6c44ddb73ef0222327854a2cda5d
  GIT_PROGRESS   TRUE
)
# After the following call, the CMake targets defined by sdl_image and
# sdl_image will be available to the rest of the build
FetchContent_MakeAvailable(sdl_image)

set(SDL_LIBRARIES ${SDL_LIBRARIES} SDL2_image)
# target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} ${SDL_LIBRARIES})

# if(SDL_IMAGE_FOUND)
#     include_directories(${sdl_image_SOURCE_DIR} ${SDL_IMAGE_LIBRARIES})
#     message("sdl_image_src_dir " ${sdl_image_SOURCE_DIR})
#     target_link_libraries(${PROJECT_NAME}  ${SDL_IMAGE_LIBRARIES})
# endif()

# INCLUDE(FindPkgConfig)
# PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

# find_package(SDL2_image REQUIRED)
# include_directories(${SDL2IMAGE_INCLUDE_DIRS})
# target_link_libraries(${PROJECT_NAME}  ${SDL_IMAGE_LIBRARIES})

# message("SDL2IMAGE_LIBRARIES " ${SDL2IMAGE_LIBRARIES})
# find_package(SDL2_image REQUIRED)
# target_link_libraries(${PROJECT_NAME} ${sdl_image_SOURCE_DIR})

# find_package(SDL2_image REQUIRED)
# target_link_libraries(${PROJECT_NAME} SDL2_image::SDL2_image)

#*=============================================================================
#                         Boost LOG 
#=============================================================================*/
set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
# set(Boost_INCLUDE_DIR C:/local/boost_1_80_0)
# set(Boost_COMPILER "-vc143")
set(BOOST_ROOT C:/local/boost_1_80_0)
# add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)
set(Boost_DIR C:/local/boost_1_80_0/stage/lib/cmake/Boost-1.80.0/)
find_package(Boost CONFIG REQUIRED log log_setup) 
# include_directories(${Boost_INCLUDE_DIRS})
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()
#*=============================================================================
#                         Copy dlls to build directory
#=============================================================================*/
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "C:/SDL2-2.26.1-win32-x64/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB BOOST_DEP_DLLS "C:/local/boost_1_80_0/lib64-msvc-14.3/*.dll")
    file(COPY ${BOOST_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB SDL2_IMAGED_DEP_DLLS "build/_deps/sdl_image-build/SDL2_imaged.dll")
    file(COPY ${SDL2_IMAGED_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
