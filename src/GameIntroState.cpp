#include "../include/GameIntroState.hpp"
#include "../include/GameStateManager.hpp"

GameIntroState GameIntroState::Instance;

GameIntroState::GameIntroState() {
  Surf_Logo = NULL;
}

void GameIntroState::OnActivate() {
  // Load Simple Logo
  //   Surf_Logo = CSurface::OnLoad("splash.png");

  //   StartTime = SDL_GetTicks();
}

void GameIntroState::OnDeactivate() {
  if (Surf_Logo) {
    SDL_FreeSurface(Surf_Logo);
    Surf_Logo = NULL;
  }
}

void GameIntroState::OnLoop() {
  //   if (StartTime + 3000 < SDL_GetTicks()) {
  //     CAppStateManager::SetActiveAppState(APPSTATE_GAME);
  //   }
}

void GameIntroState::OnRender(SDL_Surface* Surf_Display) {
  //   if (Surf_Logo) {
  //     CSurface::OnDraw(Surf_Display, Surf_Logo, 0, 0);
  //   }
}

GameIntroState* GameIntroState::GetInstance() {
  return &Instance;
}