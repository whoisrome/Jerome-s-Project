// file name -- cat.h
// This file contains the definition of the Cat class

#ifndef CLASS_CAT_
#define CLASS_CAT_
#include "pet.h"
// ====================== header files ======================
//#include <string>                   // for string class
using namespace std;                // for standard library

class Cat : public Pet
{
   private:
     string catBreed;
     string favFood;
     int limbs;
     string movement;

   public:
      Cat(string, string, string, string, string);
      Cat();

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


}; // class Cat

#endif
