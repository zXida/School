#include "List.h"

template<class T>
List<T>::List() {}

template<class T>
List<T>::~List() {}

template<class T>
size_t List<T>::size() {
	return s;
}


template<class T>
void List<T>::push_back(T element) {
	Node* n = new Node();
	n->element = element;

	if (s++ == 0) {
		first = n;
		last = n;
	}

	else {
		last->following = n;
		n->previous = last;
		last = n;
	}
}

template<class T>
void List<T>::push_front(T element) {
	Node* n = new Node();
	n->element = element;

	if (s++ == 0) {
		first = n;
		last = n;
	}

	else {
		first->previous = n;
		n->following = first;
		first = n;
	}
}


template<class T>
void List<T>::pop_back() {
	if (s == 0)
		throw empty_list;
	if (s-- == 1) {
		delete first;
		return;
	}
	last = last->previous;
	delete last->following;
}

template<class T>
void List<T>::pop_front() {
	if (s == 0)
		throw empty_list;
	if (s-- == 1) {
		delete first;
		return;
	}
	first = first->following;
	delete first->previous;
}

template<class T>
T List<T>::back() {
	if (empty())
		throw empty_list;
	return last->element;
}

template<class T>
T List<T>::front() {
	if (empty())
		throw empty_list;
	return first->element;
}

template<class T>
void List<T>::clear() {
	for (Node* n = first->following; n != last; n = n->following)
		delete n->previous;
	delete last->previous;
	delete last;
}

template<class T>
void List<T>::erase(T element) {
	if (empty())
		throw empty_list;
	for (Node* n = first->following; n != last; n = n->following) {
		if (n->element == element) {
			if (n == first)
				pop_front();
			else {
				n->previous->following = n->following;
				n->following->previous = n->previous;
				delete n;
			}
			s--;
		}
	}
	if (last->element == element) {
		pop_back();
		s--;
	}
}

template<class T>
bool List<T>::empty() {
	return s == 0;
}

template<class T>
bool List<T>::contains(T element)
{
	for (Node *n = begin; n != nullptr; n = n->following) 
		if (n->element == element)
			return true;
	
	return false;
}

template<class T>
List<T> List<T>::operator+(List<T> second)
{
	List<T> tmp = *this;
	while (!second.empty()) {
		tmp.push_back(second.front());
		second.pop_front();
	}
	return tmp;
}

template<class T>
List<T> List<T>::operator-(List<T> second)
{
	List<T> tmp;
	for (List<T>::iterator i = second.begin(); i != nullptr; i++) 
		if (contains(i->element))
			erase(i->element);
	
	return tmp;
}

template<class T>
void List<T>::reverse()
{
	Node* n = first->following;
	while (n->previous != nullptr) {
		swap(n->previous, n->following);
		n = n->previous;
	}
	swap(first->previous, first->following);
}