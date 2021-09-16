typedef struct Image
{
  unsigned char* pixels ;
  unsigned int largeur ;
  unsigned int hauteur ;
} t_image ;

#define DEBUG 	0  // utilis� en interne dans le module entree_sortie.c
#define OK 	0  // les 2 codes retour possibles ...
#define ERREUR 	1  // ... de EcrireImagePGM

//----------------------------------------------------------------------
// LireImagePGM fait les allocations m�moires pour cr�er la structure
// et la zone pour stocker les pixels
// elle lit le fichier image et initialise la structure.
// ele renvoie un pointeur sur la structure cr��e
//----------------------------------------------------------------------
t_image* LireImagePGM(const char* nomFichier) ;

//----------------------------------------------------------------------
// EcrireImagePGM �crit l'image stock�e dans la structure dans
// un fichier au format PGM dont le nom est pass� en param�tre.
// elle renvoie OK si l'�criture s'est bien d�roul�e, ERREUR sinon
//----------------------------------------------------------------------
int EcrireImagePGM(const char* nomFichier, const t_image im) ;
