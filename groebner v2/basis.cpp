#include"polynom.h"
#include"monom.h"
#include"basis.h"
#include<iostream>
#include<set>
using std::map;
using std::vector;
using std::cout;
using std::complex;
using std::pair;
using std::set;

void Buchberger_algorithm(vector<map<vector<int>, complex<double>>>& basis, bool out) {
	int k = 0;
	set<pair<int, int>>used;
	while (k < basis.size())
	{
		int j = 0;
		while (j < basis.size())
		{
			if (used.count({ std::min(j,k), std::max(j, k) })) {
				j++;
				continue;
			}
			if (j == k) {
				j++;
				continue;
			}
			if (!check(basis[k], basis[j])) {
				j++;
				continue;
			}
			if (out) {
				cout << "Многочлены ";
				print(basis[k]);
				cout << "и ";
				print(basis[j]);
				cout << "имеют зацепление\n";
			}
			used.insert({std::min(j,k ), std::max(j, k)});
			map<vector<int>, complex<double>> S_fg;
			S_fg = S(basis[k], basis[j]);
			if (out) {
				cout << "F_" << k+1<<"_" << j+1 << "=";
				print(S_fg);
				cout << "\n";
			}
			j++;
			if (!S_fg.size()) 
				continue;
			reduction(basis, S_fg, out);
			if (out) {
				if (S_fg.size()) {
					cout << "Больше зацеплений нет.\nДобавим f_" << basis.size() << "=";
					print(S_fg);
					cout << " в набор.";
				}
				else {
					cout << "S-многочлен редуцируется к нулю.";
				}
				cout << "\n\n";
			}
			if (S_fg.size())
				basis.push_back(S_fg);
		}
		k++;
	}
}

void reduction( vector<map<vector<int>, complex<double>>>& basis, map<vector<int>, complex<double>>& f, bool out)
{
	auto it = f.rbegin();
	bool flag = false;
	for (; it != f.rend();)
	{
		for (int i = 0; i < basis.size(); i++) {
			if (division(basis[i].rbegin()->first ,it->first)) {
				map<vector<int>, complex<double>> q;
				q[it->first - basis[i].rbegin()->first] += -it->second /
					basis[i].rbegin()->second;
				f = f + (q * basis[i]);
				if (out) {
					cout << "--> редукция с помощью многочлена f_" << i+1 << "=";
					print(basis[i]);
					cout << " --> ";
					print(f);
					cout << "\n";
				}
				flag = true;
				break;
			}
		}
		if (f.size() == 0)break;
		if (flag)
		{
			it = f.rbegin();
			flag = false;
		}
		else it++;
	}
}

void min_red_basis(vector<map<vector<int>, complex<double>>>& basis, bool out)
{
	int k = 0;
	while (k != basis.size())
	{
		int j = 0;
		while (j != basis.size())
		{
			if (j == k)
			{
				j++;
				continue;
			}
			if (division(basis[k].rbegin()->first, basis[j].rbegin()->first))
			{
				if (out) {
					cout << "Старший член многочлена f_" << j<<"=";
					print(basis[j]);
					cout << " делится на старший член f_ " << k << "=";
					print(basis[k]);
					cout << "\nпоэтому удалим f_"<<k<<" из набора многочленов.\n";
				}
				basis.erase(basis.begin() + j);
				k = -1;
				break;
			}
			j++;
		}
		k++;
	}
	for (auto& polynom : basis)
		for (auto& monom : polynom)
			monom.second /= polynom.rbegin()->second;

	for (int i = 0; i < basis.size(); i++)
	{

		auto it = basis[i].rbegin();
		it++;
		for (; it != basis[i].rend(); it++)
		{
			bool flag = false;
			for (int j = 0; j < basis.size(); j++)
			{
				if (j == i)
					continue;
				auto it2 = basis[j].rbegin();
				vector<int>deg11 = it->first, deg22 = it2->first;

				if (division(it2->first, it->first))
				{
					if (out)
					{
						cout << "Редуцируем f_" << i + 1 << "=";
						print(basis[i]);
						cout << " с помощью f_" << j + 1 << "=";
						print(basis[j]);
						cout << "\n";
					}
					map<vector<int>, complex<double>> q;
					vector<int>deg1 = it->first, deg2 = it2->first;
					q[deg1 - deg2] += -it->second / it2->second;
					basis[i] = basis[i] + q * basis[j];
					it = basis[i].rbegin();
					if (out)
					{
						cout << "результат редукции f_" << i + 1<<"=";
						print(basis[i]);
						cout << "\n";
					}
					if (basis[i].size() == 0) {
						basis.erase(basis.begin()+i);
						i--;
					}
					flag = true;
					break;
				}
			}
			if (flag)
			{
				i = -1;
				break;
			}
		}
	}
}

void print(vector<map<vector<int>, complex<double>>>& basis) {
	for (auto& polynom : basis)
	{
		print(polynom);
		cout << "\n";
	}
}