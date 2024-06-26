#include <GameState.hpp>
#include <memory>
#include "MenuState.hpp"
#include "OptionsState.hpp"
#include "StartGameState.hpp"
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

GameState* GameState::menu             = new Menu;
GameState* GameState::options          = new Options;
GameState* GameState::startGame        = new StartGameState;
GameState* GameState::currentGameState = menu;
bool GameState::gameRunning            = true;
Mouse* GameState::mouse                = new Mouse(ren);
// std::unique_ptr<GameState> GameState::menu(new Menu);
// GameState* GameState::currentGameState = menu;

// GameState* GameState::menu(new Menu);
// std::unique_ptr<GameState> GameState::options(new Options);
// std::unique_ptr<GameState> currentGameState = GameState::menu;

// std::shared_ptr<GameState> GameState::menu             = std::make_shared<GameState>();
// std::shared_ptr<GameState> GameState::options          = std::make_shared<GameState>();

// std::unique_ptr<GameState> GameState::currentGameState = std::move(menu);
/*=============================================================================
#                                   GameState 
#                                 ABSTRACT CLASS
#=============================================================================*/
GameState::GameState() = default;

void GameState::OnActivate() {
  gameRunning = true;
}
void GameState::OnDeactivate() {
  spdlog::info("GameState memory freed");
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  SDL_Quit();
}
void GameState::OnRender() {
}
void GameState::OnLoop() {
  spdlog::info("GameState OnLoop()");
}

void GameState::BaseUpdate() {
  mouse->Update();
}