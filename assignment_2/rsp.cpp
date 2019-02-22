/*
* Program: Rock, Paper, Scissor Terminal Game
* Author: Austin Major
* Class: CS311
* Date: 2/19/19
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  string user_selection;
  int user_encode;

  // Collects user input and encodes
  cout << "Enter a letter: r(rock), p(paper), or s(scissor)." << endl;
  cin >> user_selection;

  if(user_selection == "r")
    user_encode = 1;
  else if(user_selection == "s")
    user_encode = 2;
  else if(user_selection == "p")
    user_encode = 3;
  else
    cout << "Invalid character entered, please Draw!" << endl;

  // Computer random integer based on time
  srand((int)time(0));
  int random_integer = ((1 + (rand() % 3)) * 10);
  int sum = random_integer + user_encode;

  /*
  * Supplies a case (sum) based upon the encoding below
  * Encoding:
  * User's rock: 	10
  * User's scissor: 	20
  * User's paper: 	30
  * Comp's rock:		1
  * Comp's scissor: 	2
  * Comp's paper: 	3
  */
  switch (sum)
  {
    case 11 :
      cout << "User: Rock, Computer: Rock, Draw!" << endl;
      break;
    case 12 :
      cout << "User: Scissor, Computer: Rock, You Lose!" << endl;
      break;
    case 13 :
      cout << "User: Paper, Computer: Rock, You Win!" << endl;
    case 21 :
      cout << "User: Rock, Computer: Scissor, You Win!" << endl;
      break;
    case 22 :
      cout << "User: Scissor, Computer: Scissor, Draw!" << endl;
      break;
    case 23 :
      cout << "User: Paper, Computer: Scissor, You Lose!" << endl;
    case 31 :
      cout << "User: Rock, Computer: Paper, You Lose!" << endl;
      break;
    case 32 :
      cout << "User: Scissor, Computer: Paper, You Win!" << endl;
      break;
    case 33 :
      cout << "User: Paper, Computer: Paper, Draw!" << endl;
    default:
      cout << "Invalid characters, please Draw!" << endl;
      break;
  }

  return 0;
}
