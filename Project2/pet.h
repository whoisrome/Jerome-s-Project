// file name -- pet.h
// This file contains the definition of the Pet class

#ifndef CLASS_PET_
#define CLASS_PET_

// ====================== header files ======================
//#include <string>                   // for string class
using namespace std;                // for standard library

class Pet
{
   private:
     string petName;
     string petColor;
     int hunger;
     int happiness;


   public:
      Pet(string, string);
      Pet();

      // mutator - setters
      void setHunger(int);
      void setMood(int);

      // accessor - retrieve current content
      string getName();
      string getColor();
      int getHunger();
      int getMood();

      void checkStatus();

      // polymorphic functions to
      // print pet description
      virtual void printDesc() = 0;
      // print an ASCII image of the pet
      virtual void drawPic();
      // feed the pet
      virtual void eat();
      // play with the pet
      virtual void play() = 0;




}; // class Pet

#endif
