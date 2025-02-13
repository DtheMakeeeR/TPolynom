#pragma once
#include "Monom.h"
#include "TList.h"
#include <string>
class Polynome: TList<Monom> {
public:
	Polynome(): TList<Monom>() {}
	Polynome(const Polynome& p) : TList<Monom>(p) {}
	friend ostream& operator <<(ostream& out, const Polynome& p);
	friend istream& operator >>(istream& in, Polynome& p);
};