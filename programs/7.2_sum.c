#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int matr_sum(double**, double**,double**x, int, int, int, int);
int main(void) {
	int i, j, n1 = 100, m1 = 10, n2 = 100, m2 = 10;
	double c = 1.e3, b = -1.e3;
	double** mt1;
	double** mt2;
	double** msum;
	mt1 = (double*)malloc(n1 * sizeof(double*));
	for (i = 0; i < n1; i++) {
		mt1[i] = (double*)malloc(m1 * sizeof(double**));
		for (j = 0; j < m1; j++) {
			mt1[i][j] = b + (double)rand() / (RAND_MAX / (c - b));
		}
	}
	mt2 = (double*)malloc(n2 * sizeof(double*));
	for (i = 0; i < n2; i++) {
		mt2[i] = (double*)malloc(m2 * sizeof(double**));
		for (j = 0; j < m2; j++) {
			mt2[i][j] = b + (double)rand() / (RAND_MAX / (c - b));
		}
	}
	msum = (double*)malloc(n1 * sizeof(double*));
	for (i = 0; i < n1; i++) {
		msum[i] = (double*)malloc(m1 * sizeof(double**));
	}
	matr_sum(mt1, mt2, msum, n1, m1, n2, m2);
	for (i = 0; i < n1; i++) {
		for (j = 0; j < m1; j++) {
			printf("%8lg ", mt1[i][j]);
		}
		printf("\t");
		for (j = 0; j < m1; j++) {
			printf("%8lg ", mt2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("matrix sum\n");
	for (i = 0; i < n1; i++) {
		for (j = 0; j < m1; j++) {
			printf("%8lg ", msum[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < n1; i++) {
		free(mt1[i]);
		free(msum[i]);
	}
	for (i = 0; i < n2; i++) {
		free(mt2[i]);
	}
	free(mt1);
	free(msum);
	free(mt2);
	
	return 0;
}
int matr_sum(double** z, double** y,double**x, int n1, int m1, int n2, int m2) {
	if (n1 != n2 || m1 != m2) { printf("Not sum matrixs\n"); return -1; }
	int i, j;
	for (i = 0; i < n1; i++) {
		for (j = 0; j < m1; j++) {
			x[i][j] = z[i][j] + y[i][j];
		}
	}
	
	return 1;
}
