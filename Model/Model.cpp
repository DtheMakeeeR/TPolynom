#include "Model.h"
#include "../TPolynom/Polynome.cpp"
#include "../TPolynom/Monome.h"
#include "../TPolynom/Monome.cpp"
Model::Model()
{
	count = 0;
	//Monome m1[4] = { Monome(2, 2, 2, 0), Monome(1, 1, 1, 1), Monome(2.5, 3, 0, 1), Monome(2)};
	//Monome m2[2] = { Monome(-3, 15, 3, 3), Monome(2) };
	Monome m3[3] = { Monome(10, 7, 7, 7), Monome(9, 5, 5, 5), Monome(8, 3, 3, 3) };
	Monome m4[3] = { Monome(-8, 3, 3, 3), Monome(-10, 2, 2, 2), Monome(-9, 0, 0, 0) };
	Monome m5[1] = { Monome(1, 5, 5, 5) };
	Polynome a(m3, 3), b(m4, 3), c(m5, 1);
	polynomes.push_back(a);
	polynomes.push_back(b);
	polynomes.push_back(c);
}

void Model::Run()
{
	Update();
	char key = 'a';
	while (key != 'q') {
		cin >> key;
		Polynome res;
		int number1, number2;
		switch (key)
		{
		case '1':
			cin >> number1 >> number2;
			if (number1 >= polynomes.size() || number2 >= polynomes.size()) Update("Try again");
			else
			{
				try {
					res = polynomes[number1] + polynomes[number2];
					polynomes.push_back(res);
					Update();
				}
				catch (...) {
					Update("Try again");
				}
			}
			break;
		case '2':
			cin >> number1 >> number2;
			if (number1 >= polynomes.size() || number2 >= polynomes.size()) Update("Try again");
			else
			{
				try {
					res = polynomes[number1] - polynomes[number2];
					polynomes.push_back(res);
					Update();
				}
				catch (...) {
					Update("Try again");
				}
			}
			break;
		case '3':
			cin >> number1 >> number2;
			if (number1 >= polynomes.size() || number2 >= polynomes.size()) Update("Try again");
			else {
				try {
					res = polynomes[number1] * polynomes[number2];
					polynomes.push_back(res);
					Update();
				}
				catch (...) {
					Update("Try again");
				}
			}
			break;
		case '4':
			int number, c;
			cin >> number >> c;
			if (number >= polynomes.size()) Update("Try again");
			else
			{
				try {
					res = polynomes[number] * c;
					polynomes.push_back(res);
					Update();
				}
				catch (...) {
					Update("Try again");
				}
			}
			break;
		case '5':
			try {
				cin >> res;
				polynomes.push_back(res);
				Update();
			}
			catch (...) {
				Update("Try again");
			}
			break;
		default:
			Update("Try again");
			break;
		}
		count++;
	}
	Update("Its all over...");
	cin >> key;
}

void Model::Update(string message)
{
	system("cls");
	cout << "Polynomes count: " << polynomes.size() << endl;
	cout << "Operations are done: " << count << endl;
	for (int i = 0; i < polynomes.size(); i++) {
		cout << i << ") " << polynomes[i] << endl;
	}
	cout << "Choose operation:" << endl;
	cout << "1: Polynomes add" << endl;
	cout << "2: Polynomes dis" << endl;
	cout << "3: Polynomes mult" << endl;
	cout << "4: Polynomes multInt" << endl;
	cout << "5: Polynomes input (coeff x y z until coeff == 0" << endl;
	cout << "q: Quit" << endl;
	if (message != "") {
		cout << "\033[31m" << message << "\033[0m" << endl;
	}
}
