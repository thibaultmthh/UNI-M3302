#ifndef entree_sortie_h
#define entree_sortie_h
#include "image.h"

int EcrireImagePGM(const char* nomFichier, const t_image image);

t_image* LireImagePGM(const char* nomFichier);



#endif

