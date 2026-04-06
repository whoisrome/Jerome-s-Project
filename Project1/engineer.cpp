#include "engineer.h"
#include <iostream>
using namespace std;

Engineer::Engineer(string name) : Character(name) {
    attackStrength = 10;
    endurance = 25;
    remainingHealth = endurance;

    weapons[0] = "hammer";
    weapons[1] = "wrench";
    weapons[2] = "screwdriver";
    weapons[3] = "drill";
    weapons[4] = "saw";
    weapons[5] = "pliers";
    weapons[6] = "welding torch";
    weapons[7] = "chainsaw";
    weapons[8] = "jackhammer";
    weapons[9] = "buzzsaw";

    weaponAction[0] = "strikes with a hammer at ";
    weaponAction[1] = "swings a wrench at ";
    weaponAction[2] = "stabs with a screwdriver at ";
    weaponAction[3] = "drills into ";
    weaponAction[4] = "saws through ";
    weaponAction[5] = "grabs with pliers at ";
    weaponAction[6] = "welds ";
    weaponAction[7] = "slices with a chainsaw at ";
    weaponAction[8] = "jackhammers ";
    weaponAction[9] = "cuts with a buzzsaw at ";
}

int Engineer::selectWeapon() {
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

