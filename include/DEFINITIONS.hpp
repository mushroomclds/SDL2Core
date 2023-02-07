#pragma once
#include <string>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <iomanip>

#define LFC1_LOG_TRACE(logger)

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define LOG               \
  BOOST_LOG_TRIVIAL(info) \
      << "[" << __FILENAME__ << " | Line: " << __LINE__ << "]"  //<< std::setw(30) << std::left

#define FRAMERATE 75

#define VIDEOMODE_WIDTH 1280
#define VIDEOMODE_HEIGHT 720
#define HALF_WIN_SIZE 2

#define MENUSTATEBACKGROUND "../images/Menupage1.png"
#define STARTGAMESTATEBACKGROUND "../images/StartGameState.png"
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