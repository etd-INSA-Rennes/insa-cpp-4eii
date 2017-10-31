
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
	* \brief initializae all ojects in the game
	*/
	void init()
	{
        //Uncomment line by line as you implement and test your classes
        //IMPORTANT : your constructors may be different, if so change the provided code

		// IMPORTANT: memory is handled by MyGraphicObject -> new here -> delete in desinit
/*
		new MyPoint(100, 100, Color::Black);
		new MyRectangle(300,250,250,100,true,Color::PowderBlue);
		new MySquare(400,225,50,true,Color::MediumOrchid);
		new MySegment(400 + 25, 250 - 50, 50, 50, Color::MediumPurple);
		new MyCircle(300 - 30, 250 + 100 - 30, 60, false, Color::MediumVioletRed);
		new MyCircle(300 - 30 + 250, 250 + 100 - 30, 60, true, Color::SlateGray);
		new MyCircle(500,100,100,true,Color::SpringGreen);
        */
	}

	/*!
	* \fn void step()
	* \brief Move figures
	*/
	void step() {
/*		MyGraphicObject * current = MyGraphicObject::getFirst();
		static int cpt = 0;
		int way;
		if (cpt < 50) way = -1; // move left
		else          way = 1;  // move right
		while (current != nullptr)
		{
			current->move(way, 0);
			current = current->getNext();
		}
		cpt = (cpt + 1) % 100;
	*/	
	}

	/*!
	* \fn void draw()
	* \brief Draw figures
	*/
	void draw() {
/*		MyGraphicObject * current = MyGraphicObject::getFirst();
		while (current != nullptr)
		{
			current->draw();
			current = current->getNext();
		}
		*/
	}

	/*!
	* \fn void desinit()
	* \brief desinitializae all ojects in the game
	*/
	void desinit() {
	/*	MyGraphicObject * current = MyGraphicObject::getFirst();
		while (MyGraphicObject::getFirst() != nullptr) delete MyGraphicObject::getFirst();
		*/
	}
	
}
