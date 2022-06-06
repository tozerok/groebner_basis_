#include"monom.h"

using std::vector;

vector<int> operator+(const vector<int>& a, const vector<int>& b) {
	vector<int>c(a.size());
	for (int i = 0; i < a.size(); i++) {
		c[i] = a[i] + b[i];
	}
	return c;
}

vector<int> operator-(const vector<int>& a, const vector<int>& b) {
	vector<int>c(a.size());
	for (int i = 0; i < a.size(); i++) {
		c[i] = a[i] - b[i];
	}
	return c;
}

vector<int> LCM(const vector<int>& a, const vector<int>& b)
{
	vector<int>c(a.size());
	for (int i = 0; i < a.size(); i++) {
		c[i] = std::max(a[i] ,b[i]);
	}
	return c;
}

bool checked( vector<int>& a, vector<int>& b)
{
	for (int i = 0; i < a.size(); i++)
		if (a[i] * b[i] != 0)
			return true;
	return false;
}

bool division(const vector<int>& a,const  vector<int>& b)
{
	for (int i = 0; i < a.size(); i++) {
		if (a[i] > b[i])
			return false;
	}
	return true;
}
