#ifndef CSTORE_H_INCLUDED
#define CSTORE_H_INCLUDED
#include "CMenu.h"

/**
    ************************
    * CLASS CSTORE
    ************************

    Detalles:
        -
*/

class CStore
{

private:
    // Control de sub-estados para la tienda
    enum STORE_STATE
    {
        ARMAS,
        MEJORAS,
        MUNICIONES,
        VOLVER
    };
    int state;

    // Precios
    int cost[3][4];

    // Controla la seleccion de opcion
    int selec;

    ALLEGRO_BITMAP *weapon_img = NULL;
    ALLEGRO_BITMAP *buy_bmp = NULL;
    CButton *vBtn_buy;

public:
    void open_Store(CInventory &);
    void render_Store(CInventory &);
    void show_state();
    void destroy_bitmaps();

    // Renders por sub-estado
    void render_armas(CInventory &);
    void render_mejoras(CInventory &);
    void render_municiones(CInventory &);

    // Cambia de sub-estado (sub menu)
    void changeState(int new_state) { state = new_state; }

    CStore();
};

//-------------------------------
//  CONSTRUCTOR
//-------------------------------

CStore::CStore()
{

    //----------------------------------------
    //  INICIALIZAR VECTOR DE COSTOS EN CERO
    //----------------------------------------

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            cost[i][j] = 0;

    //----------------------------------------
    //  ASIGNAR VALORES AL VECTOR DE COSTOS
    //----------------------------------------

    cost[ARMAS][SHOTGUN] = 250;
    cost[ARMAS][UZI] = 570;
    cost[ARMAS][ASSAULT] = 1200;
    cost[MEJORAS][PISTOL] = 80;
    cost[MEJORAS][SHOTGUN] = 100;
    cost[MEJORAS][UZI] = 150;
    cost[MEJORAS][ASSAULT] = 300;
    cost[MUNICIONES][PISTOL] = 60;
    cost[MUNICIONES][SHOTGUN] = 40;
    cost[MUNICIONES][UZI] = 80;
    cost[MUNICIONES][ASSAULT] = 100;

    vBtn_buy = new CButton[12];

    for (int i = 0; i < 12; i++)
    {
        if (i < 4)
            vBtn_buy[i].init(ANCHO * .34 + ANCHO * 0.65 * (i * 0.25) + camx + 20, ALTO * .78 + camy + 10, bmp_compra);
        else if (i < 8)
            vBtn_buy[i].init(ANCHO * .34 + ANCHO * 0.65 * ((i - 4) * 0.25) + camx + 20, ALTO * .68 + camy - 100, bmp_compra);
        else
            vBtn_buy[i].init(ANCHO * .34 + ANCHO * 0.65 * ((i - 8) * 0.25) + camx + 20, ALTO * .58 + camy - 200, bmp_compra);
    }

    selec = 0;
    state = ARMAS;
    weapon_img = al_load_bitmap("resources/sprites/weapons/weapons.png");
    buy_bmp = al_load_bitmap("resources/menus/store/botones.png");
}

///*********************************************
///*               OPEN STORE
///*********************************************

