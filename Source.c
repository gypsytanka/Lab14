#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

double* full_elements(double* ptr_array, int n);
int put_elements(double* ptr_array, int n);
double* calc_elements(double* ptr_array, int n);
double calc(double x);
double sum_elements(double* ptr_array, int begin, int end);
int find_element(double* ptr_array, int n, double element);
double find_min(double* ptr_array, int n, int k);

int main() {
    setlocale(LC_CTYPE, "RUS");
    double* ptr_array;
    int begin, end;
    int size;
    double element;
    int k;

    printf("Введите размер массива > ");
    scanf("%d", &size);

    ptr_array = (double*)malloc(size * sizeof(double));

    if (ptr_array == NULL) {
        puts("error");
        return -1;
    }

    printf("Введите индекс начального элемента: ");
    scanf("%d", &begin);
    printf("Введите индекс конечного элемента: ");
    scanf("%d", &end);
    printf("Введите элемент а: ");
    scanf("%lf", &element);
    printf("Введите позицию K для поиска минимума: ");
    scanf("%d", &k);

    full_elements(ptr_array, size);
    put_elements(ptr_array, size);
    calc_elements(ptr_array, size);

    printf("Сумма элементов с %d по %d: %.4f\n", begin, end, sum_elements(ptr_array, begin, end));

    int index = find_element(ptr_array, size, element);
    printf("Индекс элемента %.4f: %d\n", element, index);

    double min = find_min(ptr_array, size, k);
    printf("Минимальное значение после позиции %d: %.4f\n", k, min);

    free(ptr_array);
    return 0;
}

double calc(double x) {
    return fabs(log10(x)) - pow(x - 2, 2);
}

double* full_elements(double* ptr_array, int n) {
    float start = 2.0f;
    float end_val = 4.1f;
    float step = (end_val - start) / (n - 1);
    for (int i = 0; i < n; i++) {
        float x = start + i * step;
        ptr_array[i] = calc(x);
    }
    return ptr_array;
}

int put_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("[%d] = %.4f\n", i, ptr_array[i]);
    }
    printf("\n");
    return n;
}

double* calc_elements(double* ptr_array, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += ptr_array[i];
    }
    double sr = sum / n;

    printf("Среднее арифметическое: %.4f\n", sr);

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] < sr) {
            count++;
        }
    }

    printf("Количество элементов меньше среднего: %d\n\n", count);
    return ptr_array;
}

double sum_elements(double* ptr_array, int begin, int end) {
    double sum = 0.0;
    if (begin < 0) begin = 0;
    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }
    return sum;
}

int find_element(double* ptr_array, int n, double element) {
    for (int i = 0; i < n; i++) {
        if (fabs(ptr_array[i] - element) < 0.001) {
            return i;
        }
    }
    return -1;
}

double find_min(double* ptr_array, int n, int k) {
    double min = ptr_array[k + 1];

    for (int i = k + 1; i < n; i++) {
        if (ptr_array[i] < min) {
            min = ptr_array[i];
        }
    }
    return min;
}