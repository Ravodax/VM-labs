// Интерполяция методом Ньютона

#include <stdio.h>

#define MAX 100

int main() {
    int n;
    double x[MAX], y[MAX];
    double table[MAX][MAX];
    double xp, yp;

    printf("Введите количество точек: ");
    scanf("%d", &n);

    printf("Введите x и y:\n");

    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
        table[i][0] = y[i];
    }

    // Таблица разделённых разностей
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            table[i][j] =
                (table[i + 1][j - 1] - table[i][j - 1]) /
                (x[i + j] - x[i]);
        }
    }

    printf("Введите значение x: ");
    scanf("%lf", &xp);

    yp = table[0][0];

    double mult = 1;

    // Формула Ньютона
    for (int i = 1; i < n; i++) {
        mult *= (xp - x[i - 1]);
        yp += table[0][i] * mult;
    }

    printf("Значение функции: %.6lf\n", yp);

    return 0;
}