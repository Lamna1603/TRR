#include<stdio.h>
void ppsinh(int a[],int n);
void init(int a[],int n);
void out(int a[],int n);
int islast(int a[],int n);
void gen(int a[],int n);
int cout=0;
int main(){
    int n;
    printf("nhap n");
    scanf("%d",&n);
    int a[n];
    ppsinh(a,n);
    return 0;
}
void ppsinh(int a[],int n){
    init(a,n);
    out(a,n);
    int stop=islast(a,n);
    while(stop==0){
        gen(a,n);
        out(a,n);
        stop=islast(a,n);
    }
}
void init(int a[],int n){
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
}
void out(int a[],int n){
    printf("%d ",++cout);
    for(int i=1;i<=n;i++){
      printf("%d",a[i]);
    }
    printf("\n");
}
int islast(int a[],int n){
    for(int i=n;i>=1;i--){
        if(a[i]>a[i-1]) return 0;
    }
    return 1;
}
void gen(int a[],int n){
    int i=n-1,j=n;
    while (i>=1&&a[i]>a[i+1])
    {
        i--;
    }
    while(a[i]>a[j])j--;
    int tam=a[i];
    a[i]=a[j];
    a[j]=tam;
    int l=i+1,r=n;
    while(l<n){
         int tam=a[l];
        a[l]=a[r];
        a[r]=tam;
        l++;r--;
    }
}