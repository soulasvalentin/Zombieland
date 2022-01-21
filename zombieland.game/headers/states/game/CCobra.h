#ifndef CCOBRA_H_INCLUDED
#define CCOBRA_H_INCLUDED

class CCobra:public CPhysicalObject{

    private:

        float rad;
        bool player_in;

    public:

        CCobra();
        void init();
        void update_cobra(int _x, int _y);
        void render_cobra();

        void setPlayer_in(bool _player_in){player_in = _player_in;}
        bool getPlayer_in(){return player_in;}
};

CCobra::CCobra(){

    x = 3354;
    y = 2126;
    rad = 0;
    player_in = false;
}

void CCobra::init(){

    x = 3354;
    y = 2126;
    rad = 0;
    player_in = false;
}

void CCobra::update_cobra(int _x, int _y){

    if(player_in){
        x = _x-236;
        y = _y-176;
    }
}

void CCobra::render_cobra(){

    if(player_in)
    {
        int cat1 = (x_mouse+camx) - (x+236);
        int cat2 = (y_mouse+camy) - (y+176);
        double rad_cobra = atan2(cat2,cat1);
        al_draw_rotated_bitmap(bmp_cobra.bmp,236,176,x+236,y+176,rad_cobra,0);
    }
    else
        al_draw_bitmap(bmp_cobra.bmp,x,y,0);

    // ASPAS

    rad+=0.25;
    if(rad > 6.28)
        rad = 0;

    al_draw_rotated_bitmap(bmp_aspa.bmp,150,151,x+236,y+176,rad,0);
}


#endif // CCOBRA_H_INCLUDED
