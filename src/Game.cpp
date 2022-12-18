#include <SDL_render.h>
#include <utility>

#include "../include./Game.hpp"

Game::Game(std::shared_ptr<SDL_Window> windowData) : windowData_(std::move(windowData)) {
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
  SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
  SDL_RenderPresent(render);
}

SDL_Renderer* Game::GetRenderer() {
  return this->renderer_;
}