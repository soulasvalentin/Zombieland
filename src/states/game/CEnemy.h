#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "CGameObject.h"

/// CLASS ENEMY

class CEnemy:public CPhysicalObject{

private:


    int w,h;
    double rad;
    int radio;

    int stamina;
    int stamina_max;
    float speed;
    int aggro_distance;
    int damage;

    ENEMY_STATE state;
    ENEMY_AI ai;

public:

    void init(ENEMY_AI _AI, int _x, int _y);

    void update(int x_target, int y_target);
    void die();
    bool recive_hit(int hit); // Devuelve 1 si muere

    float distance_target(int x1, int y1, int x2, int y2);
    float angle_target(int x1, int y1, int x2, int y2);

    void render(float x, float y);
    void draw_stamina();
    void show_aggro_distance();
    void show_initial_distance();
    void show_debug();

    void destroy(){}

    int getRadio(){return radio;}
    int getDamage(){return damage;}

    CEnemy operator=(const CEnemy Enemy_aux);
};

void CEnemy::init(ENEMY_AI _AI = EASY, int _x=0, int _y=0){


    //-------------------------------
    //  INICIALIZA EL ENEMIGO
    //-------------------------------


    xa = x = _x;
    ya = y = _y;

    live = true;
    w = al_get_bitmap_width(bmp_enemy);
    h = al_get_bitmap_height(bmp_enemy);
    state = INMOVIL;
    ai = _AI;
    radio = 20;
    rad = 0;

    //-------------------------------
    //  INICIALIZA LA DIFICULTAD DEL ENEMIGO
    //-------------------------------

    switch(_AI){

    case EASY:
        stamina_max = stamina = 100;
        speed = 0.4;
        aggro_distance = 300;
        damage = 5;
        break;

    case NORMAL:
        stamina_max = stamina = 200;
        speed = 0.6;
        aggro_distance = 300;
        damage = 15;
        break;

    case HARD:
        stamina_max = stamina = 280;
        speed = 1.2;
        aggro_distance = 500;
        damage = 25;
        break;
    }
}

void CEnemy::update(int x_target, int y_target){

    //-------------------------------
    //  ADMINISTRA EL ESTADO DEL ENEMIGO
    //  MUEVE AL ENEMIGO
    //-------------------------------

    if(state == INMOVIL){

        if(aggro_distance > distance_target(x_target,y_target,x,y) or stamina != stamina_max)
            state = PERSIGUIENDO;
    }
    else if(state == PERSIGUIENDO){

            float angle = angle_target(x,y,x_target,y_target);

            y += (sin(angle)) * speed;
            x += (cos(angle)) * speed;

            if(aggro_distance < distance_target(x,y,x_target,y_target) and stamina == stamina_max)
                state = INMOVIL;

    }

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

    xa = x;
    ya = y;
}

void CEnemy::die(){

    live = false;
}

bool CEnemy::recive_hit(int hit){

    stamina -= hit;
    if(stamina <= 0){
        die();
        return true;
    }else
        return false;

}

float CEnemy::distance_target(int x1, int y1, int x2, int y2){

    //-------------------------------
    //  CALCULA LA DISTANCIA AL OBJETIVO
    //-------------------------------

    return sqrt(pow((float)x1-x2,2) + pow((float)y1-y2,2));
}
float CEnemy::angle_target(int x1, int y1, int x2, int y2){

    //-------------------------------
    //  CALCULA EL ANGULO CON EL OBJETIVO
    //-------------------------------

    float dX = (x2 - x1);
    float dY = (y2 - y1);

    return atan2(dY,dX);
}

void CEnemy::render(float x_target, float y_target){

    //-------------------------------
    //  DIBUJA EL ENEMIGO DEPENDIENDO SU DIFICULTAD
    //-------------------------------

    if(live){
        if(state == INMOVIL)

            al_draw_rotated_bitmap(bmp_enemy,w/2,h/2,x,y,rad,0);

        else if(state == PERSIGUIENDO){

            int cat1 = x_target - x;
            int cat2 = y_target - y;
            rad = atan2(cat2,cat1);
            al_draw_rotated_bitmap(bmp_enemy,w/2,h/2,x,y,rad,0);
        }
    }
}

