#pragma once
#include "Node.cpp"
#include <iostream>
#include <fstream>

template <class T>
class ListAtt
{
	Node<T>* L;
	Node<T>* att;
public:
	ListAtt();
	~ListAtt();
	void reset();
	T read();
	void goNext();

	bool endList();
	bool empty();

	void append(T element);
	void addFront(T element);
	Node<T>* search(T element);
	void del(T element);

	void reverse();
	static ListAtt<T> merge(ListAtt<T> l1, ListAtt<T> l2);
	void addInOrder(T element);

	bool operator==(ListAtt<T>& second);
	ListAtt<T> operator-(ListAtt<T> second);
	ListAtt<T> operator+(ListAtt<T> second);

	friend std::ostream& operator<<(ostream& o, ListAtt<T>& l);
	friend std::istream& operator>>(istream& i, ListAtt<T>& l);

	friend std::ofstream& operator<<(ofstream& o, ListAtt<T>& l);
	friend std::ifstream& operator>>(ifstream& i, ListAtt<T>& l);
};

