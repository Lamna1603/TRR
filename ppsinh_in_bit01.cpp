#include<stdio.h>
 void init(int n,int a[]);
    void out(int n,int a[]);
    void ppsinh(int n,int a[]);
    int count=0;
int main(){
    int n;
    
    printf("nha so bit cua day: ");
    int a[n+1];
    scanf("%d",&n);
    
    ppsinh(n,a);
    return 0;
}
void init(int n,int a[]){
    for(int i=1;i<=n;i++){
        a[i]=0;
    }
}
void out(int n,int a[]){
    printf("%d :",++count);
    for(int i=1;i<=n;i++){
        printf("%d",a[i]);
    }
    printf("\n");
}
int islast(int n,int a[]){
    int i=n;
    for(i;i>0;i--){
        if(a[i]==0) return 0;
    }
    return 1;
}
void gen(int n,int a[]){
    int i=n;
   while(a[i]==1&&i>0){
    a[i--]=0;
   }
   a[i]=1;
}
void ppsinh(int n,int a[]){
    init(n,a);
    out(n,a);
     int stop=islast(n,a);
    while(stop==0){
        gen(n,a);
        out(n,a);
        stop=islast(n,a);
    }
}