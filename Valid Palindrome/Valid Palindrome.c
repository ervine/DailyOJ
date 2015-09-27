#include "stdio.h"
#include "stdbool.h"
/// 1
/*
char letter(char s) {
    if(s>='a'&&s<='z') return s;
    else if(s>='0'&&s<='9') return s;
    else if(s>='A'&&s<='Z'){
        return s+'a'-'A';
    }
    else return 0;
}

bool compare(char *l, char *r, char **newlr ){
    char lLetter, rLetter;
    *(newlr) = l;
    *(newlr+1) = r;
    while(l<=r){
        lLetter = letter(*l);
        if(lLetter) break;
        else if(r>l) l++;
        else {
            *(newlr) = l;
            return true;
        }
    }
    while(l<=r){
        rLetter = letter(*r);
        if(rLetter) break;
        else if(r>l) r--;
        else {
            *(newlr+1) = r;
            return true;
        }
    }printf("%c,%c\n",*r,*l);
    *newlr = l;
    *(newlr+1) = r;
    return lLetter == rLetter;
}

bool isPalindrome(char* s) {
    char *p,*newlr[2];
    p = s;
    while(*(p+1)!='\0'){
        p++;
    }
    while(p>s){
        if(compare(s,p,newlr)){
            s = *(newlr)+1;
            p = *(newlr+1)-1;
            continue;
        }else return false;
    }
    return true;
}
*/
/// 2
/*
bool isLetter(char *s) {
    if(*s>='a'&&*s<='z') return true;
    else if(*s>='0'&&*s<='9') return true;
    else if(*s>='A'&&*s<='Z'){
        *s = *s+'a'-'A';
        return true;
    }
    else return false;
}

char* nextLetter(char *s, int step, int interal) {
    while(interal--){
        if(isLetter(s)) return s;
        else if(interal) s += step;
    }
    return s;
}

bool isPalindrome(char* s) {
    char *p;
    p = s;
    while(*(p+1)!='\0'){
        p++;
    }

    while(p>s){
        s = nextLetter(s,1,p-s+1);
        p = nextLetter(p,-1,p-s+1);
        if(*s==*p){
            s++;p--;
            continue;
        }
        else return false;
    }
    return true;
}
*/
/// 3
//bool isalnum(char n) {
//    return (n>='0'&&n<='9')||(n>='A'&&n<='Z')||(n>='a'&&n<='z');
//}
//char tolower(char n) {
//    if(n>='A'&&n<='Z')
//        return n+'a'-'A';
//    else return n;
//}
bool isPalindrome(char* s) {
    char *p1 = s, *p2 = s + strlen(s) - 1;
    while(p1 < p2){
        if(!isalnum(*p1)){p1++;continue;}
        if(!isalnum(*p2)){p2--;continue;}
        if(tolower(*p1++) != tolower(*p2--)) return false;
    }
    return true;
}
void main(){




    if(isPalindrome("ab2ba"))
        printf("ok");
}
