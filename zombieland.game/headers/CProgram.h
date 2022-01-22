#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

#include "states/CGame.h"
#include "states/CHelp.h"
#include "states/CMainMenu.h"
#include "states/CPreGame.h"
#include "states/CIngameMenu.h"
#include "states/CGameover.h"
#include "states/CStore.h"
#include "states/CLoadGame.h"
#include "states/COptions.h"

/**
    ************************
    * CLASS CGAMESTATE
    ************************

    Detalles:
        - Administra el estado actual
        - Muestra el estado actual
*/

class CProgram
{

private:
    //-------------------------------
    //  OBJETOS DE ESTADOS
    //-------------------------------

    CMainMenu MainMenu;
    CIngameMenu IngameMenu;
    CGame Game;
    CGameOver GameOver;
    CHelp Help;
    CPreGame PreGame;
    CStore Store;
    CLoadGame LoadGame;
    COptions Options;

public:
    void update_actual_state(GAME_STATE state);
    void render_actual_state(GAME_STATE state);
    void destroy_all();
};

void CProgram::update_actual_state(GAME_STATE state)
{

    //-------------------------------
    //  ACTUALIZO EL ESTADO ACTUAL
    //-------------------------------

    switch (state)
    {

    case MAINMENU:
        MainMenu.open_mainmenu();
        break;
    case INGAMEMENU:
        IngameMenu.open_ingamemenu();
        break;
    case STORE:
        Store.open_Store(Game.getInventory());
        break;
    case PRE_GAME:
        PreGame.open_pregame();
        break;
    case HELP:
        Help.open_help();
        break;
    case OPTIONS:
        Options.open_options();
        break;
    case START_PLAYING:
        Game.start_game();
        break;
    case PLAYING:
        Game.update_game();
        break;
    case GAMEOVER:
        GameOver.open_gameover(Game.getScore());
        break;
    case SAVE_GAME:
        save_game(Game);
        GameState.changeState(INGAMEMENU);
        GameState.changeSaved(true);
        break;
    case LOAD_GAME:
        LoadGame.update_loadgame(Game);
        break;
    }
}

void CProgram::render_actual_state(GAME_STATE state)
{

    //-------------------------------
    //  RENDERIZO EL ESTADO ACTUAL
    //-------------------------------

    switch (state)
    {

    case MAINMENU:
        MainMenu.render_mainmenu();
        break;
    case INGAMEMENU:
        IngameMenu.render_ingamemenu();
        break;
    case STORE:
        Store.render_Store(Game.getInventory());
        break;
    case PRE_GAME:
        PreGame.render_pregame();
        break;
    case HELP:
        Help.render_help();
        break;
    case OPTIONS:
        Options.render_options_menu();
        break;
    case PLAYING:
        Game.render_game();
        break;
    case GAMEOVER:
        GameOver.render_gameover(Game.getScore());
        break;
    case LOAD_GAME:
        LoadGame.render_loadgame();
        break;
    case EXIT:
        break;
    }
}

void CProgram::destroy_all()
{

    //-------------------------------
    //  DESTRUYO TODOS LOS ELEMENTOS DEL PROGRAMA
    //-------------------------------

    Game.destroy_game();
    Store.destroy_bitmaps();
    Help.destroy_bitmaps();
}

#endif // GAMESTATE_H_INCLUDED
