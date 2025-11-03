#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int test7_8(double*, double*, double**, double**, int, int);
int main(void) {
	int n = 4, m = 4, i;
	double* x = NULL;/*хранение по строкам одномерный массив*/
	double* y = NULL;/*хранение по столбцам одномерный массив*/
	double** z = NULL;/*хранение по строкам двумерный массив*/
	double** w = NULL;/*хранение по столбцам двумерный массив*/
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

	test7_8(x, y, z, w, n, m);
	return 0;
}
int test7_8(double* x, double* y, double** z, double** w, int n, int m) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			x[i * m + j] = (i <= j + n/2) ? ((double)1 / (i + j + 1)) : 0; y[i + j * n] = ((i <= j + n / 2) ? ((double)1 / (i + j + 1)) : 0);
			z[i][j] = ((i <= j + n / 2) ? ((double)1 / (i + j + 1)) : 0); w[j][i] = ((i <= j + n / 2) ? ((double)1 / (i + j + 1)) : 0);
		}
	}
	printf("test7:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%4lg ", x[i * m + j]);
		}
		printf("\t");
		for (j = 0; j < m; j++) {
			printf("%4lg ", y[i + j * n]);
		}
		printf("\t");
		for (j = 0; j < m; j++) {
			printf("%4lg ", z[i][j]);
		}
		printf("\t");
		for (j = 0; j < m; j++) {
			printf("%4lg ", w[j][i]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			x[i * m + j] = (i>n/2 && j<n/2) ?  0 : ((double)1 / (i + j + 1)); y[i + j * n] = (i > n / 2 && j < n / 2) ? 0 : ((double)1 / (i + j + 1));
			z[i][j] = (i > n / 2 && j < n / 2) ? 0 : ((double)1 / (i + j + 1)); w[j][i] = (i > n / 2 && j < n / 2) ? 0 : ((double)1 / (i + j + 1));
		}
	}
	printf("test8:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%4lg ", x[i * m + j]);
		}
		printf("\t");
		for (j = 0; j < m; j++) {
			printf("%4lg ", y[i + j * n]);
		}
		printf("\t");
		for (j = 0; j < m; j++) {
			printf("%4lg ", z[i][j]);
		}
		printf("\t");
		for (j = 0; j < m; j++) {
			printf("%4lg ", w[j][i]);
		}
		printf("\n");
	}
	printf("\n");
	return 1;
}
