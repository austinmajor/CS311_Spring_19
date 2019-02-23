/*
* Program: TIC-TAC-TOE Terminal Game
* Author: Austin Major
* Class: CS311
* Date: 2/21/19
*/

#include <iostream>

using namespace std;

/*
* SCOPE:
* 1) a function to take in user's input.
* 2) a function to print out the board and move.
* 3) a function to tell if game is over.
* 4) a function to tell who wins (or draw.)
*/

void input(char array[][3], char player, char current_move);
void print(char array[][3], int size);
//void gameOver();
//void checkWinner();

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

  // while(/* !gameOver() */ true){
  //   input(board, current_player, current_move);
  //   print(board, 3);

  //   //Switch current player for next move
  //   if (current_player == player_x)
  //     current_player = player_o;
  //   else
  //     current_player = player_x;
  // }

  return 0;
}

void input(char array[][3], char player, char current_move)
{
  cout << "Your move " << "player " << player << " : ";
  cin >> current_move;
  cout << endl;

  cout << "AM: " << array[0][current_move - '1'] << endl;

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

// bool gameOver(void checkWinner(), char array[][3], int size)
bool gameOver()
{
  return true;
  // return checkWinner(array[][3], size) == 'X' || checkWinner(array[][3], size) == 'O' || checkWinner(array[][3], size) =='d';
}

void checkcheckWinner(char array[][3], int size)
{
  //checkWinner is..
    /*
  * 8 solutions
  * [0][0], [0][1], [0][2]
  * [1][0], [1][1], [1][2]
  * [2][0], [2][1], [2][2]
  */
}