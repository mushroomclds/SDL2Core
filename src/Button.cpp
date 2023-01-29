#include <SDL_rect.h>
#include <SDL_render.h>
#include "DEFINITIONS.hpp"
#include "Button.hpp"
#include "SDL_image.h"

// SDL_Texture* Button::tex = nullptr;  //global variable, const

Button::Button(SDL_Renderer* ren, int x, int y, std::string pathToImage)
    : srect_(), drect_(), tex(nullptr) {
  if (tex == nullptr) {
    const char* path = pathToImage.data();  //string to char ptr
    tex              = IMG_LoadTexture(ren, path);
  }
  SetSRECT(x, y, SRECTH, SRECTW);
}

Button::~Button() {
  SDL_DestroyTexture(tex);
}

void Button::Update(Mouse* mouse) {
  if (SDL_HasIntersection(&mouse->GetPoint(), &drect_) != 0) {
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
  SetDRECT(x, y, DRECTH, DRECTW);
}

void Button::SetButtonSelected(bool buttonSelected) {
  this->selected_ = buttonSelected;
}
bool Button::GetButtonSelected() const {
  return this->selected_;
}

void Button::SetSRECT(int x, int y, int h, int w) {
  srect_.x = x;  //source rect
  srect_.y = y;
  srect_.h = h;  //DRECTH
  srect_.w = w;  //DRECTW
}

void Button::SetDRECT(int x, int y, int h, int w) {  //sets the destination of button
  drect_.x = x;                                      //destination rect
  drect_.y = y;
  drect_.h = h;  //SRECTH
  drect_.w = w;  //SRECTW
}
