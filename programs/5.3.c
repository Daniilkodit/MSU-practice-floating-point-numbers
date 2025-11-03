#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
double lagr(double*, double*, double, double);
double g(double);
int main(void) {
	setlocale(LC_ALL, "Rus");
	double a = 0, b = 0.5, res, t, M = 1.e5,f_max = 0;
	int i, j;
	double* x;
	double* f;
	x = (double*)malloc(3 * sizeof(double));
	if (!x) { printf("x[] not created\n"); return -1; }
	f = (double*)malloc(3 * sizeof(double));
	x[0] = a;
	f[0] = g(x[0]);
	x[1] = (double)1/6;
	f[1] = g(x[1]);
	x[2] = b;
	f[2] = g(x[2]);
	for (j = 0; j <= M; j++) {
		t = (double)j / M;
		res = fabs(lagr(x, f, t, 3) - g(t));
		if (res > f_max) f_max = res;

	}
	res = lagr(x, f, t, 3);
	printf("pogr = %le\n", f_max);


	return 0;
}
double g(double x) {
	return sin(M_PI*x);
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