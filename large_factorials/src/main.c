#include "factorial.h"

int main(void)
{
    // char    num1[MAX], num2[MAX];
    int n = 9;
    // memset(num1, '0', MAX);
    // memset(num2, '0', MAX);
    // num1[MAX - 1] = 0;
    // num1[MAX - 2] = '5';
    // num1[MAX - 3] = '8';
    // num1[MAX - 4] = '9';
    //
    // num2[MAX - 1] = 0;
    // num2[MAX - 2] = '5';
    // num2[MAX - 3] = '3';
    // num2[MAX - 4] = '3';
    //
    printf("%d! = %s\n", n, factorial(n));
    // printf("5! = %s\n", factorial(5));
    // printf("15! = %s\n", factorial(15));
    // printf("1! = %s\n", factorial(1));
    // printf("25! = %s\n", factorial(25));
    // printf("7! = %s\n", factorial(7));
}