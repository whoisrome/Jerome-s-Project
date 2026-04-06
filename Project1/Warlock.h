#ifndef WARLOCK
#define WARLOCK
#include "character.h"

class Warlock : public Character
{
    private:

    public:
        Warlock(string name);
        //Member function to select a weapon
        //Selects a weapon for the character's attack
        //Does not modify the internal state of the object, so it is declared as const
        int selectWeapon() const;



};

#endif
