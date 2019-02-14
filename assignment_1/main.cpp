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

	string str;
	while (!inputFile.eof())
	{
		getline(inputFile, str);
	}

	cout << str << endl;

	// get length of string str
	int sl = str.length();

	int j = sl, i, sum = 0;

	// traverse the string in reverse
	for (i = 0; str[i] != '\0'; i++)
	{
		j--;
		// subtract string[i] by 48 to convert it to int
		// the character 1 in ascii is 48 in decimal
		array[j] = (str[i] - 48);
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

// #include <iostream>
// #include <string>
// #include <vector>
// #include <cstdlib>
// #include <fstream>
// #include <numeric>

// using namespace std;

// int main() {
//     const string file = "nums.txt";
//     ifstream in(file.c_str());
//     if (!in) {
//         cout << endl << "Error reading " << file << endl;
//         exit(EXIT_FAILURE);
//     }
//     vector<string> nums;
//     for (string s; getline(in,s); ) {
//         nums.push_back(s);
//     }
//     cout << endl;
//     for (size_t i = 0; i < nums.size(); i++) {
//         cout << nums.at(i) << endl;
//     }
// }