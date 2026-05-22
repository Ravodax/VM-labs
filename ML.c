// Метод Лагранжа

#include <stdio.h>

#define MAX 100

int main() {
    int n;
    double x[MAX], y[MAX];
    double xp, yp = 0;

    printf("Введите количество точек: ");
    scanf("%d", &n);

    printf("Введите x и y:\n");

    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    printf("Введите значение x: ");
    scanf("%lf", &xp);

    // Формула Лагранжа
    for (int i = 0; i < n; i++) {
        double L = 1;

        for (int j = 0; j < n; j++) {
            if (i != j) {
                L *= (xp - x[j]) / (x[i] - x[j]);
            }
        }

        yp += y[i] * L;
    }

    printf("Значение функции: %.6lf\n", yp);

    return 0;
}