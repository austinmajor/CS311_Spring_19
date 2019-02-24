/*
* Program: TIC-TAC-TOE Terminal Game
* Author: Austin Major
* Class: CS311
* Date: 2/21/19
*/

#include <iostream>

using namespace std;

/*
* FUNCTION DECLARATION:
* 1) a function to take in user's input.
* 2) a function to print out the board and move.
* 3) a function to tell who wins (or draw.)
* 4) a function to tell if game is over.
*/

void input(char array[][3], char player, char current_move);
void print(char array[][3], int win);
void checkWinner(char array[][3]);
bool gameOver(int win);

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char player_x = 'X', player_o = 'O';
char current_move = '0';
char current_player = player_x;
int win = 0;

int main()
{
  print(board, win);

  while (!gameOver(win))
  {
    input(board, current_player, current_move);
    checkWinner(board);
    print(board, win);

    //Switch current player for next move
    if (current_player == player_x)
      current_player = player_o;
    else
      current_player = player_x;
  }

  return 0;
}

void input(char array[][3], char player, char current_move)
{
  cout << "Your move "
       << "player " << player << " : ";
  cin >> current_move;
  cout << endl;

  if (current_move > '0' && current_move <= '9')
    array[0][current_move - '1'] = player;
}

void print(char array[][3], int win)
{
  int size = 3;
  cout << "*** TIC-TAC-TOE ***" << endl;
  cout << "Pick a unchosen number between (1-9): " << endl
       << endl;

  for (int x = 0; x < size; x++)
  {
    for (int y = 0; y < size; y++)
    {
      cout << array[x][y];
      cout << " ";
    }
    cout << endl;
  }

  cout << endl;

  if (win == 1)
    cout << "X WINS, GAME OVER!" << endl;
  else if (win == 2)
    cout << "Y WINS, GAME OVER!" << endl;
}

void checkWinner(char array[][3])
{
  int w = 1;
  char d = player_x;

  for (int p = 1; p <= 2; p++)
  {

    if (p == 2)
    {
      d = player_o;
      w = 2;
    }

    for (int g = 0; g < 3; g++)
    {
      if (array[0][g] == d && array[1][g] == d && array[2][g] == d)
        win = w;
    }

    for (int t = 0; t < 3; t++)
    {
      if (array[t][0] == d && array[t][1] == d && array[t][2] == d)
        win = w;
    }

    if (array[0][0] == d && array[1][1] == d && array[2][2] == d)
      win = w;

    if (array[2][0] == d && array[1][1] == d && array[0][2] == d)
      win = w;
  }
}

bool gameOver(int win)
{
  switch (win)
  {
  case 1:
    return true;
    break;
  case 2:
    return true;
    break;
  default:
    return false;
    break;
  }
}