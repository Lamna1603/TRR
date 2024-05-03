#include<stdio.h>

void Try(int i, int s, int x[], int n, int a);
void out(int n, int a[]);
int count = 0;

int main() {
    int n, a;
    scanf("%d%d", &n, &a);
    int x[n + 1];
    int s = 0;
    Try(1, s, x, n, a);
    return 0;
}

void Try(int i, int s, int x[], int n, int a) {
    for (int j = 0; j <= a; j++) {
        if (s <= a) {
            x[i] = j;
            s += x[i];
            if (i == n ) {
                if( s == a)out(n, x);
            }
                
            else
                Try(i + 1, s, x, n, a);
            s -= x[i]; // Reset s to its previous value
        }
    }
}

void out(int n, int a[]) {
    printf("%d: ", ++count);
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
