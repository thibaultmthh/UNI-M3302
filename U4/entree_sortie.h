#define DEBUG 	1  // utilis� en interne dans le module entree_sortie.c 
#define OK 	0  // les 2 codes retour possibles ...
#define ERREUR 	1  // ... de EcrireImagePGM

// on passe un nom de fichier et l'adresse de 2 entiers
// la fonction alloue de la m�moire pour stocker les pixels lus
// elle retourne l'adresse o� sont rang�s les pixels
// et renseigne la largeur et la hauteur de l'image
// c'est � l'appelant de lib�rer (free) la m�moire allou�e 
unsigned char* LireImagePGM(const char* nomFichier, int* largeur, int* hauteur) ;

// On passe un nom de fichier, l'adresse des pixels de l'image et ses dimensions
// La fonction retourne OK si l'�criture r�ussit et ERREUR en cas d'�chec
int EcrireImagePGM(const char* nomFichier, const unsigned char* buffer, const int largeur, const int hauteur) ;
