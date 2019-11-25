// labo_algo_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "heap.h"
#include "CountingSort.h"
#include "BucketSort.h"
#include <random>
#include <iostream>
#include <time.h>

void printer(int const a)
{
	std::cout << a << ", ";
}

bool cmp1(int const a, int const b)
{
	return a < b;
}

int main()
{
	//DynamicArray<int> d1;
	//DynamicArray<int> d2;
	//DynamicArray<int> d3;
	//srand(NULL);
	//int w = 0;

	//for (int i = 0; i < 20; i++)
	//{
	//	w = rand() % 1155;
	//	d1.add(w);
	//	d2.add(w);
	//	d3.add(w);
	//}

	//d1.print(printer);
	//std::cout << std::endl;

	//heap_sort_inplace<int> sort1(d1);
	//std::cout << std::endl;
	//d1.print(printer);

	//couting_sort_inplace<int> sort2(d2);
	//std::cout << std::endl;
	//d2.print(printer);

	//bucket_sort_inplace<int> sort3(d3,21);
	//std::cout << std::endl;
	//d3.print(printer);
	//std::cout << std::endl;

	//std::cout << std::boolalpha << (d1 = d2);
	//std::cout << std::boolalpha << (d2 = d3);

	srand(NULL);
	const int MAX_ORDER = 7;
	const int m = (int)pow(10,5);
	clock_t t1, t2;
	DynamicArray<int> tab1;
	DynamicArray<int> tab2;
	DynamicArray<int> tab3;
	for (int o = 1; o < MAX_ORDER; o++)
	{
		const int n = (int)pow(10, o);

		/*DynamicArray<int>* tab1 = new DynamicArray<int>;
		DynamicArray<int>* tab2 = new DynamicArray<int>;
		DynamicArray<int>* tab3 = new DynamicArray<int>;*/
		int tmp;
		for (int i = 0; i < n; i++)
		{
			tmp = rand()%32700;
			tab1.add(tmp);
			tab2.add(tmp);
			tab3.add(tmp);
		}

		tab1.print(printer, 10);
		std::cout << std::endl;
		tab2.print(printer, 10);
		std::cout << std::endl;
		tab3.print(printer, 10);
		std::cout << std::endl;

		t1 = clock();
		couting_sort_inplace<int> sort1(tab1, 32700);
		t2 = clock();
		std::cout << "Czas sortowania przez zliczanie: " << (double(t2) - double(t1)) / CLOCKS_PER_SEC << " |-| ";
		tab1.print(printer, 10);
		std::cout << std::endl;

		t1 = clock();
		heap_sort_inplace<int> sort2(tab2);
		t2 = clock();
		std::cout << "Czas sortowania przez kopcowanie: " << (double(t2) - double(t1)) / CLOCKS_PER_SEC << " |-| ";
		tab2.print(printer, 10);
		std::cout << std::endl;

		t1 = clock();
		bucket_sort_inplace<int> sort3(tab3,m);
		t2 = clock();
		std::cout << "Czas sortowania kubelkowego: " << (double(t2) - double(t1)) / CLOCKS_PER_SEC << " |-| ";
		tab3.print(printer, 10);
		std::cout << std::endl;

	std::cout << std::boolalpha << (tab1 = tab2) << " , " << (tab2 = tab3) << tab1.get_max_min(cmp1) << std::endl;
		std::cout << "-----------------------------------------------------------------------------" << std::endl;

		tab1.erase();
		tab2.erase();
		tab3.erase();
		/*delete tab1;
		delete tab2;
		delete tab3;*/
	}

}

