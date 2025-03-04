#include "Model.h"

Model::Model()
{
	count = 0;
	Monome m1[4] = { Monome(2, 2, 2, 0), Monome(1, 1, 1, 1), Monome(2.5, 3, 0, 1), Monome(2)};
	Monome m2[2] = { Monome(-3, 15, 3, 3), Monome(2) };
	Polynome a(m1, 4), b(m2, 2);
	polynomes.push_back(a);
	polynomes.push_back(b);
}

void Model::Run()
{
	Update();
	char key;
	cin >> key;
	while (key != 'q') {
		Polynome res;
		switch (key)
		{
		case '1':
			int number1, number2;
			cin >> number1 >> number2;
			try {
				res = polynomes[number1] + polynomes[number2];
				polynomes.push_back(res);
			}
			catch (...) {
				Update("Try again");
			}
			break;
		case '2':
			int number1, number2;
			cin >> number1 >> number2;
			try {
				res = polynomes[number1] - polynomes[number2];
				polynomes.push_back(res);
			}
			catch (...) {
				Update("Try again");
			}
			break;
		case '3':
			int number1, number2;
			cin >> number1 >> number2;
			try {
				res = polynomes[number1] * polynomes[number2];
				polynomes.push_back(res);
			}
			catch (...) {
				Update("Try again");
			}
			break;
		case '4':
			int number, c;
			cin >> number >> c;
			try {
				res = polynomes[number] * c;
				polynomes.push_back(res);
			}
			catch (...) {
				Update("Try again");
			}
			break;
		case '5':
			cin >> res;
			polynomes.push_back(res);
			break;
		default:
			Update("Try again");
			break;
		}
	}
	cout << "Its all over...";
}

void Model::Update(string message)
{
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
	cout << "5: Polynomes input" << endl;
	cout << "q: Quit" << endl;
	if (message != "") {
		cout << "\033[32m" << message << "\033[0m" << endl;
	}
}
