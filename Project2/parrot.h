// file name -- parrot.h
// This file contains the definition of the Parrot class

#ifndef CLASS_PARROT_
#define CLASS_PARROT_
#include "pet.h"
// ====================== header files ======================
//#include <string>                   // for string class
using namespace std;                // for standard library

class Parrot : public Pet
{
   private:
     string parrotBreed;
     string favFood;
     int limbs;
     string movement;

   public:
      Parrot(string, string, string, string, string);
      Parrot();

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


}; // class Parrot

#endif
