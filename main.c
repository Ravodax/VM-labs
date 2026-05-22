//Нахождение экстремумов функции методом Золотого сечения

#include <stdio.h>

#define EPS 0.000001

double my_abs(double x) {
    return x < 0 ? -x : x;
}

// Функция
double f(double x) {
    return x * x - 4 * x + 5;
}

int main() {
    double a, b;
    double x1, x2;
    double f1, f2;

    // коэффициент золотого сечения
    double phi = 0.6180339887;

    printf("Введите границы интервала: ");
    scanf("%lf %lf", &a, &b);

    x1 = b - phi * (b - a);
    x2 = a + phi * (b - a);

    f1 = f(x1);
    f2 = f(x2);

    while (my_abs(b - a) > EPS) {

        if (f1 < f2) {
            b = x2;

            x2 = x1;
            f2 = f1;

            x1 = b - phi * (b - a);
            f1 = f(x1);
        }
        else {
            a = x1;

            x1 = x2;
            f1 = f2;

            x2 = a + phi * (b - a);
            f2 = f(x2);
        }
    }

    double xmin = (a + b) / 2.0;
    double ymin = f(xmin);

    printf("Минимум функции:\n");
    printf("x = %.6lf\n", xmin);
    printf("f(x) = %.6lf\n", ymin);

    return 0;
}