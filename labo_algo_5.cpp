// labo_algo_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "heap.h"
#include <random>
#include <iostream>

void printer(int const a)
{
	std::cout << a << ", ";
}

bool cmp2(int const a, int const b)
{
	return a < b;
}

int main()
{
	heap<int> moj;
	srand(NULL);

	for (short i = 0; i < 10; i++)
	{
		moj.insert(rand() % 30, cmp2);
	}

	moj.print(printer);
	std::cout << std::endl;

}

