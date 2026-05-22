//Аппроксимация функции

#include <stdio.h>

#define MAX 100

int main() {
    int n;
    double x[MAX], y[MAX];
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    double a, b;

    printf("Введите количество точек: ");
    scanf("%d", &n);

    printf("Введите точки x и y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);

        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    a = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    b = (sumY - a * sumX) / n;

    printf("\nАппроксимирующая функция:\n");
    printf("y = %.6lf * x + %.6lf\n", a, b);

    return 0;
}