//
//  Card.cpp
//  Card
//
//  Created by 031 on 2021/11/10.
//  Copyright © 2021 031. All rights reserved.
//

#include <algorithm>
#include "Card.hpp"

int Card::backgroundID = 0;
int Card::cardWidth = 30;
int Card::cardHeight = 40;

Card::Card(int ID, int x, int y) {
    if(ID < 0 || ID > 51) {
        throw "Card::Card ID not in range [0, 51].";
    }
    this -> cardID = ID;
    this -> coordX = x;
    this -> coordY = y;
}

Card::Card(Card::Suit suit, int val, int x, int y) {
    if((int)suit < 0 || (int)suit > 3) {
        throw "Card::Card suit not available.";
    }
    if(val < 0 || val > 12) {
        throw "Card::Card val not available.";
    }
    this -> cardID = (int)suit * 13 + val;
    this -> coordX = x;
    this -> coordY = y;
}

Card::Card(const Card& card) { // copy constructor
    this -> coordX = card.coordX;
    this -> coordY = card.coordY;
    this -> cardID = card.cardID;
}

int Card::getBackgroundID() { // static function
    return backgroundID;
}

void Card::setBackgroundID(int ID) {
    backgroundID = ID;
}

bool Card::checkSameSuit(const Card& card) const {
    return (card.cardID / 13) == (this -> cardID / 13);
}

bool Card::checkSameValue(const Card& card) const {
    return(card.cardID % 13) == (this -> cardID % 13);
}

bool Card::checkSuit(Suit suit) const {
    return (this -> cardID / 13) == suit;
}
bool Card::checkValue(int val) const {
    return (this -> cardID % 13) == val;
}

Card& Card::setCoord(int x, int y) {
    coordX = x;
    coordY = y;
    return *this;
}

std::pair<int, int> Card::getCoord() const {
    return std::make_pair(this -> coordX + cardWidth, this -> coordY + cardHeight);
}
