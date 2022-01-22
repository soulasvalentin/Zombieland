#ifndef PRE_GAME_H_INCLUDED
#define PRE_GAME_H_INCLUDED
#include "CMenu.h"

/**
    ************************
    * CLASS CPREGAME
    ************************

*/

class CPreGame : public CMenu
{

public:
    void open_pregame();
    void render_pregame();

    CPreGame() : CMenu("NUEVA PARTIDA", "CONTINUAR", "CARGAR", "VOLVER") {}
};

///*********************************************
///*             OPEN PREGAME
///*********************************************

void CPreGame::open_pregame()
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
            imagen("resources/menus/help/objetivo.png", false);
            imagen("resources/menus/help/help.png", false);
            imagen("resources/menus/help/help_tienda.png", false);
            GameState.changeState(START_PLAYING);
            break;
        case 1:
            if (GameState.getRunning())
                GameState.changeState(PLAYING);
            break;
        case 2:
            GameState.changeState(LOAD_GAME);
            break;
        case 3:
            GameState.changeState(MAINMENU);
            break;
        }
        break;
    }
}

///*********************************************
///*              RENDER PREGAME
///*********************************************

void CPreGame::render_pregame()
{

    //-------------------------------
    //  MOSTRAR LA SELECCI�N
    //-------------------------------

    render_selection();

    //-------------------------------
    //  MOSTRAR OPCIONES DEL MENU
    //-------------------------------

    render_options();
}

#endif // PRE_GAME_H_INCLUDED
