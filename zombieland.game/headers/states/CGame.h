#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

//-------------------------------------------
//  HEADERS NECESARIOS PARA LA CLASE "GAME"
//-------------------------------------------

#include "game/CMap.h"
#include "game/CEnemy.h"
#include "game/CInventory.h"
#include "game/CPlayer.h"
#include "game/CBullets.h"
#include "game/CLoot.h"
#include "game/CCobra.h"

/**
    ************************
    * CLASS CGAME
    ************************

    Detalles:
        - Administra todo el juego
        - Posee los objetos necesarios definidos
          dentro de la parte privada
*/

class CGame
{

private:
    int ID;
    bool ready_to_shoot;
    bool reloading;
    bool reloaded;
    double reload_time_start;
    double last_time_shot;
    int live_vEnemies;
    int live_vBullets;
    int score;
    int px_aux;
    int py_aux;
    float scale;

    CBullets vBullets[MAX_BULLETS];
    CEnemy vEnemies[MAX_ENEMIES];
    CLoot vLoot[MAX_LOOT];

    CInventory Inventory, Inv_aux;
    CMap actual_map;
    CPlayer player, player_aux;
    CCobra Cobra;

public:
    int camx_aux;
    int camy_aux;
    void start_game();   // Inicializar
    void update_game();  // Actualizar
    void render_game();  // Dibujar por pantalla
    void destroy_game(); // Destruir bitmaps
    void dev_mode_on();
    void dev_mode_off();
    void load_game();
    void win(int score);

    int getScore() { return player.getScore(); }
    void setPlayerLive(bool _live) { player.setLive(_live); }

    /// Devuelve el inventario completo
    CInventory &getInventory() { return Inventory; }

    CGame &operator=(const CGame &game_aux);

    CGame();
};

CGame::CGame()
{

    GameState.changeSaved(false);
    ready_to_shoot = true;
    reloading = false;
    reloaded = true;
    reload_time_start = 0;
    last_time_shot = 0;
    Inventory.init();
    scale = 1;

    FILE *p;
    fopen_s(&p, "files/savegames.dat", "rb");
    if (p == NULL)
        ID = 0;
    else
    {
        fseek(p, 0, 2);
        ID = ftell(p) / sizeof(CGame);
        fclose(p);
    }
}

///*********************************************
///*               START GAME
///*********************************************

void CGame::start_game()
{

    //-------------------------------
    //  SE INICIALIZA EL JUEGO
    //  Solo se ejecuta con la opci�n "Nueva Partida"
    //------------------------------------------------

    player.init(230, 359);
    actual_map.init();
    Inventory.init();
    Cobra.init();

    GameState.changeRunning(true);

    for (int i = 0; i < MAX_BULLETS; i++)
        vBullets[i].init(Inventory.getActual_weap());

    load_enemies(vEnemies);
    load_loot(vLoot);

    GameState.changeState(PLAYING);
}

///*********************************************
///*              UPDATE GAME
///*********************************************

