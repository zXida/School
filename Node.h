#pragma once
using namespace std;

template <class T>
class Node
{
	T element;
	Node<T>* next;
public:
	Node();
	~Node();
	Node(T element);

	T getElement();
	void setElement(T);
	Node<T>* getNext();
	void setNext(Node*);
};
