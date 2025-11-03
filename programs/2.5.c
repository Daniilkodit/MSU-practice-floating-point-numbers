#include <stdio.h>
#include <math.h>
double my_exp(double);
int main(void) {
    double x = -40.0;
    printf("my_exp = %le,exp(x) = %le, delta_x =%le\n", my_exp(x), exp(x), (my_exp(x) / exp(x)) - 1);
    return 0;

}
double my_exp(double x)
{
    double sum = 1.0, h, eps = 1.e-16;
    int i = 2, q = 1;;
    if (x < 0) { x = fabs(x); q = 0; }
    h = x;
    do
    {
        sum += h;
        h *= x / i;
        i++;
    } while (fabs(h) > eps);
    if (q == 0) return 1 / sum;
    else return sum;
}
