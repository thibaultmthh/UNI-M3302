#include <stdlib.h>
#include <stdio.h>
#include "image.h"

#define OK 	0  // les 2 codes retour possibles ...
#define ERREUR 	1  // ... de EcrireImagePGM

int EcrireImagePGM(const char* nomFichier, const t_image image){
    FILE* fichier =  fopen(nomFichier, "w");

    if (fichier == NULL){
        printf("Ouverture du fichier impossible");
        return ERREUR;
    }

    fprintf(fichier, "P5\n%d %d\n255\n",image.largeur ,  image.hauteur );
    fwrite(image.pixels, sizeof(char), image.largeur *  image.hauteur, fichier);
    fclose(fichier);
    return OK;
}



t_image* LireImagePGM(const char* nomFichier){
    FILE* fichier =  fopen(nomFichier, "r");

    if (fichier == NULL){
        printf("Ouverture du fichier impossible");
        return ERREUR;
    }

    int largeur, hauteur;
    fscanf(fichier, "P5\n%d %d\n255\n", &largeur, &hauteur);
    t_image* image = CreerImage(largeur, hauteur);
    fread(image->pixels, largeur * hauteur, sizeof(char), fichier);
    fclose(fichier);
    return image;
}

