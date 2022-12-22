#pragma once

#include <SDL.h>

// #include "Define.hpp"

#include "../include/GameStateManager.hpp"
// #include "CFPS.h"

#include "CEvent.h"
// #include "CSurface.h"

class GameApp : public CEvent {
 private:
  bool Running;

  SDL_Surface* Surf_Display;

 public:
  GameApp();

  int OnExecute();

  bool OnInit();

  void OnEvent(SDL_Event* Event);

  void OnExit();

  void OnLoop();

  void OnRender();

  void OnCleanup();
};
