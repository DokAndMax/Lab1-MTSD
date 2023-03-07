#include "QuadraticEquation.h"
#include <stdio.h>
#include <cmath>
#include <exception>

QuadraticEquation::QuadraticEquation(int a, int b, int c) : a(a), b(b), c(c)
{
	if (a == 0)
		throw std::exception("Error. a cannot be 0\n");
}

int QuadraticEquation::GetDiscriminant()
{
	return (b * b) - (4 * a * c);
}

short QuadraticEquation::GetRootsNumber()
{
	int discriminant = GetDiscriminant();

	if (discriminant > 0)
		return 2;
	else if (discriminant == 0)
		return 1;
	else
		return 0;
}

void QuadraticEquation::GetRoots(double* x1, double* x2)
{
	int discriminant = GetDiscriminant();

	*x1 = (-b - sqrt(discriminant)) / (2 * a);
	*x2 = (-b + sqrt(discriminant)) / (2 * a);
}

void QuadraticEquation::GetStrEquation(wchar_t buff[256])
{
	swprintf(buff, 256, L"(%d) x^2 + (%d) x + (%d) = 0", a, b, c);
}
