#include <SDL_render.h>
#include <memory>
#include "GameState.hpp"
#include "MenuState.hpp"
#include "OptionsState.hpp"
#include "DEFINITIONS.hpp"

namespace logging  = boost::log;
namespace keywords = boost::log::keywords;

void InitBoost() {
  keywords::auto_flush = true;
  boost::log::add_common_attributes();
  logging::add_file_log(keywords::file_name = "../default_%N.log",
                        keywords::format    = "%Message% ");  //%TimeStamp%
  logging::core::get()->set_filter(logging::trivial::severity >= logging::trivial::info);
}

int main(int /*argc*/, char** /*argv*/) {
  InitBoost();  //intialize boost logging
  LOG << "Boost Logging Successful";

  // Menu menu;
  // menu.OnLoop();

  // Options options;
  // options.OnLoop();

  while (1) {
    GameState::currentGameState->OnLoop();
  }

  return 0;
}
