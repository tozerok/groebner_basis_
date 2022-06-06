#include<iostream>
#include"polynom.h"
#include"monom.h"

using std::map;
using std::vector;
using std::cout;
using std::cin;
using std::complex;

map<vector<int>, complex<double>> operator+(const map<vector<int>, complex<double>>& f, const map<vector<int>, complex<double>>& g) {
	map<vector<int>, complex<double>> h = g;
	vector<vector<int>>del;
	for (auto &x : f) {
		h[x.first] += x.second;
		if (fabs(h[x.first].real()) + fabs(h[x.first].imag())==0.0)
			del.push_back(x.first);
	}
	for (auto& x : del) {
			h.erase(x);
	}
	return h;
}

map<vector<int>, complex<double>> operator*(const map<vector<int>, complex<double>>& f, const map<vector<int>, complex<double>>& g) {
	map<vector<int>, complex<double>> h;
	for (auto &x : f)
		for (auto &y : g)
			h[x.first + y.first] += x.second * y.second;
	return h;
}

map<vector<int>, complex<double>> S(map<vector<int>, complex<double>>& f, map<vector<int>, complex<double>>& g) {
	map<vector<int>, complex<double>> q1, q2;
	vector<int>lcm = LCM(f.rbegin()->first, g.rbegin()->first);
	q1[lcm - f.rbegin()->first] = 1.0 / f.rbegin()->second;
	q2[lcm - g.rbegin()->first] = -1.0 / g.rbegin()->second;
	q1 = f * q1;
	q2 = g * q2;
	return (q1 + q2);
}

bool check(map<vector<int>, complex<double>>& f, map<vector<int>, complex<double>>& g)
{
	vector<int>deg1 = f.rbegin()->first;
	vector<int>deg2 = g.rbegin()->first;
	return checked(deg1, deg2);
}



void print(const map<vector<int>, complex<double>>& f)
{
	if (f.size() == 0)
	{
		cout << 0;
		return;
	}
	auto it = f.rbegin();
	for (; it != f.rend(); it++) {
		if (it != f.rbegin())
			cout << "+ ";
		cout << "("<<it->second.real()<<"; " << it->second.imag() << ") ";
		for (int i = 0; i < it->first.size(); i++) {
			if (it->first[i] == 0)
				continue;
			if (it->first[i] == 1) {
				cout << "x" << i + 1<<" ";
				continue;
			}
			cout << "x" << i + 1 << "^" << it->first[i]<<" ";
		}
		
	}
}

void input(map<vector<int>, complex<double>>& polynom,int n) {
	double a;
	double b;
	char x;
	int i, p;
	do {
		vector<int>deg(n, 0);
		cin >> x;
		cin >> a;
		cin >> x;
		cin >> b;
		cin >> x;
		cin >> x;
		while (x != '+' && x != ';') {
			if (x != 'x')
				cin >> x;
			if (x == '+' || x == ';')
				break;
			cin >> i;
			cin >> x;
			
			if (x == '^') {
				cin >> p;
				deg[i - 1] = p;
			}
			else
				deg[i - 1] = 1;
			if (x == '+' || x == ';')
				break;
		}
		polynom[deg] += {a, b};
		if (x == ';') {
			return;
		}
	} while (true);
}

