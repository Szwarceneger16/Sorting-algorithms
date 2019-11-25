#ifndef __MY_EXCEPTIONS
#define __MY_EXCEPTIONS

#include <string>

class my_exceptions_class
{
	short i;
	std::string class_name;
public:
	explicit my_exceptions_class(short ii,std::string name) :i(ii),class_name(name) {};
	std::string get_info(void)
	{
		switch (this->i)
		{
		case 1:
			return "Error! "+this->class_name+" is empty!";
			break;
		case 2:
			return "Error! You passed down value out of range of " + this->class_name + "!!!";
			break;
		case 3:
			return "Error! You pass value smaller than 0! Please Kill yoursefl";
			break;
		case 4:
			return "Error! You haven\'t more memory !!!!";
			break;
		default:
			return "I don't recognize this error";
			break;
		}
	}
};
#endif // !__MY_EXCEPTIONS




#ifndef __DYNAMIC_ARRAY
#define __DYNAMIC_ARRAY
#include <cstdio>

template <class T>
class DynamicArray 
{

	inline void twice_max() { this->max_size != 0 ? this->max_size *= 2 : this->max_size = 1; }
	long long current_size;
	long long max_size;
	T* array_pointer;

	T* get_root_pointer(void)
	{
		return this->array_pointer;
	}

protected:

	T& get_element(long long pos)
	{
		return (*(this->array_pointer + pos));
	}

public:
	//friend class DynamicArray<T>;
	DynamicArray() :array_pointer(NULL), current_size(0), max_size(1) {};
	DynamicArray(T* array_arg, long long size) :array_pointer(array_arg), current_size(size+1), max_size(size) {};
	DynamicArray(DynamicArray<T>& table)
	{
		this->array_pointer = table.get_root_pointer();
		this->current_size = table.get_current_size() + 1;
		this->max_size = table.get_max_size();
	};

	T get_max_min(bool (*fun)(T const, T const))
	{
		T tmp = NULL;
		for (long long i = 0; i <= this->current_size; i++)
		{
			if (fun(tmp,*(this->array_pointer + i))) tmp = *(this->array_pointer + i);
		}
		return tmp;
	}

	void add(T val)
	{
		if (this->array_pointer == NULL)
		{
			this->array_pointer = new T[1];
			this->array_pointer[this->current_size++] = val;
		}
		else if (current_size < max_size)
		{
			this->array_pointer[this->current_size++] = val;
		}
		else
		{

			T* tmp = this->array_pointer;
			this->array_pointer = new T[(max_size * 2)];
			for (long long i = 0; i < max_size; i++)
			{
				this->array_pointer[i] = tmp[i];
			}
			twice_max();
			this->array_pointer[this->current_size++] = val;

			delete[] tmp;
		}
	}

	T& operator [](long long pos)
	{
		if (pos < 0 || pos >= current_size) { throw my_exceptions_class(2,"DynamicArray"); }
		else return get_element(pos);
	}

	bool operator =(DynamicArray<T>& table)
	{
		if (this->current_size != table.current_size) { std::cout << "rozna dlugosc" << std::endl; return false; }
		for (long long i = 0; i < current_size; i++)
		{
			if (array_pointer[i] != table.array_pointer[i]) return false;
		}
		return true;
	}

	T& pop_back(void)
	{
		if (this->array_pointer == NULL || this->current_size == 0)
		{
			throw my_exceptions_class(1,"DynamicArray");
		}
		else
		{
			this->current_size--;
			return *(this->array_pointer + current_size);
		}
	}

	void print(void (*funkcja) (T const))
	{
		for (long long i = 0; i < this->current_size; i++)
		{
			funkcja(this->array_pointer[i]);
		}
	};
	void print(void (*funkcja) (T const), long long dlg)
	{
		if (this->current_size < dlg) dlg = this->current_size;
		for (long long i = 0; i < dlg; i++)
		{
			funkcja(this->array_pointer[i]);
		}
	};

	long long get_current_size(void) { return (this->current_size) - 1; }
	long long get_max_size(void) const { return this->max_size; }

	void erase(void)
	{
		delete[] this->array_pointer;
		this->array_pointer = NULL;
		this->current_size = 0;
		this->max_size = 1;
	}
	void erase_ptr(void)
	{
		for (size_t i = 0; i < current_size; i++)
		{
			delete this->array_pointer[i];
		}
		delete[] this->array_pointer;
		this->array_pointer = NULL;
		this->current_size = 0;
		this->max_size = 1;
	}

	~DynamicArray() {};
};
#endif // !__DYNAMIC_ARRAY

