#pragma once
#include "List.cpp"

template<class T>
class SortedList :
	public List<T>
{
private:
	using List<T>::push_back;
	using List<T>::push_front;

public:
	
	void push(T element);
	
};
