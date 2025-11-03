#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int matr_pr(double**, double**,double**, int, int, int, int);
int main(void) {
	int i, j, n1 = 6, m1 = 6, n2 = 6, m2 =6;
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
			mt1[i][j] = (double)1 / (i + j + 1);;
		}
	}
	mt2 = (double*)malloc(n2 * sizeof(double*));
	for (i = 0; i < n2; i++) {
		mt2[i] = (double*)malloc(m2 * sizeof(double**));
	}
	mt2[0][0] = (double)(n2 * n2);
	for (i = 0; i < n2; i++) {
		for (j = 0; j < m2; j++) {
			if (i == 0 && j != 0) {
				mt2[i][j] = (((i + j) % 2 == 0) ? 1.0 : -1.0) * ((double)((n2 - j) * (n2 + j)) / (double)(j * j * (j + 1))) * (fabs(mt2[i][j - 1]) * (double)j);
			}
			else if (j == 0 && i != 0) {
				mt2[i][j] = (((i + j) % 2 == 0) ? 1.0 : -1.0) * ((double)((n2 - i) * (n2 + i)) / (double)(i * i * (i + 1))) * (fabs(mt2[i - 1][j]) * (double)i);
			}
			else if (i != 0 && j != 0) {
				mt2[i][j] = (((i + j) % 2 == 0) ? 1.0 : -1.0) * ((double)((n2 - i) * (n2 + i) * (n2 - j) * (n2 + j)) / (double)(i * i * (i + 1 + j) * j * j)) * (fabs(mt2[i - 1][j - 1]) * (double)((i - 1) + (j - 1) + 1));
			}
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
			printf("%8lg ", product[i][j]);
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
