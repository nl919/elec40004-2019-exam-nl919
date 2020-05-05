// ProblemTwo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// All the debug and test functions are in this file

#include <vector>
#include <iostream>

#include "tensor.hpp"

using namespace std;

void debugPrintTensor(Tensor* x);
void debugFillTensorWithNumbers(Tensor* x);
void debugTestMatrixMultiplication(); 
Tensor* debugCreateIdentity(size_t n);

#include <math.h>



int main222()
{	
	debugTestMatrixMultiplication();

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

void debugTestIndexOrder()
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
}


void debugTestMatrixMultiplication()
{
	vector<size_t> dimS;
	dimS.push_back(1);
	dimS.push_back(1);
	Tensor* s = create_tensor(dimS);
	vector<size_t> indexS;
	first_index(s->size(), indexS);
	s->write(indexS, 2);

	vector<size_t> dimA;
	dimA.push_back(3);
	dimA.push_back(4);
	Tensor* a = create_tensor(dimA);
	debugFillTensorWithNumbers(a);
	debugPrintTensor(a);

	vector<size_t> dimB;
	dimB.push_back(4);
	dimB.push_back(3);
	Tensor* b = create_tensor(dimB);
	debugFillTensorWithNumbers(b);
	debugPrintTensor(b);

	Tensor* eye3 = debugCreateIdentity(3);
	debugPrintTensor(eye3);
	Tensor* eye4 = debugCreateIdentity(4);
	debugPrintTensor(eye4);

	Tensor* res = multiply(b, s);
	debugPrintTensor(res);


	delete eye3;
	delete eye4;
	delete a;
	delete b;
	delete s;
	delete res;
}

void debugTestMatrixAddition()
{
	vector<size_t> dim;
	dim.push_back(3);
	dim.push_back(4);
	Tensor* x = create_tensor(dim);
	debugFillTensorWithNumbers(x);
	debugPrintTensor(x);

	vector<size_t> dimS;
	dimS.push_back(1);
	dimS.push_back(1);
	Tensor* s = create_tensor(dimS);
	vector<size_t> indexS;
	first_index(s->size(), indexS);
	s->write(indexS, 2);

	Tensor* res = add(x, x);
	debugPrintTensor(res);


	delete x;
	delete s;
	delete res;
}

//-------------------------------------------------------------

void debugPrintTensor(Tensor* x)
{
	if (::is_scalar(x))
	{
		vector<size_t> index;
		index.push_back(0);
		first_index(x->size(), index);
		cout << "Scalar: " << x->read(index) << endl;
	}

	if (::is_vector(x))
	{
		vector<size_t> index;
		index.push_back(0);
		index.push_back(0);
		first_index(x->size(), index);
		cout << "Vector: " << endl;
		do
		{
			cout << x->read(index) << " ";
		} while (next_index(x->size(), index));

		cout << endl;
	}

	if (::is_Matrix(x))
	{
		vector<size_t> index;
		index.push_back(0);
		index.push_back(0);
		first_index(x->size(), index);

		cout << "Matrix: " << endl;
		size_t i = 0;
		do
		{
			cout << x->read(index) << " ";
			if (index[0] == x->size()[0] - 1)
				cout << endl;
		} while (next_index(x->size(), index));

		cout << endl;
	}
}

void debugFillTensorWithNumbers(Tensor* x)
{
	vector<size_t> index;
	index.resize(x->size().size(), 0);
	first_index(x->size(), index);

	size_t i = 0;

	do
	{
		x->write(index, i);
		i++;
	} while (next_index(x->size(), index));
}

Tensor* debugCreateIdentity(size_t n)
{
	vector<size_t> dim;
	dim.push_back(n);
	dim.push_back(n);
	
	Tensor* id = create_tensor(dim);
	vector<size_t> index;
	index.resize(2, 0);

	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			index[0] = j;
			index[1] = i;
			if (i == j)
			{
				id->write(index, 1);
			}
			else
			{
				id->write(index, 0);
			}
		}
	}

	return id;
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
