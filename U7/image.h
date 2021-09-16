#ifndef image_h
#define image_h

#define DEBUG 0


typedef struct Image
{
  unsigned char* pixels ;
  unsigned int largeur ;
  unsigned int hauteur ;
} t_image ;

t_image* CreerImage(int largeur, int hauteur);

void LibererImage(t_image* image);

void AfficherImage(char *nomImage);


#endif

