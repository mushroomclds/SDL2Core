// #pragma once
// #include <SDL2/SDL.h>
// #include <iostream>
// #include <memory>
// #include "../include/DEFINITIONS.hpp"

// class Game {

//  public:
//   explicit Game(std::shared_ptr<SDL_Window> windowData);
//   ~Game();
//   void Update();
//   void static Render(SDL_Renderer* render);
//   void static InitWindow();
//   void CheckCollisions();

//   bool Running() const;
//   void PollEvents();

//   SDL_Renderer* GetRenderer();

//  private:
//   std::shared_ptr<SDL_Window> windowData_;
//   SDL_Renderer* renderer_;
//   //  SDL_Window* window
//   bool isRunning_ = true;
//   SDL_Event event_;
// };