//
//  Monster.hpp
//  Monster
//
//  Created by 031 on 2021/11/10.
//  Copyright © 2021 031. All rights reserved.
//

#ifndef Monster_hpp
#define Monster_hpp

class Monster {
public:
    Monster(int _speed, int _hitpoint, int _damage, int _defense);
    int getSpeed    () const;
    int getHitpoint () const;
    int getDamage   () const;
    int getDefense  () const;
    Monster& fight(Monster& that); // fight between A and B
public:
    int speed, hitpoint, damage, defense;
    Monster& attack(Monster& monster);
};

#endif /* Monster_hpp */
