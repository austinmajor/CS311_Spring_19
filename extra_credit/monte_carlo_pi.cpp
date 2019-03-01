/* Estimation of Pi using Monte Carlo Simulation
*
*  Monte Carlo Definition:
*  Algorithm that relys on repeated random sampling to obtain numerical results
*
*  The Algorithm:
*  1) Generate random point x.
*  2) Generate random point y.
*  3) Calculate d = x*x + y*y.
*  4) If d <= 1, increment circle_hits.
*  5) Increment square_hits.
*  6) Increment interval.
*  7) If increment < NO_OF_ITERATIONS, repeat from 3.
*  8) pi = 4*(circle_hits/square_hits).
*
*  Facts:
*  1) area of a circle = pi(r^2)
*  2) area of a square = 4(r^2)
*  3) so, (area of circle/ area of square) = pi/4 (reduced)
*  4) thus, 4(random hits in circle/ random hits in square) = pi
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

// func decleration
void generate_pi();
void print();

// Dr. Huabo requested 1,000,000 times, 10000 is the largest
#define INTERVAL 1000

// due to small scope, all variables are global, could be enhanced by pass by ref&
double x, y, origin_dist, pi;
int circle_hits = 0, square_hits = 0;
int i;

using namespace std;

void generate_pi()
{
  srand(time(NULL));

  // total number of simulations generated = possible x values * possible y values
  for (i = 0; i < (INTERVAL * INTERVAL); i++)
  {

    // randomly generated x and y values
    x = double(rand() % (INTERVAL + 1)) / INTERVAL;
    y = double(rand() % (INTERVAL + 1)) / INTERVAL;

    // distance between (x, y) from the origin
    origin_dist = x * x + y * y;

    // checking if (x, y) lies inside the define circle with R=1
    if (origin_dist <= 1)
      circle_hits++;

    // total number of points generated
    square_hits++;

    // estimated pi after this iteration
    pi = double(4 * circle_hits) / square_hits;

    // output data
    print();
  }
}

void print()
{
  cout << "************************************************" << endl;
  cout << "Statistics: " << endl << endl;
  cout << "Generated: " << i << " out of " << INTERVAL * INTERVAL << endl;
  cout << "X: " << x << endl;
  cout << "Y: " << y << endl;
  cout << "Circle Hits: " << circle_hits << endl;
  cout << "Square Hits: " << square_hits << endl;
  cout << "MC Estimation of pi: " << pi << endl;
  cout << "Actual value of pi:  3.14159265358..." << endl;
  cout << "************************************************" << endl;
}

int main()
{
  generate_pi();

  return 0;
}
