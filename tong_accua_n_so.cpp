#include <stdio.h>

void printSolution(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generatePositiveSolutions(int a, int n, int arr[], int index, int start) {
    if (index == n) {
        if (a == 0) {
            printSolution(arr, n);
        }
        return;
    }

    for (int i = start; i <= a; i++) {
        arr[index] = i;
        generatePositiveSolutions(a - i, n, arr, index + 1, i);
    }
}

int main() {
    int a, n;
    printf("Nhap a va n: ");
    scanf("%d %d", &a, &n);

    int arr[n];
    generatePositiveSolutions(a, n, arr, 0, 1);

    return 0;
}
