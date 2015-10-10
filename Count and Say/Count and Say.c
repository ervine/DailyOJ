#include<stdio.h>
#include<stdlib.h>

char* countAndSay(int n) {
    if(!n) return 0;
    int *say[2];
    int l = 1000*n;
    say[0] = (int*)malloc(l*sizeof(n));
    say[1] = (int*)malloc(l*sizeof(n));
    int i,j,k,count,num;

    say[0][0] = 1;
    say[0][1] = 0;

    for(i=2;i<=n;i++){
        count = num = k = 0;

        for(j=0;say[i%2][j];j++){
            if(count){
                if(say[i%2][j]==num)
                    count++;
                else{
                    say[1-i%2][k++] = count;
                    say[1-i%2][k++] = num;
                    count = 1;
                    num = say[i%2][j];
                }
            }else{ // the first number
                num = say[i%2][j];
                count = 1;
            }
        }
        say[1-i%2][k++] = count;
        say[1-i%2][k++] = num;
        say[1-i%2][k]   = 0;
    }

    char *finalSay = (char*)malloc(l*sizeof(char));
    for(i=0,k=0;say[1-n%2][i];i++){
        k += sprintf(finalSay+k,"%d",say[1-n%2][i]);
    }
    *(finalSay+k) = '\0';

    free(say[0]);
    free(say[1]);
    return finalSay;
}

int main(void){
    int i;
    char *say;
    for(i=1;i<=30;i++){
        say = countAndSay(i);
        printf("No%d\n%s\n\n",i,say);
        free(say);
    }

    return 0;
}
