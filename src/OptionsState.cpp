#include "OptionsState.hpp"
#include <SDL_render.h>
#include "GameState.hpp"
#include "SDL_image.h"
#include "DEFINITIONS.hpp"

/*=============================================================================
#                                   MENU 
#=============================================================================*/
Options::Options() {
  this->bgd = IMG_LoadTexture(ren, OPTIONSSTATEBACKGROUND);
  if (this->bgd == nullptr) {
    LOG << "Options image load error " << SDL_GetError();
  }
  menuButton = new Button(ren, 0, 0, MENUBUTTONIMAGE);  //BUTTON_ONE_Y should be 128 ?
  menuButton->SetPosition(BUTTON_ONE_XPOS, BUTTON_ONE_YPOS);
  Mouse::UpdateShowCursorBool(true);
}

Options::~Options() {
  SDL_DestroyTexture(this->bgd);
};

void Options::OnActivate() {
  stateRunning = true;
  Mouse::UpdateShowCursorBool(true);
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
          if (menuButton->GetButtonSelected()) {  //checks if menu button pressed this state
            currentGameState = menu;
            stateRunning     = false;
          }
          break;
      }
    }

    BaseUpdate();
    menuButton->Update(mouse);

    const auto* key = SDL_GetKeyboardState(nullptr);
    if (key[SDL_SCANCODE_ESCAPE] != 0U) {  //if esc is pressed, exits app
      gameRunning  = false;
      stateRunning = false;
      OnDeactivate();
    }
    if (key[SDL_SCANCODE_2] != 0U) {  //if 2 pressed, changes to this state
      currentGameState = menu;
      break;
    }

    OnRender();
  }
}
