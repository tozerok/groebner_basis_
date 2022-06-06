#pragma once
#include"polynom.h"
#include"monom.h"
#include<complex>

void Buchberger_algorithm(std::vector<std::map<std::vector<int>, std::complex<double>>>& basis, bool out);

void reduction(std::vector<std::map<std::vector<int>, std::complex<double>>>& basis, std::map<std::vector<int>, std::complex<double>>& f, bool out);

void min_red_basis(std::vector<std::map<std::vector<int>, std::complex<double>>>& basis, bool out);

void print(std::vector<std::map<std::vector<int>, std::complex<double>>>& basis);
