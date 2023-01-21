#include "OptionsState.hpp"
#include <SDL_render.h>
#include "GameState.hpp"
#include "SDL_image.h"
#include "DEFINITIONS.hpp"

/*=============================================================================
#                                   MENU 
#=============================================================================*/
Options::Options() {
  this->bgd = IMG_LoadTexture(ren, "../images/Menu-3.png");
  if (this->bgd == nullptr) {
    LOG << "Options image load error " << SDL_GetError();
  }
  menuButton = new Button(ren, 0, 128);
  menuButton->SetPosition(640 - (190 / 2), 500);
  Options::mouse->UpdateShowCursorBool(true);
}

Options::~Options() {
  SDL_DestroyTexture(this->bgd);
};

void Options::OnActivate() {
  stateRunning = true;
  Options::mouse->UpdateShowCursorBool(true);
}

void Options::OnDeactivate() {
}

/*=============================================================================
#                                   Render  
#=============================================================================*/
void Options::OnRender() {
  SDL_RenderClear(ren);
  SDL_Rect rect{0, 0, VIDEOMODE_WIDTH, VIDEOMODE_HEIGHT};
  SDL_RenderCopy(ren, this->bgd, nullptr, &rect);

  menuButton->Draw(ren);

  SDL_RenderPresent(ren);
}

/*=============================================================================
#                                   Poll Events 
#=============================================================================*/
void Options::OnLoop() {
  while (stateRunning) {

    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
      switch (e.type) {
        case SDL_QUIT:
          gameRunning  = false;
          stateRunning = false;
          OnDeactivate();
          break;
        // case SDL_KEYDOWN:
        //   if (e.key.keysym.sym == SDLK_ESCAPE) {
        //     gameRunning = false;
        //   }
        case SDL_MOUSEBUTTONUP:
          if (menuButton->selected) {
            currentGameState = menu;
            stateRunning     = false;
          }
          break;
      }
    }

    BaseUpdate();
    menuButton->Update(mouse);

    const auto* key = SDL_GetKeyboardState(nullptr);
    if (key[SDL_SCANCODE_ESCAPE] != 0u) {
      gameRunning  = false;
      stateRunning = false;
      OnDeactivate();
    }
    if (key[SDL_SCANCODE_2] != 0u) {
      currentGameState = menu;
      break;
    }

    OnRender();
  }
}
