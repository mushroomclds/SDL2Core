#pragma once
#include <string>
#include <iomanip>
#include "spdlog/spdlog.h"
#include <spdlog/sinks/basic_file_sink.h>
#include "Logger.hpp"


#define LFC1_LOG_TRACE(logger)

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
// #define LOG               \
//   auto logger = Logger::get_logger(); \
//       logger->info  //<< std::setw(30) << std::left

#define FRAMERATE 75

#define VIDEOMODE_WIDTH 1280
#define VIDEOMODE_HEIGHT 720
#define HALF_WIN_SIZE 2

#define MENUSTATEBACKGROUND "../images/Menupage1.png"
#define STARTGAMESTATEBACKGROUND "../images/StartGameState.png"
#define GOTOMENUBUTTONIMAGE "../images/goToMenuButton.png"
#define OPTIONSSTATEBACKGROUND "../images/OptionsPage.png"
#define OPTIONSBUTTONIMAGE "../images/optionsButton.png"
#define STARTBUTTONIMAGE "../images/startButton.png"
#define MENUBUTTONIMAGE "../images/menuButton.png"

#define SRECTH 64
#define SRECTW 192

#define DRECTH 64
#define DRECTW 192

#define BUTTON_ONE_X 0
#define BUTTON_ONE_Y 64
#define BUTTON_ONE_XPOS 545
#define BUTTON_ONE_YPOS 500

#define STARTBUTTON_X 0
#define STARTBUTTON_Y 64
#define STARTBUTTON_XPOS 545
#define STARTBUTTON_YPOS 420