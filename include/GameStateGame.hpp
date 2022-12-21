#pragma once
#include "GameState.hpp"
#include "SDL.h"
// #include "CArea.h"
// #include "CCamera.h"
// #include "CEntity.h"
// #include "CSurface.h"

// #include "CPlayer.h"

class CAppStateGame : public GameState {
 private:
  static CAppStateGame Instance;

  //   CPlayer Player;
  //   CPlayer Player2;

 private:
  CAppStateGame();

 public:
  //   void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

  //   void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

 public:
  void OnActivate();

  void OnDeactivate();

  void OnLoop();

  void OnRender(SDL_Surface* Surf_Display);

  static CAppStateGame* GetInstance();
};
