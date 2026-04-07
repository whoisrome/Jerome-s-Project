/*
  file name -- pet.cpp

  This file contais the definitions of member functions of
  Car class
*/

// ====================== header files ======================
#include <string>                   // for string class
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;                // for standard library
#include "pet.h"


Pet::Pet(string name, string color)
{
   petName = name;
   petColor = color;

} // set-value constructor

Pet::Pet()
{

   cout << "**call to default constructor" << endl;
} // set-default constructor

// mutators
void Pet::setHunger(int n)
{
   hunger = n;
}

void Pet::checkStatus()
{
}
void Pet::drawPic()
{

}
void Pet::eat()
{

}
void Pet::play()
{

}
void Pet::setMood(int n)
{
   happiness = n;
}
// accessor
string Pet::getName()
{
   return petName;
}

string Pet::getColor()
{
   return petColor;
}

int Pet::getMood()
{
   return happiness;
}

int Pet::getHunger()
{
   return hunger;
}
