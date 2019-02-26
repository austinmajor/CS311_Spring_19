#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

/*
* write a function that picks/generates the next card.
* write a function to tell if the dealer is busted or not.
* write a function to simulate the game for n times, where n is specified by user.
*/

int pickRandomCard();
bool checkGameStatus(int);
int simulateOneGame();

void simulate();

void printIntro();
void getInputs();
void printResult();

int n;
int busts = 0;

//picks a random card
int pickRandomCard()
{
  return rand() % ((12 + 1));
}

//check if dealer busted or not
bool checkGameStatus(int score)
{
  return score >= 22 || score >= 17;
}

int simulateOneGame()
{
  int score = 0;
  int cardScore[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

  while (checkGameStatus(score) == false)
  {
    int temp = cardScore[pickRandomCard()];

    if (score >= 17)
      break;

    if (temp != 11)
    {
      score += temp;
    }
    else if (temp == 11 && (score >= 6 && score <= 10))
      score += 11;
    else
      score += 1;
  }

  return score;
}

//simulate game n times.
void simulate()
{
  int holds = 0;

  for (int i = 0; i < n; i++)
  {
    int score = simulateOneGame();
    if (score >= 22)
      busts += 1;
    else
      holds += 1;
  }
}

void printIntro()
{
  cout << "John Zelle's Blackjack Game" << endl;
  cout << "How many games to simulate: ";
}

void getInputs()
{
  cin >> n;
  cout << endl;
}

void printResult()
{
  cout << "Total # of games: " << n << endl;
  cout << "User Wins: " << busts << endl;
  cout << "Dealer Wins: " << n - busts << endl;
  cout << "Probability Dealer will bust: " << (float)busts / n << endl;
}

int main()
{
  printIntro();
  getInputs();
  simulate();
  printResult();

  return 0;
}