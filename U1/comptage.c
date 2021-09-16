#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
#define OK 0
#define FIN 1

int LireUneLigne(char*buf, int size, FILE* f)

{
	char trash[64] ;  // chaine poubelle
	char* res ;       // retour de la fonction fgets
		
	res = fgets(buf, size, f) ; // recupere le debut dans buf
	if (!res)
		return FIN ;

	if (strchr(buf, '\n') == NULL) 
	{      // on n'a pas lu le RC donc on n'a pas tout lu
		do // on jette la suite
		{
			res = fgets(trash, 64, f) ;
			if (res == NULL)
				return FIN ;
			//printf("*jette:%s*\n", trash) ;		
		}
		while (strchr(trash, '\n') == NULL) ;
	}
	else
	{
		*strchr(buf, '\n') = '\0' ; // remplace '\n' par '\0'
	}
		
	return OK ;			
}



int main(void){
    char buf[64] ;
    int compteur[128] = {0} ;

    printf("Entrez une ligne: ") ;
    LireUneLigne(buf, 64, stdin) ;
    printf("Vous avez tape: %s\n", buf) ;


    for(int i = 0; i < strlen(buf); i++){
        compteur[(int)buf[i]]++;
    }

    for(int i = 0; i < 128; i++){
        if (compteur[i] > 0){
            printf("%c : %d\n", i, compteur[i]);
            }
    }

   
    return 0;

}