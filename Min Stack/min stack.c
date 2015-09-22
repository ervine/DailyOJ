#include "stdio.h"

typedef struct {
    int *min;
    int maxSize;
    //int *base;
    int *top;
    int num;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
    stack->min = (int *)malloc(maxSize*sizeof(int));
    stack->maxSize = maxSize;
    stack->top = (int *)malloc(maxSize*sizeof(int));
    //stack->top = stack->base;
    stack->num = 0;
}

void minStackPush(MinStack *stack, int element) {
    if(stack->num>=stack->maxSize) return;
    *++stack->top = element;
    //stack->top++;
    if(stack->num==0){
        *++stack->min = element;
    }else{
        *++stack->min = *(stack->min-1)<element?*(stack->min-1):element;
    }
    stack->num++;
}

void minStackPop(MinStack *stack) {
    if(stack->num<=0) return;
    stack->top--;
    stack->min--;
    stack->num--;
}

int minStackTop(MinStack *stack) {
    if(stack->num<=0) return;
    return *stack->top;
}

int minStackGetMin(MinStack *stack) {
    if(stack->num<=0) return;
    return *stack->min;
}

void minStackDestroy(MinStack *stack) {
    free(stack->top-stack->num);
    free(stack->min-stack->num);
    stack->num = 0;
    stack->maxSize = 0;
}

int main(){



}
