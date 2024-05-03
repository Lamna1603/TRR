#include <stdio.h>
int count = 0;
void generateSolutions(int x[], int index, int n, int k) {
    if (index == n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += x[i];
        }
        if (sum == k) {
            count++;
        }
        return;
    }
    for (int i = 0; i <= k; i++) {
        x[index] = i;
        generateSolutions(x, index + 1, n, k);
    }
}
int main() {
    int n, k;
    printf("nhap so bien n: ");
    scanf("%d", &n);
    printf("nhap tong k: ");
    scanf("%d", &k);   
    int x[n];
    generateSolutions(x, 0, n, k);
    printf("So luong nghiem nguyen khong am cua phuong trinh: %d\n", count);  
    return 0;
}