#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int test5(double*, double*, double**, double**, int, int);
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

	test5(x, y, z, w, n, m);
	return 0;
}
int test5(double* x, double* y, double** z, double** w, int n, int m) {
	int i, j;
	double v;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			x[i * m + j] = (double)1/(i+j+1); y[i + j * n] = (double)1 / (i + j + 1);
			z[i][j] = (double)1 / (i + j + 1); w[j][i] = (double)1 / (i + j + 1);

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
	x[0] = n * n;
	y[0] = n * n;
	z[0][0] = n * n;
	w[0][0] = n * n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (i == 0 && j!=0) {
				x[i * m + j] = (((i + j) % 2 == 0) ? 1.0 : -1.0) * ((double)((n - j) * (n + j)) / (double)(j*j * (j + 1))) * fabs(x[i * m + j - 1]) * (double)j;
				y[i + j * n] = (((i + j) % 2 == 0) ? 1.0 : -1.0) * ((double)((n - j) * (n + j)) / (double)(j*j * (j + 1))) * fabs(y[i + (j - 1) * n]) * (double)j;
				z[i][j] = (((i + j) % 2 == 0) ? 1.0 : -1.0) * ((double)((n - j) * (n + j)) / (double)(j*j * (j + 1))) * fabs(z[i][j - 1]) * (double)j;
				w[j][i] = (((i + j) % 2 == 0) ? 1.0 : -1.0) * ((double)((n - j) * (n + j)) / (double)(j*j * (j + 1))) * fabs(w[j - 1][i]) * (double)j;
			}
			else if (j == 0 && i != 0) {
				x[i * m + j] = (((i + j) % 2 == 0) ? 1.0 : -1.0) * ((double)((n - i) * (n + i)) / (double)(i*i * (i + 1))) * fabs(x[(i - 1) * m + j]) * (double)i;
				y[i + j * n] = (((i + j) % 2 == 0) ? 1.0 : -1.0) * ((double)((n - i) * (n + i)) / (double)(i*i * (i + 1))) * fabs(y[i - 1 + j * n]) * (double)i;
				z[i][j] = (((i + j) % 2 == 0) ? 1.0 : -1.0) * ((double)((n - i) * (n + i)) / (double)(i*i * (i + 1))) * fabs(z[i - 1][j]) * (double)i;
				w[j][i] = (((i + j) % 2 == 0) ? 1.0 : -1.0) * ((double)((n - i) * (n + i)) / (double)(i*i * (i + 1))) * fabs(w[j][i - 1]) * (double)i;
			}
			else if (i!=0 && j!=0){
				x[i * m + j] = (((i + j) % 2 == 0) ? 1.0 : -1.0) * ((double)((n - i) * (n + i) * (n - j) * (n + j)) / (double)(i * i * (i + 1 + j) * j * j)) * fabs(x[(i - 1) * m + j - 1]) * (double)((i - 1) + (j - 1)+1);
				y[i + j * n] = (((i + j) % 2 == 0) ? 1.0 : -1.0) * ((double)((n - i) * (n + i) * (n - j) * (n + j)) / (double)(i * i * (i + 1 + j) * j * j)) * fabs(y[(i - 1) + (j - 1)*n]) * (double)((i - 1) + (j - 1) + 1);
				z[i][j] = (((i + j) % 2 == 0) ? 1.0 : -1.0) * ((double)((n - i) * (n + i) * (n - j) * (n + j)) / (double)(i * i * (i + 1 + j) * j * j)) * fabs(z[i - 1][j-1]) * (double)((i - 1) + (j - 1) + 1);
				w[j][i] = (((i + j) % 2 == 0) ? 1.0 : -1.0) * ((double)((n - i) * (n + i) * (n - j) * (n + j)) / (double)(i * i * (i + 1 + j) * j * j)) * fabs(w[j-1][i - 1]) * (double)((i - 1) + (j - 1) + 1);

			}
		}
	}
	printf("test5^-1:\n");
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
