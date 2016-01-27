struct NumArray {
    int num;
    int sum;
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
    struct NumArray *numArray = (struct NumArray*)malloc(numsSize*sizeof(struct NumArray));
    int i;
    for(i=0;i<numsSize;i++) {
        (numArray+i)->num = *(nums+i);
        (numArray+i)->sum = i==0?(*nums):((numArray+i-1)->sum+*(nums+i));
    }
    return numArray;
}

int sumRange(struct NumArray* numArray, int i, int j) {
    return (numArray+j)->sum-(numArray+i)->sum+(numArray+i)->num;
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
    free(numArray);
}

int main() {
    int nums[5]={1,2,3,4,5};
    int numsSize = 5;
     struct NumArray* numArray = NumArrayCreate(nums, numsSize);
     sumRange(numArray, 0, 1);
     sumRange(numArray, 1, 2);
     NumArrayFree(numArray);
}

