#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int test6(double*, double*, double**, double**, int, int);
int main(void) {
	int n = 3, m = 3, i;
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

	test6(x, y, z, w, n, m);
	return 0;
}
int test6(double* x, double* y, double** z, double** w, int n, int m) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			x[i * m + j] = ((double)1 / (i + j + 1)); y[i + j * n] = ((double)1 / (i + j + 1));
			z[i][j] = ((double)1 / (i + j + 1)); w[j][i] = ((double)1 / (i + j + 1)) ;
		}
	}
	for (i = 0; i < n; i++) {
		x[i * m + i] += 1.0; y[i + i * n] += 1.0;
		z[i][i] += 1.0; w[i][i] += 1.0;
	}
	printf("test6:\n");
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