void CStore::open_Store(CInventory &inventory_aux)
{

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

        switch (ev.keyboard.keycode)
        {
        case ALLEGRO_KEY_DOWN:
        case ALLEGRO_KEY_S:
            selec++;
            if (selec > 3)
                selec = 0;
            break;
        case ALLEGRO_KEY_UP:
        case ALLEGRO_KEY_W:
            selec--;
            if (selec < 0)
                selec = 3;
            break;
        case ALLEGRO_KEY_PAD_ENTER:
        case ALLEGRO_KEY_ENTER:
            if (selec == 3)
            {
                GameState.changeState(INGAMEMENU);
                selec = 0;
            }
            break;
        case ALLEGRO_KEY_ESCAPE:
            GameState.changeState(INGAMEMENU);
            selec = 0;
            break;
        }
    }

    //-------------------------------
    //  COMPRAR CON MOUSE
    //-------------------------------

    for (int i = 0; i < 12; i++)
        vBtn_buy[i].update();

    if (state == ARMAS)
    {

        // COMPRAR ARMAS
        for (int i = 0; i < 4; i++)
        {
            if (vBtn_buy[i].getReleased())
            {
                if (inventory_aux.getCredits() >= cost[ARMAS][i] and !inventory_aux.getWeapon(i))
                {
                    inventory_aux.aquire_weapon(i);
                    inventory_aux.add_credits(-cost[ARMAS][i]);
                }
                else if (inventory_aux.getWeapon(i))
                    Error.open_error("Error de tienda", "No puede obtener el arma. Usted ya posee este arma.");
                else
                    Error.open_error("Error de tienda", "No puede obtener el arma. Fondos insuficientes.");
            }
        }
    }
    else if (state == MEJORAS)
    {

        // da�o
        for (int i = 0; i < 4; i++)
        {
            if (vBtn_buy[i].getReleased())
            {
                if (inventory_aux.getWeapon(i))
                {
                    // tiene el arma
                    if (inventory_aux.getWeapon_damage(i) >= 100)
                    {
                        // no puede mejorarla mas
                        Error.open_error("Error de tienda", "Alcanzo el nivel maximo de mejora");
                    }
                    else if (inventory_aux.getCredits() >= cost[MEJORAS][i])
                    {
                        // mejorar el arma, quitar creditos
                        inventory_aux.setWeapon_damage(i, inventory_aux.getWeapon_damage(i) + 10);
                        inventory_aux.add_credits(-cost[MEJORAS][i]);
                    }
                    else
                    {
                        Error.open_error("Error de tienda", "No posee los creditos suficientes");
                    }
                }
                else
                {
                    // no tiene el arma
                    Error.open_error("Error de tienda", "Usted no posee ese arma");
                }
            }
        }

        // tama�o cargador
        for (int i = 0; i < 4; i++)
        {
            if (vBtn_buy[i + 4].getReleased())
            {
                if (inventory_aux.getWeapon(i))
                {
                    // tiene el arma
                    if (inventory_aux.getWeapon_mag_size(i) >= 50)
                    {
                        // no puede mejorarla mas
                        Error.open_error("Error de tienda", "Alcanzo el nivel maximo de mejora");
                    }
                    else if (inventory_aux.getCredits() >= cost[MEJORAS][i])
                    {
                        // mejorar el arma, quitar creditos
                        inventory_aux.setWeapon_mag_size(i, inventory_aux.getWeapon_mag_size(i) + 5);
                        inventory_aux.add_credits(-cost[MEJORAS][i]);
                    }
                    else
                    {
                        Error.open_error("Error de tienda", "No posee los creditos suficientes");
                    }
                }
                else
                {
                    // no tiene el arma
                    Error.open_error("Error de tienda", "Usted no posee ese arma");
                }
            }
        }

        // tama�o cargador
        for (int i = 0; i < 4; i++)
        {
            if (vBtn_buy[i + 8].getReleased())
            {
                if (inventory_aux.getWeapon(i))
                {
                    // tiene el arma
                    if (inventory_aux.getWeapon_reload_time(i) <= 0.5)
                    {
                        // no puede mejorarla mas
                        Error.open_error("Error de tienda", "Alcanzo el nivel maximo de mejora");
                    }
                    else if (inventory_aux.getCredits() >= cost[MEJORAS][i])
                    {
                        // mejorar el arma, quitar creditos
                        inventory_aux.setWeapon_reload_time(i, inventory_aux.getWeapon_reload_time(i) - 0.5);
                        inventory_aux.add_credits(-cost[MEJORAS][i]);
                    }
                    else
                    {
                        Error.open_error("Error de tienda", "No posee los creditos suficientes");
                    }
                }
                else
                {
                    // no tiene el arma
                    Error.open_error("Error de tienda", "Usted no posee ese arma");
                }
            }
        }
    }
    else if (state == MUNICIONES)
    {

        // municiones
        for (int i = 0; i < 4; i++)
        {
            if (vBtn_buy[i].getReleased())
            {
                if (inventory_aux.getWeapon(i))
                {
                    // tiene el arma
                    if (inventory_aux.getAmmunition(i) >= 1000)
                    {
                        // no le entran mas balas
                        Error.open_error("Error de tienda", "No puede cargar mas municiones de ese tipo");
                    }
                    else if (inventory_aux.getCredits() >= cost[MUNICIONES][i])
                    {
                        // mejorar el arma, quitar creditos
                        inventory_aux.ammunition_edit(i, 30);
                        inventory_aux.add_credits(-cost[MUNICIONES][i]);
                    }
                    else
                    {
                        Error.open_error("Error de tienda", "No posee los creditos suficientes");
                    }
                }
                else
                {
                    // no tiene el arma
                    Error.open_error("Error de tienda", "Usted no posee ese arma");
                }
            }
        }
    }

    //-----------------------------------------------------------
    //  Cambia el estado dependiendo de la seleccion del usuario
    //-----------------------------------------------------------

    switch (selec)
    {
    case 0:
        changeState(ARMAS);
        break;
    case 1:
        changeState(MEJORAS);
        break;
    case 2:
        changeState(MUNICIONES);
        break;
    case 3:
        changeState(VOLVER);
        break;
    }
}

