#include "MenuState.hpp"
#include <SDL_events.h>
#include <SDL_keyboard.h>
#include <SDL_rect.h>
#include <SDL_render.h>
#include "GameState.hpp"
#include "SDL_image.h"
#include "DEFINITIONS.hpp"

/*=============================================================================
#                                   MENU 
#=============================================================================*/
#include <iostream>
Menu::Menu() {  //initialized before main func since static class mem
  this->bgd = IMG_LoadTexture(ren, "../images/Menu-2.png");
  if (this->bgd == nullptr) {
    LOG << "bgd image load error " << SDL_GetError();
  }
  optionsButton = new Button(ren, 0, 64);
  optionsButton->setPosition(640 - (190 / 2), 500);  //for destination rect
}

Menu::~Menu() {
  SDL_DestroyTexture(this->bgd);
};

void Menu::OnActivate() {
  stateRunning = true;
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
  SDL_RenderClear(ren);            //clears window before new frame to render
  SDL_Rect rect{0, 0, 1280, 720};  //bg rect that will have tex applied to below

  SDL_RenderCopy(ren, this->bgd, NULL, &rect);  //applies tex to bg
  optionsButton->Draw(ren);
  mouse->Draw(ren);

  SDL_RenderPresent(ren);  //renders above to window
}

/*=============================================================================
#                                   Poll Events 
#=============================================================================*/
void Menu::OnLoop() {
  while (stateRunning) {

    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
      switch (e.type) {
        case SDL_QUIT:
          LOG << "x closed";
          gameRunning  = false;
          stateRunning = false;
          OnDeactivate();
          break;
        case SDL_MOUSEBUTTONUP:
          if (optionsButton->selected) {
            currentGameState = options;
            stateRunning     = false;
          }
          break;
      }
    }

    BaseUpdate();
    optionsButton->Update(mouse);

    auto key = SDL_GetKeyboardState(NULL);
    if (key[SDL_SCANCODE_ESCAPE]) {
      LOG << "scancode escape";
      gameRunning  = false;
      stateRunning = false;
      OnDeactivate();
    }
    if (key[SDL_SCANCODE_1]) {
      currentGameState = options;
      break;
    }

    OnRender();
  }
}