void CGame::update_game()
{

    camx_aux = camx;
    camy_aux = camy;

    //-------------------------------
    //  IMPUT DE DISPLAY
    //-------------------------------

    if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        GameState.changeState(EXIT);

    //-------------------------------
    //  IMPUT DE TECLADO
    //-------------------------------

    else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
    {

        if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        {
            GameState.changeState(INGAMEMENU);
            for (int i = 0; i < cant_keys; i++)
                keys[i] = false;
        }
        else

            switch (ev.keyboard.keycode)
            {

            // W,A,S,D
            case ALLEGRO_KEY_A:
                keys[LEFT] = true;
                break;
            case ALLEGRO_KEY_D:
                keys[RIGHT] = true;
                break;
            case ALLEGRO_KEY_W:
                keys[UP] = true;
                break;
            case ALLEGRO_KEY_S:
                keys[DOWN] = true;
                break;

                // OTRAS TECLAS

            case ALLEGRO_KEY_1:
                if (GameState.getDev_mode())
                    player.teleport();
                break;
            case ALLEGRO_KEY_2:
                if (GameState.getDev_mode())
                    Inventory.add_credits(1000);
                break;
            case ALLEGRO_KEY_3:
                if (GameState.getDev_mode())
                    player.hit_recived(20);
                break;
            case ALLEGRO_KEY_4:
                scale -= 0.1;

                break;
            // AGREGAR LOOT
            case ALLEGRO_KEY_PAD_1:
                if (GameState.getDev_mode())
                    add_loot(AMMO_PISTOL, vLoot);
                break;
            case ALLEGRO_KEY_PAD_2:
                if (GameState.getDev_mode())
                    add_loot(AMMO_SHOTGUN, vLoot);
                break;
            case ALLEGRO_KEY_PAD_3:
                if (GameState.getDev_mode())
                    add_loot(AMMO_UZI, vLoot);
                break;
            case ALLEGRO_KEY_PAD_4:
                if (GameState.getDev_mode())
                    add_loot(AMMO_ASSAULT, vLoot);
                break;
            case ALLEGRO_KEY_PAD_5:
                if (GameState.getDev_mode())
                    add_loot(HEALTH, vLoot);
                break;
            // GUARDAR LOOT
            case ALLEGRO_KEY_PAD_6:
                if (GameState.getDev_mode())
                    save_loot(vLoot);
                break;
            // AGREGAR ENEMIGOS
            case ALLEGRO_KEY_F5:
                if (GameState.getDev_mode())
                    add_enemy(EASY, vEnemies, live_vEnemies);
                break;
            case ALLEGRO_KEY_F6:
                if (GameState.getDev_mode())
                    add_enemy(NORMAL, vEnemies, live_vEnemies);
                break;
            case ALLEGRO_KEY_F7:
                if (GameState.getDev_mode())
                    add_enemy(HARD, vEnemies, live_vEnemies);
                break;
            case ALLEGRO_KEY_F8:
                if (GameState.getDev_mode())
                    save_enemies(vEnemies);
                break;
            case ALLEGRO_KEY_TAB:
                keys[TAB] = true;
                break;
            case ALLEGRO_KEY_F1:
                if (GameState.getDebug_info())
                    GameState.changeDebug_info(false);
                else
                    GameState.changeDebug_info(true);
                break;
            case ALLEGRO_KEY_F2:
                if (GameState.getGame_info())
                    GameState.changeGame_info(false);
                else
                    GameState.changeGame_info(true);
                break;
            case ALLEGRO_KEY_F3:
                if (GameState.getDev_mode())
                    dev_mode_off();
                else
                    dev_mode_on();
                break;
            case ALLEGRO_KEY_SPACE:
                keys[SPACE] = true;
                break;
            }
    }

    //-------------------------------
    //  PONE LAS TECLAS EN "FALSE"
    //-------------------------------

    if (ev.type == ALLEGRO_EVENT_KEY_UP)
    {

        if (ev.keyboard.keycode == ALLEGRO_KEY_A)
            keys[LEFT] = false;
        else if (ev.keyboard.keycode == ALLEGRO_KEY_D)
            keys[RIGHT] = false;
        else if (ev.keyboard.keycode == ALLEGRO_KEY_W)
            keys[UP] = false;
        else if (ev.keyboard.keycode == ALLEGRO_KEY_S)
            keys[DOWN] = false;
        else if (ev.keyboard.keycode == ALLEGRO_KEY_SPACE)
            keys[SPACE] = false;
        else if (ev.keyboard.keycode == ALLEGRO_KEY_TAB)
        {

            // SELECCIONA EL ARMA CON MOUSEOVER
            keys[TAB] = false;
            Inventory.select_weapon(player.getX() - 20, player.getY() - 30);
        }
    }

    //-------------------------------
    //  IMPUT DE MOUSE
    //-------------------------------

    if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
        if (ev.mouse.button == 1)
            keys[SPACE] = true;
    }

    if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
    {
        if (ev.mouse.button == 1)
            keys[SPACE] = false;
    }

    // COPIA LAS COORDENADAS, PARA HACER COLISIONES
    /*if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
        if(ev.mouse.button == 1)
            copiar();
    }*/

    //-------------------------------------------
    //  ACTUALIZA EL JUEGO 60 VECES POR SEGUNDO
    //-------------------------------------------

    if (GameState.getRedraw())
    {

        player.update();
        player.update_ant();

        if (!reloading and !reloaded and Inventory.getAmmunition() > 0)
        {

            if (Inventory.getAmmunition() % Inventory.getWeapon_mag_size() == 0)
            {

                reload_time_start = al_get_time();
                reloading = true;
            }
        }

        if (!ready_to_shoot)
        {

            if (al_get_time() - last_time_shot > Inventory.getWeapon_fire_rate())
                ready_to_shoot = true;
        }

        if (reloading)
        {

            if (al_get_time() > reload_time_start + Inventory.getWeapon_reload_time())
            {

                reloading = false;
                reloaded = true;
            }
        }

        if (keys[SPACE] and ready_to_shoot and !reloading)
        {

            reloaded = false;
            ready_to_shoot = false;
            last_time_shot = al_get_time();

            // Evalua si hay municion
            if (Inventory.getAmmunition() > 0)
            {
                for (int i = 0; i < MAX_BULLETS; i++)
                {

                    // Dispara la primera bala que no este viva
                    if (!vBullets[i].getLive())
                    {
                        vBullets[i].fire(player.getX() - 25, player.getY() - 25, Inventory.getWeapon_damage());

                        // Resta municion
                        Inventory.ammunition_edit(Inventory.getActual_weap(), -1);

                        // Reproduce sonido
                        al_play_sample(audios[Inventory.getActual_weap()], .5, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                        break;
                    }
                }
            }
        }

        live_vBullets = 0;
        for (int i = 0; i < MAX_BULLETS; i++)
        {

            if (vBullets[i].getLive())
            {
                live_vBullets++;
                vBullets[i].update();
                if (vBullets[i].isOutRange())
                    vBullets[i].destroy();
            }
            else
                vBullets[i].init(Inventory.getActual_weap());
        }

        live_vEnemies = 0;
        for (int i = 0; i < MAX_ENEMIES; i++)
        {

            if (vEnemies[i].getLive())
            {

                live_vEnemies++;

                // Actualizar la pos del enemigo
                if (!GameState.getDev_mode())
                    vEnemies[i].update(player.getX() + player.getW() / 2, player.getY() + player.getH() / 2);

                // Colision entre enemigos
                for (int j = 0; j < MAX_ENEMIES; j++)
                {
                    if (vEnemies[j].getLive() and i != j)
                    {
                        if (collision::circle_circle(vEnemies[i].getX(), vEnemies[i].getY(), 10,
                                                     vEnemies[j].getX(), vEnemies[j].getY(), 10))
                        {
                            vEnemies[i].setAnt();
                        }
                    }
                }

                // Colision con el jugador
                if (collision::circle_circle(vEnemies[i].getX(), vEnemies[i].getY(), 10,
                                             player.getX(), player.getY(), 10))
                {
                    vEnemies[i].setAnt();
                }
                else if (collision::circle_circle(vEnemies[i].getX(), vEnemies[i].getY(), 20,
                                                  player.getX(), player.getY(), 20))
                    if (rand() % 60 == 0)
                        player.hit_recived(vEnemies[i].getDamage());

                // Colision con las balas
                for (int j = 0; j < MAX_BULLETS; j++)
                    if (vBullets[j].getLive())
                        if (collision::circle_circle(vEnemies[i].getX(), vEnemies[i].getY(), vEnemies[i].getRadio(),
                                                     vBullets[j].getX(), vBullets[j].getY(), 2))
                        {

                            // Enemigo recibe da�o. Si muere, el usuario adquiere creditos y puntos
                            if (vEnemies[i].recive_hit(vBullets[j].getDamage()))
                            {
                                Inventory.add_credits(75);
                                player.addScore();
                                add_loot_random_xy(vLoot, vEnemies[i].getX(), vEnemies[i].getY());
                            }

                            // Matar la bala
                            vBullets[j].setLive(false);
                        }

                // Actualizar pos ant
                vEnemies[i].update_ant();
            }
        }

        for (int i = 0; i < MAX_LOOT; i++)
        {
            if (vLoot[i].getLive())
            {
                if (collision::boundingBox(vLoot[i].getX(), vLoot[i].getY() + 10, 40, 50,
                                           player.getX() - 10, player.getY() - 10, 30, 30))
                {

                    vLoot[i].setLive(false);
                    if (vLoot[i].getLoot_type() == 4)
                        player.setStamina(player.getStamina() + 20 + rand() % 20);
                    else
                        Inventory.ammunition_edit(vLoot[i].getLoot_type(), 10 + rand() % 30);
                }
            }
        }

        if (collision::boundingBox_pixel(Cobra.getX(), Cobra.getY(), Cobra.getX() + 128, Cobra.getY() + 352, player.getX() - camx, player.getY() - camy) and !Cobra.getPlayer_in())
        {
            player.setIs_col(false);
            player.setX(Cobra.getX() + 62);
            player.setY(Cobra.getY() + 120);
            Cobra.setPlayer_in(true);
            player.setVel(5);
            score = player.getScore();
            for (int i = 0; i < 4; i++)
            {
                Inventory.ammunition_edit(i, 9999);
                Inventory.setWeapon_damage(i, 100);
                Inventory.setWeapon_fire_rate(i, 0.06);
                Inventory.setWeapon_mag_size(i, 999);
                Inventory.setWeapon_reload_time(i, 0.1);
            }
        }

        if (player.getStamina() == 0 and !Cobra.getPlayer_in())
        {
            GameState.changeState(GAMEOVER);
            GameState.changeRunning(false);
            for (int i = 0; i < cant_keys; i++)
                keys[i] = false;
        }

        px_aux = player.getX();
        py_aux = player.getY();

        Cobra.update_cobra(player.getX(), player.getY());

        // MUEVE LA CAMARA CON LA POS DEL JUGADOR
        cameraUpdate(player.getX(), player.getY(), player.getW(), player.getH());
        al_identity_transform(&camera);
        al_scale_transform(&camera, scale, scale);
        al_translate_transform(&camera, -camx, -camy);
        al_use_transform(&camera);
    }
}

