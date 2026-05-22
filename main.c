#include <stdio.h>

#define MAX 100
#define EPS 0.0001
#define MAX_ITER 1000

double my_abs(double x) {
    return x < 0 ? -x : x;
}

int main() {
    int n;
    double a[MAX][MAX];
    double b[MAX];
    double x[MAX];
    double x_new[MAX];

    printf("Введите количество неизвестных: ");
    scanf("%d", &n);

    printf("Введите матрицу коэффициентов:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    printf("Введите свободные члены:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    // Начальное приближение
    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }

    int iter = 0;

    while (iter < MAX_ITER) {
        double max_diff = 0;

        for (int i = 0; i < n; i++) {
            double sum = b[i];

            for (int j = 0; j < n; j++) {
                if (j != i) {
                    sum -= a[i][j] * x[j];
                }
            }

            x_new[i] = sum / a[i][i];

            double diff = my_abs(x_new[i] - x[i]);

            if (diff > max_diff) {
                max_diff = diff;
            }
        }

        // Обновление значений
        for (int i = 0; i < n; i++) {
            x[i] = x_new[i];
        }

        iter++;

        if (max_diff < EPS) {
            break;
        }
    }

    printf("\nРешение системы:\n");

    for (int i = 0; i < n; i++) {
        printf("x%d = %.6lf\n", i + 1, x[i]);
    }

    printf("Количество итераций: %d\n", iter);

    return 0;
}