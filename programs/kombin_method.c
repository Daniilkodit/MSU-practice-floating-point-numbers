#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int nf;
int sign(double);
int root_kombin(double*, double, double, double(*f)(double), double);
double f(double);
int main(void) {
    double x, a = -2, b = 15;
    int res;
    nf = 0;
    res = root_kombin(&x, a, b, f, 1.e-15);
    if (res > 0) printf("x = %le,iteration = %d,vizov =%d\n", x, res, nf);
    else printf("iteration = %d,vizov =%d,metod ne primenim\n", res, nf);
    return 0;
}
int sign(double x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}
int root_kombin(double* x, double a, double b, double(*f)(double), double eps) {
    double q=1,c1 = a, c2 = b, c, fa, fb, fc, ifa, ifb, ifc;
    int k = 0;
    fa = f(a);
    fb = f(b);
    if (fabs(fa) < eps) { *x = a; return 1; }
    if (fabs(fb) < eps) { *x = b; return 1; }
    ifa = sign(fa);
    ifb = sign(fb);
    if (ifa * ifb != -1) return 0;
    while (fabs(a - b) > eps && k<1000) {
        k++;
        q *=0.5;
        c1 = ((a * fb - b * fa) / (fb - fa)); 
        c2 = (a + b) / 2;
        c = q * c1 + (1 - q) * c2;
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
    return atan(x-M_PI);
}