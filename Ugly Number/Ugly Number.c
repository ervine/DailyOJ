#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool isUgly(int num) {
    if(num<=0) return false;
    while(1) {
        if(!(num%2)) num /= 2;
        else break;
    }
    while(1) {
        if(!(num%3)) num /= 3;
        else break;
    }
    while(2) {
        if(!(num%5)) num /= 5;
        else break;
    }
    if(num==1) return true;
    else return false;
}

int main() {
    if(isUgly(2)) printf("yes");
    else printf("no");
    return 0;
}
