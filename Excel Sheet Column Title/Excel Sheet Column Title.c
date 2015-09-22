#include "stdio.h"
#define BASE 26
// 缝27进1，位权为26，A 代表 1，Z 26；

char* convertToTitle(int n) {
    char s[999];
    int nn[999];
    int i = 0, j = 0;

    while(n>0){
        n--; // BASE不进一
        nn[i++] = n%BASE;
        n /= BASE;
    }

    while(i--){
        s[j++] = 'A'+nn[i];
    }
    s[j] = '\0';

    return s;
}


int main() {
    int n;
    scanf("%d",&n);
    printf("%s",convertToTitle(n));
    return 0;
}


