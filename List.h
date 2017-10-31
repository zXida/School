#pragma once
#include <stdexcept>
template<class T>
class List
{
	struct Node {
		T element;
		Node* previous;
		Node* following;
	};

	std::out_of_range empty_list("No elements in list");

	Node* first;
	Node* last;

	size_t s;

public:

	List();
	~List();

	size_t size();

	void push_back(T element);
	void push_front(T element);

	void pop_back();
	void pop_front();

	T front();
	T back();
	
	bool contains(T element);

	void clear();
	void erase(T element);
	void reverse();
	
	List<T> operator+(List<T> second);
	List<T> operator-(List<T> second);

	bool empty();
};