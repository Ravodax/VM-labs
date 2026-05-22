// Метод хорд

#include <stdio.h>

#define EPS 0.000001

double my_abs(double x) {
    return x < 0 ? -x : x;
}

double f(double x) {
    return x * x * x - x - 2;
}

int main() {
    double x0 = 1;
    double x1 = 2;
    double x2;

    while (my_abs(x1 - x0) > EPS) {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));

        x0 = x1;
        x1 = x2;
    }

    printf("Корень: %.6lf\n", x2);

    return 0;
}