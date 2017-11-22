#include "MyGameElement.hpp"

MyGameElement::MyGameElement(const Position &p, const MySize &s, Color c) : bb_({ p, s }), color_(c) {

}

MyGameElement::MyGameElement(const Position &p, int s, Color c) : bb_({ p, MySize{s, s} }), color_(c) {

}

MyGameElement::~MyGameElement() {

}

void MyGameElement::draw() const {
	for (int i = 0; i < figures_.size(); ++i) {
		figures_[i].draw();
	}
}