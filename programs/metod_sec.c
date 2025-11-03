#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int nf;
int sign(double);
int root_hords(double*, double, double b, double(*f)(double), double);
int root_sec(double*, double, double b, double(*f)(double), double);
double f(double);
int main(void) {
    double x, a = -1, b = 10;
    int res1;
    int res2;
    nf = 0;
    res1 = root_hords(&x, a, b, f, 1.e-15);
    if (res1 > 0) printf("metod_hords:x = %le,iteration = %d,vizov =%d\n", x, res1, nf);
    else printf("metod_hords:iteration = %d,vizov =%d,metod ne primenim\n", res1, nf);
    nf = 0;
    res2 = root_sec(&x, a, b, f, 1.e-15);
    if (res2 > 0) printf("metod_sec:x = %le,iteration = %d,vizov =%d\n", x, res2, nf);
    else printf("metod_sec:iteration = %d,vizov =%d,metod ne primenim\n", res2, nf);

    return 0;
}
int sign(double x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}
int root_hords(double* x, double a, double b, double(*f)(double), double eps) {
    double c1 = a, c2 = b, q = 1, c, fa, fb, fc, ifa, ifb, ifc;
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
int root_sec(double* x, double a, double b, double(*f)(double), double eps) {
    double x1 = a, x2 = b,fa, fb,ifa, ifb;
    int k = 0;
    fa = f(a);
    fb = f(b);
    if (fabs(fa) < eps) { *x = a; return 1; }
    if (fabs(fb) < eps) { *x = b; return 1; }
    ifa = sign(fa);
    ifb = sign(fb);
    if (ifa * ifb != -1) return 0;
    while (fabs(x1-x2)>eps && k<100) {
        k++;
        x1 = b - (b - a) * fb / (fb - fa);
        fa = f(x1);
        a = x1;
        x2 = a - (a - b) * fa / (fa - fb);
        fb = f(x2);
        b = x2;
        
        if (fabs(fb) < eps) { *x = x2; return k; }
    }
    *x = x2;
    return k;

}
double f(double x) {
    nf++;
    return x/(1+x*x);
}