// Метод Нюютона

#include <stdio.h>

#define EPS 0.000001

double my_abs(double x) {
    return x < 0 ? -x : x;
}

double f(double x) {
    return x * x * x - x - 2;
}

// Производная
double df(double x) {
    return 3 * x * x - 1;
}

int main() {
    double x0 = 1.5;
    double x1;

    while (1) {
        x1 = x0 - f(x0) / df(x0);

        if (my_abs(x1 - x0) < EPS) {
            break;
        }

        x0 = x1;
    }

    printf("Корень: %.6lf\n", x1);

    return 0;
}