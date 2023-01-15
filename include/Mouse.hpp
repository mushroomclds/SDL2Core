#pragma once

#include <SDL_rect.h>
#include <SDL_render.h>

class Mouse {
 public:
  SDL_Texture* tex;
  SDL_Rect rect;
  SDL_Rect point;
  Mouse(SDL_Renderer* ren);
  ~Mouse();
  void Update();
  void Draw(SDL_Renderer* ren);
};