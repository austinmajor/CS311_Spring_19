/*
Assignment 1
This assignment is adopted from Project Euler Question 13. 

Requirement
- use file for the input (nums.txt)
- use int array(s) (size: 55) to hold each digit from each num.
- store the num reversely in the array. For example, the num 123 is stored as 3 (at index 0), 2 (at index 1) and 1 (at index 2) in the array. 
- write a function that performs the addition of numbers. This function will be called in the main. 
- write a function that prints out the answer. The answer includes two parts: the total summation and the first 10 digits of the summation. 
- comment the code clearly, especially for the number addition mechanism. 

Grading
- compilable and meaningful attemps: 30 points. That is, the code must be compilable while it cannot be just a compilable hello world. 
- functionality: 40 points. (file, string number handling, array and addition mechanism, answer printing)
- comment & indentation: 10 points. 
- explanation to lab TA: 20 points. You need to explain the array and addition mechanism to one of the lab TAs, either in the lab time, in their office hours or setup an appointment. 
- Total score: 30 + 40 + 10 + 20 = 100 points. 

Submission:
- due: feb 15, 11:59pm
- please submit through handin program.
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	int array[55] = { 0 };

	ifstream inputFile;
	inputFile.open("num1.txt");

	if (!inputFile)
	{
		cout << "Error finding input file!" << endl;
		system("pause");
		exit(-1);
	}

	string string;
	while (!inputFile.eof())
	{
		inputFile >> string;
	}

	cout << string << endl;

	// get length of string str
	int sl = string.length();

	int i, sum = 0;

	// Traverse the string
	for (i = 0; string[i] != '\0'; i++)
	{
		array[i] = array[i] * 10 + (string[i] - 48);
	}

	for (i = 0; i < sl; i++)
	{
		cout << array[i] << "";
		sum += array[i]; // sum of array
	}

	// print sum of array
	cout << "\nSum of array is = " << sum << endl;

	return 0;
}