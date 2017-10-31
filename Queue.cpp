#include "Queue.h"

template<class T>
Queue<T>::Queue()
{
}

template<class T>
Queue<T>::~Queue()
{
}

template<class T>
void Queue<T>::Enqueue(T element) {
	elements.push_back(element);
}

template<class T>
void Queue<T>::Dequeue() {
	elements.pop_front();
}

template<class T>
T Queue<T>::Front() {
	return elements.front();
}

template<class T>
bool Queue<T>::isEmpty() {
	return elements.empty();
}