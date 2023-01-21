#pragma once

#include <SDL_rect.h>
#include <SDL_render.h>
#include "Mouse.hpp"

class Button {

 public:
  static SDL_Texture* tex;  //global variable

  Button(SDL_Renderer* ren, int x, int y);
  ~Button();

  SDL_Rect srect;
  SDL_Rect drect;
  bool selected = false;

  void Update(Mouse* mouse);
  void Draw(SDL_Renderer* ren);
  void SetPosition(const int& x, const int& y);
};