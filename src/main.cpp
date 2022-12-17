#include <SDL2/SDL.h>
#include <iostream>
#include "../include/DEFINITIONS.hpp"

namespace logging  = boost::log;
namespace keywords = boost::log::keywords;
void InitBoost() {
  keywords::auto_flush = true;
  boost::log::add_common_attributes();
  logging::add_file_log(keywords::file_name = "../default_%N.log",
                        keywords::format    = "%Message% ");  //%TimeStamp%
  logging::core::get()->set_filter(logging::trivial::severity >= logging::trivial::info);
}

int main(int argv, char** args) {

  InitBoost();  //intialize boost logging
  LOG << "Boost Logging Successful";

  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window* window =
      SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

  bool isRunning = true;
  SDL_Event event;

  while (isRunning) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          isRunning = false;
          break;

        case SDL_KEYDOWN:
          if (event.key.keysym.sym == SDLK_ESCAPE) {
            isRunning = false;
          }
      }
    }

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}