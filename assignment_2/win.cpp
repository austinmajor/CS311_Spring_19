#include <iostream>

#define BOARD 3

using namespace std;

int main()
{
  int w=1;
  char d='X';
  int win=0;
  char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

  for(int p=1;p<=2;p++)
  {
    if(p==2)
    {
      d='O';
      w=2;
    }

    for(int g=0;g<3;g++)
    {
      if(board[0][g]==d && board[1][g]==d && board[2][g]==d)
      {
        win=w;
      }
    }

    for(int t=0;t<3;t++)
    {
      if(board[t][0]==d && board[t][1]==d && board[t][2]==d)
      {
        win=w;
      }
    }

    if(board[0][0]==d && board[1][1]==d && board[2][2]==d)
    {
      win=w;
    }

    if(board[2][0]==d && board[1][1]==d && board[0][2]==d)
    {
      win=w;
    }
  }
  cout << win << endl;
}