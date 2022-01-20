#ifndef AL_INIT_H_INCLUDED
#define AL_INIT_H_INCLUDED
#define FPS 60

/**
    ************************
    * CLASS ALLEGRO
    ************************

    Detalles:
        - Clase dedicada para manejar la librería de Allegro 5
*/

class Allegro{

    private:
        double new_time,old_time;
        int cont,fps,last_fps;

    public:

        Allegro(int,int);
        void install_addons();
        void load_fonts();
        void load_samples();
        void register_events();
        void terminate_allegro();
        void read_mouse_coords();
        void load_bitmaps();

        // Mostrar Info
        void showMousePos(int,int);
        void showFps();
};


Allegro::Allegro(int W=800,int H=600){


    al_init();

    ANCHO = W;
    ALTO = H;

    // ANTIALIASING x4
    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 4, ALLEGRO_SUGGEST);

    // SIN MARCO
    //al_set_new_display_flags(ALLEGRO_NOFRAME);

    // CREAR DISPLAY Y LIMPIAR
    display = al_create_display(ANCHO,ALTO);
    al_clear_to_color(al_map_rgb(20,20,20));

    // NOMBRE VENTANA
    al_set_window_title(display,"Zombieland V4!");

    // FPS
    cont = 0;
    fps = 60;
    old_time = al_get_time();
    last_fps = 0;
    timer = al_create_timer(1.0/FPS);
}

void Allegro::install_addons(){

    //-------------------------------
    //  INSTALAR ADDONS NECESARIOS
    //-------------------------------

    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    al_install_keyboard();
    al_install_mouse();
    al_init_image_addon();
    al_install_audio();
    al_init_acodec_addon();
}

void Allegro::load_fonts(){

    //-------------------------------
    //  CARGAR FUENTES
    //-------------------------------

    keepcalm24 = al_load_font("fonts/KeepCalm-Medium.ttf",48,0);
    keepcalm_med = al_load_font("fonts/KeepCalm-Medium.ttf",24,0);
    keepcalm12 = al_load_font("fonts/KeepCalm-Medium.ttf",12,0);
    farial = al_load_font("fonts/ariAllegro.ttf",16,0);
    dayslater36 = al_load_font("fonts/28DaysLater.ttf",48,0);
    dayslater_big = al_load_font("fonts/28DaysLater.ttf",96,0);
}

void Allegro::load_samples(){

    //-------------------------------
    //  CARGAR AUDIOS
    //-------------------------------

    al_reserve_samples(6);
    audios[PISTOL]      = al_load_sample("resources/sounds/snd_pistol.wav");
    audios[SHOTGUN]     = al_load_sample("resources/sounds/snd_shotgun.wav");
    audios[UZI]         = al_load_sample("resources/sounds/snd_uzi.wav");
    audios[ASSAULT]     = al_load_sample("resources/sounds/snd_assault.wav");
    audios[4]           = al_load_sample("resources/sounds/rollover1.wav");
    audios[5]           = al_load_sample("resources/sounds/error.mp3");
}

void Allegro::register_events(){

    //-------------------------------
    //  REGISTRAR EVENTOS DE TIPO INPUT
    //-------------------------------

    event_queue = al_create_event_queue();

    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());
}

void Allegro::load_bitmaps(){

    bmp_zombieland = al_load_bitmap("resources/menus/zombieland.png");
    bmp_menu_select = al_load_bitmap("resources/menus/menu_selection.png");
    bmp_enemy = al_load_bitmap("resources/sprites/players/enemigo.png");
    bmp_player = al_load_bitmap("resources/sprites/players/pibito.png");
    bmp_map = al_load_bitmap("resources/maps/mp5-comp.jpg");
    bmp_map_grid = al_load_bitmap("resources/maps/mp5-comp_grid.png");
    bmp_weapons = al_load_bitmap("resources/sprites/weapons/weapons.png");
    bmp_compra.init();
    bmp_cobra.init();
    bmp_aspa.init();
}

void Allegro::terminate_allegro(){

    //-------------------------------
    //  DESTRUYE ELEMENTOS Y TERMINA ALLEGRO
    //-------------------------------


    al_destroy_timer(timer);

    al_destroy_font(keepcalm24);
    al_destroy_font(farial);
    al_destroy_font(keepcalm12);
    al_destroy_font(keepcalm_med);
    al_destroy_font(dayslater36);
    al_destroy_font(dayslater_big);

    al_destroy_bitmap(bmp_menu_select);
    al_destroy_bitmap(bmp_zombieland);
    al_destroy_bitmap(bmp_player);
    al_destroy_bitmap(bmp_map);
    al_destroy_bitmap(bmp_map_grid);
    al_destroy_bitmap(bmp_weapons);
    al_destroy_bitmap(bmp_loot);
    al_destroy_bitmap(bmp_enemy);
    bmp_compra.destroy();
    bmp_cobra.destroy();
    bmp_aspa.destroy();

    for(int i=0; i<6; i++)
        al_destroy_sample(audios[i]);

    al_destroy_display(display);
}


void Allegro::read_mouse_coords(){

    if(ev.type == ALLEGRO_EVENT_MOUSE_AXES){
        x_mouse = ev.mouse.x;
        y_mouse = ev.mouse.y;
    }
}

///*********************************************
///*          MOSTRAR INFORMACION
///*********************************************

void Allegro::showMousePos(int x, int y){

    //-------------------------------
    //  MUESTRA LA POS DEL MOUSE
    //-------------------------------

    al_draw_textf(keepcalm12,al_map_rgb(250,250,250),camx+5,camy+80,0,"mouse x: %i",x);
    al_draw_textf(keepcalm12,al_map_rgb(250,250,250),camx+5,camy+95,0,"mouse y: %i",y);
}

void Allegro::showFps(){

    //-------------------------------
    //  CALCULA FPS Y LAS MUESTRA
    //-------------------------------

    new_time = al_get_time();
    fps = 1.0/(new_time - old_time);
    old_time = new_time;
    if(cont++ == 60){

        last_fps = fps;
        cont = 0;
    }
    al_draw_textf(keepcalm12,al_map_rgb(250,250,250),camx+5,camy+5,0,"fps: %i",(int)last_fps);
}

///*********************************************
///*                 EXTRAS
///*********************************************


void cameraUpdate(float x, float y, int w, int h){

    //-------------------------------
    //  MUEVE LA CAMARA
    //  RECIBE COORDENADAS
    //-------------------------------

    camx = -(ANCHO/2) + (x + w/2);
    camy = -(ALTO/2) + (y + h/2);

    //-------------------------------
    //  COLISIONES
    //-------------------------------

    if(camx < 0)
        camx = 0;

    if(camy < 0)
        camy = 0;

    if(camx + ANCHO > ANCHO_MAPA)
        camx = ANCHO_MAPA - ANCHO;

    if(camy + ALTO > ALTO_MAPA)
        camy = ALTO_MAPA - ALTO;
}

#endif // AL_INIT_H_INCLUDED
