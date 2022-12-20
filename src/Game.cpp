#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <utility>

#include "../include/Game.hpp"

Game::Game(std::shared_ptr<SDL_Window> windowData)
    : windowData_(std::move(windowData)), renderer_(), event_() {
}

Game::~Game() {  // deconstrutor definition
  // delete this->data;
  LOG << "shared ptr count at Game destructor: " << this->windowData_.use_count();
}
/*============================================================================= 
|                          Initialize variables (not in use)
=============================================================================*/
void Game::InitWindow() {
  // this->renderer_ = SDL_CreateRenderer(std::static_pointer_cast<SDL_Renderer*>(this->windowData_), -1, 0);
  LOG << "Original data ptr win size: ";
}
/*=============================================================================
|                          Game System Run & Update
=============================================================================*/
bool Game::Running() const {
  return this->isRunning_;
}

void Game::PollEvents() {  // checks if window was/is closed and to close game
  while (SDL_PollEvent(&this->event_) != 0) {
    switch (this->event_.type) {
      case SDL_QUIT:
        this->isRunning_ = false;
        break;

      case SDL_KEYDOWN:
        if (this->event_.key.keysym.sym == SDLK_ESCAPE) {
          this->isRunning_ = false;
        }
    }
  }
}

void Game::Update() {  // update game variables before rendered
  this->PollEvents();
}

void Game::Render(SDL_Renderer* render) {  // renders all variables to the screen, last thing done.
  SDL_RenderClear(render);
  const int rField     = 225;
  const int gField     = 0;
  const int bField     = 0;
  const int alphaField = 225;
  SDL_SetRenderDrawColor(render, rField, gField, bField, alphaField);
  SDL_RenderPresent(render);
}

SDL_Renderer* Game::GetRenderer() {
  return this->renderer_;
}