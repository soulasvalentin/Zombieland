#ifndef CMENU_H_INCLUDED
#define CMENU_H_INCLUDED

class CMenu
{

private:
    char (*vOpc)[20];
    int y_initial;
    int options;
    int prev_selection;

    void init();
    void play_sound();

protected:
    int selection;

    MENU_ACTION menu_action;
    MENU_ACTION read_imput();

    void render_options();
    void render_selection();

    int getY_initial() { return y_initial; }

public:
    //---------------------------------------------
    //  CONSTRUCTORES SOBRECARGADOS
    //  CRITERIO: CANTIDAD DE OPCIONES DEL MENU
    //---------------------------------------------

    CMenu(const char *opc1, const char *opc2);
    CMenu(const char *opc1, const char *opc2, const char *opc3);
    CMenu(const char *opc1, const char *opc2, const char *opc3, const char *opc4);
    CMenu(const char *opc1, const char *opc2, const char *opc3, const char *opc4, const char *opc5);
    CMenu(const char *opc1, const char *opc2, const char *opc3, const char *opc4, const char *opc5, const char *opc6);
    CMenu(const char *opc1, const char *opc2, const char *opc3, const char *opc4, const char *opc5, const char *opc6, const char *opc7);
    CMenu(const char *opc1, const char *opc2, const char *opc3, const char *opc4, const char *opc5, const char *opc6, const char *opc7, const char *opc8);
};

void CMenu::init()
{

    //-------------------------------
    //  INICIALIZAR EL OBJETO
    //  LLAMADO POR EL CONSTRUCTOR
    //-------------------------------

    vOpc = new char[options][20];
    y_initial = (ALTO / 2) - ((options * 50) / 2);
    selection = 0;
    menu_action = NONE;
}

