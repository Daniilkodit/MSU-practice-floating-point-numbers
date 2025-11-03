#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double my_sqrt(double, double);
double k_sqrt(double, double);
int main(void) {
	double a = 2193102391.32103124, x = 1;
	printf("my_sqrt(x) = %le,sqrt(x)=%le,delta = %le\n", my_sqrt(a, x), sqrt(a), (my_sqrt(a,x) / sqrt(a)) - 1);
	printf("k_sqrt(x) = %le,c_sqrt(x)=%le,delta = %le\n", k_sqrt(a, x), cbrt(a), (k_sqrt(a, x) / cbrt(a)) - 1);
	return 0;
}
double my_sqrt(double a, double x0) {
	int k = 0;
	while (k < 100) {
		k++;

		x0 = 0.5 * (x0 + a / x0);
	}
	return x0;
}
double k_sqrt(double a, double x0) {
	int k = 0;
	while (k < 100) {
		k++;
		x0 = (2*x0 + (a / (x0*x0)))/3;
	}
	return x0;
}