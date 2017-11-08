#include "game.hpp"
//Uncomment line by line as you implement and test your classes
//#include "MyFrame.h"
//#include "MyMissile.h"
//#include "MyRocket.h"

//Uncomment step by step
Game::Game() /*:frame_(0),rocket_(0),missile_(0),game_over_(0)*/ { }


Game::~Game() {
	//Uncomment step by step
	//delete frame_;
	//delete rocket_;
	//delete missile_;
}


/*!
* \fn void initializeScene()
* \brief initializae all ojects in the game
*/
void Game::initialize()
{
	if (frame_) return; // guard
	//Uncomment step by step
	//frame_   = new MyFrame(Position(10, 10), MySize(700, 420), Color::Brown);
	//missile_ = new MyMissile(Position(30, 40), 10, Speed(5,4), Color::Orange);
	//rocket_  = new MyRocket(Position(200, 200), MySize(60, 30), Speed(6, -3), Color::Green);
}

/*!
* \fn void step()
* \brief Move all objects left or right
*/
void Game::step() {
	/*
	//Uncomment step by step
	if (!frame_) return; // guard
	if (!game_over_)
	{
		missile_->step();
		rocket_->step();
		if (frame_->isHit(rocket_->getBoundingBox()))   rocket_->changeDirection();
		if (frame_->isHit(missile_->getBoundingBox()))  missile_->changeDirection();
		if (rocket_->isHit(missile_->getBoundingBox())) 
		{
			rocket_->explode(); 
			game_over_ = 1;
		}
	}*/
}


/*!
* \fn void draw()
* \brief Draw all objects
*/
void Game::draw() {
	if (!frame_) return; // guard
	//Uncomment step by step
	//frame_->draw();
	//missile_->draw();
	//rocket_->draw();
}


