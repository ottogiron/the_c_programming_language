#include <stdio.h>

#define IN 0
#define OUT 1


int
main(int argc, char const *argv[])
{
    int c;

    while ((c = getchar()) != EOF) {
        if (!(c == '\n' || c == '\t' || c == ' '))
            putchar(c);
        else {
            putchar('\n');
        }
    }
    
    return 0;
}
