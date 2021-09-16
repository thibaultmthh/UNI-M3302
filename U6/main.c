#include <stdlib.h>
#include <stdio.h>

#define OK 	0  // les 2 codes retour possibles ...
#define ERREUR 	1  // ... de EcrireImagePGM

typedef struct Image
{
  unsigned char* pixels ;
  unsigned int largeur ;
  unsigned int hauteur ;
} t_image ;


t_image* CreerImage(int largeur, int hauteur){
    t_image* image = malloc(sizeof(t_image));
    image->pixels = malloc(largeur*hauteur);
    image->largeur = largeur;
    image->hauteur = hauteur;
    return image;
}

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

void AfficherImage(char *nomImage){
    char commande[100];
    sprintf(commande, "eog %s", nomImage);
    system(commande);
}

int main(){

    t_image* imageUnie = LireImagePGM("guadalest.pgmx");

    // ImageUnie(imageUnie, 40);

    EcrireImagePGM("imageUnie.pmg", *imageUnie);
    AfficherImage("imageUnie.pmg");


    LibererImage(imageUnie);
    return 0;
}
