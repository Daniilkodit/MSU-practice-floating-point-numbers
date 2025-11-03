#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int test5(double*, double*, double**, double**, int, int);
int main(void) {
	int n = 5, m = 5, i;
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

	test5(x, y, z, w, n, m);
	return 0;
}
int test5(double* x, double* y, double** z, double** w, int n, int m) {
	int i, j;
	double v;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			x[i * m + j] = abs(i-j); y[i + j * n] = abs(i - j);
			z[i][j] = abs(i - j); w[j][i] = abs(i - j);

		}
	}
	printf("test5:\n");
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
	v = (double)n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if ((i == 0 && j == n - 1) || (i == n - 1 && j == 0)) {
				x[i * m + j] = (1 / (2.0 * v - 2.0)); y[i + j * n] = (1 / (2.0 * v - 2.0));
				z[i][j] = (1 / (2.0 * v - 2.0)); w[j][i] = (1 / (2.0 * v - 2.0));
			}
			else if (i == j && (j == n - 1 || j==0)) {
				x[i * m + j] = -((v-2.0)/(2.0*v-2.0)); y[i + j * n] = -((v - 2.0) / (2.0 * v - 2.0));
				z[i][j] = -((v - 2.0) / (2.0 * v - 2.0)); w[j][i] = -((v - 2.0) / (2.0 * v - 2.0));
			}
			else if (i==j) {
				x[i * m + j] = -1; y[i + j * n] = -1;
				z[i][j] = -1; w[j][i] = -1;
			}
			else if (abs(i -j) == 1) {
				x[i * m + j] = 0.5; y[i + j * n] = 0.5;
				z[i][j] = 0.5; w[j][i] = 0.5;
			}
			else {
				x[i * m + j] = 0; y[i + j * n] = 0;
				z[i][j] = 0; w[j][i] = 0;
			}
		}
	}
	printf("test5^-1:\n");
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
