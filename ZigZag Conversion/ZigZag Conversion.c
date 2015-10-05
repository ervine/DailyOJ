#include "stdio.h"
#include "string.h"

char* convert(char* s, int numRows) {
    if(numRows<=1) return s;
    int ls = strlen(s);
    int ll = numRows+(((numRows-2)<0)?0:(numRows-2));printf("%d\n",ll);
    char *z = (char*)malloc(ls*sizeof(char)+1);
    int i = 0, j, k = 0, in;
    for(;i<numRows;i++){
        for(j=i,in=1;j<ls;){
            z[k++] = s[j];
            if(i%(numRows-1)==0){
                j += ll;
            } else {
                j += in?ll-2*i:2*i;
                in = in?0:1;
            }
        }
    }
    z[ls] = 0;
    return z;
}

int main(void) {

    printf("%s",convert("1234567890",5));

    return 0;
}
