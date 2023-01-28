#pragma once

#include <SDL_rect.h>
#include <SDL_render.h>
#include "Mouse.hpp"

class Button {

 public:
  static SDL_Texture* tex;  //global variable, const

  Button(SDL_Renderer* ren, int x, int y);
  ~Button();

  void Update(Mouse* mouse);
  void Draw(SDL_Renderer* ren);
  void SetPosition(const int& x, const int& y);
  void SetButtonSelected(bool buttonSelected);
  bool GetButtonSelected() const;
  void SetSRECT(int x, int y, int h, int w);
  void SetSRECTX(int x) {
    this->srect_.x = x;
  }
  void SetDRECT(int x, int y, int h, int w);

 private:
  bool selected_ = false;
  SDL_Rect srect_;
  SDL_Rect drect_;
};