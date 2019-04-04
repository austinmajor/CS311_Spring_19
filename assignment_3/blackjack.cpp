/*
* Program: Blackjack Game
* Author: Austin Major
* Class: CS311
* Date: 3/13/19
*/

#include <iostream>
#include <ctime>

using namespace std;

int pickRandomCard();
bool checkGameStatus(int);
int simulateOneGame();
void simulate();
void printIntro();
void getInputs();
void printResult();

int num;
int busts = 0;

//picks a random number for a index in the array cardScore
int pickRandomCard()
{
  return rand() % ((12 + 1));
}

//check if dealer busted or not
bool checkGameStatus(int score)
{
  return score >= 22 || score >= 17;
}

//simulates one game
int simulateOneGame()
{
  int score = 0;
  int cardScore[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10}; //jack, queen, king = 10

  while (!checkGameStatus(score))
  {
    int temp = cardScore[pickRandomCard()];
    bool hasAce = false;

    if (score >= 17)
      break;

    if (temp == 1)
      hasAce = true;

    if (!hasAce)
      score += temp;

    if (hasAce && (score <= 10))
      score += 11;
  }

  return score;
}

//simulate game num times
void simulate()
{
  for (int i = 0; i < num; i++)
  {
    int score = simulateOneGame();
    if (score >= 22)
      busts ++;
  }
}

//prints the intro
void printIntro()
{
  cout << "*** John Zelle's Blackjack Game ***" << endl;
  cout << "How many games to simulate: ";
}

//collects inputs from the user
void getInputs()
{
  cin >> num;
  cout << endl;
}

//prints the final result
void printResult()
{
  cout << "Total # of games: " << num << endl;
  cout << "User Wins: " << busts << endl;
  cout << "Dealer Wins: " << num - busts << endl;
  cout << "Probability Dealer will bust: " << (float)busts / num << endl;
}

int main()
{
  srand(time(NULL));
  printIntro();
  getInputs();
  simulate();
  printResult();

  return 0;
}