void CEnemy::draw_stamina(){

    if(live){

        al_draw_filled_rectangle(x-25,y-30,x-25+(stamina*100/stamina_max)/2,y-35,al_map_rgb(34,255,190));
        al_draw_rectangle       (x-25,y-30,x+25,y-35,al_map_rgb(20,20,20),1);

    }
}

void CEnemy::show_aggro_distance(){

    //-------------------------------
    //  DIBUJA EL RANGO DE VISIÒN MAXIMO
    //-------------------------------
    if(live)
        al_draw_circle(x,y,aggro_distance,al_map_rgb(220,20,20),1);
}


void CEnemy::show_debug(){

    //-------------------------------
    //  MUESTRA LA VELOCIDAD DEL ENEMIGO
    //-------------------------------
    if(live){
        al_draw_textf(keepcalm12,al_map_rgb(250,250,250),x+radio+5,y-radio,0,"speed: %.1f",speed);
        al_draw_text(keepcalm12,al_map_rgb(250,250,250),x+radio+5,y-radio+15,0,ENEMY_STATE_t[state]);
        al_draw_text(keepcalm12,al_map_rgb(250,250,250),x+radio+5,y-radio+30,0,ENEMY_AI_t[ai]);
    }
}

CEnemy CEnemy::operator=(const CEnemy Enemy_aux){

    this->w = Enemy_aux.w;
    this->h = Enemy_aux.h;
    this->rad = Enemy_aux.rad;
    this->radio = Enemy_aux.radio;

    this->stamina = Enemy_aux.stamina;
    this->stamina_max = Enemy_aux.stamina_max;
    this->speed = Enemy_aux.speed;
    this->aggro_distance = Enemy_aux.aggro_distance;
    this->damage = Enemy_aux.damage;

    this->state = Enemy_aux.state;
    this->ai = Enemy_aux.ai;

    this->x = Enemy_aux.x;
    this->y = Enemy_aux.y;
    this->xa = Enemy_aux.xa;
    this->ya = Enemy_aux.ya;
    this->live = Enemy_aux.live;
    this->is_col = Enemy_aux.is_col;
    return *this;
}

// FILES

void init_enemies_file(CEnemy *vEnemies){

    FILE *p = fopen("files/enemies.dat","wb");
    if(p == NULL) return;

    for(int i=0; i<MAX_ENEMIES; i++){
        vEnemies[i].init(EASY);
        vEnemies[i].setLive(false);
    }
    for(int i=0; i<MAX_ENEMIES; i++)
        fwrite(&vEnemies[i],sizeof (CEnemy), 1, p);

    fclose(p);
}

bool load_enemies(CEnemy *vEnemies){

    FILE *p = fopen("files/enemies.dat","rb");
    if(p == NULL) {init_enemies_file(vEnemies); return false;}

    for(int i=0; i<MAX_ENEMIES; i++)
        fread(&vEnemies[i],sizeof (CEnemy), 1, p);

    fclose(p);
    return true;
}

bool save_enemies(CEnemy *vEnemies){

    FILE *p = fopen("files/enemies.dat","wb");
    if(p == NULL) return false;

    for(int i=0; i<MAX_ENEMIES; i++)
        fwrite(&vEnemies[i],sizeof (CEnemy), 1, p);

    fclose(p);
    Error.open_error("ENEMIGOS","Enemigos guardados con exito");
    return true;
}

bool add_enemy(ENEMY_AI _ai,CEnemy *vEnemies, int live_vEnemies){

    if(live_vEnemies < MAX_ENEMIES){
        for(int i=0; i<MAX_ENEMIES; i++){
            if(!vEnemies[i].getLive()){

                FILE *p = fopen("files/enemies.dat","rb+");
                if(p == NULL) {init_enemies_file(vEnemies); return false;}
                vEnemies[i].init(_ai,x_mouse+camx,y_mouse+camy);
                fseek(p,i*sizeof (CEnemy),0);
                fwrite(&vEnemies[i],sizeof (CEnemy),1,p);
                fclose(p);
                return true;
            }
        }
    }
    return false;
}

#endif // ENEMY_H_INCLUDED



















