#include <bits/stdc++.h>
void init(int a[], int k,int n);
void out(int a[],int k,int n);
bool ilast(int a[],int k,int n);
void gen(int a[],int k,int n);
void ppsinh(int a[],int k,int n);
int main(){
    int n,k;
    cin>>n>>k;
    int a[k+1];
    ppsinh(a,k,n);
}
void init(int a[], int k,int n){
    for(int i=1;i<=k;i++){
        a[i]=i;
    }
}
void out(int a[],int k,int n){
    for(int i=1;i<=k;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
bool ilast(int a[],int k,int n){
    for(int i=1;i<=k;i++){
        if(a[i]!= n-k+i)
        return 0;
    }
    return 1;
}
void gen(int a[],int k,int n){
    int i=k;
    while(a[i]==n-k+i){
        i--;
    }
    a[i]+=1;
    for(int j=i+1;j<=k;j++){
        a[j]=a[i]+j-i;
    }
}
void ppsinh(int a[],int k,int n){
    init(a,k,n);
    out(a,k,n);
    bool stop=ilast(a,k,n);
    while(stop==0){
        gen(a,k,n);
        out(a,k,n);
        stop=ilast(a,k,n);
    }
}