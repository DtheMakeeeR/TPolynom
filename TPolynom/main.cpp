#include "TList.h"
#include "Polynome.h"
#include <iostream>
using namespace std;
void main() {
	/*TList<int> l1;
	for (int i = 0; i < 5; i++) {
		l1.PushBack(i);
	}
	TList<int> l2(l1);
	l1.DelFront();
	l1.PushBack(5);
	cout << endl << (l1 == l2) << endl << (l1 != l2);
	cout << endl << endl;
	for (int i = 0; i < 5; i++) {
		cout << l1.Pop() << endl;
		cout << l2.Pop() << endl;
	}*/
	/*Polynome p1;
	cin >> p1;
	cout << p1;
	Polynome p2(p1);
	cout << endl << p2;*/
	Monome m[3] = { Monome(1, 2, 1, 1), Monome(-3, 1, 0, 0), Monome(4, 0, 2, 1) };
	Polynome p1(m, 3);
	cout << p1 << endl;
	Monome test1(-4, 0, 2, 1);
	p1.AddMonome(test1);
	cout << p1 << " back del" << endl;

	Monome test2(-1, 2, 1, 1);
	p1.AddMonome(test2);
	cout << p1 << " front del" << endl;

	p1.AddMonome(test1);
	cout << p1 << " back add" << endl;

	p1.AddMonome(test2);
	cout << p1 << " front add" << endl;

	Monome test3(3, 1, 0, 0);
	p1.AddMonome(test3);
	cout << p1 << " mid del" << endl;

	Monome test4(-3, 1, 0, 0);
	p1.AddMonome(test4);
	cout << p1 << " mid add" << endl;
	Polynome::iterator p = p1.Begin();
	for (; p != p1.End(); ++p) {
		cout << *p << "iiter" << endl;
	}
}