#ifndef CERROR_H_INCLUDED
#define CERROR_H_INCLUDED
#include <fstream>

class CError
{

private:
    char short_text[200];
    char long_text[400];
    double start_time;
    double duration;
    bool active;

public:
    CError();
    void open_error(const char *_short_text, const char *_long_text, double _duration);
    void update_error();
    void render_error();
};

CError::CError()
{

    *short_text = NULL;
    *long_text = NULL;
    start_time = 0;
    duration = 3;
    active = false;
}

void CError::open_error(const char *_short_text, const char *_long_text, double _duration = 3)
{

    al_play_sample(audios[5], .5, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
    strcpy_s(short_text, _short_text);
    strcpy_s(long_text, _long_text);
    start_time = al_get_time();
    active = true;
    duration = _duration;

    ofstream myfile;
    myfile.open("logs/errors.txt", ios::app);
    myfile << short_text;
    myfile << " - ";
    myfile << long_text;
    myfile << "\n";
    myfile.close();
}

void CError::update_error()
{

    if (start_time < al_get_time() - duration)
    {
        active = false;
    }
}

void CError::render_error()
{

    if (active)
    {
        al_draw_filled_rectangle(ANCHO / 2 + camx - 250, ALTO / 2 + camy - 30, ANCHO / 2 + camx + 250, ALTO / 2 + camy + 40, al_map_rgb(60, 60, 60));
        al_draw_rectangle(ANCHO / 2 + camx - 250, ALTO / 2 + camy - 30, ANCHO / 2 + camx + 250, ALTO / 2 + camy + 40, al_map_rgb(230, 0, 0), 3);
        al_draw_text(keepcalm_med, al_map_rgb(250, 250, 0), ANCHO / 2 + camx, ALTO / 2 + camy - 20, ALLEGRO_ALIGN_CENTER, short_text);
        al_draw_text(keepcalm12, al_map_rgb(250, 250, 0), ANCHO / 2 + camx, ALTO / 2 + camy + 15, ALLEGRO_ALIGN_CENTER, long_text);
    }
}

CError Error;

#endif // CERROR_H_INCLUDED
