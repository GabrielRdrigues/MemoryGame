#pragma once
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

typedef struct elemento{
    int identidade;
    ALLEGRO_BITMAP* desenho;
}elemento;

typedef struct Retangulo{
    float x1,y1,x2,y2;
}retangulo;