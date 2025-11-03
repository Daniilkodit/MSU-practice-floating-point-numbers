#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int matr_pr(double**, double**, double**, int, int, int, int);
int main(void) {
	int i, j, n1 = 7, m1 = 7, n2 = 7, m2 = 1;
	double c = 1.e3, b = -1.e3;
	double** mt1;
	double** mt2;
	double** product = NULL;
	product = (double*)malloc(n1 * sizeof(double*));
	for (i = 0; i < n1; i++) {
		product[i] = (double*)malloc(m2 * sizeof(double**));
		for (j = 0; j < m2; j++) {
			product[i][j] = 0;
		}
	}
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
	matr_pr(mt1, mt2, product, n1, m1, n2, m2);
	for (i = 0; i < n1; i++) {
		for (j = 0; j < m1; j++) {
			printf("%8lg ", mt1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < n2; i++) {
		for (j = 0; j < m2; j++) {
			printf("%8lg ", mt2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("matrix product\n");
	for (i = 0; i < n1; i++) {
		for (j = 0; j < m2; j++) {
			printf("%8le ", product[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < n1; i++) {
		free(product[i]);
		free(mt1[i]);
	}
	for (i = 0; i < n2; i++) {
		free(mt2[i]);
	}
	free(product);
	free(mt1);
	free(mt2);
	return 0;
}
int matr_pr(double** z, double** y, double** x, int n1, int m1, int n2, int m2) {
	if (m1 != n2) { printf("Not product matrix\n"); return -1; }
	int i, j, q;
	for (i = 0; i < n1; i++) {
		for (j = 0; j < m2; j++) {
			for (q = 0; q < m1; q++) {
				x[i][j] += z[i][q] * y[q][j];
			}
		}
	}
	return 1;
}
