#pragma once

#include<vector>

std::vector<int> operator+(const std::vector<int>& a, const std::vector<int>& b);

std::vector<int> operator-(const std::vector<int>& a, const std::vector<int>& b);

std::vector<int> LCM(const std::vector<int>& a, const std::vector<int>& b);

std::vector<int> GCD(std::vector<int>& a, std::vector<int>& b);

bool checked(std::vector<int>& a, std::vector<int>& b);

bool division(const std::vector<int>& a,const std::vector<int>& b);

