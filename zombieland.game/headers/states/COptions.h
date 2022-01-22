#ifndef COPTIONS_H_INCLUDED
#define COPTIONS_H_INCLUDED

/**
    ************************
    * CLASS CINGAMEMENU
    ************************

*/

class COptions : public CMenu
{

public:
    void open_options();
    void render_options_menu();

    COptions() : CMenu("PANTALLA COMPLETA", "VOLVER") {}
};

///*********************************************
///*            OPEN INGAMEMENU
///*********************************************

void COptions::open_options()
{

    //-------------------------------
    //  LEER IMPUTS
    //-------------------------------

    switch (read_imput())
    {

    case BACK:
        if (source == MAINMENU)
            GameState.changeState(MAINMENU);
        else
            GameState.changeState(INGAMEMENU);
        break;
    case SELECT:

        //---------------------------------------
        //  CAMBIAR DE ESTADO SEGUN 'SELECTION'
        //---------------------------------------

        switch (selection)
        {
        case 0:
            if (al_get_display_flags(display) == 552)
                al_toggle_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, 0);
            else
                al_toggle_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, 1);
            ANCHO = al_get_display_width(display);
            ALTO = al_get_display_height(display);
            break;
        case 1:
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
///*            RENDER OPTIONS
///*********************************************

void COptions::render_options_menu()
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

#endif // COPTIONS_H_INCLUDED
