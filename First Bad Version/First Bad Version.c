#include "stdio.h"

int isBadVersion(int version) {
    return version>=1702766719;
}

int firstBadVersion(int n) {
    int i = (n+1)/2, l = 1, r = n;
    while(1){
        printf("%d\n",i);
        if(isBadVersion(i)){
            if(i==1||!isBadVersion(i-1)) return i;
            else{
                r = i;
                i  = l/2+i/2;
            }
        }else{
            l = i;
            i = i/2+r/2+1;
        }
    }
}

void main(){
    int n = firstBadVersion(2126753390);
    printf("%d",n);
}
