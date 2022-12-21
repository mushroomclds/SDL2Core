#include "../include/GameApp.hpp"

bool GameApp::OnInit() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    return false;
  }

  // if ((Surf_Display = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF))
  //     == NULL) {
  //   return false;
  // }

  // SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

  CAppStateManager::SetActiveAppState(APPSTATE_INTRO);

  return true;
}

void GameApp::OnEvent(SDL_Event* Event) {
  //   CEvent::OnEvent(Event);

  CAppStateManager::OnEvent(Event);
}

void GameApp::OnExit() {
  Running = false;
}

void GameApp::OnLoop() {
  CAppStateManager::OnLoop();

  //   CFPS::FPSControl.OnLoop();

  //   char Buffer[255];
  //   sprintf(Buffer, "FPS: %d", CFPS::FPSControl.GetFPS());
  //   SDL_WM_SetCaption(Buffer, Buffer);
}

void GameApp::OnCleanup() {
  CAppStateManager::SetActiveAppState(APPSTATE_NONE);

  SDL_FreeSurface(Surf_Display);
  SDL_Quit();
}