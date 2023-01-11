#include "GameState.hpp"

class Menu : public GameState {
 public:
  Menu();
  virtual ~Menu();
  void OnActivate();
  void OnDeactivate();
  void OnLoop();
  void OnRender();
};