#pragma once

#include <SDL_render.h>
#include <SDL_surface.h>
#include <SDL.h>
// #include <build/_deps/sdl_image-src/SDL_image.h>
// #include "IMG.c"
#include <SDL_video.h>
#include <memory>

static int k = SDL_Init(SDL_INIT_EVERYTHING);

class GameState {  //interface class
 public:
  GameState();
  virtual ~GameState() = default;

  static SDL_Window* win;
  static SDL_Renderer* ren;

  static GameState* menu;
  static GameState* options;
  static GameState* currentGameState;
  static bool gameRunning;
  // static std::unique_ptr<GameState> options;
  // static std::unique_ptr<GameState> currentGameState;
  // static std::shared_ptr<GameState> menu;
  // static std::shared_ptr<GameState> options;
  // static std::unique_ptr<GameState> currentGameState;

  //enter
  virtual void OnActivate() = 0;  //equal 0 requires inheriter class to define func.

  //exit
  virtual void OnDeactivate() = 0;

  //update
  virtual void OnLoop() = 0;

  virtual void OnRender() = 0;
  // virtual void OnRender(SDL_Surface* Surf_Display) = 0;

  SDL_Texture* bgd;
};
