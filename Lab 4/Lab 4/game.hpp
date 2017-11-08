#pragma once
#include <vector>

// forward declations
class MyFrame;
class MyRocket;
class MyMissile;

class Game {
public:
	Game();
	~Game();

	void initialize();    // call once
	void step();          // time progress
	void draw();          // redraw

private:
	MyFrame   *frame_;      // C++11 unique_ptr
	MyRocket  *rocket_;      // C++11 unique_ptr
	MyMissile *missile_;      // C++11 unique_ptr

	int game_over_;

	// rule of 3
	Game(const Game &) {}                           // C++11 simpler: delete
	Game &operator=(const Game &) { return *this; } // C++11 simpler: delete

};
