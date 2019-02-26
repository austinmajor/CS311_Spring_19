#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

int simulateOneGame();
bool checkGameStatus(int);
int pickRandomCard();

//function to check dealer is busted or not
bool checkGameStatus(int score)
{
  //Player is busted or not
  return score >= 22 || score >= 17;
}

//function to simulate game n times.
void simulate(int n)
{
  int holds = 0;
  int busts = 0;
  for (int i = 0; i < n; i++)
  {
    //simulating ith game out of total n game.
    int score = simulateOneGame();
    //if score is more then 22 then busts then hold.
    if (score >= 22)
      busts += 1;
    else
      holds += 1;
  }
  cout << busts << " game out of total " << n << " games are busted" << endl;
  cout << "Probability of bursts for given n = " << (float)busts / n << endl;
}

//function to pick random card
int pickRandomCard()
{
  return rand() % ((12 + 1));
}

//function that perform one pass of the game
int simulateOneGame()
{
  int score = 0;
  //THis is cardScore list contains the score of each card.
  int cardScore[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
  while (checkGameStatus(score) == false)
  {
    //picking random card;
    int temp = cardScore[pickRandomCard()];

    if (score >= 17)
      break;
    if (temp != 11)
    {
      score += temp;
    }
    else if (temp == 11 and (score >= 6 and score <= 10))
      score += 11;
    else
      score += 1;
  }
  return score;
}

int main()
{
  //Introducing game
  cout << "This code will simulate the Blackjack game" << endl;

  //taking inputs
  int n;
  cout << "Enter the number of games you want to simulate: " << endl;
  cin >> n;

  //simulating one game. This task will be implemented as separate function.
  simulate(n);
  return 0;
}