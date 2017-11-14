#include "Naturale.h"



void Naturale::push(uint i)
{
	Node* n = new Node(i);
	Node* tmp;
	if (first == nullptr) {
		first = n;
		return;
	}
	for (tmp = first; tmp->next != nullptr; tmp = tmp->next);
	tmp->next = n;
}

unsigned int Naturale::pop()
{
	uint ui;
	Node* tmp, * tmp2;
	if (first == nullptr)
		throw exception("No elements");
	for (tmp = first, tmp2 = tmp->next; tmp2 != nullptr && tmp2->next != nullptr; tmp = tmp2, tmp2 = tmp2->next);
	if (tmp2 == nullptr) {
		ui = tmp->cifra;
		delete tmp;
	}
	else {
		ui = tmp2->cifra;
		delete tmp2;
	}
	return ui;
}

unsigned long long Naturale::fact(unsigned long long l)
{
	if (l == 0)
		return 1;
	return l * fact(l - 1);
}

Naturale::Naturale()
{
}


Naturale::~Naturale()
{
}

Naturale Naturale::operator++(int)
{
	Naturale n = *this;
	*this = iton(decimale + 1);
	return n;
}

Naturale Naturale::operator--(int)
{
	Naturale n = *this;
	if (decimale == 0)
		throw exception("Number is 0");
	*this = iton(this->decimale - 1);
	return n;
}

Naturale Naturale::operator+(Naturale n)
{
	Naturale tmp = *this;
	for (int i = 0; i < n.decimale; i++) 
		tmp++;
	
	return tmp;
}

Naturale Naturale::operator*(Naturale n)
{
	Naturale tmp;
	for (int i = 0; i < n.decimale; i++)
		tmp = tmp + *this;
	return tmp;
}

Naturale Naturale::operator^(Naturale n)
{
	return iton(pow(decimale,n.decimale));
}

void Naturale::Zero()
{
	decimale = 0;
	Node* tmp;
	for (Node* n = first; n != nullptr; n = tmp) {
		tmp = n->next;
		delete n;
	}
}

bool Naturale::isZero()
{
	return decimale == 0;
}

unsigned long long Naturale::Fatt()
{
	return fact(decimale);
}

Naturale iton(int i)
{
	Naturale n;
	i = abs(i);
	n.decimale = i;
	do {
		n.push(i % 10);
	} while (i /= 10);
	return n;
}

int ntoi(Naturale n)
{
	int i = 1;
	int num = 0;
	while (!n.isZero()) 
		num += n.pop()*(i++);
	
	return num;
}

ostream & operator<<(ostream & o, Naturale & n)
{
	return o << n.decimale;
}

istream & operator>>(istream & i, Naturale & n)
{
	int myInt;
	i >> myInt;
	n = iton(myInt);
	return i;
}
