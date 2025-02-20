#pragma once
#include <iostream>
using namespace std;
struct Monome {
	double coeff;
	int x, y, z;
public:
	Monome(int c = 0, int xp = 0, int yp = 0, int zp = 0) : coeff(c), x(xp), y(yp), z(zp) {}
	bool operator <(const Monome& m);
	bool operator ==(const Monome& m) { return ((x == m.x) && (y == m.y) && (z == m.z)); };
	bool operator !=(const Monome& m) { return !(*this == m); };
	friend ostream& operator <<(ostream& out, const Monome& m);
	friend istream& operator >>(istream& in, Monome& m);
};