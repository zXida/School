#include "Node.h"

template <class T>
Node<T>::Node()
{
	next = nullptr;
}

template <class T>
Node<T>::~Node()
{
}

template<class T>
Node<T>::Node(T element)
{
	this->element = element;
	next = nullptr;
}

template<class T>
T Node<T>::getElement()
{
	return element;
}

template<class T>
void Node<T>::setElement(T element)
{
	this->element = element;
}

template<class T>
Node * Node<T>::getNext()
{
	return next;
}

template<class T>
void Node<T>::setNext(Node* next)
{
	this->next = next;
}