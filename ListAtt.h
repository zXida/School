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
	ListAtt<T> merge(ListAtt<T> l);
	void addInOrder(T element);

	bool operator==(ListAtt<T>& second);
	ListAtt<T> operator-(ListAtt<T> second);
	ListAtt<T> operator+(ListAtt<T> second);

	friend ostream& operator<<(ostream& o, ListAtt<T>& l) {
		o << "[";
		for (l.att = l.L; l.att != nullptr; l.att = l.att->getNext()) {
			o << l.att->getElement();
			if (l.att->getNext() != nullptr)
				o << ", ";
		}
		o << "]";
		return o;
	}
	friend istream& operator>>(istream& i, ListAtt<T>& l) {
		T tmp;
		i >> tmp;
		l.append(tmp);
		return i;
	}

	friend ofstream& operator<<(ofstream& o, ListAtt<T>& l) {
		o << "[";
		for (l.att = l.L; l.att != nullptr; l.att = l.att->getNext()) {
			o << l.att->getElement();
			if (l.att->getNext() != nullptr)
				o << ", ";
		}
		o << "]";
		return o;
	}
	friend ifstream& operator>>(ifstream& i, ListAtt<T>& l) {
		T tmp;
		i >> tmp;
		l.append(tmp);
		return i;
	}
};

