#include "traitement.h"

#define SEUIL(valeur, seuil) (valeur < seuil) ? 0 : 255 ;


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

#define MIROIR_HORIZONTAL 1
#define MIROIR_VERTICAL 0

void Miroir(t_image* image, int type){
    if (type == MIROIR_HORIZONTAL){
        for (unsigned int i = 0; i < image->largeur/2; i++)
        {
            for (unsigned int y = 0; y < image->hauteur; y++)
            {
                int pos = image->largeur * y + i;
                int posDest = image->largeur * y + image->largeur - i;
                char tmp = image->pixels[pos];
                image->pixels[pos] = image->pixels[posDest];
                image->pixels[posDest] = tmp;
            }  
        }
        
    } else {
        for (unsigned int i = 0; i < image->largeur; i++)
        {
            for (unsigned int y = 0; y < image->hauteur/2; y++)
            {
                int pos = image->largeur * y + i;

                int posDest = image->largeur * (image->hauteur - y) + i;

                char tmp = image->pixels[pos];
                image->pixels[pos] = image->pixels[posDest];
                image->pixels[posDest] = tmp;
            }  
        }
        
    }

}

t_image* Rotation(t_image* image){
    t_image* newImage = CreerImage(image->hauteur,image->largeur);
    int newPos = 0;
    for (unsigned int i = 0; i < image->largeur; i++)
    {
        for (unsigned int y = 0; y < image->hauteur; y++)
        {
            int pos = image->largeur * y + i;
            newImage->pixels[newPos] =  image->pixels[pos];
            newPos ++;
        }  
    }
    return newImage;
    
}

 int* Histogramme(t_image* image){
    int size = image->hauteur * image->largeur;

    int* compteur = malloc(sizeof(int) *255);

    for ( int i = 0; i < 255; i++)
    {
        compteur[i]  = 0;
    }  

    for ( int i = 0; i < size; i++)
    {
        int val = image->pixels[i];
        compteur[val]++;
    }   

    // for(int i = 0; i < 255; i++ ){
    //     printf("Couleur : %d -> V = %ld\n", i, compteur[i]);
    // }


    return compteur;
}



 int max( int* array, int size){
     int max = 0;
    for ( int i = 0; i < size; i++)
        {
            if (array[i]> max){
                max = array[i];
            }
        }
    return max;
}


t_image* HistogrammeImage( int* histo, int hauteur){
    t_image* image = CreerImage(256, hauteur);

    for (unsigned int i = 0; i < image->largeur; i++)
        {
            int valeur = histo[i];
            unsigned int hmax = 0;
            hmax = ((long)valeur*(long)hauteur)/(long)max(histo, 255);

            for (unsigned int y = 0; y < image->hauteur; y++)
            {
                unsigned int pos = image->largeur * y + i;
                if (hauteur-y > hmax){
                    image->pixels[pos] = 0;
                } else {
                    image->pixels[pos] = 255;
                }
            }  
    }
    return image;
}