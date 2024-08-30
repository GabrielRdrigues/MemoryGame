#pragma once
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <stdbool.h>


typedef struct Retangulo{
    float x1,y1,x2,y2;
}retangulo;

typedef struct elemento{
    int identidade;
    retangulo hitbox;
    ALLEGRO_BITMAP* desenho;
    bool clicado;
}elemento;
