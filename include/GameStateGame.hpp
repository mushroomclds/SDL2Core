#pragma once
#include "GameState.hpp"
#include "SDL.h"
// #include "CArea.h"
// #include "CCamera.h"
// #include "CEntity.h"
// #include "CSurface.h"

// #include "CPlayer.h"

class GameStateGame : public GameState {
 private:
  static GameStateGame Instance;
  //   CPlayer Player;
  //   CPlayer Player2;
  GameStateGame();

 public:
  //   void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
  //   void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
  void OnActivate();

  void OnDeactivate();

  void OnLoop();

  void OnRender(SDL_Surface* Surf_Display);

  static GameStateGame* GetInstance();
};
