#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int CompteOccurence(char* string, char* substring){
    int len = strlen(string);

    int subLen = strlen(substring);

    int x = 0;
    int count = 0;

    for (int i = 0; i < len; i++)
    {
        /* code */
        if (string[i] == substring[x]){
            //
            printf("%c, %c\n",string[i]  ,substring[x] );
            x++;
        }

        if (x==subLen){
            x = 0;
            printf("%d , %d \n", x, subLen-1);
            count++;
        }

    }
    return count;
    
}

void GenTriangle(int n ){
    // int n = atoi(argv[1]);
    int* triangel[100];

    int l = 1;

    triangel[0] = malloc(sizeof(int) );
    triangel[0][0] = 1;
    triangel[0][1] = 1;

    for (int i = 1; i < n; i++)
    {
        triangel[i] = malloc(sizeof(int)*l+1);
        triangel[i][l - 1] = 1;
        triangel[i][0] = 1;
        printf("n%d :  \t", i-1);
        for (int pL = 0; pL < l; pL++){
            //
            int val = triangel[i-1][pL - 1] + triangel[i-1][pL];
            triangel[i][pL] = val;
            printf("%d\t", val);
        }
        printf("\n\n");
        l ++;

    }
}


int main(int argc, char const *argv[])
{
    char* chain1 = "coucou c'est moi coucou th";
    char* chain2 = "cou";
    int val = CompteOccurence(chain1, chain2);
    printf("%d is oc \n", val);
    return 0;
}
