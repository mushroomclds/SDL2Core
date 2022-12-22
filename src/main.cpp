#include <SDL_render.h>
#include <memory>
#include "../include/Game.hpp"

namespace logging  = boost::log;
namespace keywords = boost::log::keywords;
void InitBoost() {
  keywords::auto_flush = true;
  boost::log::add_common_attributes();
  logging::add_file_log(keywords::file_name = "../default_%N.log",
                        keywords::format    = "%Message% ");  //%TimeStamp%
  logging::core::get()->set_filter(logging::trivial::severity >= logging::trivial::info);
}

// int main(int /*argc*/, char** /*argv*/) {

//   InitBoost();  //intialize boost logging
//   LOG << "Boost Logging Successful";

//   SDL_Init(SDL_INIT_EVERYTHING);
//   SDL_Window* window = SDL_CreateWindow("Hello SDL",
//                                         SDL_WINDOWPOS_CENTERED,
//                                         SDL_WINDOWPOS_CENTERED,
//                                         VIDEOMODE_WIDTH,
//                                         VIDEOMODE_HEIGHT,
//                                         0);
//   std::shared_ptr<SDL_Window> windowData;
//   windowData.reset(window, SDL_DestroyWindow);

//   Game game(windowData);  //object to handle update and render

//   SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);

//   while (game.Running()) {
//     game.Update();         // update all variables, including renderWindow
//     Game::Render(render);  // render all varia bles
//   }

//   //clean up after window closed
//   SDL_DestroyRenderer(render);
//   SDL_Quit();
//   SDL_DestroyWindow(window);
//   return 0;
// }