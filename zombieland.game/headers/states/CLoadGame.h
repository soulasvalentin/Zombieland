#ifndef CLOADGAME_H_INCLUDED
#define CLOADGAME_H_INCLUDED

class CLoadGame
{

private:
    int selected;
    int y_initial;
    int cant_saves;
    enum LOADGAME_STATE
    {
        START,
        UPDATE,
        LOAD
    };
    LOADGAME_STATE state;

public:
    void update_loadgame(CGame &);
    void render_loadgame();
    CLoadGame();
};

CLoadGame::CLoadGame()
{

    selected = 0;
    state = START;
}

void CLoadGame::update_loadgame(CGame &Game)
{

    if (state == START)
    {
        FILE *p;
        fopen_s(&p, "files/savegames.dat", "rb");
        if (p == NULL)
        {
            Error.open_error("Cargar Partida", "No hay partidas guardadas");
            GameState.changeState(PRE_GAME);
            state = START;
            return;
        }

        fseek(p, 0, 2);
        cant_saves = ftell(p) / sizeof(CGame);
        fclose(p);
        state = UPDATE;
        y_initial = (ALTO / 2) - ((cant_saves * 50) / 2);
    }
    else if (state == UPDATE)
    {

        if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
            switch (ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_UP:
            case ALLEGRO_KEY_W:
                if (selected > 0)
                    selected--;
                break;
            case ALLEGRO_KEY_DOWN:
            case ALLEGRO_KEY_S:
                if (selected < cant_saves)
                    selected++;
                break;
            case ALLEGRO_KEY_F1:
                if (GameState.getDebug_info())
                    GameState.changeDebug_info(false);
                else
                    GameState.changeDebug_info(true);
                break;
            case ALLEGRO_KEY_ENTER:
            case ALLEGRO_KEY_SPACE:
            case ALLEGRO_KEY_PAD_ENTER: // cargar juego
                state = LOAD;
                break;
            case ALLEGRO_KEY_ESCAPE:
                state = START;
                GameState.changeState(PRE_GAME);
                break;
            }
        else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {

            for (int i = 0; i < cant_saves; i++)

                if (collision::boundingBox_pixel(ANCHO / 2 - 200 + camx, y_initial + (i * 50) + camy, ANCHO / 2 + 200 + camx, y_initial + ((i + 1) * 50) + camy, x_mouse, y_mouse))
                {
                    selected = i;
                    // cargar juego
                    state = LOAD;
                }
        }
        else
        {

            for (int i = 0; i < cant_saves; i++)
                if (collision::boundingBox_pixel(ANCHO / 2 - 200 + camx, y_initial + (i * 50) + camy, ANCHO / 2 + 200 + camx, y_initial + ((i + 1) * 50) + camy, x_mouse, y_mouse))
                    selected = i;
        }
    }
    else if (state == LOAD)
    {

        CGame Game_aux;
        FILE *p;
        fopen_s(&p, "files/savegames.dat", "rb");
        fseek(p, selected * sizeof(CGame), 0);
        fread(&Game_aux, sizeof(CGame), 1, p);
        fclose(p);
        state = START;
        GameState.changeState(PLAYING);
        GameState.changeRunning(true);
        Game = Game_aux;
        camx = Game_aux.camx_aux;
        camy = Game_aux.camy_aux;
    }
}

void CLoadGame::render_loadgame()
{

    al_draw_scaled_bitmap(bmp_menu_select, 0, 0, al_get_bitmap_width(bmp_menu_select), al_get_bitmap_height(bmp_menu_select),
                          ANCHO / 2 + camx - 150, y_initial + (selected * 50) + camy, 300, al_get_bitmap_height(bmp_menu_select) + 5, 0);

    for (int i = 0; i < cant_saves; i++)
        al_draw_textf(dayslater36, al_map_rgb(255, 255, 20), ANCHO / 2 + camx, y_initial + (i * 50) + camy, ALLEGRO_ALIGN_CENTER, "Partida %i", i + 1);

    if (GameState.getDebug_info())
        al_draw_textf(keepcalm12, al_map_rgb(250, 250, 250), camx + 5, camy + 110, 0, "selected: %i", selected);
}

#endif // CLOADGAME_H_INCLUDED
