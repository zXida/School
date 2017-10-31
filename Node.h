#pragma once
using namespace std;

template <class T>
class Node
{
	T element;
	Node* next;
public:
	Node();
	~Node();
	Node(T element);

	T getElement();
	void setElement(T);
	Node* getNext();
	void setNext(Node*);
};