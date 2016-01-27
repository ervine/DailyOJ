#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int numsTable[9], i,ii,j,jj;
    char c;
    // row
    for(i=0;i<boardRowSize;i++) {
        memset(numsTable,0,9*sizeof(int));
        for(j=0;j<boardColSize;j++) {
            c = *(*(board+i)+j);
            if(c=='.') continue;
            else if(c>'0' && c<='9')
                if(numsTable[c-'1']) return false;
                else numsTable[c-'1'] = 1;
            else return false;
        }
    }

    return true;
}
void sayhi(int **c) {
    printf("%d",**c);
}
int main()
{
    int
    //isValidSudoku(c,9,9);
    printf("Hello world!\n");
    return 0;
}
