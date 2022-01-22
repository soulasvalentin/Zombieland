#ifndef GAMEOVER_H_INCLUDED
#define GAMEOVER_H_INCLUDED
#include "CMenu.h"

class CGameOver : public CMenu
{

public:
    void open_gameover(int);
    void render_gameover(int);

    CGameOver() : CMenu("VOLVER A INTENTARLO", "VER RANKINGS", "MENU PRINCIPAL") {}
};

void CGameOver::open_gameover(int score)
{

    //-------------------------------
    //  LEER IMPUTS
    //-------------------------------

    switch (read_imput())
    {

    case BACK:
        GameState.changeState(MAINMENU);
        break;
    case SELECT:

        //---------------------------------------
        //  CAMBIAR DE ESTADO SEGUN 'SELECTION'
        //---------------------------------------

        switch (selection)
        {
        case 0:
            GameState.changeState(START_PLAYING);
            break;
        //case 1: GameState.changeState(RANKING);         break;
        case 2:
            GameState.changeState(MAINMENU);
            break;
        }
        break;
    }
}

void CGameOver::render_gameover(int score)
{

    // MOSTRAR PUNTAJE

    al_draw_textf(keepcalm_med, al_map_rgb(200, 200, 20), ANCHO / 2 + camx, ALTO * 0.20 + camy,
                  ALLEGRO_ALIGN_CENTER, "PUNTAJE: %i", score);

    //-------------------------------
    //  MOSTRAR LA SELECCI�N
    //-------------------------------

    render_selection();

    //-------------------------------
    //  MOSTRAR LAS OPCIONES
    //-------------------------------

    render_options();
}

#endif // GAMEOVER_H_INCLUDED
