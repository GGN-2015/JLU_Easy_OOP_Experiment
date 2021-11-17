//
//  Card.hpp
//  Card
//
//  Created by 031 on 2021/11/10.
//  Copyright © 2021 031. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <algorithm>

class Card {
public:
    enum Suit {
        Spade, Heart, Diamond, Club
    };
    
    Card(int ID, int x, int y);
    Card(Suit suit, int val, int x, int y);
    explicit Card(const Card& card);
    
    static int getBackgroundID();
    static void setBackgroundID(int ID);
    
    bool checkSameSuit(const Card& card) const;
    bool checkSameValue(const Card& card) const;
    
    bool checkSuit(Suit suit) const;
    bool checkValue(int val) const;
    
    Card& setCoord(int x, int y);               // set the left-top point
    std::pair<int, int> getCoord() const;        // get the right bottom point
private:
    static int backgroundID;
    static int cardWidth;
    static int cardHeight;
    
    int coordX, coordY; // coordination of the top-left point of the card
    int cardID;
};

#endif /* Card_hpp */
