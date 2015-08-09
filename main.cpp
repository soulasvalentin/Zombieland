#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdio.h>
#include <cmath>

using namespace std;

#include "src/Globals.h"
#include "src/CError.h"
#include "src/CAllegro.h"
#include "src/CCollision.h"
#include "src/CGameState.h"
#include "src/CButton.h"
#include "src/CProgram.h"


                /**************************************
               **            ZOMBIELAND V4            **
              ***       @author Valentin Soulas       ***
             ****  @contact soulasvalentin@gmail.com  ****
             ****                                     ****
              ***         UTN GENERAL PACHECO         ***
               **     LABORATORIO II - TSP (2015)     **
                **************************************/

/**
   BUGS CONOCIDOS
   - Al guardar una partida, esta podrá ser cargada solo si no se
     cerró el programa desde que se guardó la partida. Si se quiere
     cargar una partida de una sesión del programa anterior, se
     carga con datos corruptos.
*/


/**
    ESTRUCTURA

    inicializar();
    while(control){
        leer_inputs();
        if("60 veces x segundo){
            actualizar();
            renderizar();
        }
    }
    destruir();

    Video tutoriales recomendados
    https://www.youtube.com/playlist?list=PL9333715188CD7669
    https://www.youtube.com/playlist?list=PL39C639F833BEB5E4
*/

int main()
{


    //-------------------------------
    //  INICIALIZAR ALLEGRO
    //-------------------------------

    Allegro al(1024,768);
    al.install_addons();
    al.load_fonts();
    al.load_samples();
    al.register_events();
    al_start_timer(timer);
    imagen("resources/menus/intro_zombieland.jpg",true);
    al.load_bitmaps();

    srand(time(NULL));

    CProgram Program;


    ///*********************************************
    ///*          COMIENZO DEL PROGRAMA
    ///*********************************************

    while(GameState.getState() != EXIT){

        ///*********************************************
        ///*        PROCESO DEL PROGRAMA
        ///*********************************************

        al_wait_for_event(event_queue, &ev);
        if(ev.type == ALLEGRO_EVENT_TIMER) GameState.changeRedraw(true);

        al.read_mouse_coords();

        Program.update_actual_state(GameState.getState());

        Error.update_error();


        ///*********************************************
        ///*        RENDERIZADO DEL PROGRAMA
        ///*********************************************

        if(GameState.getRedraw() and al_is_event_queue_empty(event_queue)){

            GameState.changeRedraw(false);

            Program.render_actual_state(GameState.getState());

            Error.render_error();

            if(GameState.getDebug_info()){
                al.showMousePos(x_mouse+camx,y_mouse+camy);
                al.showFps();
                GameState.show_state_debug();
            }

            al_flip_display();
            al_clear_to_color(al_map_rgb(20,20,20));
        }
    }

    ///*********************************************
    ///*            DESTRIUR EL JUEGO
    ///*********************************************

    Program.destroy_all();
    al.terminate_allegro();

    return 0;
}
























