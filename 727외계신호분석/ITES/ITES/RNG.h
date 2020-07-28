#pragma once
#include<vector>
#include<iostream>
#include<math.h>
using namespace std;
class RNG
{
public:
	RNG(int n);
	void print();
private:
	vector<int> A;
};
