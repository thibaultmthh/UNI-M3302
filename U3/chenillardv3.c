#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define ON '1'
#define OFF '0'
#define NUMBER 150
#define TEMP 100


typedef unsigned int interrupteurs_t ;

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

int ValeurAmpoule(interrupteurs_t inter, int i){
    interrupteurs_t masque = 1;
    masque <<= i;
    if ( (inter & masque ) > 0){
        return 1;
    } else {
        return 0;
    }

    
}

interrupteurs_t Inversion(interrupteurs_t inter){
    return ~inter;
}


interrupteurs_t Compteur(interrupteurs_t inter){
    return inter + 0x1;
}

interrupteurs_t RotationGauche(interrupteurs_t inter){
    interrupteurs_t masque = 1;
    masque <<= 8*sizeof(interrupteurs_t)-1 ;
    if ( (inter & masque ) > 0){
        inter ++;
    } 

    return inter << 1;
}

interrupteurs_t RotationDroite(interrupteurs_t inter){
    interrupteurs_t masque = 1;
    
    if ( (inter & masque ) > 0){

        interrupteurs_t masque2 = 1;
        masque2 <<= 8*sizeof(interrupteurs_t)-1;
        inter = (inter>>1) + masque2;
        return inter;
        
    } 
    return inter >> 1;
}


int main(void){
    interrupteurs_t inter = 0xAA; // les interrupteurs qui pilotent les ampoules
    int number = 8*sizeof(interrupteurs_t);
    unsigned char rampe[ 8*sizeof(interrupteurs_t)+1]={0}; // les ampoules que l'on affiche


    

    while(1){
        for(int z = 0; z < number; z++){
        rampe[z] = OFF;
        }
        inter = RotationDroite(inter);
        printf("\r");
        for(int i = 0; i < number; i++){
            if (ValeurAmpoule(inter, i)){
                rampe[i] = ON;
            }

        }
        for (int y = 0; y < number; y++){
            printf("%c", rampe[y]);

        }          
        Temporisation(TEMP);
        fflush(stdout) ;
    }

    return 0;

}

