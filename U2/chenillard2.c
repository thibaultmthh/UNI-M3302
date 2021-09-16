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

void chenillard(int number, int temp, char on, char off){
    char rampe[number] ;

    for(int z = 0; z < number; z++){
        rampe[z] = off;
    }

    while(1){

        for(int i = 0; i < number; i++){
            printf("\r");
    
            rampe[i] = on;
            for (int y = 0; y < number; y++)
            {
                printf("%c", rampe[y]);

            }
            
            rampe[i] = off;
            Temporisation(temp);
            fflush(stdout) ;

        }
    }

}


int main(int argc, char const *argv[]){

    int number = NUMBER;
    int temp = TEMP;
    char on = ON;
    char off = OFF;

    if(argc != 9){
        printf("Usage : %s [-o <car_ampoule_allumee>] [-f <car_ampoule_eteinte>] [-t <temporisation>] [-n <nombre_d_ampoules>]  %d \n", argv[0], argc);
    }

    for (int i = 0; i < argc; i++){
        if (argv[i][0] == '-'){
            if (argv[i][1] == 'n'){
                number = atoi(argv[i+1]);
            }
            if (argv[i][1] == 't'){
                temp = atoi(argv[i+1]);
            }
            if (argv[i][1] == 'o'){
                on = argv[i+1][0];
            }
            if (argv[i][1] == 'f'){
                off = argv[i+1][0];
            }


        }
        

    }

    
    


    chenillard(number, temp, on, off);
    return 0;
}

