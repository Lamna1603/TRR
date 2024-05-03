#include <stdio.h>
void doi(int a[], int b[], int c[], int n);
void Try(int i, int x[], int a[], int b[], int c[], int n);
void out(int x[], int n);
int count=0;
int main()
{
    int n;
    scanf("%d", &n);
    int x[n + 1]; int a[n + 1];
    int b[100];
    int c[170];
    doi(a, b, c, n);
    Try(1, x, a, b, c, n);
    return 0;
}
void doi(int a[], int b[], int c[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = 1;
    }
    for (int i = 2; i <= 2 * n; i++)
    {
        b[i] = 1;
    }
    for (int i = 1 - n; i <= n - 1; i++)
    {
        c[i] = 1;
    } 
}
void Try(int i, int x[], int a[], int b[], int c[], int n)
{
    for (int j = 1; j <= n; j++)
    {
        if (a[j] == 1 && b[i + j] == 1 && c[i - j] == 1)
        {
            x[i] = j;
            a[j] = 0;
            b[i + j] = 0;
            c[i - j] = 0;
            if (i == n)
                out(x, n);
            else
                Try(i + 1, x, a, b, c, n);
            a[j] = 1;
            b[i + j] = 1;
            c[i - j] = 1;
        }
    }
}
void out(int x[], int n)
{
    printf("%d: ", ++count);
    for (int i = 1; i <= n; i++)
    {

        printf("%d", x[i]);
    }
    printf("\n");
}
