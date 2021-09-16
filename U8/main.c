#include "traitement.h"
#include "entree_sortie.h"
#include <time.h>

int main(){

    clock_t cl1 = clock();

    t_image* imageUnie = LireImagePGM("guadalest.pgmx");


    // ImageUnie(imageUnie, 40);

    //Miroir(imageUnie, 0);

    int* historigrame = Histogramme(imageUnie);
    t_image* newImage = HistogrammeImage(historigrame, 300);


    EcrireImagePGM("imageUnie14.pgm", *newImage);
    // AfficherImage("imageUnie.pgm");
    LibererImage(imageUnie);
    LibererImage(newImage);
    free(historigrame);
    clock_t cl2 = clock();
    printf("%ld\n", cl2 - cl1 );

    return 0;
}
