// ProblemTwo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vector>
#include <iostream>

#include "tensor.hpp"

using namespace std;

int main()
{
	vector<size_t> dims;
	dims.push_back(2);
	dims.push_back(3);
	dims.push_back(4);

	size_t total = volume(dims);
	size_t i;
	for (i = 0; i < total; i++)
	{
		vector<size_t> index = offset_to_index(dims, i);
		cout << index[0] << " " << index[1] << " " << index[2] << endl;
	}

	return 0;
}


void debugShowNextIndex()
{
	vector<size_t> dims;
	dims.push_back(2);
	dims.push_back(3);
	dims.push_back(4);

	vector<size_t> index;
	index.resize(3, 0);

	first_index(dims, index);
	while (next_index(dims, index))
	{
		cout << index[0] << " " << index[1] << " " << index[2] << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
