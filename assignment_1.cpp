#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	const int INPUT_SIZE = 55;
	int arrayA[INPUT_SIZE];
	int count;

	ifstream inputFile;
	inputFile.open("nums.txt");

	if (!inputFile)
	{
		cout << "Error finding input file!" << endl;
		system("pause");
		exit(-1);
	}

	count = 0;
	while (!inputFile.eof())
	{
		inputFile >> arrayA[count];
		count++;
	}

	cout << "here! 3" << endl;

	int number = count;
	for (int i = 0; i >= number; i++)
		cout << arrayA[i] << endl;
    
}
