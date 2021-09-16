#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Carre1(int x){
    return x * x;
}

void Carre2(int* x){
    *x *= *x;
}

void Permut(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

char* StringDup(char* s){
    int len = strlen(s);
    char* addr = NULL;
    addr = (char*) malloc(sizeof(char)*(len+1));
    if (addr == NULL){
        printf("Error: Out of memory\n");
        exit(1);
    }

    strcpy(addr,s);


    return addr; 

}

int main(void){
    int a = 2;
    int b = 3;

    a = Carre1(a);
    Carre2(&b);
    printf("%d\n", a);
    printf("%d\n", b);

    Permut(&a, &b);

    printf("%d\n", a);
    printf("%d\n", b);

    char chaine[] = "exemple de chaine à copier" ;

    char* chaine2 = StringDup(chaine);

    printf("%s\n", chaine2);

    free(chaine2);
    return 0;

}