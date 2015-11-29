/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *addDigits, flag;
    *returnSize = digitsSize;
    for(;digitsSize>0;digitsSize--)
        if(*(digits+digitsSize-1)!=9) break;
    if(!digitsSize) (*returnSize)++;
    addDigits = (int*)calloc(*returnSize,sizeof(int));
    if(!digitsSize) *addDigits = 1;
    else {
        for(digitsSize=*returnSize-1,flag=1;digitsSize>=0;digitsSize--) {
            *(addDigits+digitsSize) = *(digits+digitsSize)+flag;
            flag = *(addDigits+digitsSize)/10;
            *(addDigits+digitsSize) %=10;
        }
    }
    return addDigits;
}
int main() {
    int a[2]={9,9},b,c;
    b = 2;
    plusOne(a,b,&c);printf("%d\n",c);
    return 0;

}
