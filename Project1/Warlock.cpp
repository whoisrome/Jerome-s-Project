#include "Warlock.h"
#include <iostream>
using namespace std;
// When Wizard constructor is called, instantiate the Character
// constructor and pass the name from the Wizard constuctor into it
Warlock::Warlock(string name) : Character(name) {
    attackStrength = 15;
    endurance = 30;
    remainingHealth = endurance;

    weapons[0] = "scimitar of speed";
    weapons[1] = "whip";
    weapons[2] = "staff of charming";
    weapons[3] = "dancing shortsword";
    weapons[4] = "dagger of venom";
    weapons[5] = "wand of the war mage";
    weapons[6] = "rakdos riteknife";
    weapons[7] = "blade of broken mirrors";
    weapons[8] = "rod of the pact keeper";
    weapons[9] = "staff of the magi";

    weaponAction[0] = "slashes with a scimitar at ";
    weaponAction[1] = "lashes with a whip at ";
    weaponAction[2] = "enchants with a staff at ";
    weaponAction[3] = "dances with a sword at ";
    weaponAction[4] = "poisons with a dagger at ";
    weaponAction[5] = "casts with a wand at ";
    weaponAction[6] = "ritualizes with a riteknife at ";
    weaponAction[7] = "shatters with a blade at ";
    weaponAction[8] = "blasts with a rod at ";
    weaponAction[9] = "summons with a staff at ";
}

int Warlock::selectWeapon() {
    int weaponID;
    for (int i = 0; i < MAXNUMOFWEAPONS; i++)
        cout << i + 1 << ". " << weapons[i] << endl;

    do
    {
        cout << "Select a weapon: ";
        cin >> weaponID;
    }
    while (weaponID < 1 || weaponID > 10);

    return (weaponID - 1);
}



