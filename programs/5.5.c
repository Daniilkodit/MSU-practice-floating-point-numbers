#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double splain(double*, double*, double, int, double);
double g(double);
int main(void) {
	double M = 1.e5, a = 0, b = 1;
	int n, k = 200;
	double res;
	for (n = 100; n <= k; n++) {
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
			x[i] = x[i - 1] + (b - a) / n;
			f[i] = g(x[i]);
		}
		for (j = 0; j <= M; j++) {
			t = (double)j / M;
			res = fabs(splain(x, f, t, n,b) - g(t));
			if (res > f_max) f_max = res;

		}
		printf("n=%d\tpogr = %le\t pogr(1/(8*n^2) = %le\n", n, f_max, (double)1 / (8 * n * n));

	}
	return 0;
}
double g(double x) {
	return sin(x);
}
double splain(double* x, double* f, double t, int n, double b) {
	int i;
	for (i = 0; i < n - 1; i++) {
		if (t >= x[i] && t <= x[i + 1]) return f[i] + (f[i + 1] - f[i]) / (x[i + 1] - x[i]) * (t - x[i]);
	}
	return f[n - 1] + (((g(b) - f[n - 1]) / (b - x[n - 1])) * (t - x[n - 1]));

}