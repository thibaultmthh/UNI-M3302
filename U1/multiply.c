#include <stdlib.h>
#include <stdio.h>

// multiply 2 numbers
int main(int argc, char **argv) {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("%d * %d = %d\n", a, b, a * b);
    return 0;
}