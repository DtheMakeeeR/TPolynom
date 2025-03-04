#pragma once
#include "../TPolynom/Polynome.h"
#include <vector>

class Model {
	vector<Polynome> polynomes;
	int count;
public:
	Model();
	void Run();
	void Update(string message = "");
};