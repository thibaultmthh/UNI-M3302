#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    printf("Entrez un nombre : ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int nbChar = (i * 2 )- 1;
        for (int j = 0; j < n - (nbChar/2); j++){
            printf(" ");
        }
        for (int j = 0; j < nbChar; j++){
            printf("*");
        }
       
        printf("\n");

       
    }
    return 0;
}