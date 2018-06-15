#include <stdio.h>
#include "arith.h"

int main(void)
{
    int op1;
    int op2;
    char op;

    printf("Enter the calculation:\n");
    scanf("%d%c%d", &op1, &op, &op2);

    switch (op) {
        case '+':
            printf("=%d\n", add(op1, op2));
            break;
        case '-':
            printf("=%d\n", sub(op1, op2));
            break;
        case '*':
            printf("=%d\n", mul(op1, op2));
            break;
        case '/':
            printf("=%d\n", div(op1, op2));
            break;
        case '%':
            printf("=%d\n", mod(op1, op2));
            break;
        default:
            printf("\nNot valid operation.\n");
            break;
    }
    return 0;
}