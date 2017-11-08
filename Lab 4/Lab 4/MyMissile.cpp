#include "MyMissile.hpp"

MyMissile::MyMissile(const Position &p, const MySize &s, const Speed &sp, Color c) : MyMobile(p, s, sp, c) {

}

MyMissile::MyMissile(const Position &p, int s, const Speed &sp, Color c) : MyMobile(p, s, sp, c) {

}

MyMissile::~MyMissile() {

}
