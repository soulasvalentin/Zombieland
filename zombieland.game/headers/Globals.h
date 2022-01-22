#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED

///*********************************************
///*            GLOBALES
///*********************************************

//-------------------------------
//  STRUCTS
//-------------------------------

struct bitmap
{

    ALLEGRO_BITMAP *bmp = NULL;
    int w, h;
    char location[200];
    bitmap() {}
    bitmap(const char *_location)
    {
        strcpy_s(location, _location);
    }
    void init()
    {
        bmp = al_load_bitmap(location);
        w = al_get_bitmap_width(bmp);
        h = al_get_bitmap_height(bmp);
    }
    void destroy()
    {
        al_destroy_bitmap(bmp);
        delete location;
    }
    /*bitmap &operator=(const bitmap &aux){
        this->bmp = aux.bmp;
        this->w = aux.w;
        this->h = aux.h;
        strcpy_s(this->location,aux.location);
    }*/
};

//-------------------------------
//  VARIABLES DE ALLEGRO
//-------------------------------

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_FONT *keepcalm24 = NULL, *farial = NULL, *keepcalm12 = NULL,
             *keepcalm_med = NULL, *dayslater36 = NULL, *dayslater_big = NULL;
ALLEGRO_EVENT ev;
ALLEGRO_BITMAP *bmp_menu_select = NULL,
               *bmp_enemy = NULL,
               *bmp_loot = NULL,
               *bmp_zombieland = NULL,
               *bmp_player = NULL,
               *bmp_map = NULL,
               *bmp_map_grid = NULL,
               *bmp_weapons = NULL;
ALLEGRO_TRANSFORM camera;
ALLEGRO_SAMPLE *audios[6] = {NULL, NULL, NULL, NULL, NULL, NULL};
bitmap bmp_compra("resources/menus/store/botones_compra.png");
bitmap bmp_cobra("resources/sprites/entorno/Cobra.png");
bitmap bmp_aspa("resources/sprites/entorno/aspa.png");

//-------------------------------
//  ENUMS
//-------------------------------

enum GAME_STATE
{
    MAINMENU,
    OPTIONS,
    INGAMEMENU,
    STORE,
    PRE_GAME,
    START_PLAYING,
    PLAYING,
    HELP,
    GAMEOVER,
    RANKING,
    SAVE_GAME,
    LOAD_GAME,
    EXIT
};
const char *GAME_STATE_t[] = {"MAINMENU", "OPTIONS", "INGAMEMENU", "STORE", "PRE_GAME", "START_PLAYING", "PLAYING", "HELP",
                              "GAMEOVER", "RANKING", "SAVE_GAME", "LOAD_GAME", "EXIT"};
enum DIREC
{
    ESTE,
    SUDESTE,
    SUR,
    SUDOESTE,
    OESTE,
    NOROESTE,
    NORTE,
    NORESTE,
    QUIETO
};
enum WEAP
{
    PISTOL,
    SHOTGUN,
    UZI,
    ASSAULT
};
const char *WEAP_t[] = {"PISTOL", "SHOTGUN", "UZI", "ASSAULT"};
enum WEAP_STATE
{
    SELECTED,
    UNSELECTED
};
enum ENEMY_STATE
{
    INMOVIL,
    PERSIGUIENDO,
    VOLVIENDO
};
const char *ENEMY_STATE_t[] = {"INMOVIL", "PERSIGUIENDO", "VOLVIENDO"};
enum ENEMY_AI
{
    EASY,
    NORMAL,
    HARD
};
const char *ENEMY_AI_t[] = {"EASY", "NORMAL", "HARD"};
enum LOOT_TYPE
{
    AMMO_PISTOL,
    AMMO_SHOTGUN,
    AMMO_UZI,
    AMMO_ASSAULT,
    HEALTH
};
enum MENU_ACTION
{
    GOUP,
    GODOWN,
    BACK,
    SELECT,
    QUIT,
    NONE
};
enum COL_TYPE
{
    WALL,
    WATER
};
enum PLAYER_STATE
{
    IDLE,
    WALKING,
    SHOOTING
};
enum BUTTON_STATE
{
    NONE_,
    MOUSEOVER,
    CLICKHOLD,
    RELEASE
};
enum KEYS
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SPACE,
    ONE,
    TAB,
    RIGHTCLICK
};
bool keys[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int cant_keys = 8;

//-------------------------------
//  VARIABLES DEL PROGRAMA
//-------------------------------

int ANCHO, ALTO;
int ANCHO_MAPA, ALTO_MAPA;
const int MAX_BULLETS = 20;   // Si se modifica, borrar archivos
const int MAX_ENEMIES = 80;   // Si se modifica, borrar archivos
const int MAX_LOOT = 100;     // Si se modifica, borrar archivos
float camx = 0, camy = 0;     // Coordenadas de la c�mara
int x_mouse = 0, y_mouse = 0; // Coordenadas del mouse

//-------------------------------
//  FUNCIONES
//-------------------------------

void imagen(const char *BMP, bool redimensionar, int num = 0)
{

    bool done = false;
    ALLEGRO_BITMAP *bmp = al_load_bitmap(BMP);
    int w = al_get_bitmap_width(bmp);
    int h = al_get_bitmap_height(bmp);
    int h_new;

    while (!done)
    {

        al_wait_for_event(event_queue, &ev);
        if (ev.type == ALLEGRO_EVENT_KEY_DOWN or
            ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
            done = true;

        h_new = (ANCHO * h) / w;

        if (redimensionar)
            al_draw_scaled_bitmap(bmp, 0, 0, w, h, 0, ALTO / 2 - (h_new / 2), ANCHO, h_new, 0);
        else
            al_draw_bitmap(bmp, ANCHO / 2 - (w / 2), ALTO / 2 - (h / 2), 0);

        if (num != 0)
            al_draw_textf(keepcalm_med, al_map_rgb(20, 255, 20), ANCHO / 2 + camx, ALTO * 0.20 + camy,
                          ALLEGRO_ALIGN_CENTER, "SU PUNTAJE: %i", num);

        al_flip_display();
        al_clear_to_color(al_map_rgb(20, 20, 20));
    }
    al_destroy_bitmap(bmp);
}

/// Copiar al clipboard (para hacer colisiones)
//void copiar(){
//
//    char x[6],y[6];
//    char texto[25];
//
//    itoa(x_mouse+(int)camx,x,10);
//    itoa(y_mouse+(int)camy,y,10);
//
//    strcpy_s(texto,x);
//    strcat(texto,",");
//    strcat(texto,y);
//
//    HGLOBAL hText;
//    char *pText;
//    hText = GlobalAlloc(GMEM_DDESHARE|GMEM_MOVEABLE, 2000);
//    pText = (char*)GlobalLock(hText);
//    strcpy_s(pText, texto);
//    GlobalUnlock(hText);
//
//    OpenClipboard(NULL);
//    EmptyClipboard();
//    SetClipboardData(CF_TEXT, hText);
//    CloseClipboard();
//}

#endif // GLOBALS_H_INCLUDED
