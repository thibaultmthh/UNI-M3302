#include <stdlib.h>
#include <stdio.h>
#include "image.h"

t_image* CreerImage(int largeur, int hauteur){
    t_image* image = malloc(sizeof(t_image));
    image->pixels = malloc(largeur*hauteur);
    image->largeur = largeur;
    image->hauteur = hauteur;
    return image;
}

void LibererImage(t_image* image){
  free(image->pixels);
  free(image);
  }

void AfficherImage(char *nomImage){
    char commande[100];
    sprintf(commande, "eog %s", nomImage);
    system(commande);
}
