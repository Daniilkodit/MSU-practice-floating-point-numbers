#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int jg(double**, double*, int);
int matr_pr(double**, double*, double*, int);
int gil_E(double**, int);
int main(void) {
	int n = 1000, i, j, norm1 = 0, norm1nev = 0, norm2 = 0, norm3 = 0, norm2nev = 0, norm3nev = 0;
	clock_t st, end;
	double time;
	double** a = NULL;
	double* b = NULL;
	double* x0 = NULL;
	double* x1 = NULL;
	double* b1 = NULL;
	a = (double*)malloc(n * sizeof(double*));
	x0 = (double*)malloc(n * sizeof(double));
	b = (double*)malloc(n * sizeof(double));
	x1 = (double*)malloc(n * sizeof(double));
	b1 = (double*)malloc(n * sizeof(double));
	for (i = 0; i < n; i++) {
		a[i] = (double*)malloc(n * sizeof(double**));
		x0[i] = ((i % 2 == 0) ? 1.0 : -1.0);
		b[i] = 0;
	}
	gil_E(a, n);
	
	matr_pr(a, x0, b, n);
	
	x1 = b;
	st = clock();
	jg(a, x1, n);
	end = clock();

	time = (double)(end - st) / CLOCKS_PER_SEC;

	printf("time:\t %lf\n", time);
	matr_pr(a, x1, b1, n);
	for (i = 0; i < n; i++) {
		norm1 += fabs(x0[i] - x1[i]);
		norm1nev += fabs(b1[i] - b[i]);
		norm2 += (x0[i] - x1[i]) * (x0[i] - x1[i]);
		norm2nev += (b1[i] - b[i]) * (b1[i] - b[i]);
		if (norm3 < fabs(x0[i] - x1[i])) norm3 = fabs(x0[i] - x1[i]);
		if (norm3nev < fabs(b1[i] - b[i])) norm3nev = fabs(b1[i] - b[i]);
	}
	norm2 = sqrt(norm2);
	norm2nev = sqrt(norm2nev);
	printf("norm1 = %le\t norm1nev = %le\nnorm2 = %le\t norm2nev = %le\nnorm3 = %le\t norm3nev = %le\n", norm1, norm1nev, norm2, norm2nev, norm3, norm3nev);
	return 0;
}
int matr_pr(double** z, double* y, double* x, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			x[i] += z[j][i] * y[j];
		}
	}
	return 1;
}
int gil_E(double** x, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			x[j][i] = ((double)1 / (i + j + 1));
		}
	}
	for (i = 0; i < n; i++) {
		x[i][i] += 1.0;
	}
}
int jg(double** a, double* b, int n) {
	int i, j, l = 0, p, q, k;
	double swap, m;
	for (i = 0; i < n; i++) {
		l = i;
		for (j = i; j < n; j++) {
			if (fabs(a[i][l]) < fabs(a[i][j]))  l = j;
		}
		for (j = i; j < n; j++) {
			swap = a[j][i];
			a[j][i] = a[j][l];
			a[j][l] = swap;
		}
		swap = b[i];
		b[i] = b[l];
		b[l] = swap;
		for (j = i + 1; j < n; j++) {
			a[j][i] /= a[i][i];
		}
		b[i] /= a[i][i];
		a[i][i] = 1;

		for (k = 0; k < n; k++) {
			m = a[i][k];
			for (j = 0; j < n; j++) {
				if (k >= i + 1 && j >= i) a[j][k] -= a[j][i] * m;
				if (k < i && j >= i) a[j][k] -= a[j][i] * m;
			}
			if (k >= i + 1) b[k] -= b[i] * m;
			if (k < i) b[k] -= b[i] * m;
		}
	}
	
	return 0;
}