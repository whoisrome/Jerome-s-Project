#include <iostream>
#include <cstdlib>
#include "pet.h"
#include "dog.h"
#include "cat.h"
#include "parrot.h"
#include <iomanip>

using namespace std;

int main()
{
   // Data declarations
   Dog shaggy("Scooby", "brown", "Pitbull", "steak", "wagging tail");
   Cat jon("Garfield", "orange", "Persian tabby", "lasagna", "laying down");
   Parrot aladdin("Lago", "red", "Scarlet macaw", "berries", "flying");
   Dog peter("Brian", "white", "White labrador retriever", "chicken", "standing");
   Parrot granny("Tweety Bird", "yellow", "Yellow canary", "berries", "flying");

    // Declare an array named petStore of 5 pet pointers
    Pet *petStore[3];
    system("clear");

    //create 5 pets and assign addresses to petStore array
    petStore[0] = &shaggy;
    petStore[1] = &jon;
    petStore[2] = &aladdin;
    petStore[3] = &peter;
    petStore[4] = &granny;


    char option;
    do {
        // Display menu
        cout << "Menu:" << endl;
        cout << "1. Feed pet" << endl;
        cout << "2. Play with pet" << endl;
        cout << "3. Check status of pet" << endl;
        cout << "4. Draw pet" << endl;
        cout << "5. Exit" << endl;

        // Get user option
        cout << "Enter your option (1-5): ";
        cin >> option;

        // Perform action based on user option
        switch (option)
        {
            case '1':
                // Feed pet
                for (int i = 0; i < 5; ++i)
                {
                    petStore[i]->eat();
                }
                break;
            case '2':
                // Play with pet
                for (int i = 0; i < 5; ++i)
                {
                    petStore[i]->play();
                }
                break;
            case '3':
                // Check status of pet
                for (int i = 0; i < 5; ++i)
                {
                    petStore[i]->printDesc();
                }
                break;
            case '4':
                // Draw pet
                for (int i = 0; i < 5; ++i)
                {
                    petStore[i]->drawPic();
                }
                break;
            case '5':
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid option. Please enter a number from 1 to 5." << endl;
        }
    } while (option != '5');

    return 0;
}



