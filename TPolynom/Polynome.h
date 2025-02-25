#pragma once
#include "Monome.h"
#include "TList.h"
#include <string>
class Polynome: public TList<Monome> {
public:
	Polynome(): TList<Monome>() {}
	Polynome(const Polynome& p) : TList<Monome>(p) {}
	Polynome(Monome* p, int sz);

	bool operator==(const Polynome& p) const;

	Polynome operator+(Polynome& p);
	Polynome operator+(double coef);
	Polynome operator*(Polynome& p);
	Polynome operator*(Monome m);

	void AddMonome(Monome m);
	friend ostream& operator <<(ostream& out, Polynome& p);
	friend istream& operator >>(istream& in, Polynome& p);
};