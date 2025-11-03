#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
double lagr(double*, double*, double, double);
double g(double);
int main(void) {
	setlocale(LC_ALL, "Rus");
	double a = 0, b = 1, res, t = M_PI_4/3;
	int n = 100,i;
	double* x;
	double* f;
	x = (double*)malloc(n * sizeof(double));
	if (!x) { printf("x[] not created\n"); return -1; }
	f = (double*)malloc(n * sizeof(double));
	x[0] = a;
	f[0] = g(x[0]);
	for (i = 1; i < n; i++) {
		x[i] = x[i - 1] + ((b - a) / n);
		f[i] = g(x[i]);
	}
	res = lagr(x, f, t, n);
	printf("lagr = %le\tg = %le\totn =%le\n", res, g(t), (res / g(t)) - 1);


	return 0;
}
double g(double x) {
	return sin(x);
}
double lagr(double* x, double* f, double t, double n) {
	double sum = 0, sum1 = 1;
	int i, j;
	for (j = 0; j < n; j++) {
		for (i = 0; i < n; i++) {
			if (i != j) sum1 *= (t - x[i]) / (x[j] - x[i]);
		}
		sum += f[j] * sum1;
		sum1 = 1;
	}
	return sum;

}