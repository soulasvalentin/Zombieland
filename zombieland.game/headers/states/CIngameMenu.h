#ifndef INGAMEMENU_H_INCLUDED
#define INGAMEMENU_H_INCLUDED
#include "CMenu.h"

/**
    ************************
    * CLASS CINGAMEMENU
    ************************

*/

class CIngameMenu : public CMenu
{

public:
    void open_ingamemenu();
    void render_ingamemenu();

    CIngameMenu() : CMenu("CONTINUAR", "TIENDA", "GUARDAR", "OPCIONES", "AYUDA", "MENU PRINCIPAL") {}
};

///*********************************************
///*            OPEN INGAMEMENU
///*********************************************

void CIngameMenu::open_ingamemenu()
{

    source = INGAMEMENU;

    //-------------------------------
    //  LEER IMPUTS
    //-------------------------------

    switch (read_imput())
    {

    case BACK:
        GameState.changeState(PLAYING);
        break;
    case SELECT:

        //---------------------------------------
        //  CAMBIAR DE ESTADO SEGUN 'SELECTION'
        //---------------------------------------

        switch (selection)
        {
        case 0:
            GameState.changeState(PLAYING);
            break;
        case 1:
            GameState.changeState(STORE);
            break;
        case 2:
            if (!GameState.getSaved())
                GameState.changeState(SAVE_GAME);
            break;
        case 3:
            GameState.changeState(OPTIONS);
            break;
        case 4:
            GameState.changeState(HELP);
            break;
        case 5:
            GameState.changeState(MAINMENU);
            break;
        }
        break;
    }
}

///*********************************************
///*            RENDER INGAMEMENU
///*********************************************

void CIngameMenu::render_ingamemenu()
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

#endif // INGAMEMENU_H_INCLUDED
