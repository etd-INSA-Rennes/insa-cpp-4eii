
#include "MyGDIPlus.hpp"
#include "MyRectangle.hpp"
#include "MyCircle.hpp"
#include "MySquare.hpp"
#include "MySegment.hpp"
#include "MyPoint.hpp"

#include <iostream>

namespace Game {

	/*!
	* \fn void init()
	* \brief initialize all ojects in the game
	*/
	void init() {
		// IMPORTANT: memory is handled by MyGraphicObject -> new here -> delete in desinit

		new MyPoint(100, 100, Color::Black);
		new MyRectangle(300, 250, Color::PowderBlue, true, 250, 100);
		new MySquare(400, 225, Color::MediumOrchid, true, 50, 50);
		new MySegment(400 + 25, 250 - 50, Color::MediumPurple, 50, 50);
		new MyCircle(300 - 30, 250 + 100 - 30, Color::MediumVioletRed, false, 60);
		new MyCircle(300 - 30 + 250, 250 + 100 - 30, Color::SlateGray, true, 60);
		new MyCircle(500, 100, Color::SpringGreen, true, 100);
	}

	/*!
	* \fn void step()
	* \brief Move figures
	*/
	void step() {
		MyGraphicObject * current = MyGraphicObject::getFirst();
		static int cpt = 0;
		int way;

		if (cpt < 50) way = -1; // move left
		else          way = 1;  // move right

		while (current != nullptr) {
			current->move(way, 0);
			current = current->getNext();
		}

		cpt = (cpt + 1) % 100;
	}

	/*!
	* \fn void draw()
	* \brief Draw figures
	*/
	void draw() {
		MyGraphicObject * current = MyGraphicObject::getFirst();

		while (current != nullptr) {
			current->draw();
			current = current->getNext();
		}
	}

	/*!
	* \fn void desinit()
	* \brief desinitializae all ojects in the game
	*/
	void desinit() {
		MyGraphicObject * current = MyGraphicObject::getFirst();
		while (MyGraphicObject::getFirst() != nullptr) delete MyGraphicObject::getFirst();
	}
}
