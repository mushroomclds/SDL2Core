#include "../include/GameState.hpp"
#include <SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL_render.h>
#include <SDL_surface.h>
#include <SDL_video.h>

SDL_Window* GameState::win = SDL_CreateWindow("window",
                                              SDL_WINDOWPOS_UNDEFINED,
                                              SDL_WINDOWPOS_UNDEFINED,
                                              1280,
                                              720,
                                              SDL_WINDOW_RESIZABLE);

SDL_Renderer* GameState::ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

GameState::GameState() = default;

void GameState::OnActivate() {
}
void GameState::OnDeactivate() {
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  //   SDL_QUIT();
}
void GameState::OnRender() {
}
void GameState::OnLoop() {
}

Menu::Menu() {  //   backgroundTexture = IMG_LoadTexture(ren, "./Menu-1.png");
  //   backgroundTexture = IMG_LoadTexture(ren, "./Menu-1.png");
  SDL_Surface* image = SDL_LoadBMP("./Menu-2.png");
  backgroundTexture  = SDL_CreateTextureFromSurface(ren, image);
}

Menu::~Menu() {
}

void Menu::OnActivate() {
}

void Menu::OnDeactivate() {
}
void Menu::OnRender() {
}
void Menu::OnLoop() {
  while (1) {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
      switch (e.type) {
        case SDL_QUIT:
          OnDeactivate();
      }
    }
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, backgroundTexture, NULL, NULL);
    SDL_RenderPresent(ren);
  }
}
