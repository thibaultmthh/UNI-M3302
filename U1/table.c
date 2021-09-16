#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, j;
    printf("Vous voulez la table de combien ? : \n");
    scanf("%d", &i);
    for (j = 1; j <= 10; j++) {
        printf("%d * %d = %d\n", i, j, i * j);
    }
    return 0;
}

