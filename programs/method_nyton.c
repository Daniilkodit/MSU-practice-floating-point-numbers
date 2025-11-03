#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int nf;
int sign(double);
int root_nyton(double*, double, double(*f)(double), double(*g)(double), double);
double f(double);
double prf(double);
int main(void) {
    double x;
    int res;
    nf = 0;
    res = root_nyton(&x, -3.16, f, prf, 1.e-15);
    if (res > 1) printf("x = %le,iteration =%d,vizov =%d\n", x, res, nf);
    else printf("metod ne primenim\n");
    return 0;
}
int sign(double x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}
int root_nyton(double* x, double x0, double(*f)(double), double(*g)(double), double eps) {
    double fx = f(x0), pfx = g(x0);
    int k = 0;
    if (fabs(pfx) < eps) return -1;
    printf("f(x%d) = %le, g(x%d) = %le, x%d = %le\n", k, fx, k, pfx, k, x0);
    while ((fabs((1 / pfx) * fx) > eps) && k < 100) {
        if (fabs(fx) < eps) { *x = x0; return k; }
        k++;
        x0 = x0 - ((1 / pfx) * fx);
        pfx = g(x0);
        fx = f(x0);
        printf("f(x%d) = %le, g(x%d) = %le, x%d = %.13le\n", k, fx, k, pfx, k, x0);

    }
    *x = x0 - ((1 / pfx) * fx);
    return k;

}
double f(double x) {
    nf++;
    return 10 * atan(20 * x * x - 200) + sqrt(1 + x * x);
}
double prf(double x) {
    nf++;
    return (x / sqrt(1 + x * x)) + 400 * x / ((20 * x * x - 200) * (20 * x * x - 200) + 1);
}