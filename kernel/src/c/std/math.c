#include "std/math.h"

long factorial(char n) {
	return n < 2 ? 1 : n * factorial(n - 1);
}

double pow(double x, double n) {
	if(n < 1)
		return 0;
	double result = x;
	for(double i = 1; i < n; i++)
		result *= x;
	return result;
}