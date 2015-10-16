#include<stdio.h>

// argv.exe can called in cmd by its name ignoring case
int main(int argc, char* argv[]) {
    for(;argc--;)
        printf("%s\n",argv[argc]);
    return 0;
}
