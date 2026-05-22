#include <stdio.h>

#define MAX 100
#define EPS 0.000000001

double my_abs(double x) {
    return x < 0 ? -x : x;
}

int main() {
    int n;
    double a[MAX][MAX + 1];
    double x[MAX];

    printf("Введите количество неизвестных: ");
    scanf("%d", &n);

    printf("Введите расширенную матрицу системы:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    // Прямой ход метода Гаусса
    for (int k = 0; k < n; k++) {
        int maxRow = k;

        // Поиск главного элемента
        for (int i = k + 1; i < n; i++) {
            if (my_abs(a[i][k]) > my_abs(a[maxRow][k])) {
                maxRow = i;
            }
        }

        if (my_abs(a[maxRow][k]) < EPS) {
            printf("Система не имеет единственного решения.\n");
            return 0;
        }

        // Обмен строк
        for (int j = k; j <= n; j++) {
            double temp = a[k][j];
            a[k][j] = a[maxRow][j];
            a[maxRow][j] = temp;
        }

        // Обнуление элементов ниже главного
        for (int i = k + 1; i < n; i++) {
            double factor = a[i][k] / a[k][k];

            for (int j = k; j <= n; j++) {
                a[i][j] -= factor * a[k][j];
            }
        }
    }

    // Обратный ход
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];

        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }

        x[i] /= a[i][i];
    }

    printf("\nРешение системы:\n");

    for (int i = 0; i < n; i++) {
        printf("x%d = %.6lf\n", i + 1, x[i]);
    }

    return 0;
}