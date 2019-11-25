#pragma once
#include <type_traits>
#include "DynamicArray.h"
#include "list.h"

template <class T>/*,
	typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>*/
class couting_sort_inplace
	:private DynamicArray<T>
{
	long long possibly_value;

	bool static cmp1(T const a, T const b)
	{
		return a < b;
	}

	bool static cmp(T const a, T const b)
	{
		return a == b;
	}

	void search_possibly_value(list<T>* my_list)
	{
		
		long long i = 0, count = 0;
		while (i <= this->get_current_size())
		{
			if (!my_list->find_value_bool(this->get_element(i),cmp)) my_list->add(this->get_element(i),cmp1); count++;
			i++;
		}
		this->possibly_value = count;
	}

	void so_sort(list<T>* my_list)
	{
		long long* tmp = new long long[this->possibly_value]();
		for (long long i = 0; i <= this->get_current_size(); i++)
		{
				tmp[my_list->find_position(this->get_element(i), cmp)]++;
		}
		int j = 0;
		for (long long i = 0; i < this->possibly_value; i++)
		{
			while (0 < tmp[i])
			{
				T pom = my_list->get_element(i);
				this->get_element(j) = pom;
				tmp[i]--; j++;
			}
		}
	}

	void so_sort(long long start)
	{
		long long* tmp = new long long[this->possibly_value]();
		for (long long i = 0; i <= this->get_current_size(); i++)
		{
			tmp[this->get_element(i)-start]++;
		}
		int j = 0;
		for (long long i = 0; i < this->possibly_value; i++)
		{
			while (0 < tmp[i])
			{
				this->get_element(j) = start + i;
				tmp[i]--; j++;
			}
		}
	}

public:
	couting_sort_inplace(T* arr1, long size1) :DynamicArray<T>(arr1, size1) 
	{ 
		list<T>* mem_val_list = new list<T>();
		this->search_possibly_value(mem_val_list);
		this->so_sort(mem_val_list);
		delete mem_val_list;
	};
	couting_sort_inplace(T* arr1, long size1,long long poss_val, long long start = 0) :DynamicArray<T>(arr1, size1),possibly_value(poss_val)
	{
		this->possibly_value = poss_val;
		this->so_sort(start);
	};
	couting_sort_inplace(DynamicArray<T> table) :DynamicArray<T>(table) 
	{ 
		list<T>* mem_val_list = new list<T>;
		this->search_possibly_value(mem_val_list);
		this->so_sort(mem_val_list);
		delete mem_val_list;
	};
	couting_sort_inplace(DynamicArray<T> table, long long poss_val, long long start = 0) :DynamicArray<T>(table),possibly_value(poss_val)
	{
		this->possibly_value = poss_val;
		this->so_sort(start);
	};
};