void CStore::render_Store(CInventory &inventory_aux)
{

    //-------------------------------
    //  MOSTRAR TITULO
    //-------------------------------

    al_draw_text(dayslater_big, al_map_rgb(255, 255, 20), ANCHO / 2 + camx, (ALTO * 0.15) - 90 + camy, ALLEGRO_ALIGN_CENTER, "TIENDA");

    //-------------------------------
    //  DIBUJAR ESTRUCTURA
    //-------------------------------

    al_draw_line(camx, (ALTO * 0.15) + camy, camx + ANCHO, (ALTO * 0.15) + camy, al_map_rgb(180, 180, 180), 2);                           // -----
    al_draw_line((ANCHO * 0.34) + camx, (ALTO * 0.15) + camy, (ANCHO * 0.34) + camx, (ALTO * 0.85) + camy, al_map_rgb(180, 180, 180), 2); // |
    al_draw_line(camx, (ALTO * 0.85) + camy, camx + ANCHO, (ALTO * 0.85) + camy, al_map_rgb(180, 180, 180), 2);                           // _____
    al_draw_line(ANCHO * 0.34 + ANCHO * 0.65 * 0.25 + camx, ALTO * 0.16 + camy, ANCHO * 0.34 + ANCHO * 0.65 * 0.25 + camx, ALTO * 0.84 + camy, al_map_rgb(180, 180, 180), 1);
    al_draw_line(ANCHO * 0.34 + ANCHO * 0.65 * 0.50 + camx, ALTO * 0.16 + camy, ANCHO * 0.34 + ANCHO * 0.65 * 0.50 + camx, ALTO * 0.84 + camy, al_map_rgb(180, 180, 180), 1);
    al_draw_line(ANCHO * 0.34 + ANCHO * 0.65 * 0.75 + camx, ALTO * 0.16 + camy, ANCHO * 0.34 + ANCHO * 0.65 * 0.75 + camx, ALTO * 0.84 + camy, al_map_rgb(180, 180, 180), 1);

    al_draw_text(keepcalm12, al_map_rgb(250, 250, 20), camx + 15, ALTO * 0.75 + camy, ALLEGRO_ALIGN_LEFT, "NAVEGA CON EL LAS TECLAS");
    al_draw_text(keepcalm12, al_map_rgb(250, 250, 20), camx + 15, ALTO * 0.80 + camy, ALLEGRO_ALIGN_LEFT, "COMPRA CON EL MOUSE");

    //-------------------------------
    //  MOSTRAR CREDITOS DEL JUGADOR
    //-------------------------------

    al_draw_textf(keepcalm_med, al_map_rgb(82, 204, 0), ANCHO * 0.34 + camx, ALTO * 0.86 + camy, ALLEGRO_ALIGN_RIGHT, "CREDITOS: %i", inventory_aux.getCredits());

    //-------------------------------
    //  RENDERIZA SUB-ESTADO
    //-------------------------------

    switch (selec)
    {
    case ARMAS:
        render_armas(inventory_aux);
        break;
    case MEJORAS:
        render_mejoras(inventory_aux);
        break;
    case MUNICIONES:
        render_municiones(inventory_aux);
        break;
    }

    //---------------------------------
    //  MOSTRAR LA OPCION SELECCIONADA
    //---------------------------------

    al_draw_filled_rectangle(5 + camx, (ALTO * 0.15) + (48 * selec) + camy + 10, (ANCHO * 0.34) + camx - 10, (ALTO * 0.15) + (48 * selec) + 42 + camy + 15, al_map_rgb(180, 180, 180));

    //-------------------------------
    //  MOSTRAR LAS OPCIONES
    //-------------------------------

    if (selec == 0)
        al_draw_text(keepcalm24, al_map_rgb(20, 20, 20), (ANCHO * 0.34) + camx - 10, (ALTO * 0.15) + camy + 10, ALLEGRO_ALIGN_RIGHT, "ARMAS");
    else
        al_draw_text(keepcalm24, al_map_rgb(180, 180, 180), (ANCHO * 0.34) + camx - 10, (ALTO * 0.15) + camy + 10, ALLEGRO_ALIGN_RIGHT, "ARMAS");

    if (selec == 1)
        al_draw_text(keepcalm24, al_map_rgb(20, 20, 20), (ANCHO * 0.34) + camx - 10, (ALTO * 0.15) + camy + 58, ALLEGRO_ALIGN_RIGHT, "MEJORAS");
    else
        al_draw_text(keepcalm24, al_map_rgb(180, 180, 180), (ANCHO * 0.34) + camx - 10, (ALTO * 0.15) + camy + 58, ALLEGRO_ALIGN_RIGHT, "MEJORAS");

    if (selec == 2)
        al_draw_text(keepcalm24, al_map_rgb(20, 20, 20), (ANCHO * 0.34) + camx - 10, (ALTO * 0.15) + camy + 106, ALLEGRO_ALIGN_RIGHT, "MUNICIONES");
    else
        al_draw_text(keepcalm24, al_map_rgb(180, 180, 180), (ANCHO * 0.34) + camx - 10, (ALTO * 0.15) + camy + 106, ALLEGRO_ALIGN_RIGHT, "MUNICIONES");

    if (selec == 3)
        al_draw_text(keepcalm24, al_map_rgb(20, 20, 20), (ANCHO * 0.34) + camx - 10, (ALTO * 0.15) + camy + 154, ALLEGRO_ALIGN_RIGHT, "VOLVER");
    else
        al_draw_text(keepcalm24, al_map_rgb(180, 180, 180), (ANCHO * 0.34) + camx - 10, (ALTO * 0.15) + camy + 154, ALLEGRO_ALIGN_RIGHT, "VOLVER");

    show_state();
    if (GameState.getDebug_info())
        GameState.show_state_debug();
}

