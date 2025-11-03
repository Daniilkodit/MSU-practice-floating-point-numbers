#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int metod(double*, double*, int,double*,double*);
int main(void) {
	double err, eps = 0.3, a = 0.5, b=1, x_min = 1 ,dx = 10,a1,b1;
	double* x;
	double* y;
	int n = 100,i;
	x = (double*)malloc(n * sizeof(double));
	if (!x) { printf("x[] not created\n"); return -1; }
	y = (double*)malloc(n * sizeof(double));
	if (!y) { printf("y[] not created\n"); return -1; }
	for (i = 0; i < n; i++) {
		x[i] = x_min + ((dx * rand()) / RAND_MAX);
		err = eps * ((2.0 * rand()) / (RAND_MAX - 1.0));
		y[i] = a * x[i] + b + err;
	}
	metod(x, y, n,&a1,&b1);
	printf("otn_a = %le\totn_b = %le\ta1 = %le\tb1= %le\n", fabs((a / a1) - 1), fabs((b / b1) - 1), a1, b1);

	return 0;
}
int metod(double*x, double*y, int n, double*a, double*b) {
	int i;
	double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, v;
	for (i = 0; i < n; i++) {
		sum1 += x[i];
		sum2 += y[i];
		sum3 += x[i] * y[i];
		sum4 += x[i] * x[i];
	}
	v = (double)n;
	if (fabs(sum4 * v - (sum1 * sum1)) < 1.e-14) {printf("znam  =0\n"); return 1;}
	*a = (sum3 * v - (sum1 * sum2)) / (sum4 * v - (sum1 * sum1));
	*b = (sum2 - ((*a) * sum1)) / v;
	return 0;
}