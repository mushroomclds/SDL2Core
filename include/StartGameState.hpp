#include "GameState.hpp"

class StartGameState : public GameState {
 public:
  StartGameState();
  ~StartGameState() override;
  void OnActivate() override;
  void OnDeactivate() override;
  void OnLoop() override;
  void OnRender() override;
};