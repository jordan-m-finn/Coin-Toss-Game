#include "Jordan_Finn_Coin.h"
#include <iostream>
#include <cstdlib>
#include <ctime> 

// This is the default constructor for the Coin class
Coin::Coin() 
{

     // This generates a value with the chance of 50/50
     int randomValue1 = rand() % 2;

     // If the random number is 0, return false, otherwise this returns true
     if (randomValue1 == 0)
     {
          sideUp = "Heads";
     }
     else
     {
          sideUp = "Tails";
     }
}

// This class function emulates the toss of a coin with a 50/50 chance of being heads or tails
void Coin::toss()
{

     // This generates a value with the chance of 50/50
     int randomValue2 = rand() % 2;

     // If the random number is 0, return false, otherwise this returns true
     if (randomValue2 == 0)
     {
          sideUp = "Heads";
     }
     else
     {
          sideUp = "Tails";
     }
}

// This class function returns the string value for sideUp
std::string Coin::getSideUp() 
{
     return sideUp;
}