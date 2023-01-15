#include "GameState.hpp"

class Options : public GameState {
 public:
  Options();
  virtual ~Options();
  void OnActivate();
  void OnDeactivate();
  void OnLoop();
  void OnRender();

  Button* menuButton;
};