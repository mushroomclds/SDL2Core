#include "GameState.hpp"

class Menu : public GameState {
 public:
  Menu();
  ~Menu() override;
  void OnActivate() override;
  void OnDeactivate() override;
  void OnLoop() override;
  void OnRender() override;
  Button* optionsButton;
};