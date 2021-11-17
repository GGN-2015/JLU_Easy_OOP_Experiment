//
//  Hero.hpp
//  Hero
//
//  Created by 031 on 2021/11/10.
//  Copyright © 2021 031. All rights reserved.
//

#ifndef Hero_hpp
#define Hero_hpp

class Treasure;
class Hero {
public:
    Hero(int Charm, int Prestige, int Attack, int Defend, int Magic);
    ~Hero();
    
    Hero& takeTreasure(int position, int treasureID);
    Hero& abandonTreasure(int position);
    
    int getCharm() const;
    int getPrestige() const;
    int getAttack() const;
    int getDefend() const;
    int getMagic() const;
    
private:
    static const int carryMax = 5;
    
    int charm, prestige, attack, defend, magic;
    Treasure* treasure[carryMax];
};

#endif /* Hero_hpp */