///*********************************************
///*               RENDER GAME
///*********************************************

void CGame::render_game()
{

    //-------------------------------
    //  DIBUJA EL MAPA
    //-------------------------------

    actual_map.draw(-player.getX(), -player.getY());

    // DIBUJAR JUGADOR
    player.render();

    //-------------------------------
    //  DIBUJA EL INVENTARIO
    //-------------------------------

    if (keys[TAB])
        Inventory.show_weapons_mouseover(player.getX() - 20, player.getY() - 30);

    //-------------------------------
    //  DIBUJA LAS BALAS
    //-------------------------------

    for (int i = 0; i < MAX_BULLETS; i++)
        vBullets[i].render(Inventory.getActual_weap());

    //-------------------------------
    //  DIBUJA LOS ENEMIGOS
    //-------------------------------

    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        vEnemies[i].render(player.getX(), player.getY());
        vEnemies[i].draw_stamina();
        if (GameState.getDebug_info())
        {
            vEnemies[i].show_debug();
        }
        if (GameState.getGame_info())
        {
            vEnemies[i].show_aggro_distance();
        }
    }

    //-------------------------------
    //  DIBUJA LOOT
    //-------------------------------

    for (int i = 0; i < MAX_LOOT; i++)
        vLoot[i].render_loot();

    //--------------------------------------------
    //  DIBUJA INFORMACION DEL JUEGO POR PANTALLA
    //--------------------------------------------

    Inventory.show_ammunition_by_actual_weapon(reloading);
    Inventory.show_actualweapon();
    Inventory.show_info();
    player.draw_stamina_bar();
    player.draw_score();

    // Dibuja arco con weapon reload time
    if (reloading)
    {
        al_draw_arc(player.getX(), player.getY(), 30, 0,
                    (al_get_time() - last_time_shot) * (6.3 / Inventory.getWeapon_reload_time()), al_map_rgb(200, 200, 20), 5);

        al_draw_text(keepcalm12, al_map_rgb(240, 240, 0), player.getX(), player.getY() + 50,
                     ALLEGRO_ALIGN_CENTER, "RECARGANDO");
    }

    // DIBUJAR COBRA
    Cobra.render_cobra();
    if (Cobra.getPlayer_in())
    {

        al_draw_filled_rectangle(camx, camy, ANCHO + camx, ALTO * 0.15 + camy, al_map_rgb(20, 20, 20));
        al_draw_filled_rectangle(camx, ALTO * 0.85 + camy, ANCHO + camx, ALTO + camy, al_map_rgb(20, 20, 20));
        al_draw_text(dayslater_big, al_map_rgb(250, 250, 20), ANCHO / 2 + camx, ALTO * 0.034 + camy, ALLEGRO_ALIGN_CENTER, "GANASTE");
        al_draw_textf(keepcalm_med, al_map_rgb(250, 250, 20), camx + 20, ALTO * 0.9 + camy, ALLEGRO_ALIGN_LEFT, "TU PUNTAJE FUE DE %i", score);
        al_draw_text(keepcalm_med, al_map_rgb(250, 250, 20), ANCHO + camx - 20, ALTO * 0.9 + camy, ALLEGRO_ALIGN_RIGHT, "PARA SALIR PRESIONA ESCAPE");
    }

    //-------------------------------
    //  DIBUJA INFORMACION (DEBUG)
    //-------------------------------

    if (GameState.getDebug_info())
    {

        al_draw_textf(keepcalm12, al_map_rgb(250, 250, 250), camx + 5, camy + 110, 0, "camera x: %i", (int)camx);
        al_draw_textf(keepcalm12, al_map_rgb(250, 250, 250), camx + 5, camy + 125, 0, "camera y: %i", (int)camy);
        al_draw_textf(keepcalm12, al_map_rgb(250, 250, 250), camx + 5, camy + 170, 0, "live enemies: %i", live_vEnemies);
        al_draw_textf(keepcalm12, al_map_rgb(250, 250, 250), camx + 5, camy + 185, 0, "live bullets: %i", live_vBullets);
        player.show_debug();
        al_draw_textf(keepcalm12, al_map_rgb(250, 250, 250), camx + 5, camy + 215, 0, "reloading: %i", reloading);
        al_draw_textf(keepcalm12, al_map_rgb(250, 250, 250), camx + 5, camy + 230, 0, "ammunition: %i", Inventory.getAmmunition());
        Inventory.show_debug_info();

        if (GameState.getDev_mode())
        {

            al_draw_text(keepcalm12, al_map_rgb(250, 250, 0), ANCHO + camx - 5, camy + 5, ALLEGRO_ALIGN_RIGHT, "YOU ARE NOW IN DEV MODE, PRESS F3 TO GO BACK TO NORMAL");
            al_draw_text(keepcalm12, al_map_rgb(250, 250, 250), ANCHO + camx - 5, camy + 20, ALLEGRO_ALIGN_RIGHT, "DEV KEYS");
            al_draw_text(keepcalm12, al_map_rgb(250, 250, 250), ANCHO + camx - 5, camy + 35, ALLEGRO_ALIGN_RIGHT, "1- tele");
            al_draw_text(keepcalm12, al_map_rgb(250, 250, 250), ANCHO + camx - 5, camy + 50, ALLEGRO_ALIGN_RIGHT, "2- add credits");
            al_draw_text(keepcalm12, al_map_rgb(250, 250, 250), ANCHO + camx - 5, camy + 65, ALLEGRO_ALIGN_RIGHT, "3- recibe hit");
            al_draw_text(keepcalm12, al_map_rgb(250, 250, 0), ANCHO + camx - 5, camy + 80, ALLEGRO_ALIGN_RIGHT, "ENEMY SPAWN");
            al_draw_text(keepcalm12, al_map_rgb(250, 250, 250), ANCHO + camx - 5, camy + 95, ALLEGRO_ALIGN_RIGHT, "F5- easy");
            al_draw_text(keepcalm12, al_map_rgb(250, 250, 250), ANCHO + camx - 5, camy + 110, ALLEGRO_ALIGN_RIGHT, "F6- normal");
            al_draw_text(keepcalm12, al_map_rgb(250, 250, 250), ANCHO + camx - 5, camy + 125, ALLEGRO_ALIGN_RIGHT, "F7- hard");
            al_draw_text(keepcalm12, al_map_rgb(250, 250, 250), ANCHO + camx - 5, camy + 140, ALLEGRO_ALIGN_RIGHT, "F8- save enemies");
            al_draw_text(keepcalm12, al_map_rgb(250, 250, 0), ANCHO + camx - 5, camy + 155, ALLEGRO_ALIGN_RIGHT, "LOOT SPAWN");
            al_draw_text(keepcalm12, al_map_rgb(250, 250, 250), ANCHO + camx - 5, camy + 170, ALLEGRO_ALIGN_RIGHT, "Pad1- pistol ammo");
            al_draw_text(keepcalm12, al_map_rgb(250, 250, 250), ANCHO + camx - 5, camy + 185, ALLEGRO_ALIGN_RIGHT, "Pad2- shotgun ammo");
            al_draw_text(keepcalm12, al_map_rgb(250, 250, 250), ANCHO + camx - 5, camy + 200, ALLEGRO_ALIGN_RIGHT, "Pad3- uzi ammo");
            al_draw_text(keepcalm12, al_map_rgb(250, 250, 250), ANCHO + camx - 5, camy + 215, ALLEGRO_ALIGN_RIGHT, "Pad4- assault ammo");
            al_draw_text(keepcalm12, al_map_rgb(250, 250, 250), ANCHO + camx - 5, camy + 230, ALLEGRO_ALIGN_RIGHT, "Pad5- health");
            al_draw_text(keepcalm12, al_map_rgb(250, 250, 250), ANCHO + camx - 5, camy + 245, ALLEGRO_ALIGN_RIGHT, "Pad6- save loot");
        }
    }
    if (GameState.getGame_info())
    {

        // Dibuja arco con weapon fire rate
        if (!ready_to_shoot)
            al_draw_arc(player.getX() + (player.getW() / 2) - 33, player.getY() + (player.getH() / 2) - 28, 45, 0,
                        (al_get_time() - last_time_shot) * (6.3 / Inventory.getWeapon_fire_rate()), al_map_rgb(255, 255, 255), 1);
    }
}

