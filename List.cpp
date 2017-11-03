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
	Node<T>* node = new Node<T>(element);
	Node<T>* tmp = first;
	if (tmp == nullptr)
		return push_front(element);
	while (tmp->getNext() != nullptr) {
		tmp = tmp->getNext();
	}
	tmp->setNext(node);
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
	Node<T>* node = first;
	T tmp;
	if (first == nullptr)
		throw exception("No elements in list");
	
	while (node->getNext() != nullptr) 
		node = node->getNext();
	
	tmp = node->getElement();
	delete node;

	return tmp;
}

template<class T>
T List<T>::pop_front()
{
	Node<T>* node = first;
	T tmp;
	
	if (first == nullptr)
		throw exception("No elements in list");
	
	tmp = first->getElement();
	first = first->getNext();
	delete node;

	return tmp;
}

template<class T>
void List<T>::clear()
{
	Node<T>* tmp;
	if (first == nullptr)
		return;
	for (Node<T>* n = first; n != nullptr; n = tmp) {
		tmp = n->getNext();
		delete n;
	}
}

template<class T>
void List<T>::reverse() {
	Node<T>* tmp;
	Node<T>* tmp2 = nullptr;
	Node<T>* n = first;

	if (n == nullptr)
		return;

	do {
		tmp = n->getNext();
		n->setNext(tmp2);
		tmp2 = n;
	} while (tmp != nullptr && (n = tmp));

	first = n;
}

template<class T>
bool List<T>::empty() {
	return first == nullptr;
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

template<class T>
void List<T>::erase(T element) {
	delfirst(element);
	
	if (first == nullptr)
		return;
	
	for (Node<T>* n = first->getNext(); n->getNext() != nullptr; n = n->getNext()) 
		del(n, element);
	
}

template<class T>
List<T> List<T>::operator-(List<T> second) {
	List<T> l = *this;
	
	for(Node<T>* n = second.first; n != nullptr; n = n->getNext())
		l.erase(n->getElement());
	
	return l;
}

template<class T>
void List<T>::delfirst(T element) {
	Node<T>* tmp;
	if (first != nullptr && first->getElement() == element) {
		tmp = first;
		first = first->getNext();
		delete tmp;
		delfirst(element);
	}
}

template<class T>
void List<T>::del(Node<T>* source, T element) {
	Node<T>* tmp;
	if (source->getNext() != nullptr && source->getNext()->getElement() == element) {
		tmp = source->getNext();
		source->setNext(source->getNext()->getNext());
		delete tmp;
		del(source, element);
	}
}
