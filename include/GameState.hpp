#pragma once

#include <SDL_render.h>
#include <SDL_surface.h>
#include <SDL.h>
// #include <build/_deps/sdl_image-src/SDL_image.h>
// #include "IMG.c"
#include <SDL_video.h>

static int k            = SDL_Init(SDL_INIT_EVERYTHING);
static bool gameRunning = true;

class GameState {  //interface class
 public:
  GameState();
  virtual ~GameState() = default;

  static SDL_Window* win;
  static SDL_Renderer* ren;

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

class Menu : public GameState {
 public:
  Menu();
  virtual ~Menu();
  void OnActivate();
  void OnDeactivate();
  void OnLoop();
  void OnRender();
};