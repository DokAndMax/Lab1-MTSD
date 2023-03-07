#pragma once
class QuadraticEquation
{
public:
	QuadraticEquation(int, int, int);
	int GetDiscriminant();
	short GetRootsNumber();
	void GetRoots(double*, double*);
	void GetStrEquation(wchar_t[256]);

private:
	int a;
	int b;
	int c;
};