void CGame::dev_mode_on()
{

    GameState.changeDev_mode(true);

    // BACKUP
    Inv_aux = Inventory;
    player_aux = player;

    for (int i = 0; i < 4; i++)
    {
        Inventory.aquire_weapon(i);
        Inventory.setWeapon_fire_rate(i, 0.1);
        Inventory.setWeapon_mag_size(i, 100);
        Inventory.setWeapon_reload_time(i, 0.4);
        Inventory.ammunition_edit(i, 5000);
    }
    Inventory.add_credits(50000);
    player.setVel(5);
    player.addMax_stamina(200);
    player.setStamina(player.getMax_stamina());
}

void CGame::dev_mode_off()
{

    GameState.changeDev_mode(false);

    // RESTAURAR BACKUP
    Inventory = Inv_aux;
    player = player_aux;
    player.setX(px_aux);
    player.setY(py_aux);
}

void CGame::win(int score)
{

    imagen("resources/menus/win.png", 0, score);
    GameState.changeRunning(false);
    GameState.changeState(MAINMENU);
}

CGame &CGame::operator=(const CGame &game_aux)
{

    this->ID = game_aux.ID;
    this->ready_to_shoot = true;
    this->reloading = false;
    this->reloaded = true;
    this->reload_time_start = 0;
    this->last_time_shot = 0;

    for (int i = 0; i < MAX_BULLETS; i++)
        this->vBullets[i].init(PISTOL);
    for (int i = 0; i < MAX_ENEMIES; i++)
        this->vEnemies[i] = game_aux.vEnemies[i];
    for (int i = 0; i < MAX_LOOT; i++)
        this->vLoot[i] = game_aux.vLoot[i];

    this->Inventory = game_aux.Inventory;
    this->Inv_aux = game_aux.Inv_aux;
    this->actual_map.init();
    this->player = game_aux.player;
    this->Cobra.init();
    //this->  = game_aux.;
    return *this;
}

bool save_game(CGame aux)
{

    FILE *p;
    fopen_s(&p, "files/savegames.dat", "ab");
    if (p == NULL)
    {
        Error.open_error("Error de archivo", "No se pudo abrir el archivo.");
        return false;
    }
    if (fwrite(&aux, sizeof(CGame), 1, p))
    {
        Error.open_error("Archivo guardado", "Se ha guardado la partida exitosamente.");
        fclose(p);
        return true;
    }
    Error.open_error("Error al guardar", "No se pudo guardar la partida.");
    fclose(p);
    return false;
}

///*********************************************
///*             DESTROY GAME
///*********************************************

void CGame::destroy_game()
{

    //--------------------------------------
    //  DESTRUYE LOS ELEMENTOS DEL JUEGO
    //--------------------------------------
}

#endif // GAME_H_INCLUDED
