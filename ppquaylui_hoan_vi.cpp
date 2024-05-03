#include<stdio.h>
void out(int n,int a[]);
int count=0;
void Try(int i,int n,int a[],int b[]);
int main(){
    int n;
    printf("nhap do dai sau: ");
    scanf("%d",&n);
    int a[n+1];
    
    
    int b[n+1];
    for(int i=1;i<=n;i++){
        b[i]=1;
    }Try(1,n,a,b);
    return 0;
}
void out(int n,int a[]){
    printf("%d: ",++count);
    for(int i=1;i<=n;i++){
        printf("%d",a[i]);
    }
    printf("\n");
}
void Try(int i,int n, int a[],int b[]){
    for(int j=1;j<=n;j++){
        
        if(b[j]==1){
            a[i]=j;
            b[j]=0;
        
        if(i==n){out(n,a);}
        else {Try(i+1,n,a,b);
        }
        b[j]=1;

        }
}
}