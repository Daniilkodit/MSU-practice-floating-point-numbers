#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int test9(double*, double*, double**, double**,double*, int, int);
int main(void) {
	int n = 3, m = 3, i;
	double* p = NULL;
	double* x = NULL;/*хранение по строкам одномерный массив*/
	double* y = NULL;/*хранение по столбцам одномерный массив*/
	double** z = NULL;/*хранение по строкам двумерный массив*/
	double** w = NULL;/*хранение по столбцам двумерный массив*/
	p = (double*)malloc(n * sizeof(double));
	for (i = 0; i < n; i++) {
		p[i] = sin((double)i+1);
	}
	x = (double*)malloc(n * m * sizeof(double));
	if (!x) { printf("x[] not created\n"); return -1; }
	y = (double*)malloc(n * m * sizeof(double));
	if (!y) { printf("y[] not created\n"); return -1; }
	z = (double*)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++) {
		z[i] = (double*)malloc(m * sizeof(double**));
	}
	w = (double*)malloc(m * sizeof(double*));
	for (i = 0; i < m; i++) {
		w[i] = (double*)malloc(n * sizeof(double**));
	}

	test9(x, y, z, w,p, n, m);
	return 0;
}
int test9(double* x, double* y, double** z, double** w,double*p, int n, int m) {
	int i, j,k=0;
	double pr = 1;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			while (k < j) { k++; pr *= p[i]; }
			x[i * m + j] = pr; y[i + j * n] = pr;
			z[i][j] = pr; w[j][i] = pr;
			pr = 1; k = 0;
		}
	}
	printf("test9:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%8lg ", x[i * m + j]);
		}
		printf("\t");
		for (j = 0; j < m; j++) {
			printf("%8lg ", y[i + j * n]);
		}
		printf("\t");
		for (j = 0; j < m; j++) {
			printf("%8lg ", z[i][j]);
		}
		printf("\t");
		for (j = 0; j < m; j++) {
			printf("%8lg ", w[j][i]);
		}
		printf("\n");
	}
	printf("\n");
	return 1;
}
