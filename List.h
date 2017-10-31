#pragma once
#include "Node.cpp"
#include <string>
#include <stdexcept>

template <class T>
class List
{
	Node* first;

	void delfirst(T element);
	void del(Node* source, T element);
public:
	List();
	~List();

	void push_back(T element);
	void push_front(T element);
	
	T pop_back();
	T pop_front();
	
	void clear();
	void reverse();
	void erase(T element);

	bool empty();
	bool contains(T element);

	List<T> operator-(List<T> second);

	std::string toString();
};
