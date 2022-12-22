#pragma once
#include <SDL_events.h>
#include "GameState.hpp"

enum {
  // Add your Other App States Here
  APPSTATE_NONE,
  APPSTATE_INTRO,
  APPSTATE_GAME
};

class GameStateManager {
 private:
  static GameState* ActiveAppState;

 public:
  static void OnEvent(SDL_Event* Event);

  static void OnLoop();

  static void OnRender(SDL_Surface* Surf_Display);

  static void SetActiveAppState(int AppStateID);

  static GameState* GetActiveAppState();
};
