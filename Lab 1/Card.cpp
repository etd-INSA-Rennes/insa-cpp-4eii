//
//  Card.cpp
//  Lab 1
//
//  Created by Thomas Bouvier on 02/10/2017.
//  Copyright © 2017 Thomas Bouvier. All rights reserved.
//

#include "Card.hpp"

using namespace std;

const vector<Card::Suit> Card::_suits = {Suit::CLUBS, Suit::DIAMONDS, Suit::HEARTS, Suit::SPADES};
const vector<Card::Symbol> Card::_symbols = {Symbol::ACE, Symbol::KING, Symbol::QUEEN, Symbol::JACK, Symbol::TEN, Symbol::NINE, Symbol::EIGHT, Symbol::SEVEN};

Card::Card(Suit suit, Symbol symbol) : _suit(suit), _symbol(symbol) {
    
}

Card::~Card() {
    
}

ostream& Card::display(ostream& os) const {
    os << suits_names[static_cast<unsigned>(_suit)] << " " << symbols_names[static_cast<unsigned>(_symbol)] << endl;
    
    return os;
}

bool Card::equalsSuit(Card &card) const {
    return _suit == card.getSuit();
}

bool Card::equalsSymbol(Card &card) const {
    return _symbol == card.getSymbol();
}

inline Card::Suit Card::getSuit() const {
    return _suit;
}

inline Card::Symbol Card::getSymbol() const {
    return _symbol;
}

Card& Card::operator=(const Card& card) {
    cout << "operator= call" << endl;
    
    if (this != &card) {
        _suit = card.getSuit();
        _symbol = card.getSymbol();
    }
    
    return *this;
}

ostream& operator<<(ostream& os, const Card& card) {
    return card.display(os);
}
