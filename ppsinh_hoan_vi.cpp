#include<stdio.h>
int count=0;
void ppsinh(int n,int a[]);
void init(int n,int a[]);
void out(int n,int a[]);
int islast(int n,int a[]);
void gen(int n,int a[]);
int main(){
    int n;
    printf("nhap n: ");
    scanf("%d",&n);
    int a[n+1];
    ppsinh(n,a);
    return 0;
}void ppsinh(int n,int a[]){
    init(n,a);
    out(n,a);
    int stop=islast(n,a);
    while(stop==0){
        gen(n,a);
        out(n,a);
        stop=islast(n,a);
    }
}
void init(int n,int a[]){
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
}
void out(int n,int a[]){
    printf("%d: ",++count);
    for(int i=1;i<=n;i++){
        printf("%d",a[i]);
    }
    printf("\n");
}
int islast(int n,int a[]){
    for(int i=n;i>0;i--){
        if(a[i]>a[i-1])return 0;
    }
    return 1;
}
void gen(int n,int a[]){
    int i=n-1,k=n;
      while(i>0&&a[i]>a[i+1])i--;
      while (a[i]>a[k])k--;
      int tam=a[i];
      a[i]=a[k];
      a[k]=tam;
      int l=i+1,r=n;
      while(l<r){
        int tam=a[l];
        a[l]=a[r];
        a[r]=tam;
        l++;r--;
      }
      
}