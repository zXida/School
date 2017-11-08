#include "SortedList.h"

template<class T>
void SortedList<T>::push(T element)
{
	Node<T>* node = new Node<T>(element);
	Node<T>* tmp = nullptr;
	if (first != nullptr && first->getElement() > element) {
		node->setNext(first);
		first = node;
		return;
	}
	for (Node<T>* n = first; n != nullptr; n = n->getNext()) {
		if (n->getElement() > element)
		{
			node->setNext(n);
			tmp->setNext(node);
			return;
		}
	}
	first = node;
}

