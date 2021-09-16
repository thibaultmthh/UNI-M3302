#include "image.h"
#include <stdio.h>

#define SEUIL(valeur, seuil) (valeur < seuil) ? 0 : 255;

#if (DEBUG)
#define AFFICHER_FONCTION  printf("%s\n", __func__)

#else
#define AFFICHER_FONCTION 

#endif

void ImageUnie(t_image* image, unsigned char couleur){

    int size = image->largeur * image->hauteur;
    for (int i = 0; i < size; i++)
    {
        image->pixels[i] = couleur;
    }    
}

void Negatif(t_image* image){
    int size = image->largeur * image->hauteur;
    for (int i = 0; i < size; i++)
    {
        image->pixels[i] = 255-image->pixels[i];
    }
}

void Seuillage(t_image* image,  unsigned char seuil ){
    AFFICHER_FONCTION;
    int size = image->largeur * image->hauteur;
    for (int i = 0; i < size; i++){

        //  image->pixels[i] =  image->pixels[i]- ( image->pixels[i]%seuil);
        image->pixels[i] = SEUIL(image->pixels[i], seuil);
    }
}

void Degrade(t_image* image){

    int largeur = image->largeur;
    int hauteur = image->hauteur;


    for (int x = 0; x < largeur; x++)
    {   
        for (int y = 0; y < hauteur; y++)
        {
            int couleur = (x*100)/(largeur)*255/100 ;

            image->pixels[y*largeur + x] = couleur;
        }   
    }
}