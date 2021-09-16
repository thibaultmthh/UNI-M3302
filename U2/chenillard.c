#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define ON '*'
#define OFF '.'
#define NUMBER 150
#define TEMP 10

void Temporisation(int n)
//------------------------------------------------------------------------------
// Fonction qui met n milli-secondes a s'executer
// C'est donc une temporisation de n ms
// necessite <stdio.h>
{
	clock_t start, stop ;

	n = n*CLOCKS_PER_SEC/1000 ; // clock() ne fonctionne pas forcement en milli-secondes
	start = clock() ;           // Top depart. start = l'heure de depart
	stop = start + n ;          // stop = l'heure de fin

	while(clock() < stop)       // On scrute l'heure tant qu'on n'a pas atteint la fin
	{
	} 
}

void main(void){
    char rampe[NUMBER] = {OFF};

    for(int z = 0; z < NUMBER; z++){
        rampe[z] = OFF;
    }

    while(1){

        for(int i = 0; i < NUMBER; i++){
            printf("\r");
    
            rampe[i] = ON;
            for (int y = 0; y < NUMBER; y++)
            {
                printf("%c", rampe[y]);

            }
            
            rampe[i] = OFF;
            Temporisation(TEMP);
            fflush(stdout) ;

        }
    }

}

