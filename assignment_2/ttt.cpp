/*
* Program: TIC-TAC-TOE Terminal Game
* Author: Austin Major
* Class: CS311
* Date: 2/21/19
*/

#include <iostream>

using namespace std;

/*
* a function to take in user's input.
* a function to print out the board and move.
* a function to tell if game is over.
* a function to tell who wins (or draw.)
*/

void input(char array[][3], char player, char current_move);
void print(char array[][3], int size);
//void gameOver();
//void winner();

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char player_x = 'X', player_o = 'O';
char current_move = '0';
char current_player = player_x;

int main()
{
  print(board, 3);

  for (int move = 0; move < 9; move++)
  {
    input(board, current_player, current_move);
    print(board, 3);

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
  cout << "Your move: " << "Player " << player << " (1-9): ";
  cin >> current_move;
  cout << endl;

  if (current_move > '0' && current_move <= '9')
    array[0][current_move - '1'] = player;
}

void print(char array[][3], int size)
{
  cout << "*** TIC-TAC-TOE ***" << endl;
  cout << "Pick a unchosen number between (1-9): " << endl << endl;

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
}

// bool gameOver(char array[][3], int size)
// {
//   return winner(array[][3], size) == 'X' || winner(array[][3], size) == 'O' || winner(array[][3], size) =='d';
// }

// void winner()
// {
//   //winner is..
// }