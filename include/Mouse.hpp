#pragma once

#include <SDL_rect.h>
#include <SDL_render.h>

class Mouse {
 public:
  SDL_Texture* tex{};
  SDL_Rect rect;
  SDL_Rect point;
  explicit Mouse(SDL_Renderer* ren);
  ~Mouse() = default;
  void Update();
  void Draw(SDL_Renderer* ren);
};