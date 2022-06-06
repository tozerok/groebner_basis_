#pragma once
#include<vector>
class monom
{
	std::vector<int>example;
public:
	static monom LCM(monom& f, monom& g);
	static monom GCD(monom& f, monom& g);
};

monom LCM(monom& f, monom& g) {
	return f;
}
