#include <stdio.h>
#include <math.h>
double my_sin(double);
int main(void) {
    double x = 3.1415926535;
    printf("my_sin(x)=%le, sin(x) =%le,delta = %le", my_sin(x), sin(x), (my_sin(x) / sin(x)) - 1);
    return 0;

}
double my_sin(double x) {
    double sum = 0, h, eps = 1.e-16,fact = 1,term=x;
    int i = 1,sign=1;
    h = x;
    while (fabs(term) > eps) {
        sum += sign * term;
        h *= x * x;
        fact *= 2 * i * (2 * i + 1);
        term = h / fact;
        i++;
        sign *= -1;
    }
    return sum;
}

