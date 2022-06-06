#pragma once
#include<vector>
#include<map>
#include<complex>

std::map<std::vector<int>, std::complex<double>> operator*(const std::map<std::vector<int>, std::complex<double>>& f, const std::map<std::vector<int>, std::complex<double>>& g);
std::map<std::vector<int>, std::complex<double>> operator+(const std::map<std::vector<int>, std::complex<double>>& f, const std::map<std::vector<int>, std::complex<double>>& g);
std::map<std::vector<int>, std::complex<double>> S(std::map<std::vector<int>, std::complex<double>>&f, std::map<std::vector<int>, std::complex<double>>&g);
bool check(std::map<std::vector<int>, std::complex<double>>&f, std::map<std::vector<int>, std::complex<double>>&g);
void print(const std::map<std::vector<int>, std::complex<double>>& f);
void input(std::map<std::vector<int>, std::complex<double>>& polynom,int n);
