#include <stdio.h>
#include <stdlib.h>

/* --- Operation functions --- */
int add(int a, int b) {
    printf("Adding 'a' and 'b'\n");
    return a + b;
}
int subtract(int a, int b) {
    printf("Subtracting 'b' from 'a'\n");
    return a - b;
}
int multiply(int a, int b) {
    printf("Multiplying 'a' and 'b'\n");
    return a * b;
}
int divide(int a, int b) {
    printf("Dividing 'a' by 'b'\n");
    return a / b;
}
int exit_prog(int a, int b) {
    printf("Exiting program...\n");
    exit(0);
}

/* --- Main --- */
int main(void) {
    int a = 6, b = 3, result;
    char input;

    // Array of function pointers
    int (*ops[5])(int, int) = { add, subtract, multiply, divide, exit_prog };

    printf("Operand 'a': %d | Operand 'b': %d\n", a, b);
    printf("Specify the operation to perform (0:add | 1:subtract | 2:multiply | 3:divide | 4:exit): ");
    scanf(" %c", &input);

    result = ops[input - '0'](a, b);
    printf("x = %d\n", result);
    return 0;
}
