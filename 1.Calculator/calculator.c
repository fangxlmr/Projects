#include <stdio.h>

int main(void)
{
    double op1;
    double op2;
    char op;

    printf("Enter the calculation:\n");
    scanf("%lf%c%lf", &op1, &op, &op2);

    switch(op) {
        case '+':
            printf("=%lf\n",op1+op2);
            break;

        case '-':
            printf("=%lf\n",op1-op2);
            break;

        case '*':
            printf("=%lf\n",op1*op2);
            break;

        case '/':
            if(op2==0)
                printf("\n\n\aDivision by zero error!\n");
            else
                printf("=%lf\n",op1/op2);
            break;

        case '%':
            if((long)op2==0)
                printf("\n\n\aDivision by zero error!\n");
            else
                printf("=%ld\n",(long)op1%(long)op2);
            break;

        default:
            printf("\n\n\aDivision by zero error!\n");
            break;
    }
    return 0;
}