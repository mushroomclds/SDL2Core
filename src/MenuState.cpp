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
Menu::Menu() {  //initialized before main func since static class mem
  this->bgd = IMG_LoadTexture(ren, MENUSTATEBACKGROUND);
  if (this->bgd == nullptr) {
    LOG << "bgd image load error "
        << SDL_GetError();  //doesnt show because done at compile time since its static
  }
  optionsButton = new Button(ren, 0, 0, OPTIONSBUTTONIMAGE);
  optionsButton->SetPosition(BUTTON_ONE_XPOS, BUTTON_ONE_YPOS);  //for destination rect
  startGameButton = new Button(ren, 0, 0, STARTBUTTONIMAGE);
  startGameButton->SetPosition(STARTBUTTON_XPOS, STARTBUTTON_YPOS);  //for destination rect
  Mouse::UpdateShowCursorBool(false);  //can call directyl since its static function
}

Menu::~Menu() {
  SDL_DestroyTexture(this->bgd);
};

void Menu::OnActivate() {
  stateRunning = true;
  Mouse::UpdateShowCursorBool(false);
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
  SDL_RenderClear(ren);  //clears window before new frame to render
  SDL_Rect rect{0,
                0,
                VIDEOMODE_WIDTH,
                VIDEOMODE_HEIGHT};  //bg rect that will have tex applied to below

  SDL_RenderCopy(ren, this->bgd, nullptr, &rect);  //applies tex to bg
  optionsButton->Draw(ren);
  startGameButton->Draw(ren);
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
          if (optionsButton->GetButtonSelected()) {
            currentGameState = options;
            stateRunning     = false;
          }
          break;
      }
    }

    BaseUpdate();
    optionsButton->Update(mouse);

    const auto* key = SDL_GetKeyboardState(nullptr);
    if (key[SDL_SCANCODE_ESCAPE] != 0U) {
      LOG << "scancode escape";
      gameRunning  = false;
      stateRunning = false;
      OnDeactivate();
    }
    if (key[SDL_SCANCODE_1] != 0U) {
      currentGameState = options;
      break;
    }

    OnRender();
  }
}
