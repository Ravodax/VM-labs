// Метод трапеций

#include <stdio.h>

double f(double x) {
    return x * x;   // функция y = x^2
}

int main() {
    int n;
    double a, b, h, sum, result;

    printf("Введите a, b и n: ");
    scanf("%lf %lf %d", &a, &b, &n);

    h = (b - a) / n;

    sum = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }

    result = h * sum;

    printf("Интеграл = %.6lf\n", result);

    return 0;
}