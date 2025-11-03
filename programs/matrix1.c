#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int test1(double*,double*,double**,double**,int,int);
int main(void) {
	int n = 10, m = 10,i;
	double* x = NULL;/*хранение по строкам одномерный массив*/
	double* y = NULL;/*хранение по столбцам одномерный массив*/
	double** z = NULL;/*хранение по строкам двумерный массив*/
	double** w = NULL;/*хранение по столбцам двумерный массив*/
	x = (double*)malloc(n*m * sizeof(double));
	if (!x) { printf("x[] not created\n"); return -1; }
	y = (double*)malloc(n*m * sizeof(double));
	if (!y) { printf("y[] not created\n"); return -1; }
	z = (double*)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++) {
		z[i] = (double*)malloc(m * sizeof(double**));
	}
	w = (double*)malloc(m * sizeof(double*));
	for (i = 0; i < m; i++) {
		w[i] = (double*)malloc(n * sizeof(double**));
	}

	test1(x, y, z, w, n, m);
	return 0;
}
int test1(double* x,double*y,double**z,double**w,int n,int m) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (i <= j) { 
				x[i * m + j] = n - j; y[i + j * n] = n - j;
				z[i][j] = n - j; w[j][i] = n - j;
			}
			else { 
				x[i * m + j] = n - i; y[i + j * n] = n - i;
				z[i][j] = n - i; w[j][i] = n - i;
			}
		}
	}
	printf("test1:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%2lg ", x[i * m + j]);
		}
		printf("\t");
		for (j = 0; j < m; j++) {
			printf("%2lg ", y[i + j * n]);
		}
		printf("\t");
		for (j = 0; j < m; j++) {
			printf("%2lg ", z[i][j]);
		}
		printf("\t");
		for (j = 0; j < m; j++) {
			printf("%2lg ", w[j][i]);
		}
		printf("\n");
	}
	printf("\n");
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (i == j && i==0) {
				x[i * m + j] = 1; y[i + j * n] = 1;
				z[i][j] = 1; w[j][i] = 1;
			}
			else if(i == j) {
				x[i * m + j] = 2; y[i + j * n] = 2;
				z[i][j] = 2; w[j][i] = 2;
			}
			else if (abs(i - j) == 1) {
				x[i * m + j] = -1; y[i + j * n] = -1;
				z[i][j] = -1; w[j][i] = -1;
			}
			else {
				x[i * m + j] = 0; y[i + j * n] = 0;
				z[i][j] = 0; w[j][i] = 0;
			}
		}
	}
	printf("test1^-1:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%2lg ", x[i * m + j]);
		}
		printf("\t");
		for (j = 0; j < m; j++) {
			printf("%2lg ", y[i + j * n]);
		}
		printf("\t");
		for (j = 0; j < m; j++) {
			printf("%2lg ", z[i][j]);
		}
		printf("\t");
		for (j = 0; j < m; j++) {
			printf("%2lg ", w[j][i]);
		}
		printf("\n");
	}
	printf("\n");
	return 1;
}
