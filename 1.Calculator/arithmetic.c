#include <stdio.h>
#include "arithmetic.h"

int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

int mul(int x, int y)
{
    return x * y;
}

int div(int x, int y)
{
    if (y == 0) {
        printf("\nZero division.\n");
        return -1;
    }
    return x / y;
}


int mod(int x, int y)
{
    return x % y;
}