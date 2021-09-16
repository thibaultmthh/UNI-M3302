#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BinToDec(char bin[], char dec[]){
    int res = 0;
    int puissance = 1;
    for (int i = 0; i < strlen(bin); i++)
    {
        
        if (bin[ strlen(bin)-i-1] == '1'){
            res += puissance;
        }
        puissance *= 2;

    }
    sprintf(dec, "%d", res);
}


void DecToBin(char dec[], char bin[]){
    int a = 0 ;
    int actual = atoi(dec);
    char binres[100] = {0} ;

    while (actual > 0){
        if (actual % 2){
            binres[a] = '1';
        }
        else {
            binres[a] = '0';
        }

        actual /= 2;
        a++;
    }

    for (int i = 0; i < 100; i++) {
        bin[i] = binres[ 99 - i];
        
    }

    

}



int main(void){
    char bin[100] ;
    char dec[100];
    printf("Enter binary number: ");
    scanf("%s", dec);
    DecToBin(dec, bin);
    
    for (int i = 0; i < 100; i++) {
        printf("%c", bin[i])     ;   
    }
    printf("%s in decimal is %s\n", bin, dec);
    return 0;
}