#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "objetos.h"

void inicialization(bool init,const char* description)
{
    if(init) return;
    printf("Não foi possível inicializar %s",description);
    exit(1);
}

void menu()
{

    ALLEGRO_BITMAP* menubackground = al_load_bitmap("menubackgroud.png");
    inicialization(menubackground,"menu background");
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    inicialization(timer,"timer");
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    inicialization(queue,"fila");
    ALLEGRO_DISPLAY* disp = al_create_display(1280,720);
    inicialization(disp,"display");
    ALLEGRO_FONT* font = al_load_font("burbank.ttf",60,0);
    inicialization(font,"fonte");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer);

    while(1)
    {
        al_wait_for_event(queue, &event);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                // game logic goes here.
                redraw = true;
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }

        if(done){
            al_stop_timer(timer);
            break;
        }

        if(redraw && al_is_event_queue_empty(queue))
        {
            al_draw_bitmap(menubackground,0,0,1);
            al_draw_text(font, al_map_rgb(255, 255, 255),400,360,0, "Pressione Qualquer Tecla");
            al_flip_display();
            redraw = false;
        }
    }

    al_destroy_bitmap(menubackground);
    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
}


int main()
{

/*===============Inicialização do programa=====================
===============================================================
===============================================================*/

    inicialization(al_init(),"allegro");
    inicialization(al_install_keyboard(),"teclado");
    inicialization(al_install_mouse(),"mouse");
    inicialization(al_init_ttf_addon(),"ttf addon");
    inicialization(al_init_font_addon(),"fonte");
    inicialization(al_init_image_addon(),"imagem addon");
    inicialization(al_init_primitives_addon(),"primitivos falharam");
    
/*===========================================================================
=============================================================================
=============================================================================*/

    menu(); // menu do jogo

/*===========================GAME LOGIC===========================================
==================================================================================
============================================================================*/   

/*================= GAME LOGIC INICIALIZAÇÃO ================================*/
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    inicialization(timer,"timer");
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    inicialization(queue,"fila");
    ALLEGRO_DISPLAY* disp = al_create_display(1280,720);
    inicialization(disp,"display");
    ALLEGRO_FONT* font = al_load_font("burbank.ttf",60,0);
    inicialization(font,"fonte");
    ALLEGRO_BITMAP* fundojogo = al_load_bitmap("fundojogo.png");
    inicialization(fundojogo,"fundo do jogo");
    ALLEGRO_BITMAP* icone = al_load_bitmap("icone.png");
    inicialization(icone,"icone");
    ALLEGRO_EVENT event;
/*==========================================================================*/    

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

/*============================VARIÁVEIS PRIMITIVAS===========================*/
    bool redraw = true;
    bool done = false;
    elemento jogo_da_memoria[2][4];
    retangulo hitboxes[8];
    float x=100,y=100;
    float icone_x=50, icone_y=100;

/*=========================================================================*/
    jogo_da_memoria[0][0].identidade = 1;
    jogo_da_memoria[0][1].identidade = 2;
    jogo_da_memoria[0][2].identidade = 3;
    jogo_da_memoria[0][3].identidade = 1;
    jogo_da_memoria[1][0].identidade = 3;
    jogo_da_memoria[1][1].identidade = 2;
    jogo_da_memoria[1][2].identidade = 4;
    jogo_da_memoria[1][3].identidade = 4;

    al_start_timer(timer);
    while(1)
    {
        al_wait_for_event(queue, &event);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                
                redraw = true;
                break;
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                 x= event.mouse.x;
                 y= event.mouse.y;
                 for(int k =0;k<8;k++){
                    if(x >= hitboxes[k].x1 && x<= hitboxes[k].x2 && y<=hitboxes[k].y2 && y>=hitboxes[k].y1){
                        
                    }
                 }
                 break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }

        if(done)
            break;

        if(redraw && al_is_event_queue_empty(queue))
        {
            al_draw_bitmap(fundojogo,0,0,0);
            for(int i=0;i<2;i++){
                for(int j=0;j<4;j++){
                    hitboxes[(i * 4)+ j].x1 = icone_x;
                    hitboxes[(i * 4)+ j].y1 = icone_y;
                    hitboxes[(i * 4)+ j].x2 = icone_x + 236;
                    hitboxes[(i * 4)+ j].y2 = icone_y + 200;
                    //al_draw_filled_rectangle(icone_x,icone_y,icone_x + 236,icone_y + 200,al_map_rgb(255,0,0));
                    al_draw_bitmap(icone,icone_x,icone_y,0);
                    icone_x+= 300;
                }
                icone_y+=350;
                icone_x=50;
            }
            al_flip_display();
            redraw = false;
            icone_x=50;
            icone_y=100;
        }
    }

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}