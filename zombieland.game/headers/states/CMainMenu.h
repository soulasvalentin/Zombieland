#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED
#include "CMenu.h"

/**
    ************************
    * CLASS CMAINMENU
    ************************

*/

class CMainMenu : public CMenu
{

public:
    void open_mainmenu();
    void render_mainmenu();

    CMainMenu() : CMenu("JUGAR", "OPCIONES", "AYUDA", "SALIR") {}
};

///*********************************************
///*             OPEN MAINMENU
///*********************************************

void CMainMenu::open_mainmenu()
{

    source = MAINMENU;

    //-------------------------------
    //  LEER IMPUTS
    //-------------------------------

    switch (read_imput())
    {

    case BACK:
        GameState.changeState(EXIT);
        break;
    case SELECT:

        //---------------------------------------
        //  CAMBIAR DE ESTADO SEGUN 'SELECTION'
        //---------------------------------------

        switch (selection)
        {
        case 0:
            GameState.changeState(PRE_GAME);
            break;
        case 1:
            GameState.changeState(OPTIONS);
            break;
        case 2:
            GameState.changeState(HELP);
            break;
        case 3:
            GameState.changeState(EXIT);
            break;
        }
        break;
    }
}

///*********************************************
///*            RENDER MAINMENU
///*********************************************

void CMainMenu::render_mainmenu()
{

    //-------------------------------
    //  MOSTRAR LA SELECCI�N
    //-------------------------------

    render_selection();

    //-------------------------------
    //  MOSTRAR LAS OPCIONES
    //-------------------------------

    render_options();
}

#endif // MAINMENU_H_INCLUDED
