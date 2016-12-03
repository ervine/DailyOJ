#include <stdio.h>
#include <stdlib.h>
#define min(a,b) (a<b?a:b)
int minDistance(char* word1, char* word2) {
    int len1,len2,i,j,k,unmatch;

    len1 = i =0;
    while(word1[i++]) {
        len1++;
    }
    len2 = i =0;
    while(word2[i++]) {
        len2++;
    }

    len2++;
    int *distance = (int*)calloc(len2,sizeof(int));
    for(i=0;i<len2;i++) {
        distance[i] = i;
    }

    for(i=0;i<len1;i++) {
        for(j=len2-1;j>=0;j--) {
            unmatch = (word1[i]!=word2[j]);
            distance[j]++;
            for(k=0;k<j;k++) {
                distance[j] = min(distance[j],
                    distance[k]+(j-1-k)+unmatch); // [pre]+[insert]+[cur]
            }
            // distance[j] += (word1[i]==word2[j]);
        }
    }

    return distance[len2-1];
}
int main()
{
    printf("Hello world!\n");
    minDistance("a","b");
    return 0;
}
