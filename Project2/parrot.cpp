/*
  file name -- parrot.cpp

  This file contais the definitions of member functions of
  Car class
*/

// ====================== header files ======================
#include <string>                   // for string class
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;                // for standard library
#include "parrot.h"


Parrot::Parrot(string name, string color, string breed, string food,
         string move) : Pet(name, color)
{
   parrotBreed = breed;
   favFood = food;
   movement  = move;
   limbs = 4;
   setHunger(5);
   setMood(1);

} // set-value constructor

Parrot::Parrot()
{

   cout << "**call to default constructor" << endl;
} // set-default constructor

// mutators

// accessor
string Parrot::getBreed()
{
   return parrotBreed;
}

string Parrot::getFood()
{
   return favFood;
}

string Parrot::getMovement()
{
   return movement;
}

void Parrot::printDesc()
{
   cout << "Name: " << getName() << endl;
   cout << "Name: " << getColor() << endl;
   cout << "Breed of Parrot: " << parrotBreed << endl;
   cout << "Favorite Food: " << favFood << endl;
   cout << "Fun time movement/action: " << movement << endl;
   cout << "Mood of Parrot: " << getMood() << endl;
   cout << "Hunger Status: " << getHunger() << endl;
}

void Parrot::makeSound()
{
   cout << getName() << ": chirp chirp! " << endl;
}

void Parrot:: drawPic()
{
   cout<< " Parrot " << endl;
   cout << "   \\" << endl;
   cout << "   (o> " << endl;
   cout << "\\_//) " << endl;
   cout << "\_/_)  " << endl;
   cout << " _|_ " << endl;
   cout << endl;
}


void Parrot:: eat()
{
   cout << getName() << ": eats " << favFood << ". Hunger decreased by 1. " << endl;
   setHunger(getHunger()-1);
   if(getHunger() < 0)
   {
      setHunger(0);
   }
}

void Parrot:: play()
{
   cout << getName() << ": performs a playful movement " << movement << ". Mood increased by 1. " << endl;
   setMood(getMood()+1);

}
void Parrot:: checkStatus()
{
   cout << "Name: " << getName() << endl;
   cout << "Hunger points: " << getHunger() << endl;
   if (getHunger() >= 3)
   {
      cout << "Feed this animal" << endl;
   }

   else
   {
      cout << "Hunger is OK" << endl;
   }

   cout << "Happiness points: " << getMood() << endl;
   if (getMood() >= 3)
   {
      cout << "Having fun" << endl;
   }
   else
   {
      cout << "Is lonely, play with this pet" << endl;
   }

}
