#include "StartGameState.hpp"
#include <SDL_events.h>
#include <SDL_keyboard.h>
#include <SDL_rect.h>
#include <SDL_render.h>
#include "GameState.hpp"
#include "SDL_image.h"
#include "DEFINITIONS.hpp"

/*=============================================================================
#                                   StartGameState 
#=============================================================================*/
StartGameState::StartGameState() {  //initialized before main func since static class mem
  this->bgd = IMG_LoadTexture(ren, STARTGAMESTATEBACKGROUND);
  if (this->bgd == nullptr) {
    LOG << "bgd image load error "
        << SDL_GetError();  //doesnt show because done at compile time since its static
  }
  Mouse::UpdateShowCursorBool(false);  //can call directly since its static function
}

StartGameState::~StartGameState() {
  SDL_DestroyTexture(this->bgd);
};

void StartGameState::OnActivate() {
  stateRunning = true;
  Mouse::UpdateShowCursorBool(false);
}

void StartGameState::OnDeactivate() {

  LOG << "StartGameState Deactivate called";
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  SDL_Quit();
}

/*=============================================================================
#                                   Render  
#=============================================================================*/
void StartGameState::OnRender() {
  SDL_RenderClear(ren);  //clears window before new frame to render
  SDL_Rect rect{0,
                0,
                VIDEOMODE_WIDTH,
                VIDEOMODE_HEIGHT};  //bg rect that will have tex applied to below

  SDL_RenderCopy(ren, this->bgd, nullptr, &rect);  //applies tex to bg
  mouse->Draw(ren);

  SDL_RenderPresent(ren);  //renders above to window
}

/*=============================================================================
#                                   Poll Events 
#=============================================================================*/
void StartGameState::OnLoop() {
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
          // case SDL_MOUSEBUTTONUP://checks if menu button pressed this state
          //   if (optionsButton->GetButtonSelected()) {
          //     currentGameState = options;
          //     stateRunning     = false;
          //   }
          //   break;
      }
    }

    BaseUpdate();

    const auto* key = SDL_GetKeyboardState(nullptr);
    if (key[SDL_SCANCODE_ESCAPE] != 0U) {  //if esc is pressed, exits app
      LOG << "scancode escape";
      gameRunning  = false;
      stateRunning = false;
      OnDeactivate();
    }
    if (key[SDL_SCANCODE_1] != 0U) {  //if 1 pressed, changes to this state
      currentGameState = GameState::startGame;
      break;
    }

    OnRender();
  }
}
