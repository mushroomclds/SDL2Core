#include "OptionsState.hpp"
#include <SDL_render.h>
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
  menuButton->setPosition(640 - (190 / 2), 500);
}

Options::~Options() {
  SDL_DestroyTexture(this->bgd);
};

void Options::OnActivate() {
}

void Options::OnDeactivate() {
}

/*=============================================================================
#                                   Render  
#=============================================================================*/
void Options::OnRender() {
  SDL_RenderClear(ren);
  SDL_Rect rect{0, 0, 1280, 720};
  SDL_RenderCopy(ren, this->bgd, NULL, &rect);

  menuButton->Draw(ren);

  SDL_RenderPresent(ren);
}

/*=============================================================================
#                                   Poll Events 
#=============================================================================*/
void Options::OnLoop() {
  while (gameRunning) {

    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
      switch (e.type) {
        case SDL_QUIT:
          gameRunning = false;
          OnDeactivate();
          break;
          // case SDL_KEYDOWN:
          //   if (e.key.keysym.sym == SDLK_ESCAPE) {
          //     gameRunning = false;
          //   }
      }
    }

    BaseUpdate();
    menuButton->Update(mouse);

    auto key = SDL_GetKeyboardState(NULL);
    if (key[SDL_SCANCODE_ESCAPE]) {
      OnDeactivate();
    }
    if (key[SDL_SCANCODE_2]) {
      currentGameState = menu;
      break;
    }

    OnRender();
  }
}