void CStore::render_armas(CInventory &inventory_aux)
{

    for (int i = 0; i < 4; i++)
    {
        al_draw_text(keepcalm12, al_map_rgb(180, 180, 180), ANCHO * (0.42 + (i * 0.16)) + camx, ALTO * 0.16 + camy, ALLEGRO_ALIGN_CENTER, WEAP_t[i]);
        al_draw_bitmap_region(weapon_img, 139 * i, 43 * SELECTED, 139, 43, ANCHO * 0.34 + ANCHO * 0.65 * (i * 0.25) + (ANCHO * 0.65 * 0.25 - 139) / 2 + camx, ALTO * 0.20 + camy, 0);
        vBtn_buy[i].render();
        if (inventory_aux.getWeapon(i))
            al_draw_text(keepcalm_med, al_map_rgb(250, 160, 0), ANCHO * 0.34 + (i * (ANCHO * .16)) + camx + 20, ALTO * 0.72 + camy, 0, "OBTENIDA");
    }
}

void CStore::render_mejoras(CInventory &inventory)
{

    for (int i = 0; i < 4; i++)
    {
        al_draw_textf(keepcalm12, al_map_rgb(180, 180, 180), ANCHO * (0.42 + (i * 0.16)) + camx, ALTO * 0.16 + camy, ALLEGRO_ALIGN_CENTER, "MEJORAR %s", WEAP_t[i]);
        al_draw_bitmap_region(weapon_img, 139 * i, 43 * SELECTED, 139, 43, ANCHO * 0.34 + ANCHO * 0.65 * (i * 0.25) + (ANCHO * 0.65 * 0.25 - 139) / 2 + camx, ALTO * 0.20 + camy, 0);
    }

    for (int i = 0; i < 12; i++)
    {
        vBtn_buy[i].render();
    }

    for (int i = 0; i < 4; i++)
    {
        al_draw_text(keepcalm12, al_map_rgb(180, 180, 180), ANCHO * (0.42 + (i * 0.17)) + camx, ALTO * .58 + camy - 235,
                     ALLEGRO_ALIGN_CENTER, "RECARGA -0.5");
        al_draw_textf(keepcalm12, al_map_rgb(180, 180, 180), ANCHO * (0.42 + (i * 0.17)) + camx - 40, ALTO * .58 + camy - 220,
                      ALLEGRO_ALIGN_RIGHT, "$%i", cost[MEJORAS][i]);
        al_draw_textf(keepcalm12, al_map_rgb(180, 180, 180), ANCHO * (0.42 + (i * 0.16)) + camx - 10, ALTO * .58 + camy - 220,
                      ALLEGRO_ALIGN_LEFT, "ACTUAL: %.1f", inventory.getWeapon_reload_time(i));

        al_draw_text(keepcalm12, al_map_rgb(180, 180, 180), ANCHO * (0.42 + (i * 0.17)) + camx, ALTO * .78 + camy - 255,
                     ALLEGRO_ALIGN_CENTER, "CARGADOR +5");
        al_draw_textf(keepcalm12, al_map_rgb(180, 180, 180), ANCHO * (0.42 + (i * 0.17)) + camx - 40, ALTO * .78 + camy - 240,
                      ALLEGRO_ALIGN_RIGHT, "$%i", cost[MEJORAS][i]);
        al_draw_textf(keepcalm12, al_map_rgb(180, 180, 180), ANCHO * (0.42 + (i * 0.16)) + camx - 10, ALTO * .78 + camy - 240,
                      ALLEGRO_ALIGN_LEFT, "ACTUAL: %i", inventory.getWeapon_mag_size(i));

        al_draw_text(keepcalm12, al_map_rgb(180, 180, 180), ANCHO * (0.42 + (i * 0.17)) + camx, ALTO * .88 + camy - 105,
                     ALLEGRO_ALIGN_CENTER, "DANIO +10");
        al_draw_textf(keepcalm12, al_map_rgb(180, 180, 180), ANCHO * (0.42 + (i * 0.17)) + camx - 40, ALTO * .88 + camy - 90,
                      ALLEGRO_ALIGN_RIGHT, "$%i", cost[MEJORAS][i]);
        al_draw_textf(keepcalm12, al_map_rgb(180, 180, 180), ANCHO * (0.42 + (i * 0.16)) + camx - 10, ALTO * .88 + camy - 90,
                      ALLEGRO_ALIGN_LEFT, "ACTUAL: %i", inventory.getWeapon_damage(i));
    }

    /*for(int i=0; i<4; i++){
        al_draw_textf(keepcalm12,al_map_rgb(250,160,0),ANCHO*(0.42+(i*0.164))+camx,ALTO*0.70+camy,
                      ALLEGRO_ALIGN_CENTER,"TIEMPO RECARGA: %.1f",inventory.getWeapon_reload_time(i));
        al_draw_textf(keepcalm12,al_map_rgb(250,160,0),ANCHO*(0.42+(i*0.164))+camx,ALTO*0.75+camy,
                      ALLEGRO_ALIGN_CENTER,"TIEMPO RECARGA $%i",cost[MEJORAS][i]);
        al_draw_bitmap(buy_bmp,ANCHO*0.34+ANCHO*0.65*(0.25*i)+(ANCHO*0.65*0.25-al_get_bitmap_width(buy_bmp))/2+camx,ALTO*0.79+camy,0);
    }
    for(int i=0; i<4; i++){
        al_draw_textf(keepcalm12,al_map_rgb(20,230,20),ANCHO*(0.42+(i*0.164))+camx,ALTO*0.50+camy,
                      ALLEGRO_ALIGN_CENTER,"DANIO ACTUAL: %i",inventory.getWeapon_damage(i));
        al_draw_textf(keepcalm12,al_map_rgb(250,160,0),ANCHO*(0.42+(i*0.164))+camx,ALTO*0.55+camy,
                      ALLEGRO_ALIGN_CENTER,"DANIO ARMA $%i",cost[MEJORAS][i]);
        al_draw_bitmap(buy_bmp,ANCHO*0.34+ANCHO*0.65*(0.25*i)+(ANCHO*0.65*0.25-al_get_bitmap_width(buy_bmp))/2+camx,ALTO*0.59+camy,0);
    }*/
}

