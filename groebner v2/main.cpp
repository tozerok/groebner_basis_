#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<complex>
#include<string>
#include"basis.h"
#include"polynom.h"
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	string s;
	cin >> s >> n;
	cin >> s >> m;
	cin >> s>>s;
	bool out = (s=="true");
	vector<map<vector<int>, complex<double>>> basis(m);
	for (int i = 0; i < m; i++)
		input(basis[i],n);
	//print(basis);
	Buchberger_algorithm(basis, out);
	if (out) {
		cout << "Базис Гребнера:\n";
		print(basis);
		cout << "\n";
	}
	min_red_basis(basis, out);
	cout << "\nМинимальный редуцированный базис Грёбнера\n";
	print(basis);
	return 0;
}
