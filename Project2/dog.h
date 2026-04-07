// file name -- pet.h
// This file contains the definition of the Dog class

#ifndef CLASS_DOG_
#define CLASS_DOG_
#include "pet.h"
// ====================== header files ======================
//#include <string>                   // for string class
using namespace std;                // for standard library

class Dog : public Pet
{
   private:
     string dogBreed;
     string favFood;
     int limbs;
     string movement;

   public:
      Dog(string, string, string, string, string);
      Dog();

      // mutator - setters


      // accessor - retrieve current content
      string getBreed();
      string getFood();
      string getMovement();

      void printDesc();
      void makeSound();
      void drawPic();
      void eat();
      void play();
      void checkStatus();


}; // class Dog

#endif
