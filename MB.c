// Метод бисекций

#include <stdio.h>

#define EPS 0.000001

double my_abs(double x) {
    return x < 0 ? -x : x;
}

// Функция
double f(double x) {
    return x * x * x - x - 2;
}

int main() {
    double a = 1;
    double b = 2;
    double c;

    if (f(a) * f(b) > 0) {
        printf("На отрезке нет корня.\n");
        return 0;
    }

    while ((b - a) > EPS) {
        c = (a + b) / 2.0;

        if (f(c) == 0) {
            break;
        }

        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    printf("Корень: %.6lf\n", c);

    return 0;
}