#include <utility>

#include "../include/Game.hpp"
#include "../include/DEFINITIONS.hpp"
/*=============================================================================
|                         Constructor/Deconstructor
=============================================================================*/
Game::Game(std::shared_ptr<sf::RenderWindow> data)
    : data_(std::move(data)), endGame_(false), ev_() {  // constructor definition
}

Game::~Game() {  // deconstrutor definition
  // delete this->data;
  std::cout << "shared ptr count at Game destructor: " << this->data_.use_count()
            << std::endl;
}
/*============================================================================= 
|                          Initialize functions
=============================================================================*/

void Game::InitWindow() {
  // this->videoMode = sf::VideoMode(800, 600);
  // this->window = new sf::RenderWindow(this->videoMode, "Game",
  // sf::Style::Close | sf::Style::Titlebar); //render window needed to draw
  // on
  this->data_->create(sf::VideoMode(VIDEOMODE_WIDTH, VIDEOMODE_HEIGHT),
                      "title",
                      sf::Style::Close | sf::Style::Titlebar);
  std::cout << "Original data ptr win size: " << data_->getSize().x << " x "
            << data_->getSize().y << std::endl;
}
/*=============================================================================
|                          Game System Run & Update
=============================================================================*/
bool Game::Running() const {
  return this->data_->isOpen();
}

#pragma clang diagnostic ignored "-Wswitch"
void Game::PollEvents() {  // checks if window was/is closed and
  while (this->data_->pollEvent(this->ev_)) {
    switch (this->ev_.type) {
      case sf::Event::Closed:
        this->data_->close();
        break;
      case sf::Event::KeyPressed:
        if (ev_.key.code == sf::Keyboard::Escape) this->data_->close();
    }
  }
}

void Game::Update() {  // update game variables before rendered
  this->PollEvents();
  std::cout << "Poll Events Done" << std::endl;
}

void Game::Render() {  // renders all variables to the screen, last thing done.
  this->data_->clear();

  // render stuff here

  this->data_->display();
}

/*=============================================================================
|
=============================================================================*/