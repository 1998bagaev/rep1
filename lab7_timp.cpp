#include <stdexcept>
#include "Header.h"

template <class T = int>
class Queue : public IQ<T>
{
	bool isFull;
	const size_t size;
	size_t top_, bottom;
	T *arr;
public:
	Queue(size_t n = 100)
		: isFull(false), size(n), top_(0), bottom(0), arr(new T[size])
	{
	}
	
	bool empty()
	{
		return top_ == bottom && !isFull;
	}
	/*
	
	void push(const T &val) {
	   	if (isFull)
			return;
	   	arr[bottom] = val;
	   	bottom = (bottom + 1) % size;
	  	if (top_ == bottom)
			isFull = true;
	}
	
	void pop() {
	  	if (empty())
	  		return;
	   	isFull = false;
	   	top_ = (top_ + 1) % size;
	}
	
	T &top() {
		if (!empty())
			return arr[top_];
		else
			throw std::out_of_range("queue is empty");
	}

	~Queue() {
		delete[] arr;
	}
};


extern "C"
{
	__declspec(dllexport) IQ<> *GetSomeIQ()
	{
		return new Queue<>();
	}
}
