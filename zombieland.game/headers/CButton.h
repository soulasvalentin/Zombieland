#ifndef CBUTTON_H_INCLUDED
#define CBUTTON_H_INCLUDED

class CButton
{

private:
    BUTTON_STATE state;
    int x, y, w, h;
    bitmap bmp;

public:
    CButton();
    void init(int _x, int _y, bitmap);
    void update();
    void render();
    bool getReleased()
    {
        if (state == RELEASE)
            return true;
        else
            return false;
    }
};

CButton::CButton()
{

    state = NONE_;
}

void CButton::init(int _x, int _y, bitmap bmp_aux)
{

    x = _x;
    y = _y;
    bmp = bmp_aux;
}

void CButton::update()
{

    if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        if (ev.mouse.button == 1)
            keys[RIGHTCLICK] = true;
    if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        if (ev.mouse.button == 1)
            keys[RIGHTCLICK] = false;

    if (collision::boundingBox_pixel(x + camx, y + camy, x + bmp.w + camx, y + (bmp.h / 3) + camy, x_mouse, y_mouse))
    {
        if (keys[RIGHTCLICK])
        {

            state = CLICKHOLD;
        }
        else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        {
            if (ev.mouse.button == 1)
            {

                keys[RIGHTCLICK] = false;
                state = RELEASE;
            }
        }
        else
        {
            state = MOUSEOVER;
        }
    }
    else
        state = NONE_;
}

void CButton::render()
{

    al_draw_bitmap_region(bmp.bmp, 0, state * (bmp.h / 3), bmp.w, bmp.h / 3, x + camx, y + camy, 0);
}

#endif // CBUTTON_H_INCLUDED
