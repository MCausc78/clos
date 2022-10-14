#include "std/math.h"

long factorial(long n) {
	if(n == 0) {
		return 1;
	} else {
		long result = 1;
		for(long i = 0; i < n; i++)
			result *= i;
		return result;
	}
}

double pow(double x, double n) {
	if(n < 1)
		return 0;
	double result = x;
	for(double i = 1; i < n; i++)
		result *= x;
	return result;
}