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
	/*void repair_imported(void)
	{
		for (long i = ((this->get_current() - 1) / 2 ); i >= 0; i--)
		{
		this->heap_down(i);
		}
	}*/

protected:
	void heap_up(long i, bool (*fun)(T const, T const))
	{
		if (i == 0) return;
		long j = ((i - 1) / 2);
		if (fun(this->get_element(j), this->get_element(i)))
		{
			std::swap(this->get_element(i), this->get_element(j));
			this->heap_up(j, fun);
		}
	}

	void heap_down(long i, bool (*fun)(T const, T const))
	{
		if ((2 * i + 1) >= this->get_current()) return;

		if ((2 * i + 2) >= this->get_current())
		{
			if (fun(this->get_element(i), this->get_element((2 * i + 1))))
			{
				std::swap(this->get_element(i), this->get_element((2 * i + 1)));
			}
		}
		else {
			long max;
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
	heap(T* arr, long size) :DynamicArray<T>(arr, size)
	{
		for (long i = ((this->get_current() - 1) / 2); i >= 0; i--)
		{
			this->heap_down(i);
		}
	};
	heap(DynamicArray<T> heap) :DynamicArray<T>(heap)
	{
		for (long i = ((this->get_current() - 1) / 2); i >= 0; i--)
		{
			this->heap_down(i);
		}
	};

	void insert(T val, bool (*fun)(T const, T const))
	{
		this->add(val);
		this->heap_up(this->get_current() - 1, fun);
	}


	T pop(bool (*fun)(T const, T const))
	{
		T tmp = this->get_element(0);
		try
		{
			this->get_element(0) = this->pop_back();
		}
		catch (const DynamicArray_exceptions & e)
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
	void print(void (*fun)(T const), long dlg)
	{
		DynamicArray<T>::print(fun, dlg);
	}

};


template <class U>
class heap_sort_inplace :
	protected heap<U>
{
	void inplace_sort(bool (*fun)(U const, U const))
	{
		for (long i = this->get_current(); i >= 0; i--)
		{
			this->pop(i, fun);
		}
	}

public:
	heap_sort_inplace(U* arr1, long size1) :heap<U>(arr1, size1) { this->inplace_sort(); };
	heap_sort_inplace(DynamicArray<U> heap1) :heap<U>(heap1) { this->inplace_sort(); };

};
#endif // !__HEAP
