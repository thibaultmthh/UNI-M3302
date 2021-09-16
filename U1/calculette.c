#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc != 4){
        printf("Usage: %s <number1> <operande> <number2>\n", argv[0]);
        return EXIT_FAILURE;
        }
    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[3]);
    char op = argv[2][0];
    if (op == '+'){
        printf("%d + %d = %d\n", n1, n2, n1 + n2);
        }
    else if (op == '-'){
        printf("%d - %d = %d\n", n1, n2, n1 - n2);
        }
    else if (op == '*'){
        printf("%d * %d = %d\n", n1, n2, n1 * n2);
        }
    else if (op == '/'){
        printf("%d / %d = %d\n", n1, n2, n1 / n2);
        }
    else if (op == '%'){
        printf("%d %% %d = %d\n", n1, n2, n1 % n2);
        }
    else{
        printf("operator unknow : %c", op);
    }
}