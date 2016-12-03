#include <stdio.h>
#include <stdlib.h>
#define numc(s) ((s>='a'&&s<='z')?(s-'a'):((s>='A'&&s<='Z')?(s-'A'):(-1)))


int numDistinct(char* s, char* t) {
    int lenS,lenS2,lenT,i,j;
    int *table = (int*)calloc(26,sizeof(int));

    lenT = i = 0;
    while(t[i++]) {
        lenT++;
        table[numc(t[i-1])] = 1;
    }
    int *numSeq = (int*)calloc(lenT,sizeof(int));
    numSeq[0] = 1;

    lenS = i = 0;
    while(s[i++]) lenS++;
    int *s2 = (int*)calloc(lenS,sizeof(int));
    lenS2 = 0;
    for(i=0;i<lenS;i++) {
        if(table[numc(s[i])]) {
            s2[lenS2] = s[i];
            lenS2++;
        }
    }


    for(i=0;i<lenS2;i++) {
        for(j=1;j<lenT;j++) {
            if(numc(s2[i])==numc(t[j-1])) {
                numSeq[j] += numSeq[j-1];
            }
        }for(j=0;j<lenT;j++) printf("%d",numSeq[j]);
    }

    return numSeq[lenT-1];

}
int main()
{
    printf("Hello world!\n");
    char s[]="rrr";
    char t[]="r";
    numDistinct(s,t);
    return 0;
}
