#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Naturale
{
	using uint = unsigned int;

	struct Node {
		uint cifra;
		Node* next;

		Node(uint i) {
			cifra = i;
			next = nullptr;
		}
	};

	void push(uint i);
	unsigned int pop();

	Node* first;
	uint decimale;

	unsigned long long fact(unsigned long long l);

public:
	Naturale();
	~Naturale();

	friend Naturale iton(int i);
	friend int ntoi(Naturale n);

	friend ostream& operator<<(ostream& o, Naturale& n);
	friend istream& operator>>(istream& i, Naturale& n);

	Naturale operator++(int);
	Naturale operator--(int);
	Naturale operator+(Naturale n);
	Naturale operator*(Naturale n);
	Naturale operator^(Naturale n);

	void Zero();
	bool isZero();
	unsigned long long Fatt();
};

