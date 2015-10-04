#include "stdio.h"


char* addBinary(char* a, char* b) {
    int la = strlen(a), lb = strlen(b);
    int l = la>lb?la:lb;
    int acc = 0, temp = 0;
    char *c = (char *)malloc(l*sizeof(char)+1+1); // +1 '\0' +1 ½øÎ»
    int i;
    for(i=1;i<=l;i++){
        temp = 0;
        if(la-i>=0 && a[la-i]=='1') temp++;
        if(lb-i>=0 && b[lb-i]=='1') temp++;
        if(acc) temp++;
        acc = 0;
        switch(temp){
            case 0: c[l-i+1] = '0'; break;
            case 1: c[l-i+1] = '1'; break;
            case 2: c[l-i+1] = '0'; acc = 1; break;
            case 3: c[l-i+1] = '1'; acc = 1; break;
        }
    }
    c[l+1] = '\0';
    if(acc){
        c[0] = '1';
    }else {
        for(i=0;i<l+1;i++){
            c[i] = c[i+1];
        }
    }
    return c;
}

int main(void) {
    printf("%s",addBinary("1","0"));

}
