#include "ListAtt.h"


template <class T>
ListAtt<T>::ListAtt()
{
}

template<class T>
ListAtt<T>::~ListAtt()
{
}

template<class T>
void ListAtt<T>::reset()
{
	att = L;
}

template<class T>
T ListAtt<T>::read()
{
	T tmp = att->getElement();
	att = att->getNext();
	return tmp;
}

template<class T>
void ListAtt<T>::goNext()
{
	att = att->getNext();
}

template<class T>
bool ListAtt<T>::endList()
{
	return att == nullptr;
}

template<class T>
bool ListAtt<T>::empty()
{
	return L == nullptr;
}

template<class T>
void ListAtt<T>::append(T element)
{
	Node<T>* tmp = new Node<T>(element);
	reset();
	if (empty())
		L = tmp;
	else {
		for (; att->getNext() != nullptr; att = att->getNext());
		att->setNext(tmp);
	}

}

template<class T>
void ListAtt<T>::addFront(T element)
{
	Node<T>* n = new Node<T>(element);
	n->setNext(L);
	L = n;
}

template<class T>
Node<T>* ListAtt<T>::search(T element)
{
	for (att = L; att != nullptr; att = att->getNext())
		if (att->getElement() == element)
			return att;
	return nullptr;
}

template<class T>
void ListAtt<T>::del(T element)
{
	Node<T>* tmp = nullptr;
	for (att = L; att != nullptr; att = att->getNext()) {
		if (att->getElement() == element) {
			if (att == L) {
				L = L->getNext();
				delete att;
			}
			else {
				tmp->setNext(att->getNext());
				delete att;
			}
		}

		tmp = att;
	}
}

template<class T>
void ListAtt<T>::reverse()
{
	Node<T>* prec;
	Node<T>* succ;
	reset();
	for (att = L;;) {
		succ = att->getNext();
		att->setNext(prec);
		if (tmp == nullptr)
			break;
		att = tmp;
	}
	L = att;
}

template<class T>
static ListAtt<T> ListAtt<T>::merge(ListAtt<T> l1, ListAtt<T> l2)
{
	for (l2.att = l2.L; l2.att != nullptr; l2.att = l2.att->getNext())
		l1.addInOrder(l2.att->getElement());
	return l1;
}

template<class T>
void ListAtt<T>::addInOrder(T element)
{
	Node<T>* tmp;
	Node<T>* n = new Node<T>(element);
	for (att = L; att != nullptr; att = att->getNext()) {
		if (att->getElement() > element) {
			if (att == L) {
				n->setNext(L);
				L = n;
			}
			else {
				n->setNext(tmp->getNext());
				tmp->setNext(n);
			}
			return;
		}
	}
	L = n;
}

template<class T>
bool ListAtt<T>::operator==(ListAtt<T>& second)
{
	for (att = L, second.att = second.l; att == nullptr && second.att == nullptr; att = att->getNext(), second.att = second.att->getNext()) {
		if (att == nullptr != second.att == nullptr) 
			return false;

		if (att->getElement() != second.att->getElement())
			return false;
	}
	return true;
}

template<class T>
ListAtt<T> ListAtt<T>::operator-(ListAtt<T> second)
{
	ListAtt<T> l = *this;
	for (second.att = second.L; second.att != nullptr; second.att = second.att->getNext())
		l.del(second.att->getElement());
	return l;
}

template<class T>
ListAtt<T> ListAtt<T>::operator+(ListAtt<T> second)
{
	ListAtt<T> l = *this;
	for (l.att = l.L, second.att = second.L;l.att != nullptr && second.att != nullptr ;l.att = l.att->getNext(), second.att = second.att->getNext()) {
		second.att->setNext(l.att->getNext());
		l.att->setNext(second.att);
	}
	return l;
}

template <class T>
std::ostream & operator<<(ostream & o, ListAtt<T>& l)
{
	o << "[";
	for (l.att = l.L; l.att != nullptr; l.att = l.att->getNext()) {
		o << l.att->getElement();
		if (l.att->getNext() != nullptr)
			o << ", ";
	}
	o << "]";
	return o;
}

template <class T>
std::istream & operator>>(istream & i, ListAtt<T>& l)
{
	T tmp;
	i >> tmp;
	l.append(tmp);
	return i;
}

template <class T>
std::ofstream & operator<<(ofstream & o, ListAtt<T>& l)
{
	o << "[";
	for (l.att = l.L; l.att != nullptr; l.att = l.att->getNext()) {
		o << l.att->getElement();
		if (l.att->getNext() != nullptr)
			o << ", ";
	}
	o << "]";
	return o;
}

template <class T>
std::ifstream & operator>>(ifstream & i, ListAtt<T>& l)
{
	T tmp;
	i >> tmp;
	l.append(tmp);
	return i;
}
