#include "GameState.hpp"

class Options : public GameState {
 public:
  Options();
  ~Options() override;
  void OnActivate() override;
  void OnDeactivate() override;
  void OnLoop() override;
  void OnRender() override;

  Button* menuButton;
};