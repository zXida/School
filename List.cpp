#include "List.h"

template <class T>
List<T>::List()
{
	first = nullptr;
}

template <class T>
List<T>::~List()
{
}

template<class T>
void List<T>::push_back(T element)
{
	Node<T>* tmp = new Node<T>(element);
	Node<T>* _tmp = first;
	if (_tmp == nullptr)
		return push_front(element);
	while (_tmp->getNext() != nullptr) {
		_tmp = _tmp->getNext();
	}
	_tmp->setNext(tmp);
}

template<class T>
void List<T>::push_front(T element)
{
	Node<T>* tmp = new Node<T>(element);
	tmp->setNext(first);
	first = tmp;
}

template<class T>
T List<T>::pop_back()
{
	Node<T>* tmp;
	T _tmp;
	if (first == nullptr)
		throw exception("No elements in list");
	tmp = first;
	while (tmp->getNext() != nullptr) {
		tmp = tmp->getNext();
	}
	_tmp = tmp->getElement();
	delete tmp;

	return _tmp;
}

template<class T>
T List<T>::pop_front()
{
	Node<T>* tmp;
	T _tmp;
	if (first == nullptr)
		throw exception("No elements in list");
	_tmp = first->getElement();
	
	tmp = first;
	first = first->getNext();
	delete tmp;

	return _tmp;
}

template<class T>
void List<T>::clear()
{
	Node<T>* tmp;
	if (first == nullptr)
		return;
	for (Node<T>* n = first; n->getNext() != nullptr; n = tmp) {
		tmp = n->getNext();
		delete n;
	}
}

template<class T>
void List<T>::reverse() {
	Node<T>* tmp;
	Node<T>* tmp2;
	Node<T>* n = first;

	if (n == nullptr)
		return;

	do {
		tmp = n->getNext();
		n->setNext(tmp2);
		tmp2 = n;
	} while (tmp != nullptr && n = tmp);

	first = n;
}


template<class T>
string List<T>::toString(){
	string s = "[";
	for(Node<T>* n = first; n != nullptr; n = n->getNext()){
		s += to_string(n->getElement());
		if(n->getNext() != nullptr)
			s += ", ";
	}
	s += "]";
	return s;
}
