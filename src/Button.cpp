#include <SDL_rect.h>
#include <SDL_render.h>
#include "DEFINITIONS.hpp"
#include "Button.hpp"
#include "SDL_image.h"

SDL_Texture* Button::tex = nullptr;  //global variable, const

Button::Button(SDL_Renderer* ren, int x, int y) : srect_(), drect_() {
  if (tex == nullptr) {
    tex = IMG_LoadTexture(ren, "../images/options.png");
  }
  SetDRECT(x, y, SRECTH, SRECTW);
}

Button::~Button() {
  SDL_DestroyTexture(tex);
}

void Button::Update(Mouse* mouse) {
  if (SDL_HasIntersection(&mouse->point, &drect_) != 0) {
    SetButtonSelected(true);
    SetSRECTX(SRECTW);
  }
  else {
    SetButtonSelected(false);
    SetSRECTX(0);
  }
}

void Button::Draw(SDL_Renderer* ren) {
  SDL_RenderCopy(ren, tex, nullptr, &drect_);  //NULL should be srect but doesnt work for me
}

void Button::SetPosition(const int& x, const int& y) {
  SetSRECT(x, y, DRECTH, DRECTW);
}

void Button::SetButtonSelected(bool buttonSelected) {
  this->selected_ = buttonSelected;
}

void Button::SetDRECT(int x, int y, int h, int w) {
  srect_.x = x;  //source rect
  srect_.y = y;
  srect_.h = h;  //SRECTH
  srect_.w = w;  //SRECTW
}

void Button::SetSRECT(int x, int y, int h, int w) {
  srect_.x = x;  //source rect
  srect_.y = y;
  srect_.h = h;  //DRECTH
  srect_.w = w;  //DRECTW
}