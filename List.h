#pragma once
#include "Node.cpp"
#include <string>
#include <stdexcept>

template <class T>
class List
{
	Node* first;
public:
	List();
	~List();

	void push_back(T element);
	void push_front(T element);
	
	T pop_back();
	T pop_front();
	
	void clear();
	void reverse();

	std::string toString();
};