#include "entree_sortie.h"
#include <stdlib.h>
#include <stdio.h>


void AfficherImage(char *nomImage){
    char commande[100];
    sprintf(commande, "eog %s", nomImage);
    system(commande);
}

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
    int size = image->largeur * image->hauteur;
    for (int i = 0; i < size; i++){

         image->pixels[i] =  image->pixels[i]- ( image->pixels[i]%seuil);
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


int main(){

    // int largeur, hauteur;
    

    // unsigned char* image = LireImagePGM("guadalest.pgm", &largeur, &hauteur);

    // Seuillage(image, largeur, hauteur, 150);

    // EcrireImagePGM("guadalest_copie.pgm", image, largeur, hauteur);
    // // AfficherImage("guadalest_copie.pgm");



    int l2, h2;
    l2 = 900;
    h2 = 50;
    t_image* imageUnie = CreerImage(l2, h2);

    Degrade(imageUnie);

    EcrireImagePGM("imageUnie.pmg", *imageUnie);
    AfficherImage("imageUnie.pmg");


    LibererImage(imageUnie);
    return 0;
}



