//
//  Card.hpp
//  Lab 1
//
//  Created by Thomas Bouvier on 02/10/2017.
//  Copyright © 2017 Thomas Bouvier. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

namespace {
    const std::string suits_names[] = {"None", "Clubs", "Diamonds", "Hearts", "Spades"};
    const std::string symbols_names[] = {"None", "Ace", "King", "Queen", "Jack", "Ten", "Nine", "Eight", "Seven"};
}

class Card {
public:
    
    enum class Suit {
        NONE, CLUBS, DIAMONDS, HEARTS, SPADES
    };
    
    static const std::vector<Suit> _suits;
    
    enum class Symbol {
        NONE, ACE, KING, QUEEN, JACK, TEN, NINE, EIGHT, SEVEN
    };
    
    static const std::vector<Symbol> _symbols;
    
    
    explicit Card(Suit suit = Suit::NONE, Symbol symbol = Symbol::NONE);
    ~Card();
    
    std::ostream& display(std::ostream& os) const;
    
    bool equalsSuit(Card &card) const;
    bool equalsSymbol(Card &card) const;
    
    Suit getSuit() const;
    Symbol getSymbol() const;
    
    Card& operator=(const Card& card);
    
private:
    
    Suit _suit;
    Symbol _symbol;
};

std::ostream& operator<<(std::ostream& os, const Card& card);

#endif /* Card_hpp */
