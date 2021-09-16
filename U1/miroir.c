#include <stdio.h>
#include <stdlib.h>


// do the mirror of the string into another string
// ex: "bonjour" -> "rojnub"

int main(void) {
    
    char ch[64] = "bonjour";
    char ch1[64] = "xxxxxxxxxxxxxxxxx";

    for (int i = 0; i < 64; i++) {
        ch1[i] = ch[ 63 - i];
    }
    
    printf("\n");
    for (int i2 = 0; i2 < 64; i2++)
    {
        printf("%c", ch1[i2]);
    }
    printf("\n");
    
    return 0;
}

