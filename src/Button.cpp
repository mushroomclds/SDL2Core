#include <SDL_rect.h>
#include <SDL_render.h>
#include "DEFINITIONS.hpp"
#include "Button.hpp"
#include "SDL_image.h"

SDL_Texture* Button::tex = NULL;
Button::Button(SDL_Renderer* ren, int x, int y) {
  if (!tex) {
    tex = IMG_LoadTexture(ren, "../images/options.png");
  }
  srect.x = x;  //source rect
  srect.y = y;
  srect.h = 64;
  srect.w = 192;
}

Button::~Button() {
  SDL_DestroyTexture(tex);
}

void Button::Update(Mouse* mouse) {
  if (SDL_HasIntersection(&mouse->point, &drect)) {
    selected = true;
    srect.x  = 192;
  }
  else {
    selected = false;
    srect.x  = 0;
  }
}
void Button::Draw(SDL_Renderer* ren) {
  SDL_RenderCopy(ren, tex, NULL, &drect);  //NULL should be srect but doesnt work for me
}

void Button::setPosition(int x, int y) {
  drect.x = x;  //destination rect
  drect.y = y;
  drect.h = 64;
  drect.w = 192;
}