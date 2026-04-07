/*
  file name -- dog.cpp

  This file contais the definitions of member functions of
  Car class
*/

// ====================== header files ======================
#include <string>                   // for string class
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;                // for standard library
#include "dog.h"


Dog::Dog(string name, string color, string breed, string food,
         string move) : Pet(name, color)
{
   dogBreed = breed;
   favFood = food;
   movement  = move;
   limbs = 4;
   setHunger(5);
   setMood(1);

} // set-value constructor

Dog::Dog()
{

   cout << "**call to default constructor" << endl;
} // set-default constructor

// mutators

// accessor
string Dog::getBreed()
{
   return dogBreed;
}

string Dog::getFood()
{
   return favFood;
}

string Dog::getMovement()
{
   return movement;
}

void Dog::printDesc()
{
   cout << "Name: " << getName() << endl;
   cout << "Name: " << getColor() << endl;
   cout << "Breed of Dog: " << dogBreed << endl;
   cout << "Favorite Food: " << favFood << endl;
   cout << "Fun time movement/action: " << movement << endl;
   cout << "Mood of Dog: " << getMood() << endl;
   cout << "Hunger Status: " << getHunger() << endl;
}

void Dog::makeSound()
{
   cout << getName() << ": bark bark! " << endl;
}

void Dog:: drawPic()
{
   cout << "Dog" << endl;
   cout << "            __" << endl;
   cout << "(\\,--------'()'--o" << endl;
   cout <<"  (_    ___    /~\"" <<endl;
   cout <<"   (_)_)  (_)_)" << endl;
   cout << endl;

}


void Dog:: eat()
{
   cout << getName() << ": eats " << favFood << ". Hunger decreased by 1. " << endl;
   setHunger(getHunger()-1);
   if(getHunger() < 0)
   {
      setHunger(0);
   }
}

void Dog:: play()
{
   cout << getName() << ": performs a playful movement " << movement << ". Mood increased by 1. " << endl;
   setMood(getMood()+1);

}
void Dog:: checkStatus()
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

