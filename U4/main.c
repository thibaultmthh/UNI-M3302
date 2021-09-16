#include "entree_sortie.h"
#include <stdlib.h>
#include <stdio.h>


void AfficherImage(char *nomImage){
    char commande[100];
    sprintf(commande, "eog %s", nomImage);
    system(commande);
}

unsigned char * CreerImage(int largeur, int hauteur){
    unsigned char* image = malloc(largeur*hauteur);
    return image;
}

void ImageUnie(unsigned char * image, int largeur, int hauteur, unsigned char couleur){
    int size = largeur * hauteur;
    for (int i = 0; i < size; i++)
    {
        image[i] = couleur;
    }    
}

void Negatif(unsigned char* image, int largeur, int hauteur){
    int size = largeur * hauteur;
    for (int i = 0; i < size; i++)
    {
        image[i] = 255-image[i];
    }
}

void Seuillage(unsigned char* image, int largeur, int hauteur,  unsigned char seuil ){
    int size = largeur * hauteur;
    for (int i = 0; i < size; i++)
    {
        image[i] = image[i]- (image[i]%seuil);
    }
}

void Degrade(unsigned char* image, int largeur, int hauteur){

    int pas = (largeur*100)/255;

    int a = 0;

    for (int x = 0; x < largeur; x++)
    {   
        if (x*100>pas*a){
            a++;
        }

        for (int y = 0; y < hauteur; y++)
        {
            /* code */

            int couleur = (x*100)/(largeur)*255/100 ;

            image[y*largeur + x] = couleur;

            printf("c : %d x : %d  l : %d \n", couleur, x, largeur);
        }
        
    }
    
}


int main(){

    int largeur, hauteur;
    

    unsigned char* image = LireImagePGM("guadalest.pgm", &largeur, &hauteur);

    Seuillage(image, largeur, hauteur, 150);

    EcrireImagePGM("guadalest_copie.pgm", image, largeur, hauteur);
    // AfficherImage("guadalest_copie.pgm");



    int l2, h2;
    l2 = 900;
    h2 = 7;
    unsigned char* imageUnie = CreerImage(l2, h2);

    Degrade(imageUnie, l2,h2);

    EcrireImagePGM("imageUnie.pmg", imageUnie, l2, h2);
    AfficherImage("imageUnie.pmg");


    free(imageUnie);
    return 0;
}



