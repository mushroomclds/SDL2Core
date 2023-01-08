#include <GameState.hpp>
#include "SDL_image.h"
#include <SDL_error.h>
#include <SDL_events.h>
#include <SDL_render.h>
#include "DEFINITIONS.hpp"

SDL_Window* GameState::win = SDL_CreateWindow("window",
                                              SDL_WINDOWPOS_UNDEFINED,
                                              SDL_WINDOWPOS_UNDEFINED,
                                              1280,
                                              720,
                                              SDL_WINDOW_RESIZABLE);

SDL_Renderer* GameState::ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
/*=============================================================================
#                                   GameState 
#=============================================================================*/
GameState::GameState() = default;

void GameState::OnActivate() {
}
void GameState::OnDeactivate() {
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  SDL_Quit();
}
void GameState::OnRender() {
}
void GameState::OnLoop() {
}
/*=============================================================================
#                                   MENU 
#=============================================================================*/
Menu::Menu() {
  this->bgd = IMG_LoadTexture(ren, "../Menu-2.png");
  if (this->bgd == nullptr) {
    LOG << "bgd image load error " << SDL_GetError();
  }
}

Menu::~Menu() = default;

void Menu::OnActivate() {
}

void Menu::OnDeactivate() {
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
          OnDeactivate();
          gameRunning = false;
        case SDL_KEYDOWN:
          if (e.key.keysym.sym == SDLK_ESCAPE) {
            gameRunning = false;
          }
      }
    }
    OnRender();
  }
}
