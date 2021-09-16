#ifndef traitement_h
#define traitement_h

#include "image.h"


void ImageUnie(t_image* image, unsigned char couleur);

void Negatif(t_image* image);

void Seuillage(t_image* image,  unsigned char seuil );

void Degrade(t_image* image);

void Miroir(t_image* image, int type);

t_image* Rotation(t_image* image);

int* Histogramme(t_image* image);

t_image* HistogrammeImage(int* histo, int hauteur);



#endif




