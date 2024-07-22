#ifndef COIN_H
#define COIN_H

#include <iostream>
#include <string>

// class definition for a coin to be used in various games
class Coin 
{

private:
     std::string sideUp;

public:
     // A default constructor that randomly determines the side of the coin that is
     // facing up(“heads” or “tails”) and initializes the sideUp member variable
     // accordingly.
     Coin();
     
     // A void member function named toss that simulates the tossing of the coin.
     // When the toss member function is called, it randomly determines the side of
     // the coin that is facing up(“heads” or “tails”) and sets the sideUp member
     // variable accordingly.
     void toss();

     // A member function named getSideUp that returns the value of the sideUp
     // member variable.
     std::string getSideUp();
};

#endif