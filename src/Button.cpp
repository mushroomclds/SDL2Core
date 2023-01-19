#include <SDL_rect.h>
#include <SDL_render.h>
#include "DEFINITIONS.hpp"
#include "Button.hpp"
#include "SDL_image.h"

SDL_Texture* Button::tex = nullptr;

Button::Button(SDL_Renderer* ren, int x, int y) : srect(), drect() {
  if (tex == nullptr) {
    tex = IMG_LoadTexture(ren, "../images/options.png");
  }
  srect.x = x;  //source rect
  srect.y = y;
  srect.h = SRECTH;
  srect.w = SRECTW;
}

Button::~Button() {
  SDL_DestroyTexture(tex);
}

void Button::Update(Mouse* mouse) {
  if (SDL_HasIntersection(&mouse->point, &drect) != 0) {
    selected = true;
    srect.x  = SRECTW;
  }
  else {
    selected = false;
    srect.x  = 0;
  }
}

void Button::Draw(SDL_Renderer* ren) {
  SDL_RenderCopy(ren, tex, nullptr, &drect);  //NULL should be srect but doesnt work for me
}

void Button::SetPosition(int x, int y) {
  drect.x = x;  //destination rect
  drect.y = y;
  drect.h = DRECTH;
  drect.w = DRECTW;
}
