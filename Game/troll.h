// Troll Derived Class Of Warrior

#ifndef TROLL_H
#define TROLL_H

#include "warrior.h"
#include <string>

class Troll : public Warrior {
    public:
        Troll(std::string troll_name);  // Troll Name Constructor Delegated To Base Main Constructor
        void choose_attacks(void);      // Populate Attacks
};

#endif // TROLL_H
