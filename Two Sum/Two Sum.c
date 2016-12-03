#include "stdio.h"
#include "stdlib.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct _hashNode {
     int val;
     int index;
     struct _hashNode *next;
 } HashNode;

 HashNode* findNode(int target, int m, HashNode **table, int sum) {
    HashNode *node = NULL;
    unsigned int h = (target^(sum-target));printf("%d",h);
    h = (h%m);
    printf("%d\n",h);


    if(node=table[h]) {
        while(node->val!=target&&node->next) node = node->next;
        if(node->val!=target) {
            node->next = (HashNode*)calloc(1,sizeof(HashNode));
            node = node->next;
            node->index = -1;
            node->next = NULL;
        }
    } else {
        node = (HashNode*)calloc(1,sizeof(HashNode));
        table[h] = node;
        node->index = -1;
        node->next = NULL;
    }

    return node;
 }


int* twoSum(int* nums, int numsSize, int target) {
    HashNode **table = (HashNode**)calloc(numsSize,sizeof(HashNode*)), *tmp;

    int *twoNumIndex = (int*)calloc(2,sizeof(int));

    int i;
    for(i=0;i<numsSize;i++) {
        tmp = findNode(target-nums[i],numsSize,table,target);
        if(tmp->index==-1) {
            tmp->val = nums[i];
            tmp->index = i;
        } else {
            twoNumIndex[0] = tmp->index;
            twoNumIndex[1] = i;
            return twoNumIndex;
        }
    }
    return twoNumIndex;
}

int main() {
    int input[10] = {-2,-1,0,1,2,3,4,5,6}, *result = twoSum(input,3,-2);

    printf("%d %d\n",result[0],result[1]);
    return 0;
}
