#include <stdio.h>
#include <stdlib.h>
void printfA(int *p, int size) {
    for(;size>0;size--) {
        printf("%d ",*p++);
    }
    printf("\n");
}
void printfA2(int *p, int sizer, int sizec) {
    int i,j;
    for(i=0;i<sizer;i++)
        for(j=0;j<sizec;j++)
            printf("%d ",*(p+i*sizer+j));
    printf("\n");
}
int main() {
    int A[3] = {1,2,3}, B[] = {4,5,6};
    // int C[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int C[][3] = {{1,2,3},{4,5,6},{7,8,9}}; // the same as last row
    printf("%d\n",A);
    int a = 4;
    printf("%d\n",&a);
    // error: incompatible types when assigning to type 'int[3]'(A) from type 'int *'(&a)
    // A = &a;

    // an array (of 3 pointers)
    int *array_2_pointers[3];
    array_2_pointers[0] = A;
    *(array_2_pointers+1)  = B;
    printfA(array_2_pointers[0],3);
    printfA(*(array_2_pointers+1),3);

    // a pointer (to an array of 3 integers)
    int (*pointer2array_3)[3];
    pointer2array_3 = A;
    printfA((int*)pointer2array_3,3);

    // a pointer (to a two-dimension array)
    int (*pointer2_2d_array)[3][3];
    // todo http://stackoverflow.com/questions/14808908/c-pointer-to-two-dimensional-array
    //*pointer2_2d_array = C;
    printfA2((int*)C,3,3);


    return 0;
}
