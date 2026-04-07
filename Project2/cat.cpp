/*
  file name -- cat.cpp

  This file contais the definitions of member functions of
  Car class
*/

// ====================== header files ======================
#include <string>                   // for string class
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;                // for standard library
#include "cat.h"


Cat::Cat(string name, string color, string breed, string food,
         string move) : Pet(name, color)
{
   catBreed = breed;
   favFood = food;
   movement  = move;
   limbs = 4;
   setHunger(5);
   setMood(1);

} // set-value constructor

Cat::Cat()
{

   cout << "**call to default constructor" << endl;
} // set-default constructor

// mutators

// accessor
string Cat::getBreed()
{
   return catBreed;
}

string Cat::getFood()
{
   return favFood;
}

string Cat::getMovement()
{
   return movement;
}

void Cat::printDesc()
{
   cout << "Name: " << getName() << endl;
   cout << "Name: " << getColor() << endl;
   cout << "Breed of Cat: " << catBreed << endl;
   cout << "Favorite Food: " << favFood << endl;
   cout << "Fun time movement/action: " << movement << endl;
   cout << "Mood of Cat: " << getMood() << endl;
   cout << "Hunger Status: " << getHunger() << endl;
}

void Cat::makeSound()
{
   cout << getName() << ": meow meow! " << endl;
}

void Cat:: drawPic()
{
   cout << "Cat" << endl;
   cout << "|\__/,|   (`\ " << endl;
   cout << "|_ _  |.--.) )" << endl;
   cout << "( T   )     / " << endl;
   cout << "(((^_(((/(((_/" << endl;
   cout << endl;

}


void Cat:: eat()
{
   cout << getName() << ": eats " << favFood << ". Hunger decreased by 1. " << endl;
   setHunger(getHunger()-1);
   if(getHunger() < 0)
   {
      setHunger(0);
   }
}

void Cat:: play()
{
   cout << getName() << ": performs a playful movement " << movement << ". Mood increased by 1. " << endl;
   setMood(getMood()+1);

}
void Cat:: checkStatus()
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
