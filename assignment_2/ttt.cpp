#include <iostream>

using namespace std;

int main()
{
  char two_dim[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
  int columns = 3, rows = 3;

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      cout << two_dim[i][j] << ' ';
    }
    cout << endl;
  }

  char x_input, y_input;

  cout << "X goes first, X enter a number (1 - 9): " << endl;
  cin >> x_input;

  cout << "Y goes second, Y enter a number (1 - 9): " << endl;
  cin >> y_input;



  return 0;
}