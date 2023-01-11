#include "MenuState.hpp"
#include <SDL_keyboard.h>
#include <SDL_render.h>
#include "SDL_image.h"
#include "DEFINITIONS.hpp"

/*=============================================================================
#                                   MENU 
#=============================================================================*/
Menu::Menu() {
  this->bgd = IMG_LoadTexture(ren, "../Menu-2.png");
  if (this->bgd == nullptr) {
    LOG << "bgd image load error " << SDL_GetError();
  }
}

Menu::~Menu() {
  SDL_DestroyTexture(this->bgd);
};

void Menu::OnActivate() {
}

void Menu::OnDeactivate() {

  LOG << "Menu Deactivate called";
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  SDL_Quit();
}

/*=============================================================================
#                                   Render  
#=============================================================================*/
void Menu::OnRender() {
  SDL_RenderClear(ren);
  SDL_RenderCopy(ren, this->bgd, NULL, NULL);
  SDL_RenderPresent(ren);
}

/*=============================================================================
#                                   Poll Events 
#=============================================================================*/
void Menu::OnLoop() {
  while (gameRunning) {

    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
      switch (e.type) {
        case SDL_QUIT:
          gameRunning = false;
          OnDeactivate();
          break;
        case SDL_KEYDOWN:
          if (e.key.keysym.sym == SDLK_ESCAPE) {
            gameRunning = false;
            OnDeactivate();
          }
          break;
      }
    }

    auto key = SDL_GetKeyboardState(NULL);
    if (key[SDL_SCANCODE_ESCAPE]) {
      gameRunning = false;
      OnDeactivate();
    }
    if (key[SDL_SCANCODE_1]) {
      currentGameState = options;
      break;
    }

    OnRender();
  }
}
