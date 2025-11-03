#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int nf;
int sign(double);
int root_hords(double*, double,double,double(*f)(double),double);
double f(double);
int main(void) {
    double x, a = 0.3, b = 1;
    int res;
    nf = 0;
    res = root_hords(&x, a, b, f, 1.e-15);
    if (res > 0) printf("x = %le,iteration = %d,vizov =%d\n", x, res, nf);
    else printf("iteration = %d,vizov =%d,metod ne primenim\n", res, nf);
    return 0;
}
int sign(double x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}
int root_hords(double* x, double a,double b,double(*f)(double), double eps) {
    double c1 = a, c2 = b, q = 1,c, fa, fb, fc, ifa, ifb, ifc;
    int k = 0;
    fa = f(a);
    fb = f(b);
    if (fabs(fa) < eps) { *x = a; return 1; }
    if (fabs(fb) < eps) { *x = b; return 1; }
    ifa = sign(fa);
    ifb = sign(fb);
    if (ifa * ifb != -1) return 0;
    while (fabs(c1 - c2) > eps) {
        k++;
        if (q == 1) { c1 = ((a * fb - b * fa) / (fb - fa)); q = 2; c = c1; }
        else { c2 = ((a * fb - b * fa) / (fb - fa)); q = 1; c = c2; }
        fc = f(c);
        ifc = sign(fc);
        if (fabs(fc) < eps) { *x = c; return k; }
        if (ifa == ifc) { a = c; fa = fc; }
        else { b = c; fb = fc; }

    }
    *x = c;
    return k;

}
double f(double x) {
    nf++;
    return (1 / x) - 2;
}