#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double kub_splain(double*, double*, double*, double, int, double);
double g(double);
double dg(double);
int main(void) {
	double M = 1.e5, a = 0, b = 1;
	int n, k = 100;
	double res;
	for (n = 1; n <= k; n++) {
		double t, f_max = 0, v = (double)n;
		double* x;
		double* f;
		double* d;
		int i, j;
		x = (double*)malloc(n * sizeof(double));
		if (!x) { printf("x[] not created\n"); return -1; }
		f = (double*)malloc(n * sizeof(double));
		if (!f) { printf("f[] not created\n"); return -1; }
		d = (double*)malloc(n * sizeof(double));
		if (!d) { printf("d[] not created\n"); return -1; }
		for (i = 0; i < n; i++) {
			x[i] = a+i*(b-a)/n;
			f[i] = g(x[i]);
			d[i] = dg(x[i]);
		}
		for (j = 0; j <= M; j++) {
			t = (double)j / M;
			res = fabs(kub_splain(x, f, d, t, n, b) - g(t));
			if (res > f_max) f_max = res;

		}
		printf("n=%d\tpogr = %le\t pogr(1 / (384*n^4) = %le\n", n, f_max, 1 / (384.0 * v * v * v * v));

	}
	return 0;
}
double g(double x) {
	return sin(x);
}
double dg(double x) {
	return cos(x);
}
double kub_splain(double* x, double* f, double* d, double t, int n, double b) {
	int i;
	double c2, c3;
	for (i = 0; i < n - 1; i++) {
		if (t >= x[i] && t <= x[i + 1]) {
			c2 = (-2 * d[i] * (x[i + 1] - x[i]) + 3 * f[i + 1] - 3 * f[i] - d[i + 1] * (x[i + 1] - x[i])) / ((x[i + 1] - x[i]) * (x[i + 1] - x[i]));
			c3 = (d[i + 1] * (x[i + 1] - x[i]) - 2 * f[i + 1] + 2 * f[i] + d[i] * (x[i + 1] - x[i])) / ((x[i + 1] - x[i]) * (x[i + 1] - x[i]) * (x[i + 1] - x[i]));
			return f[i] + d[i] * (t - x[i]) + c2 * (t - x[i]) * (t - x[i]) + c3 * (t - x[i]) * (t - x[i]) * (t - x[i]);
		}
	}
	c2 = (-2 * d[n - 1] * (b - x[n - 1]) + 3 * g(b) - 3 * f[n - 1] - dg(b) * (b - x[n - 1])) / ((b - x[i]) * (b - x[i]));
	c3 = (dg(b) * (b - x[n - 1]) - 2 * g(b) + 2 * f[n - 1] + d[n - 1] * (b - x[n - 1])) / ((b - x[i]) * (b - x[i]) * (b - x[i]));
	return f[n - 1] + d[n - 1] * (t - x[n - 1]) + c2 * (t - x[n - 1]) * (t - x[n - 1]) + c3 * (t - x[n - 1]) * (t - x[n - 1]) * (t - x[n - 1]);
}