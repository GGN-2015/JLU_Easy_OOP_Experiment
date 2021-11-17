//
//  Hero.cpp
//  Hero
//
//  Created by 031 on 2021/11/10.
//  Copyright © 2021 031. All rights reserved.
//

#include "Hero.hpp"
#include "Treasure.hpp"

static const Treasure treasures[] = {
    Treasure(0, 0, 0, 0, 0), // Treasure 0
    Treasure(2, 0, 0, 0, 0), // Treasure 1
    Treasure(0, 3, 0, 0, 0), // Treasure 2
    Treasure(0, 0, 1, 0, 0), // Treasure 3
    Treasure(0, 0, 0, 2, 0), // Treasure 4
    Treasure(0, 0, 0, 0, 3), // Treasure 5
    Treasure(1, 1, 0, 0, 0), // Treasure 6
};

Hero::Hero(int Charm, int Prestige, int Attack, int Defend, int Magic) {
    this -> charm       = Charm;
    this -> prestige    = Prestige;
    this -> attack      = Attack;
    this -> defend      = Defend;
    this -> magic       = Magic;
    for(int i = 0; i < Hero::carryMax; i ++) {
        this -> treasure[i] = nullptr;
    }
}
Hero::~Hero() {
    for(int i = 0; i < Hero::carryMax; i ++) { // abandon all the treasures
        delete this -> treasure[i];
    }
}

Hero& Hero::takeTreasure(int position, int treasureID) {
    if(position < 0 || position > Hero::carryMax) {
        throw "Hero::takeTreasure position not in [0, carrymax - 1]";
    }
    if(this -> treasure[position] != nullptr) {
        delete this -> treasure[position];
        // you must abandon last item to reload a new item
    }
    this -> treasure[position] = new Treasure(treasures[treasureID]); // copy a treasure
    return *this;
}

Hero& Hero::abandonTreasure(int position) {
    delete this -> treasure[position];
    return *this;
}

int Hero::getCharm() const {
    int sumCharm = this -> charm;
    for(int i = 0; i < Hero::carryMax; i ++) {
        if(this -> treasure[i] != nullptr) {
            sumCharm += this -> treasure[i] -> getCharm();
        }
    }
    return sumCharm;
}

int Hero::getPrestige() const {
    int sumPrestige = this -> prestige;
    for(int i = 0; i < Hero::carryMax; i ++) {
        if(this -> treasure[i] != nullptr) {
            sumPrestige += this -> treasure[i] -> getPrestige();
        }
    }
    return sumPrestige;
}

int Hero::getAttack() const {
    int sumAttack = this -> attack;
    for(int i = 0; i < Hero::carryMax; i ++) {
        if(this -> treasure[i] != nullptr) {
            sumAttack += this -> treasure[i] -> getAttack();
        }
    }
    return sumAttack;
}
int Hero::getDefend() const {
    int sumDefend = this -> defend;
    for(int i = 0; i < Hero::carryMax; i ++) {
        if(this -> treasure[i] != nullptr) {
            sumDefend += this -> treasure[i] -> getDefend();
        }
    }
    return sumDefend;
}

int Hero::getMagic() const {
    int sumMagic = this -> magic;
    for(int i = 0; i < Hero::carryMax; i ++) {
        if(this -> treasure[i] != nullptr) {
            sumMagic += this -> treasure[i] -> getMagic();
        }
    }
    return sumMagic;
}
