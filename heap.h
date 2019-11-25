#pragma once
#ifndef __HEAP
#define __HEAP
#include "DynamicArray.h"
#include <algorithm>
#include <iostream>

//#define DEBUG


template <class T>
class heap :
	private DynamicArray<T>
{

	bool static cmp1(T const a, T const b)
	{
		return a < b;
	}

protected:
	void heap_up(long long i, bool (*fun)(T const, T const))
	{
		if (i == 0) return;
		long long j = ((i - 1) / 2);
		if (fun(this->get_element(j), this->get_element(i)))
		{
			std::swap(this->get_element(i), this->get_element(j));
			this->heap_up(j, fun);
		}
	}

	void heap_down(long long i, bool (*fun)(T const, T const))
	{
		if ((2 * i + 1) > this->get_current_size()) return;

		if ((2 * i + 1) == this->get_current_size())
		{
			if (fun(this->get_element(i), this->get_element((2 * i + 1))))
			{
				std::swap(this->get_element(i), this->get_element((2 * i + 1)));
			}
		}
		else {
			long long max;
			fun(this->get_element((2 * i + 1)), this->get_element((2 * i + 2))) ? max = (2 * i + 2) : max = (2 * i + 1);
			if (fun(this->get_element(i), this->get_element(max)))
			{
				std::swap(this->get_element(max), this->get_element(i));
			}
			this->heap_down(max, fun);
		}
	}


public:
	//friend int main();
	heap() :DynamicArray<T>() {};
	heap(T* arr, long long size) :DynamicArray<T>(arr, size)
	{
		/*for (long long i = this->get_current_size(); i >= 0; i--)
		{
			this->heap_up(i, cmp1);
		}*/
		for (long long i = 0; i <= this->get_current_size(); i++)
		{
			this->heap_up(i, cmp1);
		}
	};
	heap(DynamicArray<T> table) :DynamicArray<T>(table)
	{
		/*for (long long i = this->get_current_size(); i >= 0; i--)
		{
			this->heap_up(i,cmp1);
		}*/
		for (long long i = 0; i <= this->get_current_size(); i++)
		{
			this->heap_up(i, cmp1);
		}
	};

	void insert(T val, bool (*fun)(T const, T const))
	{
		this->add(val);
		this->heap_up(this->get_current_size() /*- 1*/, fun);
	}

	long long get_current_size(void) { return DynamicArray<T>::get_current_size(); }

	T pop(bool (*fun)(T const, T const))
	{
		T tmp = this->get_element(0);
		try
		{
			std::swap(this->get_element(0),this->pop_back());
		}
		catch (const my_exceptions_class & e)
		{
			throw e;
		}
		heap_down(0, fun);

		return tmp;
	}

	void erase(void)
	{
		DynamicArray<T>::erase();
	}

	void erase_ptr(void)
	{
		DynamicArray<T>::erase_ptr();
	}

	void print(void (*fun)(T const))
	{
		DynamicArray<T>::print(fun);
	}
	void print(void (*fun)(T const), long long dlg)
	{
		DynamicArray<T>::print(fun, dlg);
	}

};


template <class T>
class heap_sort_inplace :
	protected heap<T>
{
	bool greater;

	bool static cmp1(int const a, int const b)
	{
		return a < b;
	}

	bool static cmp2(int const a, int const b)
	{
		return a > b;
	}

	void inplace_sort(bool (*fun)(T const, T const))
	{
		while (this->get_current_size()>0)
		{
			this->pop(fun);
		}
	}

public:
	heap_sort_inplace(T* arr1, long long size1, bool greater = false) :heap<T>(arr1, size1), greater(greater)
	{ 
		if (this->greater) this->inplace_sort(cmp2);
		else this->inplace_sort(cmp1);
	};
	heap_sort_inplace(DynamicArray<T> heap1, bool greater = false) :heap<T>(heap1), greater(greater)
	{ 
		if (this->greater) this->inplace_sort(cmp2);
		else this->inplace_sort(cmp1);
	};

};
#endif // !__HEAP
