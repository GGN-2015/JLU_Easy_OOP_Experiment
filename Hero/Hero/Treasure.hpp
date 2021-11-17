//
//  Treasure.hpp
//  Hero
//
//  Created by 031 on 2021/11/10.
//  Copyright © 2021 031. All rights reserved.
//

#ifndef Treasure_hpp
#define Treasure_hpp

class Treasure {
public:
    Treasure(int addCharm, int addPrestige, int addAttack, int addDefend, int addMagic);
    
    int getCharm() const;
    int getPrestige() const;
    int getAttack() const;
    int getDefend() const;
    int getMagic() const;
    
private:
    int charm, prestige, attack, defend, magic;
};

#endif /* Treasure_hpp */
