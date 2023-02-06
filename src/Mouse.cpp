#include "Mouse.hpp"
#include <SDL_mouse.h>
#include <SDL_render.h>
#include "SDL_image.h"

Mouse::Mouse(SDL_Renderer* ren)
    : rect_(),
      point_(),
      tex_(IMG_LoadTexture(ren, "../images/mouseCursor.png")),
      showCursor_(false) {
  const int xPos   = 300;
  const int yPos   = 300;
  const int width  = 50;
  const int length = 50;
  rect_            = {xPos, yPos, width, length};
  point_           = {xPos, yPos, 1, 1};
  SDL_ShowCursor(static_cast<int>(showCursor_));  //false
}

void Mouse::Update() {
  SDL_GetMouseState(&rect_.x, &rect_.y);
  point_.y = rect_.y;
  point_.x = rect_.x;
}

void Mouse::Draw(SDL_Renderer* ren) {
  SDL_RenderCopy(ren, tex_, nullptr, &rect_);  //point_ in nullptr
}

void Mouse::UpdateShowCursorBool(bool showCursor) {
  // this->showCursor = showCursor;
  SDL_ShowCursor(static_cast<int>(showCursor));  //true
}

SDL_Rect& Mouse::GetPoint() {  //returns reference to point, basically like ptr bc address
  return point_;
}
