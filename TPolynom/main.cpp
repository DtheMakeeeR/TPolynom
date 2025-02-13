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
	Polynome p1;
	cin >> p1;
	cout << p1;
}