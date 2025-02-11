#pragma once
#include <iostream>
using namespace std;
struct Monom {
	double coeff;
	int x, y, z;
public:
	bool operator <(const Monom& m);
	friend ostream& operator <<(ostream& out, const Monom& m);
	friend istream& operator >>(istream& in, Monom& m);
};