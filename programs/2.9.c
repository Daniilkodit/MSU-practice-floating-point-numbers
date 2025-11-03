#include <stdio.h>
#include <math.h>
#define RAND_MAX 32767
int kv1(double, double, double*, double*);
int kv2(double, double, double*, double*);
int x_sign(double);
double frand(double, double);
int main(void) {
	double x1, x2, y1, y2;
	double a1, a2;
	double b, c,p1 = pow(10, 7), p2 = pow(10,9);
	int i = 0;
	for (i = 0; i < 10; i++) {
		a1 = frand(p1, p2);
		a2 = frand(-100.0,100.0);
		printf("%d; a1 = %le;,a2 =%le\n",i+1, a1, a2);
		b = -(a1 + a2);
		c = a1 * a2;
		
		if (kv1(b, c, &y1, &y2) == 0 || kv2(b, c, &x1, &x2) == 0) { printf("d<0\n"); break; }
		if (fabs(y1 * y1 + b * y1 + c) < fabs(y2 * y2 + b * y2 + c)) printf("Y; neyvaz = %le\n", fabs(y1 * y1 + b * y1 + c));
		else printf("Y; neyvaz = %le\n", fabs(y2 * y2 + b * y2 + c));
		if (fabs(x1 * x1 + b * a1 + c) < fabs(x2 * x2 + b * x2 + c)) printf("X; neyvaz = %le\n", fabs(x1 * x1 + b * x1 + c));
		else printf("X; neyvaz = %le\n", fabs(x2 * x2 + b * x2 + c));
		if (x_sign(b) > 0) printf("%d; y1 = %le,y2 = %le, x1 =%le, x2 = %le, delta(y1-x1) =%le, delta(y2 -x2) = %le\n",i+1, y1, y2, x2, x1, fabs(y1 - x2), fabs(y2 - x1));
		else printf("%d; y1 = %le,y2 = %le, x1 =%le, x2 = %le, delta(y1-x1) =%le, delta(y2 -x2) = %le\n",i+1, y1, y2, x1, x2, fabs(y1 - x1), fabs(y2 - x2));
		printf("\n");
	}
	return 0;
}
int kv1(double b, double c, double* x1, double* x2){
	double d;
	d = b * b - 4 * c;
	if (d < 0) return 0;
	*x1 = (-b + sqrt(d)) / 2;
	*x2 = (-b - sqrt(d)) / 2;
	return 1;
}
int kv2(double b, double c, double* x1, double* x2) {
	double d;
	d = b * b - 4 * c;
	if (d < 0) return 0;
	*x1 = -(b + (x_sign(b) * sqrt(d)))/2;
	*x2 = c / (*x1);
	return 1;
}
int x_sign(double x) {
	if (x > 0) return 1;
	else return -1;
}
double frand(double min, double max){
	double range = (max - min);
	double div = RAND_MAX / range;
	return min + ((double)rand() / div);
}