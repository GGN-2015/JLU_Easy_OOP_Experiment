//
//  Monster.cpp
//  Monster
//
//  Created by 031 on 2021/11/10.
//  Copyright © 2021 031. All rights reserved.
//

#include "Monster.hpp"

Monster::Monster(int _speed, int _hitpoint, int _damage, int _defense) {
    this -> speed = _speed;
    this -> hitpoint = _hitpoint;
    this -> damage = _damage;
    this -> defense = _defense;
}

int Monster::getSpeed() const {
    return this -> speed;
}

int Monster::getHitpoint() const {
    return this -> hitpoint;
}

int Monster::getDamage() const {
    return this -> damage;
}

int Monster::getDefense() const {
    return this -> defense;
}

// this -> attack (that)
Monster& Monster::attack(Monster& monster) {
    int attack = 2 * this -> getHitpoint() - monster.getDefense();
    if(attack < 1) {
        attack = 1;
    }
    monster.hitpoint -= attack;
    return *this;
}
