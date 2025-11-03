#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
double lagr(double*, double*, double, double);
double g(double);
int main(void) {
	setlocale(LC_ALL, "Rus");
	double M = 1.e4, a = 0, b = 1, q = 1;
	int n, k = 50;
	double res;
	for (n = 1; n <= k; n++) {
		double t, f_max = 0;
		double* x;
		double* f;
		int i, j;
		x = (double*)malloc(n * sizeof(double));
		if (!x) { printf("x[] not created\n"); return -1; }
		f = (double*)malloc(n * sizeof(double));
		x[0] = a;
		f[0] = g(x[0]);
		for (i = 1; i < n; i++) {
			x[i] = x[i-1] + (b-a)/n;
			f[i] = g(x[i]);
		}
		for (j = 0; j <= M; j++) {
			t = (double)j / M;
			res = fabs(lagr(x, f, t, n) - g(t));
			if (res > f_max) f_max = res; 

		}
		q *= 2*n;
		printf("n=%d\tpogr = %le\t pogr(1/(n*2^n) = %le\n",n, f_max, (double)1 / q);

	}
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