void CMenu::play_sound()
{

    al_play_sample(audios[4], .5, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
}

///*********************************************
///*            IMPUTS
///*********************************************

MENU_ACTION CMenu::read_imput()
{

    y_initial = (ALTO / 2) - ((options * 50) / 2);

    //-------------------------------
    //  IMPUT DE DISPLAY
    //-------------------------------

    if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    {
        GameState.changeState(EXIT);
        return QUIT;
    }

    //-----------------------------------------------
    //  IMPUT DE TECLADO
    //  MUEVE LA SELECCI�N. DEVUELVE 'MENU_ACTION'
    //-----------------------------------------------

    else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
    {

        switch (ev.keyboard.keycode)
        {

        case ALLEGRO_KEY_S:
        case ALLEGRO_KEY_DOWN:
            selection++;
            if (selection > options - 1)
                selection = 0;
            return GODOWN;
            break;

        case ALLEGRO_KEY_W:
        case ALLEGRO_KEY_UP:
            selection--;
            if (selection < 0)
                selection = options - 1;
            return GOUP;
            break;

        case ALLEGRO_KEY_SPACE:
        case ALLEGRO_KEY_PAD_ENTER:
        case ALLEGRO_KEY_ENTER:
            return SELECT;
            break;
        case ALLEGRO_KEY_BACKSPACE:
        case ALLEGRO_KEY_ESCAPE:
            return BACK;
            break;
        case ALLEGRO_KEY_F1:
            if (GameState.getDebug_info())
                GameState.changeDebug_info(false);
            else
                GameState.changeDebug_info(true);
            break;
        }

        //--------------------------------------------------------
        //  IMPUT POR MOUSEOVER + CLICK. DEVUELVE 'MENU_ACTION'
        //--------------------------------------------------------
    }
    else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {

        for (int i = 0; i < options; i++)

            if (collision::boundingBox_pixel(ANCHO / 2 - 200 + camx, y_initial + (i * 50) + camy, ANCHO / 2 + 200 + camx, y_initial + ((i + 1) * 50) + camy, x_mouse, y_mouse))
            {
                selection = i;
                return SELECT;
            }
    }
    else
    {

        for (int i = 0; i < options; i++)
            if (collision::boundingBox_pixel(ANCHO / 2 - 200 + camx, y_initial + (i * 50) + camy, ANCHO / 2 + 200 + camx, y_initial + ((i + 1) * 50) + camy, x_mouse, y_mouse))
                selection = i;
    }

    //-------------------------------
    //  REPRODUCE SONIDO AL CAMBIAR LA SELECCION
    //-------------------------------

    if (selection != prev_selection)
        play_sound();
    prev_selection = selection;

    return NONE;
}

///*********************************************
///*            RENDERIZADO
///*********************************************

void CMenu::render_options()
{

    al_draw_bitmap(bmp_zombieland, ANCHO / 2 - 275 + camx, 20 + camy, 0);

    for (int i = 0; i < options; i++)
    {

        al_draw_text(dayslater36, al_map_rgb(255, 255, 20), ANCHO / 2 + camx, y_initial + (i * 50) + camy, ALLEGRO_ALIGN_CENTER, vOpc[i]);
        al_draw_rectangle(ANCHO / 2 - 200 + camx, y_initial + (i * 50) + camy, ANCHO / 2 + 200 + camx, y_initial + ((i + 1) * 50) + camy, al_map_rgb(255, 255, 255), 1);
    }
}

void CMenu::render_selection()
{

    al_draw_scaled_bitmap(bmp_menu_select, 0, 0, al_get_bitmap_width(bmp_menu_select), al_get_bitmap_height(bmp_menu_select),
                          ANCHO / 2 - (strlen(vOpc[selection]) * 20) + camx, y_initial + (selection * 50) + camy, strlen(vOpc[selection]) * 40,
                          al_get_bitmap_height(bmp_menu_select) + 5, 0);

    if (GameState.getDebug_info())
        al_draw_textf(keepcalm12, al_map_rgb(250, 250, 250), camx + 5, camy + 110, 0, "selection: %i", selection);
}

///*********************************************
///*            CONSTRUCTORES
///*********************************************

CMenu::CMenu(const char *opc1, const char *opc2)
{

    options = 2;
    init();

    strcpy_s(vOpc[0], opc1);
    strcpy_s(vOpc[1], opc2);
}

CMenu::CMenu(const char *opc1, const char *opc2, const char *opc3)
{

    options = 3;
    init();

    strcpy_s(vOpc[0], opc1);
    strcpy_s(vOpc[1], opc2);
    strcpy_s(vOpc[2], opc3);
}

CMenu::CMenu(const char *opc1, const char *opc2, const char *opc3, const char *opc4)
{

    options = 4;
    init();

    strcpy_s(vOpc[0], opc1);
    strcpy_s(vOpc[1], opc2);
    strcpy_s(vOpc[2], opc3);
    strcpy_s(vOpc[3], opc4);
}

CMenu::CMenu(const char *opc1, const char *opc2, const char *opc3, const char *opc4, const char *opc5)
{

    options = 5;
    init();

    strcpy_s(vOpc[0], opc1);
    strcpy_s(vOpc[1], opc2);
    strcpy_s(vOpc[2], opc3);
    strcpy_s(vOpc[3], opc4);
    strcpy_s(vOpc[4], opc5);
}

CMenu::CMenu(const char *opc1, const char *opc2, const char *opc3, const char *opc4, const char *opc5, const char *opc6)
{

    options = 6;
    init();

    strcpy_s(vOpc[0], opc1);
    strcpy_s(vOpc[1], opc2);
    strcpy_s(vOpc[2], opc3);
    strcpy_s(vOpc[3], opc4);
    strcpy_s(vOpc[4], opc5);
    strcpy_s(vOpc[5], opc6);
}

CMenu::CMenu(const char *opc1, const char *opc2, const char *opc3, const char *opc4, const char *opc5, const char *opc6, const char *opc7)
{

    options = 7;
    init();

    strcpy_s(vOpc[0], opc1);
    strcpy_s(vOpc[1], opc2);
    strcpy_s(vOpc[2], opc3);
    strcpy_s(vOpc[3], opc4);
    strcpy_s(vOpc[4], opc5);
    strcpy_s(vOpc[5], opc6);
    strcpy_s(vOpc[6], opc7);
}

CMenu::CMenu(const char *opc1, const char *opc2, const char *opc3, const char *opc4, const char *opc5, const char *opc6, const char *opc7, const char *opc8)
{

    options = 8;
    init();

    strcpy_s(vOpc[0], opc1);
    strcpy_s(vOpc[1], opc2);
    strcpy_s(vOpc[2], opc3);
    strcpy_s(vOpc[3], opc4);
    strcpy_s(vOpc[4], opc5);
    strcpy_s(vOpc[5], opc6);
    strcpy_s(vOpc[6], opc7);
    strcpy_s(vOpc[7], opc8);
}

#endif // CMENU_H_INCLUDED
