#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "CGameObject.h"

/**
    *******************
    * CLASS CHARACTER *
    *******************

    - Clase dedicada a los personajes y ejecuciones de sus comportamientos
*/

class CPlayer:public CPhysicalObject{

    private:

        int w,h;
        int vel, stamina, max_stamina;
        int score;
        char name[20];

        PLAYER_STATE state;

    public:

        void init(int,int);
        void update();
        void render();
        void teleport();
        void hit_recived(int ammount);
        void show_debug();
        void draw_stamina_bar();
        void draw_score();

        // Setters && Getters && Addition
        int getW(){return w;}
        int getH(){return h;}
        int getMax_stamina(){return max_stamina;}
        int getScore(){return score;}
        int getStamina(){return stamina;}
        void addMax_stamina(int cant=1){max_stamina += cant; if(max_stamina > 400) max_stamina = 400;}
        void addScore(int cant=1){score += cant;}
        void setStamina(int _stamina){stamina = _stamina; if(stamina > max_stamina) stamina = max_stamina;}
        void setVel(int _vel){vel = _vel;}
        CPlayer operator=(const CPlayer aux);
};


void CPlayer::init(int X,int Y){

    //-------------------------------
    //  INICIALIZA EL JUGADOR
    //-------------------------------

    xa = x = X;
    ya = y = Y;

    vel = 1;
    max_stamina = stamina = 200;
    score = 0;
    live = true;

    state = IDLE;

    w = al_get_bitmap_width(bmp_player);
    h = al_get_bitmap_height(bmp_player);

    is_col = true;
}


void CPlayer::update(){

    //-------------------------------
    //  ACTUALIZA LA POS DEL JUGADOR
    //-------------------------------

    if(keys[UP] && keys[RIGHT]){
            x += vel;
            y -= vel;
    }
    else if(keys[DOWN] && keys[RIGHT]){
            x += vel;
            y += vel;
    }
    else if(keys[UP] && keys[LEFT]){
            x -= vel;
            y -= vel;
    }
    else if(keys[DOWN] && keys[LEFT]){
            x -= vel;
            y += vel;
    }
    else if(keys[UP]){
            y -= vel;
    }
    else if(keys[DOWN]){
            y += vel;
    }
    else if(keys[LEFT]){
            x -= vel;
    }
    else if(keys[RIGHT]){
            x += vel;
    }

    //-------------------------------
    //  COLISION
    //-------------------------------

    if(x < 0) x = 0;
    if(y < 0) y = 0;
    if(x + w > ANCHO_MAPA) x = ANCHO_MAPA - 51;
    if(y + h > ALTO_MAPA) y = ALTO_MAPA - 60;
    if(is_col)
        switch(collision_map1(x-10,y-10,20,20)){
        case WALL:
            x = xa;
            y = ya;
            break;
        case WATER:
            if(rand()%30 == 0)
                stamina -= 10;
            break;
        }
}

void CPlayer::hit_recived(int ammount){

    stamina -= ammount;
    if(stamina < 0)
        stamina = 0;
}

void CPlayer::teleport(){

    //-------------------------------
    //  TELEPORT CON LA TECLA "1"
    //-------------------------------

    x = x_mouse - w/2 + camx;
    y = y_mouse - h/2 + camy;
}


void CPlayer::render(){

    //-------------------------------
    //  DIBUJAR AL JUGADOR
    //-------------------------------

    int cat1 = (x_mouse+camx) - x;
    int cat2 = (y_mouse+camy) - y;
    double rad = atan2(cat2,cat1);

    al_draw_rotated_bitmap(bmp_player,w/2,h/2,x,y,rad,0);

    if(GameState.getGame_info())
        al_draw_rectangle(x-10,y-10,x+10,y+10,al_map_rgb(250,250,250),1);
}

void CPlayer::show_debug(){

    //-------------------------------
    //  MUESTRA DEBUG
    //-------------------------------

    al_draw_textf(keepcalm12,al_map_rgb(250,250,250),camx+5,camy+140,0,"player x: %i",(int)x);
    al_draw_textf(keepcalm12,al_map_rgb(250,250,250),camx+5,camy+155,0,"player y: %i",(int)y);
    al_draw_textf(keepcalm12,al_map_rgb(250,250,250),camx+5,camy+245,0,"salud: %i/%i",stamina,max_stamina);

}

void CPlayer::draw_stamina_bar(){

    al_draw_rectangle(camx+4,camy+ALTO-91,camx+6+max_stamina,camy+ALTO-64,al_map_rgb(20,20,20),2);
    al_draw_filled_rectangle(camx+5,camy+ALTO-90,camx+5+max_stamina,camy+ALTO-65,al_map_rgba_f(.1,.1,.1,.1));
    al_draw_filled_rectangle(camx+5,camy+ALTO-90,camx+5+stamina,camy+ALTO-65,al_map_rgb(210,20,20));
    al_draw_text(keepcalm_med,al_map_rgb(255,255,255),camx+7,camy+ALTO-90,0,"SALUD");
}

void CPlayer::draw_score(){

    al_draw_textf(keepcalm_med,al_map_rgb(250,250,250),ANCHO-5+camx,ALTO-30+camy,ALLEGRO_ALIGN_RIGHT,
                  "PUNTAJE: %i",score);
}

CPlayer CPlayer::operator=(const CPlayer aux){

    this->vel = aux.vel;
    this->stamina = aux.stamina;
    this->max_stamina = aux.max_stamina;
    this->score = aux.score;
    this->state = aux.state;

    this->x = aux.x;
    this->y = aux.y;
    this->xa = aux.xa;
    this->ya = aux.ya;
    this->live = aux.live;
    this->is_col = aux.is_col;

    return *this;
}

#endif // PLAYER_H_INCLUDED



















