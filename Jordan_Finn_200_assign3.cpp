// The 200_assign3.cpp file (application program) should contain the game logic for
// the coin toss game.You should have multiple functions aside from main in your
// application program.

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "Jordan_Finn_Coin.h"

void tossCoinsForUser(Coin&, Coin&, Coin&, double&);
void tossCoinsForComp(Coin&, Coin&, Coin&, double&);
void updateBalanceQuarter(double&, const std::string&);
void updateBalanceDime(double&, const std::string&);
void updateBalanceNickel(double&, const std::string&);

int main() {

     // This seeds the random number generator
     srand(time(nullptr));

     // Create Coin objects for quarter, dime, and nickel
     Coin quarter;
     Coin dime;
     Coin nickel;

     // Initialize balances for the player and computer
     double userBalance = 0.00;
     double compBalance = 0.00;
     const double maxBalance = 1.00; // Maximum balance to reach for winning

     std::cout << std::fixed << std::setprecision(2);

     // Display starting balances
     std::cout << "Your starting balance: $" << userBalance << std::endl;
     std::cout << "The computer's starting balance: $" << compBalance << std::endl;

     // Comment 1:
     // This logic sets the rounds to start at 1 and continuously checks whether the user and computer have reached the maximum balance
     // before it decides if either player lost, won, or tied
     int round = 1;
     while (userBalance < maxBalance && compBalance < maxBalance) 
     {
          // Comment 2:
          // The following function calls pass the 3 coin objects, ending with updating the balance of either the user or computer
          tossCoinsForUser(quarter, dime, nickel, userBalance);
          tossCoinsForComp(quarter, dime, nickel, compBalance);

          // Comment 3:
          // This displays the balance for the user and computer every round
          std::cout << "Your balance after round " << round << ": $" << userBalance << std::endl;
          std::cout << "The computer's balance after round " << round << ": $" << compBalance << std::endl;
          round++;
     }

     // Comment 4:
     // This logic contiuously checks whether the user and computer balances are higher than one another
     // or if they remain the same upon reaching the equivalent value of maxBalance
     if (userBalance >= maxBalance && compBalance >= maxBalance)
     {
          std::cout << "\nYour ending balance: $" << userBalance << std::endl;
          std::cout << "The computer's ending balance: $" << compBalance << std::endl;
          std::cout << "\nTie! Nobody wins." << std::endl;
     }
     else if (userBalance >= compBalance)
     {
          std::cout << "\nYour ending balance: $" << userBalance << std::endl;
          std::cout << "The computer's ending balance: $" << compBalance << std::endl;
          std::cout << "\nCongratulations! You win." << std::endl;
     }
     else
     {
          std::cout << "\nYour ending balance: $" << userBalance << std::endl;
          std::cout << "The computer's ending balance: $" << compBalance << std::endl;
          std::cout << "\nSorry! The computer won." << std::endl;
     }

     return 0;
}

// Comment 5:
// This function simulates the tossing of all three coins on behalf of the user by calling the Coin class public member function, toss()
// and then proceeds to call other functions to update balances
void tossCoinsForUser(Coin& quarter, Coin& dime, Coin& nickel, double& balance) 
{
     // The toss functions update the sideUp private member variable
     quarter.toss();
     dime.toss();
     nickel.toss();
     
     // Comment 6:
     // These functions specifically utilize the getSideUp public member function to recieve
     // the the side and update the balance for the user accordingly
     updateBalanceQuarter(balance, quarter.getSideUp());
     updateBalanceDime(balance, dime.getSideUp());
     updateBalanceNickel(balance, nickel.getSideUp());
}

void tossCoinsForComp(Coin& quarter, Coin& dime, Coin& nickel, double& balance)
{
     // Comment 7:
     // These functions specifically utilize the getSideUp public member function to recieve
     // the the side and update the balance for the computer accordingly
     quarter.toss();
     dime.toss();
     nickel.toss();
     updateBalanceQuarter(balance, quarter.getSideUp());
     updateBalanceDime(balance, dime.getSideUp());
     updateBalanceNickel(balance, nickel.getSideUp());
}


// Comment 8:
// This function updates either the balance for the user or the computer
// based on the tossCoins function calling it and calculates the value of
// a quarter to add to the balance
void updateBalanceQuarter(double& balance, const std::string& sideUp)
{
     if (sideUp == "Heads")
          balance += 0.25;
     else
          balance += 0.00;
}

// Comment 9:
// This function updates either the balance for the user or the computer
// based on the tossCoins function calling it and calculates the value of
// a dime to add to the balance
void updateBalanceDime(double& balance, const std::string& sideUp)
{
     if (sideUp == "Heads")
          balance += 0.10;
     else
          balance += 0.00;
}

// Comment 10:
// This function updates either the balance for the user or the computer
// based on the tossCoins function calling it and calculates the value of
// a nickel to add to the balance
void updateBalanceNickel(double& balance, const std::string& sideUp)
{
     if (sideUp == "Heads")
          balance += 0.05;
     else
          balance += 0.00;
}