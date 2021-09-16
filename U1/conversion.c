#include <stdio.h>
#include <stdlib.h>

float conversion(float f){
    return (f -32) * (5.0/9.0);
}

int main(void){
    
    for(int i; i < 50; i += 10)

{    printf("%d : En Celcius c'est : %f\n" ,i, conversion(i));
}}