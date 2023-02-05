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
    SetSRECTY(64);  //sets x coord in image given
  }
  else {
    SetButtonSelected(false);
    SetSRECTY(0);  //sets x coord in image to 0
  }
}

void Button::Draw(SDL_Renderer* ren) {
  SDL_RenderCopy(ren, tex, &srect_, &drect_);  //NULL should be srect but doesnt work for me
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

void Button::SetSRECT(int x, int y, int h, int w) {  //souce rect, image here
  srect_.x = x;                                      //x coord of image given
  srect_.y = y;                                      //y coord of image given
  srect_.h = h;                                      //DRECTH, height of image
  srect_.w = w;                                      //DRECTW, width of image
}

void Button::SetDRECT(int x, int y, int h, int w) {  //destination rect
  drect_.x = x;                                      //x coord of destination, on window
  drect_.y = y;                                      //y coord of destination, on window
  drect_.h = h;                                      //SRECTH, height of rect on window
  drect_.w = w;                                      //SRECTW, width of rect on window
}
