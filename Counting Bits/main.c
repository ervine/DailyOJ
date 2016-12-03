#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
//int* countBits(int num, int* returnSize) {
//    if(num<0) return NULL;
//
//    *returnSize = num+1;
//    int *numBit = (int*)calloc(*returnSize,sizeof(int));
//    int i,curNum;
//    for(i=0;i<*returnSize;i++) {
//        curNum = i;
//        while(curNum){
//            numBit[i] += (curNum&1);
//            curNum = curNum>>1;
//        }
//    }
//
//    return numBit;
//}

int* countBits(int num, int* returnSize) {
    if(num<0) return NULL;

    *returnSize = num+1;
    int *numBit = (int*)calloc(*returnSize,sizeof(int));
    int i,j;
    for(i=1;i<=num;i*=2) {
        numBit[i] = 1;
    }
    for(i=1;i<*returnSize;i++) { // numBit[0] = 0;
        if(numBit[i]) continue;
        for(j=1;j<i;j=(j<<1)+1) {
            if(i&j){
                numBit[i] = numBit[i&j]+numBit[i&~j];
                break;
            }
        }

    }

    return numBit;
}

int main()
{
    printf("Hello world!\n");
    int returnSize;
    int *num = countBits(15,&returnSize);

    return 0;
}
