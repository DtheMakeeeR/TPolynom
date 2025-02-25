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
	Monome m2[3] = { Monome(1, 2, 1, 1), Monome(-3, 1, 0, 0), Monome(4, 0, 3, 1) };
	Polynome p1(m, 3), p2(m2, 3);
	cout << p1 << " p1" << endl << endl;
	Monome test1(-4, 0, 2, 1);
	p1.AddMonome(test1);
	cout << p1 << " back del" << endl << endl;
	Monome test2(-1, 2, 1, 1);
	p1.AddMonome(test2);
	cout << p1 << " front del" << endl << endl;

	p1.AddMonome(test1);
	cout << p1 << " back add" << endl << endl;

	p1.AddMonome(test2);
	cout << p1 << " front add" << endl << endl;

	Monome test3(3, 1, 0, 0);
	p1.AddMonome(test3);
	cout << p1 << " mid del" << endl << endl;

	Monome test4(-3, 1, 0, 0);
	p1.AddMonome(test4);
	cout << p1 << " mid add" << endl << endl;
	Polynome::iterator p = p1.Begin();
	for (; p != p1.End(); ++p) {
		cout << *p << "iiter" << "endl";
	}
	cout << "\n\n\n\n\n ****operator+ ****\n";
	cout << p1 << " p1" << endl;
	cout << p2 << " p2" << endl;
	Polynome p3 = p1 + p2;
	cout << p3 << " p1 + p2" << endl;
	cout << "\n\n\n\n\n ****operator* monom ****\n";
	Monome m4[3] = { Monome(2, 0, 10, 1), Monome(-3, 10, 0, 0), Monome(4, 0, 0, 10) };
	Monome monom1(2.5, 1, 1, 1);
	Polynome p4(m4, 3);
	Polynome p5 = p4 * monom1;
	cout << p4 << " p4" << endl;
	cout << monom1 << " monom1" << endl;
	cout << p5 << " p4 * monom1" << endl;
	cout << "\n\n\n\n\n ****operator* polynom ****\n";
	Monome m5[2] = { Monome(2, 2, 2), Monome(1, 1, 1, 1) };
	Monome m6[1] = { Monome(3, 3, 3, 3) };
	Polynome p6(m5, 2), p7(m6, 1);
	Polynome res = p6 * p7;
	cout << p6 << " p6" << endl;
	cout << p7 << " p7" << endl;
	cout << res << " p6 * p7" << endl;
}