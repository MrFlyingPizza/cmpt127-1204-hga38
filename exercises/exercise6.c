#include <stdio.h>

// a dumb implementation of a program
// that prints the various powers of a
// number but it nonetheless shows a
// value being hard-code repeatedly.
int main(void)
{
    printf("first power: %d\n", 4);
    printf("second power: %d\n", 4*4);
    printf("third power: %d\n", 4*4*4);
    printf("fourth power: %d\n", 4*4*4*4);
    printf("fifth power: %d\n", 4*4*4*4*4);
    printf("tenth power: %d\n", 4*4*4*4*4*4*4*4*4*4);
    // darn it must be really annoying to change
    // these values manually, what am I going to do?!
    return 0;
}