#include <stdio.h>

int main() {
    int n1 = 10;
    int *p = &n1;
    int n2 = 33;
    char s[11];
    int n3 = 12;
    
    printf("address of n1: %p\n", (void *)&n1); // Print address of n1
    printf("address stored in p: %p\n", (void *)p); // Print address stored in pointer p
    printf("address of n2: %p\n", (void *)&n2); // Print address of n2
    printf("address of s: %p\n", (void *)s); // Print address of s
    printf("address of n3: %p\n", (void *)&n3); // Print address of n3
    
    printf("value of n1: %d\n", n1); // Print value of n1
    printf("value pointed to by p: %d\n", *p); // Print value pointed to by p
    printf("value of n2: %d\n", n2); // Print value of n2
    printf("value of s: %s\n", s); // Print value of s
    printf("value of n3: %d\n", n3); // Print value of n3
    
    return 0;
}
