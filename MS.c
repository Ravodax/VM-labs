//Метод Симпсона

#include <stdio.h>

double f(double x) {
    return x * x;   // функция y = x^2
}

int main() {
    int n;
    double a, b, h, sum, result;

    printf("Введите a, b и n: ");
    scanf("%lf %lf %d", &a, &b, &n);

    if (n % 2 != 0) {
        printf("Для метода Симпсона n должно быть четным.\n");
        return 0;
    }

    h = (b - a) / n;

    sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            sum += 2 * f(a + i * h);
        } else {
            sum += 4 * f(a + i * h);
        }
    }

    result = h * sum / 3.0;

    printf("Интеграл = %.6lf\n", result);

    return 0;
}