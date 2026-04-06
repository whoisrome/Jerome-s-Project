#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>
#include "character.h"
#include "Warlock.h"
#include "engineer.h"
#include "wizard.h"

using namespace std;

void createCharacter(string charName, Character*& one)
{
    int charChoice;

    // Ask the user for character type and name
    cout << "1. Wizard\n2. Warlock\n3. Engineer" << endl;
    cout << "Choose a character type: ";
    cin >> charChoice;
    cout << "Enter your character's name: ";
    cin >> charName;
    cout << endl;

    // instantiate character object based on the specified character type
    // and use charName as the name of the character.
    if (charChoice == 1)
    {
        // dynamically allocate the Wizard Character and assign it to one
        one = new Wizard(charName);
    }
    else if (charChoice == 2)
    {
        // dynamically allocate the Warlock Character and assign it to one
        one = new Warlock(charName);
    }
    else if (charChoice == 3)
    {
        // dynamically allocate the Engineer Character and assign it to one
        one = new Engineer(charName);
    }
}


int main()
{
    // variable declaration and initialization
    string myName, yourName;
    Character *player = 0, *opponent = 0;
    int weaponID,  damage,
     diceRoll, hit = 1;


    // Explanation of the game
    cout << "Welcome to the Battle Arena!" << endl;
    cout << "In this game, two mighty warriors will engage in combat until one emerges victorious." << endl;
    cout << "Prepare yourself for an epic showdown!" << endl;

    // Brief description of the setting
    cout << "\nSetting the Scene: The battle takes place in a mythical arena surrounded by towering mountains" << endl;
    cout << "and filled with the echoes of ancient battles. The ground trembles beneath your feet as you" << endl;
    cout << "prepare to face your opponent." << endl;

    // Call createCharacter for your character
    createCharacter(myName, player);
    createCharacter(yourName, opponent);

    // Loop until either character "dies"
    while (hit)
    {
        // Player's turn
        cout << "Player 1 it's your turn, " << player->getName() << "!" << endl;
        cout << "Select your weapon for this round:" << endl;
        weaponID = player->selectWeapon();
   // Print the dice roll result

       cout << "Enter your dice roll value (1-20): ";
       cin >> diceRoll;
       cout << "You rolled a " << diceRoll << "!" << endl;


        // Combat actions
        // Player attacks opponent
        damage = player->attack(weaponID, opponent->getName());
        if (damage > 0) {
            cout << player->getName() <<" you dealt " << damage << " damage to " << opponent->getName() << "!" << endl;
            int remainingHealth = opponent->hitByOpponent(damage);
            if (remainingHealth <= 0) {
                cout << "Congratulations, " << player->getName() << "! You have defeated your opponent!" << endl;
                break;
            }
        } else {
            cout << "You missed your attack!" << endl;
        }

        // Opponent attacks player
        // Opponent's turn
        cout << " Your opponent, " << opponent->getName() << ", prepares to strike!" << endl;
        cout << "Player 2 it's your turn, " << opponent->getName() << "!" << endl;
        cout << "Select your weapon for this round:" << endl;
        weaponID = opponent->selectWeapon();
        // Print the dice roll result

       cout << "Enter your dice roll value (1-20): ";
       cin >> diceRoll;
       cout << "You rolled a " << diceRoll << "!" << endl;
        damage = opponent->attack(weaponID, player->getName());
        if (damage > 0) {
            cout << opponent->getName() << " dealt " << damage << " damage to " << player->getName() << "!" << endl;
            int remainingHealth = player->hitByOpponent(damage);
            if (remainingHealth <= 0) {
                cout << "Oh no, " << player->getName() << "! You have been defeated!" << endl;
                break;
            }
        } else {
            cout << opponent->getName() << " missed their attack!" << endl;
        }

    } // If either player dies, the while loop breaks

    return 0;
}

