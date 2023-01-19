#include "Mouse.hpp"
#include <SDL_mouse.h>
#include <SDL_render.h>
#include "SDL_image.h"

Mouse::Mouse(SDL_Renderer* ren)
    : rect(), point(), tex(IMG_LoadTexture(ren, "../images/mouse.png")) {
  const int xPos   = 300;
  const int yPos   = 300;
  const int width  = 50;
  const int length = 50;
  rect             = {xPos, yPos, width, length};
  point            = {xPos, yPos, 1, 1};
  SDL_ShowCursor(0);  //false
}

void Mouse::Update() {
  SDL_GetMouseState(&rect.x, &rect.y);
  point.y = rect.y;
  point.x = rect.x;
}

void Mouse::Draw(SDL_Renderer* ren) {
  SDL_RenderCopy(ren, tex, nullptr, &rect);  //point in nullptr
}