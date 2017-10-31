//
//  Game.hpp
//  Lab 1
//
//  Created by Thomas Bouvier on 02/10/2017.
//  Copyright © 2017 Thomas Bouvier. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <vector>
#include <algorithm>

#include "Card.hpp"

class Game {
    
    typedef std::vector<Card> Stack;
    
    Stack _draw_stack;
    Stack _discard_stack;
    
public:
    
    Game(bool random = false);
    ~Game();
    
    void shuffle();
    
    bool extractCard(unsigned int i);
    void putInDrawStack();
    
    std::ostream& display(std::ostream& os) const;
    
    const Stack& getDrawStack() const;
    const Stack& getDiscardStack() const;
};

std::ostream& operator<<(std::ostream& os, const Game& game);