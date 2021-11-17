//
//  Treasure.cpp
//  Hero
//
//  Created by 031 on 2021/11/10.
//  Copyright © 2021 031. All rights reserved.
//

#include "Treasure.hpp"

Treasure::Treasure(int addCharm, int addPrestige, int addAttack, int addDefend, int addMagic) {
    this -> charm = addCharm;
    this -> prestige = addPrestige;
    this -> attack = addAttack;
    this -> defend = addDefend;
    this -> magic = addMagic;
}

int Treasure::getCharm() const {
    return this -> charm;
}

int Treasure::getPrestige() const {
    return this -> prestige;
}

int Treasure::getAttack() const {
    return this -> attack;
}

int Treasure::getDefend() const {
    return this -> defend;
}

int Treasure::getMagic() const {
    return this -> magic;
}
