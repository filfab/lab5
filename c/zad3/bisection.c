#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef double (*functype)(double);
double find_zero(functype f, double a, double b, double eps) {
    if (a >= b) {
        printf("Given arguments don't make a range [ a>=b ]"); exit(-1);
    }

    double fa = f(a);
    double fb = f(b);
    if ((fa<0 && fb<0) || (fa>0 && fb>0)) {
        printf("Same sign in range ends [ f(a)*f(b) > 0 ]"); exit(-1);
    }

    double x, y, h;
    while (1) {
        x = (a+b)/2;
        y = f(x);
        h = (b-a)/2;

        if (y==0 || (h<eps && h>-eps)) { return x; }

        h = f(a);
        if ((y<0 && h<0) || (y>0 && h>0)) {
            a = x;
        } else {
            b = x;
        }
    }
}

double func(double x) {
    return cos(x/2);
}

int main() {
    // double a, b;
    // if (scanf("%lf", &a)!=1 || scanf("%lf", &b)!=1) {
    //     printf("Bad argument"); return -1;
    // }

    double epsilon = 1;
    for (int i=1; i<=8; i++) {
        epsilon *= 0.1;
        printf("10^%d : %.*lf\n", -i, i, find_zero(func, 2, 4, epsilon));
    }
    return 0;
}