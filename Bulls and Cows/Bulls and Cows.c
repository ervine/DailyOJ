#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* getHint(char* secret, char* guess) {
    int bulls, cows, num,num2, len;
    static int hash[10];

    num2 = num = strlen(secret);
    for(len=0;num;num/=10,len++) ;
    char *hint = (char*)malloc((2*len+3)*sizeof(char));

    for(bulls=0;*secret;secret++,guess++)
        if(*secret==*guess) bulls++;
        else hash[*secret-'0']++;
    secret -= num2;
    guess -= num2;
    for(cows=0;*secret;secret++,guess++)
        if(*secret!=*guess && hash[*guess-'0']){
            hash[*guess-'0']--;
            cows++;
        }


    num = sprintf(hint, "%dA", bulls);
    num += sprintf(hint+num, "%dB", cows);
    *(hint+num) = 0;

    return hint;
}


int main() {
    printf("%s",getHint("1234","0111"));
    return 0;
}
