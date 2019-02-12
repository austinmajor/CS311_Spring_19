#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	// const int INPUT_SIZE = 55;
	// int arrayA[INPUT_SIZE];

	ifstream inputFile;
	inputFile.open("num1.txt");

	if (!inputFile)
	{
		cout << "Error finding input file!" << endl;
		system("pause");
		exit(-1);
	}

	string temp;
	while (!inputFile.eof())
	{
		inputFile >> temp;
	}

 	cout << temp << endl;

	return 0;
}