void CStore::render_municiones(CInventory &inventory)
{

    for (int i = 0; i < 4; i++)
    {
        al_draw_text(keepcalm12, al_map_rgb(180, 180, 180), ANCHO * (0.42 + (i * 0.16)) + camx, ALTO * 0.16 + camy, ALLEGRO_ALIGN_CENTER, WEAP_t[i]);
        al_draw_bitmap_region(weapon_img, 139 * i, 43 * SELECTED, 139, 43, ANCHO * 0.34 + ANCHO * 0.65 * (i * 0.25) + (ANCHO * 0.65 * 0.25 - 139) / 2 + camx, ALTO * 0.20 + camy, 0);
        vBtn_buy[i].render();
        al_draw_text(keepcalm12, al_map_rgb(250, 160, 0), ANCHO * 0.34 + (i * (ANCHO * .16)) + camx + 20, ALTO * 0.72 + camy, 0, "MUNICION +30");
    }
}

//-------------------------------
//  MUESTRA EL SUB-ESTADO ACTUAL
//-------------------------------

void CStore::show_state()
{

    if (GameState.getDebug_info())
        switch (state)
        {

        case ARMAS:
            al_draw_text(keepcalm12, al_map_rgb(180, 180, 180), 5 + camx, ALTO - 30 + camy, 0, "SUB STATE: ARMAS");
            break;
        case MEJORAS:
            al_draw_text(keepcalm12, al_map_rgb(180, 180, 180), 5 + camx, ALTO - 30 + camy, 0, "SUB STATE: MEJORAS");
            break;
        case MUNICIONES:
            al_draw_text(keepcalm12, al_map_rgb(180, 180, 180), 5 + camx, ALTO - 30 + camy, 0, "SUB STATE: MUNICIONES");
            break;
        case VOLVER:
            al_draw_text(keepcalm12, al_map_rgb(180, 180, 180), 5 + camx, ALTO - 30 + camy, 0, "SUB STATE: VOLVER");
            break;
        }
}

///*********************************************
///*            DESTRUIR BITMAPS
///*********************************************

void CStore::destroy_bitmaps()
{

    al_destroy_bitmap(weapon_img);
    al_destroy_bitmap(buy_bmp);
}

#endif // CSTORE_H_INCLUDED
