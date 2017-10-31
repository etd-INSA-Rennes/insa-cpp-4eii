//
//  Game.cpp
//  Lab 1
//
//  Created by Thomas Bouvier on 02/10/2017.
//  Copyright © 2017 Thomas Bouvier. All rights reserved.
//

#include "Game.hpp"

using namespace std;

Game::Game(bool random) {
    for (const auto& suit : Card::_suits) {
        for (const auto& symbol : Card::_symbols) {
            _draw_stack.push_back(Card(suit, symbol));
        }
    }
    
    if (random)
        shuffle();
}

Game::~Game() {
    
}

void Game::shuffle() {
    random_shuffle(_draw_stack.begin(), _draw_stack.end());
}

bool Game::extractCard(unsigned int i) {
    if (i > _draw_stack.size() - 1)
        return false;
    
    Card & card = _draw_stack.at(i);
    
    _discard_stack.push_back(card);
    _draw_stack.erase(_draw_stack.begin() + i);
    
    return true;
}

void Game::putInDrawStack() {
    for (auto it : _discard_stack)
        _draw_stack.push_back(it);
    
    _discard_stack.clear();
}

ostream& Game::display(std::ostream& os) const {
    os << "\nCards in the draw stack:" << endl;

    for (auto it : _draw_stack)
        os << it;

    os << "\nCards in the discard stack:" << endl;

    for (auto it : _discard_stack)
        os << it;

    return os;
}

inline const Game::Stack& Game::getDrawStack() const {
    return _draw_stack;
}

inline const Game::Stack& Game::getDiscardStack() const {
    return _discard_stack;
}

ostream& operator<<(ostream& os, const Game& game) {
    return game.display(os);
}

