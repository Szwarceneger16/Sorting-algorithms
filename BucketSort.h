#pragma once
#include "DynamicArray.h"
#include "list.h"
#include <iostream>

template <class T>
class bucket_sort_inplace :
	private DynamicArray<T>
{
	long long buckets;

	bool static cmp1(T const a, T const b)
	{
		return a < b;
	}

	void so_sort(void)
	{
		list<T>* bin = new list<T>[this->buckets+1];
		T max = this->get_max_min(cmp1);
		T tmp; long long tmp2;
		for (long long i = 0; i <= this->get_current_size(); i++)
		{
			tmp = this->get_element(i);
			tmp2 = floor((this->buckets * tmp) / max);
			bin[tmp2].add(tmp, cmp1);
			/**bin[].add(tmp,cmp1);*/
		}
		long long k = 0;
		for (long long i = 0; i <= this->buckets; i++)
		{
			for (long long j = 0; j < bin[i].get_size(); j++)
			{
				this->get_element(k) = bin[i].get_element(j);
				k++;
			}
		}
	}

public:
	//bucket_sort_inplace(T* arr1, long size1) :DynamicArray<T>(arr1, size1)
	//{
	//	list<T>* mem_val_list = new list<T>();
	//	this->search_possibly_value(mem_val_list);
	//	this->so_sort(mem_val_list);
	//	delete mem_val_list;
	//};
	bucket_sort_inplace(T* arr1, long size1, long long k_bucket) :DynamicArray<T>(arr1, size1),buckets(k_bucket)
	{
		this->so_sort();
	};
	//bucket_sort_inplace(DynamicArray<T> table) :DynamicArray<T>(table)
	//{
	//	list<T>* mem_val_list = new list<T>;
	//	this->search_possibly_value(mem_val_list);
	//	this->so_sort(mem_val_list);
	//	delete mem_val_list;
	//};
	bucket_sort_inplace(DynamicArray<T> table, long long k_bucket) :DynamicArray<T>(table), buckets(k_bucket)
	{
		this->so_sort();
	};
};

