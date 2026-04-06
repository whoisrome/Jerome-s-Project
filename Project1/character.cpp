#include "character.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

Character::Character(string name) {
    charName = name;
    attackStrength = 0;
    endurance = 0;
    remainingHealth = 0;

}

void Character::setName(string name) {
    charName = name;
}

string Character::getName() const {
    return charName;
}
// Update the selectWeapon function to prompt the player for their dice roll value
int Character::selectWeapon() const {
    int weaponID;

    // Loop through all the weapons a character has and print them out
    for (int i = 0; i < MAXNUMOFWEAPONS; i++)
        cout << i + 1 << ". " << weapons[i] << endl;

    // Get a weapon based on the user's choice
    do {
        cout << "Select a weapon: ";
        cin >> weaponID;
    } while (weaponID < 1 || weaponID > 10);

    // Return the ID of that weapon
    return (weaponID - 1);
}
int Character::attack(int weaponID, string opponent) const {
int randRoll = rand() % 64 + 1;

    // Determine the attack result
    cout << "Attacking " << opponent << " with " << weapons[weaponID] << " (" << weaponAction[weaponID] << opponent << ")..." << endl;
    if (randRoll > attackStrength) {
        // If the roll is greater than the attack strength, the attack hits
        cout << "Good hit for you!" << endl;
        return 1;
    } else {
        // If the roll is less than or equal to the attack strength, the attack misses
        cout << "Missed!" << endl;
        return 0;
    }
}
int Character::hitByOpponent(int hitPoint) {
    remainingHealth -= hitPoint;

    if (remainingHealth > 0) {
        cout << "Hit was successful. Remaining health points: " << remainingHealth << endl;
        return 1;
    } else {
        cout << charName << " has been defeated!" << endl;
        return 0;
    }
}

















