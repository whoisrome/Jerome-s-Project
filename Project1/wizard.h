#ifndef WIZARD
#define WIZARD
#include "character.h"

class Wizard : public Character
{
    private:
        
    public:
        Wizard(string name);        
        int selectWeapon();
        
};

#endif
