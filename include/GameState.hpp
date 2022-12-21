#pragma once

#include <SDL_surface.h>
// #include "CEvent.h"

class GameState /* :public CEvent*/ {  //interface class
 public:
  virtual ~GameState() = default;
  GameState();

  virtual void OnActivate() = 0;  //equal 0 requires inheriter class to define func.

  virtual void OnDeactivate() = 0;

  virtual void OnLoop() = 0;

  virtual void OnRender(SDL_Surface* Surf_Display) = 0;
};
