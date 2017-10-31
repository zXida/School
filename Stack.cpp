#include "Stack.h"


template<class T>
Stack<T>::Stack()
{
}

template<class T>
Stack<T>::~Stack()
{
}

template<class T>
void Stack<T>::Push(T element) {
	elements.push_back(element);
}

template<class T>
void Stack<T>::Pop() {
	elements.pop_back();
}

template<class T>
T Stack<T>::Top() {
	return elements.back();
}

template<class T>
bool Stack<T>::isEmpty() {
	return elements.empty();
}
