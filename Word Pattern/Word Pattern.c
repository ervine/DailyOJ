#include<stdio.h>
#include<stdbool.h>

unsigned char hash(char *str){
    unsigned char h;
    for(h=0;*str&&*str!=' ';str++)
        h += 31*h+*str;
    return h;
}

bool wordPattern(char* pattern, char* str) {
    char *patterns[26]={0}, *p, words[256]={0};
    unsigned temp;

    while(*str) {
        if(!*pattern) return false; // weather pattern is too short
        if(!patterns[*pattern-'a']){
            temp = hash(str);
            if(words[temp]) return false;
            words[temp] = 1;
            patterns[*pattern-'a'] = str;
            while(*str&&*str++!=' ') ;
        }else {
            for(p=patterns[*pattern-'a'];*str&&*str!=' ';p++,str++)
                if(*p!=*str)  return false;
            if(*p!=' ') return false; // weather pattern word is too long
            if(*str)str++; // when str ends
        }
        pattern++;
    }
    return !*pattern; // weather pattern is too long
}

int main(void) {
    if(wordPattern("aa","aa"))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
