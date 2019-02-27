#include <iostream>
#include <ctime>
#include <cmath>

void getInputs(double& prob1, double& prob2);
void simNGames(const double& prob1, const double& prob2, int& win1, int& win2);
void simOneGame(const double& prob1, const double& prob2, int& score1, int& score2);
bool gameOver(const int& score1, const int& score2);
void printSummary(const int& win1, const int& win2);

int main()
{
  double prob1;
  double prob2;
  int win1;
  int win2;

  srand(time(NULL));
  getInputs(prob1, prob2);
  simNGames(prob1, prob2, win1, win2);
  printSummary(win1, win2);

  return 0;
}

void getInputs(double& prob1, double& prob2)
{
  using namespace std;
  cout << "Enter prob1: ";
  cin >> prob1;
  cout << "Enter prob2: ";
  cin >> prob2;
}

void simNGames(const double& prob1, const double& prob2, int& win1, int& win2)
{
  int score1;
  int score2;
  win1 = 0;
  win2 = 0;

  for(int i = 0; i < 500; i++)
  {
    simOneGame(prob2, prob2, score1, score2);
    (score1 > score2) ? win1++ : win2++; 
  }
}

void simOneGame(const double& prob1, const double& prob2, int& score1, int& score2)
{
  int serve = rand() % 2;
  score1 = 0;
  score2 = 0;

  while(!gameOver(score1, score2))
  {
    if (serve == 0 && rand() % 100 < prob1 * 100)
      score1++;
    else
      serve = 1;

    if (serve == 1 && rand() % 100 < prob2 * 100)
      score2++;
    else
      serve = 0;
  }

}

bool gameOver(const int& score1, const int& score2)
{
  return (score1 >= 15 || score2 >= 15) && (abs(score1 - score2) >= 2);
}

void printSummary(const int& win1, const int& win2)
{
  using namespace std;

  cout << "Win by player 1: " << win1 << endl;
  cout << "Win by player 2: " << win2 << endl;
}

