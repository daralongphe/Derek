#include <iostream>
#include <ctime>
#include "sorted.h"

using namespace std;

const int SIZE = 10000;

template <class elemType>
void print(const elemType list[])
{
	for (int i = 0; i < SIZE; i++) {
		cout << list[i] << " ";
		if ((i + 1) % 45 == 0)//print 45 numbers per line
			cout << endl;
	}
	cout << endl;
}

int main()
{
	int a[SIZE];

	//A.
	//initialize arrays with random numbers starting from 1 to 1,000
	for (int i = 0; i < SIZE; i++)
	{
		a[i] = rand() % 1000 + 1;//range from 1 to 1,000
	}
	cout << "PART A:\nElements before sorting: " << endl;
	print(a);
	clock_t a_bef = clock();
	quickSort_mid(a, 0, SIZE - 1); //method quickSort_mid for Part A
	clock_t a_aft = clock();
	//cout << "CPU TIME(before,after): " << a_bef << " " << a_aft << endl;
	cout << "Elements after sorting: " << endl;
	print(a);
	cout << "CPU Time for Part A: " << a_aft - a_bef << endl;
	for (int i = 0; i < 100; i++)
	{
		cout << "=";
	}

	return 0;
}
