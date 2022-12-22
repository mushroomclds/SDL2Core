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

  GameStateManager::SetActiveAppState(APPSTATE_INTRO);

  return true;
}

void GameApp::OnEvent(SDL_Event* Event) {
  //   CEvent::OnEvent(Event);

  GameStateManager::OnEvent(Event);
}

void GameApp::OnExit() {
  Running = false;
}

void GameApp::OnLoop() {
  GameStateManager::OnLoop();

  //   CFPS::FPSControl.OnLoop();

  //   char Buffer[255];
  //   sprintf(Buffer, "FPS: %d", CFPS::FPSControl.GetFPS());
  //   SDL_WM_SetCaption(Buffer, Buffer);
}

void GameApp::OnCleanup() {
  GameStateManager::SetActiveAppState(APPSTATE_NONE);

  SDL_FreeSurface(Surf_Display);
  SDL_Quit();
}

//==============================================================================
GameApp::GameApp() {
  Surf_Display = NULL;

  Running = true;
}

//------------------------------------------------------------------------------
int GameApp::OnExecute() {
  if (OnInit() == false) {
    return -1;
  }

  SDL_Event Event;

  while (Running) {
    while (SDL_PollEvent(&Event)) {
      OnEvent(&Event);
    }

    OnLoop();
    OnRender();
  }

  OnCleanup();

  return 0;
}

//==============================================================================
int main(int argc, char** argv) {
  GameApp theApp;

  return theApp.OnExecute();
}

//==============================================================================
