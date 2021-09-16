#include "traitement.h"
#include "image.h"
#include "entree_sortie.h"
#include <time.h>

int main(){

    clock_t cl1 = clock();

    t_image* imageUnie = LireImagePGM("guadalest.pgmx");
    for(int i = 0; i < 200; i++){


    // ImageUnie(imageUnie, 40);

    Seuillage(imageUnie, 50);


}
    EcrireImagePGM("imageUnie.pmg", *imageUnie);
    // AfficherImage("imageUnie.pmg");
    LibererImage(imageUnie);
    clock_t cl2 = clock();
    printf("%ld\n", cl2 - cl1 );

    return 0;
}