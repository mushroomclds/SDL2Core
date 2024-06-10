#include <SDL_render.h>
#include <memory>
#include "GameState.hpp"
#include "MenuState.hpp"
// #include "OptionsState.hpp"
#include "DEFINITIONS.hpp"

void setupLogger() {
    // Create a file logger
    auto file_logger = spdlog::basic_logger_mt("file_logger", "../logs.txt");
    // Set it as the default logger
    spdlog::set_default_logger(file_logger);
}

int main(int /*argc*/, char** /*argv*/) {
  // try {
  //   auto file_logger = spdlog::basic_logger_mt("basic_logger", "./basic-log.txt", true);
  //   spdlog::set_default_logger(file_logger);
  //   file_logger->set_level(spdlog::level::info);
  //   file_logger->info("Logs started successfully");
  //   // spdlog::set_default_logger(file_logger);
  //   spdlog::flush_every(std::chrono::seconds(1));
  //   // file_logger->flush();
  //   // file_logger->info("Logs started successfully");

  // }
  // catch (const spdlog::spdlog_ex& ex){
  //   return 1;
  // }
  setupLogger();

   spdlog::info("Logging from main.cpp");

  // Menu menu; //debugging state works
  // menu.OnLoop();

  // Options options; //debugging state works
  // options.OnLoop();

  while (GameState::gameRunning) {
    GameState::currentGameState->OnActivate();
    GameState::currentGameState->OnLoop();
  }
  return 0;
}
