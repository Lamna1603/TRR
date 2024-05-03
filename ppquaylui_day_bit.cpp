#include<stdio.h>
void out(int n,int a[]);
int count=0;
void Try(int i,int n,int a[]);
int main(){
    int n;
    printf("nhap do dai sau: ");
    scanf("%d",&n);
    int a[n+1];
    Try(1,n,a);
    return 0;
}
void out(int n,int a[]){
    printf("%d: ",++count);
    for(int i=1;i<=n;i++){
        printf("%d",a[i]);
    }
    printf("\n");
}
void Try(int i,int n, int a[]){
    for(int j=0;j<=1;j++){
        a[i]=j;
        if(i==n){out(n,a);}
        else {Try(i+1,n,a);
        }
}
}