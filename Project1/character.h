#ifndef CHARACTER_
#define CHARACTER_

#include <string>
using namespace std;

const int MAXNUMOFWEAPONS = 10;

class Character {

private:

protected:
    string charName;
    int attackStrength;
    int endurance;
    int remainingHealth;
    string weapons[MAXNUMOFWEAPONS];
    string weaponAction[MAXNUMOFWEAPONS];
    int diceRoll;

public:
    // Constructor with default name parameter
    Character(string name = "");

    // Set the character's name
    void setName(string name);

    // Get the character's name
    string getName() const;

   // Perform an attack with the specified weapon against the opponent
   // Accepts the dice roll value as a parameter
   int attack(int weaponID, string opponent) const;





   // Process a hit received from an opponent
   // Returns 1 if the character is still alive, 0 otherwise
   int hitByOpponent(int hitPoint);

   // Select a weapon for the character's attack
   // Prompt the player to input their dice roll value
   int selectWeapon() const;

};

#endif
