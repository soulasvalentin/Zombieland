#ifndef CGAMESTATE_H_INCLUDED
#define CGAMESTATE_H_INCLUDED

/**
    ************************
    * CLASS CGAMESTATE
    ************************

    Detalles:
        - Administra el estado del juego
*/

class CGameState
{

private:
    GAME_STATE state;
    bool running;    // Controla si hay una partida en curso
    bool saved;      // Controla si se guardo o no la partida
    bool debug_info; // Controla si se muestra info (debug) o no
    bool game_info;  // Controla si se muestra la informacion del juego
    bool redraw;     // Controla si es momento de renderizar
    bool dev_mode;   // Estado desarrollador

public:
    void changeState(GAME_STATE new_state) { state = new_state; }
    void changeRunning(bool _running) { running = _running; }
    void changeSaved(bool _saved) { saved = _saved; }
    void changeDebug_info(bool _debug_info) { debug_info = _debug_info; }
    void changeGame_info(bool _game_info) { game_info = _game_info; }
    void changeRedraw(bool _redraw) { redraw = _redraw; }
    void changeDev_mode(bool _dev_mode) { dev_mode = _dev_mode; }

    GAME_STATE getState() { return state; }
    bool getRunning() { return running; }
    bool getSaved() { return saved; }
    bool getDebug_info() { return debug_info; }
    bool getGame_info() { return game_info; }
    bool getRedraw() { return redraw; }
    bool getDev_mode() { return dev_mode; }

    CGameState();
    void show_state_debug();
};

CGameState::CGameState()
{

    state = MAINMENU;
    running = false;
    saved = false;
    debug_info = true;
    game_info = true;
    redraw = false;
    dev_mode = false;
}

void CGameState::show_state_debug()
{

    //-------------------------------
    //  MOSTRAR ESTADO ACTUAL
    //-------------------------------

    al_draw_text(keepcalm12, al_map_rgb(250, 250, 250), 5 + camx, camy + 20, 0, GAME_STATE_t[state]);
    al_draw_textf(keepcalm12, al_map_rgb(250, 250, 250), 5 + camx, camy + 35, 0, "running: %i", running);
    al_draw_textf(keepcalm12, al_map_rgb(250, 250, 250), 5 + camx, camy + 50, 0, "saved: %i", saved);
    int time = al_get_time();
    al_draw_textf(keepcalm12, al_map_rgb(250, 250, 250), 5 + camx, camy + 65, 0, "time: %i", time);
}

CGameState GameState;

#endif // CGAMESTATE_H_INCLUDED
