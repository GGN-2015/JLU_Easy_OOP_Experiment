//
//  main.cpp
//  Hero
//
//  Created by 031 on 2021/11/10.
//  Copyright © 2021 031. All rights reserved.
//

#include <iostream>

#include "Hero.hpp"
#include "Treasure.hpp"

static void outputHero(const Hero& hero) {
    using std::cout;
    using std::cin;
    using std::endl;
    cout << endl << "--- HERO STATUS ---" << endl;
    cout << "Charm:    " << hero.getCharm() << endl;
    cout << "prestige: " << hero.getPrestige() << endl;
    cout << "Attack:   " << hero.getAttack() << endl;
    cout << "Defend:   " << hero.getDefend() << endl;
    cout << "Magic:    " << hero.getMagic() << endl;
    
}

int main(int argc, const char * argv[]) {
    Hero hero(1, 2, 3, 4, 5);
    hero.takeTreasure(0, 1).takeTreasure(1, 2).takeTreasure(3, 6);
    outputHero(hero);
    return 0;
}
