// #include "../include/GameStateManager.hpp"

// // Refer to your Other App States Here
// #include "../include/GameIntroState.hpp"
// #include "../include/GameStateGame.hpp"

// GameState* GameStateManager::ActiveAppState = 0;

// void GameStateManager::OnEvent(SDL_Event* EventHolder) {
//   if (ActiveAppState) ActiveAppState->OnEvent(EventHolder);
// }

// void GameStateManager::OnLoop() {
//   if (ActiveAppState) ActiveAppState->OnLoop();
// }

// void GameStateManager::OnRender(SDL_Surface* Surf_Display) {
//   if (ActiveAppState) ActiveAppState->OnRender(Surf_Display);
// }

// void GameStateManager::SetActiveAppState(int AppStateID) {
//   if (ActiveAppState) ActiveAppState->OnDeactivate();

//   // Also, add your App State Here so that the Manager can switch to it
//   if (AppStateID == APPSTATE_NONE) ActiveAppState = 0;
//   if (AppStateID == APPSTATE_INTRO) ActiveAppState = GameIntroState::GetInstance();
//   if (AppStateID == APPSTATE_GAME) ActiveAppState = GameIntroState::GetInstance();

//   if (ActiveAppState) ActiveAppState->OnActivate();
// }

// GameState* GameStateManager::GetActiveAppState() {
//   return ActiveAppState;
// }