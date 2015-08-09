#ifndef BULLETS_H_INCLUDED
#define BULLETS_H_INCLUDED

class CBullets:public CPhysicalObject{

    private:

        int w,h;
        float vx,vy;
        int speed;
        int damage;

    public:

        CBullets();

        void init(int weapon);
        void render(int weapon);
        void fire(int x_player,int y_player, int damage);
        void update();
        void destroy();
        bool isOutRange();
        void show_debug(){}

        int getDamage(){return damage;}
};

CBullets::CBullets(){

    live = false;
}

void CBullets::init(int weapon){

    //-------------------------------
    //  INICIALIZAR BALAS
    //-------------------------------

    switch(weapon){
    case PISTOL:
        speed  = 5;
        break;
    case SHOTGUN:
        speed  = 4;
        break;
    case UZI:
        speed  = 5;
        break;
    case ASSAULT:
        speed  = 5;
        break;
    }
}
void CBullets::render(int weapon){

    //-------------------------------------------
    //    DIBUJAR BALAS
    //-------------------------------------------

    if(live)
        if(weapon != SHOTGUN)
            al_draw_line(x,y,x+vx*3,y+vy*3,al_map_rgb(255,220,0),3);
        else{
            al_draw_filled_circle(x,y,2,al_map_rgb(255,220,0));
            al_draw_filled_circle(x+5,y+7,2,al_map_rgb(255,220,0));
            al_draw_filled_circle(x+5,y+1,2,al_map_rgb(255,220,0));
            al_draw_filled_circle(x-4,y+4,2,al_map_rgb(255,220,0));
        }
}


void CBullets::fire(int x_player, int y_player, int _damage){

    //-------------------------------
    //  DISPARAR BALAS
    //  EN LA POS DEL JUGADOR
    //  CALCULA EL ANGULO
    //-------------------------------

    x = x_player + 22;
    y = y_player + 30;
    w = (x_mouse+camx) - x_player;
    h = (y_mouse+camy) - y_player;
    double rad = atan2(h,w);
    vy=sin(rad)*speed;
    vx=cos(rad)*speed;
    live = true;
    damage = _damage;
}
void CBullets::update(){

    //-------------------------------
    //  ACTUALIZA LA POS DE LA BALA
    //-------------------------------

    x += (vx*speed);
    y += (vy*speed);

    if(collision_map1(x,y,2,2) == WALL)
        live = false;
}
bool CBullets::isOutRange(){

    //-------------------------------
    //  EVALUA SI LA BALA SALE DE LA PANTALLA
    //-------------------------------

    if(x > ANCHO + camx or
       x < camx or
       y > ALTO + camy or
       y < camy)
        return true;
    else
        return false;
}
void CBullets::destroy(){

    //-------------------------------
    //  DESTRUYE LA BALA
    //-------------------------------

    live = false;
}

#endif // BULLETS_H_INCLUDED
