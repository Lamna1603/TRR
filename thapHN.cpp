#include<stdio.h>
void move(char a,char b);
void thap(int n,char a, char b,char c);
int main(){
    int n;
    printf("nhap n: ");
    scanf("%d",&n);
    char a='a',b='b',c='c';
    thap(n,a,b,c);
    return 0;
}
void move(char a,char b){
    printf("%c----->%c\n",a,b);
}
void thap(int n,char a, char b,char c){
    if(n==1) move(a,c);
    else{
        thap(n-1,a,c,b);
        thap(1,a,b,c);
        thap(n-1,b,a,c);
    }
}