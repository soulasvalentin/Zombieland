#ifndef HELP_H_INCLUDED
#define HELP_H_INCLUDED
#include "CMenu.h"

///*************************
///*   GAME STATE: HELP    *
///*************************

/**
    ************************
    * CLASS CHELP
    ************************

*/

class CHelp : public CMenu
{

private:
    enum
    {
        NONE,
        TECLAS,
        OBJETIVO
    };
    int state; // Opcion seleccionada
    ALLEGRO_BITMAP *bmp_teclas = NULL;
    ALLEGRO_BITMAP *bmp_objetivo = NULL;

public:
    void open_help();
    void render_help();
    void destroy_bitmaps();

    CHelp() : CMenu("TECLAS", "OBJETIVO", "VOLVER")
    {
        state = 0;
        bmp_teclas = al_load_bitmap("resources/menus/help/help.png");
        bmp_objetivo = al_load_bitmap("resources/menus/help/objetivo.png");
    }
};

//--------------------------------------------
//  VARIABLE QUE IDENTIFICA DE QUE MEN� VIENE
//--------------------------------------------

int source = 0;

///*********************************************
///*              OPEN HELP
///*********************************************

void CHelp::open_help()
{

    //-------------------------------
    //  LEER IMPUTS
    //-------------------------------

    switch (read_imput())
    {

    case BACK:
        if (state == NONE)
        {
            if (source == MAINMENU)
                GameState.changeState(MAINMENU);
            else
                GameState.changeState(INGAMEMENU);
        }
        else
            state = NONE;
        break;

    case SELECT:

        //---------------------------------------
        //  CAMBIAR DE ESTADO SEGUN 'SELECTION'
        //---------------------------------------

        switch (selection)
        {
        case 0:
            state = TECLAS;
            break;
        case 1:
            state = OBJETIVO;
            break;
        case 2:
            if (source == MAINMENU)
                GameState.changeState(MAINMENU);
            else
                GameState.changeState(INGAMEMENU);
            break;
        }
        break;
    }
}

///*********************************************
///*              RENDER HELP
///*********************************************

void CHelp::render_help()
{

    //-----------------------------------------
    //  DIBUJA EL SUB ESTADO CORRESPONDIENTES
    //-----------------------------------------

    if (state == 0)
    {

        //-------------------------------
        //  MOSTRAR SELECCI�N
        //-------------------------------

        render_selection();

        //-------------------------------
        //  MOSTRAR OPCIONES
        //-------------------------------

        render_options();
    }
    else if (state == 1)
    {

        // Informacion de las teclas
        al_draw_bitmap(bmp_teclas, ANCHO / 2 - al_get_bitmap_width(bmp_teclas) / 2 + camx, ALTO / 2 - al_get_bitmap_height(bmp_teclas) / 2 + camy, 0);
    }
    else if (state == 2)
    {

        // Informaci�n del objetivo
        al_draw_bitmap(bmp_objetivo, ANCHO / 2 - al_get_bitmap_width(bmp_teclas) / 2 + camx, ALTO / 2 - al_get_bitmap_height(bmp_teclas) / 2 + camy, 0);
    }
}

//-------------------------------
//  DESTRUIR BITMAPS
//-------------------------------

void CHelp::destroy_bitmaps()
{

    al_destroy_bitmap(bmp_teclas);
}

#endif // HELP_H_INCLUDED
