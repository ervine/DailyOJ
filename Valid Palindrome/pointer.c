#include "stdio.h"
#include "math.h"

int main(){

    int i;
    printf("Address of i:%d\n\n",&i);


    char a,*s,**p;
    a = 'A';
    s = &a;
    p = &s;
    printf("Length of pointer:%d\n",sizeof(p));
    printf("The size of all the pointers are the same:%d,%d\n",sizeof(int *),sizeof(int **));
    printf("Value of a:%c-%c-%c\n",a,*s,**p);
    printf("Address of a:%d-%d-%d\n",&a,s,*p); // Why is there 7 bytes between s and a?
    printf("Address of s:%d-%d\n",&s,p);
    printf("Address of p:%d\n\n",&p);


    char b[20]; // b is a pointer but stick to the array[20], cannot change the value of "pointer" b but the value
    b[0] = 'B'; // *b = 'B'
    s = b;
    printf("Size of b:[%d]\n",sizeof(b));
    printf("Value of top of the array b point to:%c-%c-%c-%c-%c\n",b[0],*b,s[0],*s,**p); // b[n] = *(b+n)
    printf("Address of the array b point to:%d-%d-%d\n",b,s,*p);
    printf("Address of b:%d\n",&b);
    printf("Address of s:%d-%d\n",&s,p);
    printf("Address of p:%d\n\n",&p);


    // char *       -> a (char) pointer
    // char *[10]   -> a array of (char) pointers; 10 pointers in this array
    // the same as char *(c[10]);
    char *c[10]={}; // initialize the array as 0
    c[0] = &a;
    *(c+1) = b;
    printf("Size of c:[%d]\n",sizeof(c));
    printf("Index of c\tAddress of c\tValue of c\n");
    for(i = 0;i<10;i++){
        printf("%d\t\t%d\t\t%d\n",i,c+i,c[i]);
    }
    printf("\n");


    char z[10] = "An array.";
    printf("Length of z:[%d]\n",sizeof(z));
    // A pointer which is supposed to point to a 10-size char array
    char (*d)[10];
    // d = &b; // Warning: assignment from incompatible pointer type [enabled by default]
    d = &z;
    printf("Size of d:[%d]\n",sizeof(d));
    printf("Address of d:%d\n",&d);
    printf("Value of d:%d\n",d);
    printf("\"%s\"--\"%s\"\n",z,d);
    printf("\n");


    return 0;

}
