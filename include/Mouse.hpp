#pragma once

#include <SDL_rect.h>
#include <SDL_render.h>

class Mouse {
 public:
  explicit Mouse(SDL_Renderer* ren);
  ~Mouse() = default;
  void Update();
  void Draw(SDL_Renderer* ren);

  // showCursor_
  void static UpdateShowCursorBool(bool);
  bool GetShowCursorBool();
  // point_
  void static SetPoint(SDL_Rect);
  SDL_Rect& GetPoint();

 private:
  SDL_Texture* tex_{};
  SDL_Rect rect_;
  SDL_Rect point_;
  bool showCursor_;
};