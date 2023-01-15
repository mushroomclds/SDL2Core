#include "Mouse.hpp"
#include <SDL_mouse.h>
#include <SDL_render.h>
#include "SDL_image.h"

Mouse::Mouse(SDL_Renderer* ren) {
  tex   = IMG_LoadTexture(ren, "../images/mouse.png");
  rect  = {300, 300, 50, 50};
  point = {300, 300, 1, 1};
  SDL_ShowCursor(false);
}

Mouse::~Mouse() {
}
void Mouse::Update() {
  SDL_GetMouseState(&rect.x, &rect.y);
  point.y = rect.y;
  point.x = rect.x;
}

void Mouse::Draw(SDL_Renderer* ren) {
  SDL_RenderCopy(ren, tex, NULL, &rect);
}