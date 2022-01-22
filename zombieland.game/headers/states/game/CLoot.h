#ifndef CLOOT_H_INCLUDED
#define CLOOT_H_INCLUDED
#include "CGameObject.h"

class CLoot : public CPhysicalObject
{

private:
    int w, h;
    int loot_type;

public:
    int getLoot_type() { return loot_type; }
    void setLoot_type(int _loot_type) { loot_type = _loot_type; }
    void init(int _loot_type, int _x, int _y);

    CLoot();
    void render_loot();
};

CLoot::CLoot()
{

    bmp_loot = al_load_bitmap("resources/sprites/loot/loot.png");
}

void CLoot::init(int _loot_type, int _x, int _y)
{

    loot_type = _loot_type;
    x = _x;
    y = _y;
    live = true;
}

void CLoot::render_loot()
{

    if (live)
    {
        al_draw_bitmap_region(bmp_loot, loot_type * 40, 0, 40, 60, x, y, 0);

        if (GameState.getGame_info())

            al_draw_rectangle(x, y, x + 40, y + 50, al_map_rgb(255, 255, 0), 2);
    }
}

// FILES

void init_loot_file(CLoot *vLoot)
{

    FILE *p;
    fopen_s(&p, "files/loot.dat", "wb");
    if (p == NULL)
        return;

    for (int i = 0; i < MAX_LOOT; i++)
    {
        vLoot[i].setLoot_type(AMMO_PISTOL);
        vLoot[i].setLive(false);
    }
    for (int i = 0; i < MAX_LOOT; i++)
        fwrite(&vLoot[i], sizeof(CLoot), 1, p);
    fclose(p);
}

bool load_loot(CLoot *vLoot)
{

    FILE *p;
    fopen_s(&p, "files/loot.dat", "rb");
    if (p == NULL)
    {
        init_loot_file(vLoot);
        return false;
    }

    for (int i = 0; i < MAX_LOOT; i++)
        fread(&vLoot[i], sizeof(CLoot), 1, p);
    fclose(p);
    return true;
}

bool save_loot(CLoot *vLoot)
{

    FILE *p;
    fopen_s(&p, "files/loot.dat", "wb");
    if (p == NULL)
        return false;

    for (int i = 0; i < MAX_LOOT; i++)
        fwrite(&vLoot[i], sizeof(CLoot), 1, p);
    fclose(p);
    Error.open_error("Loot", "Se guardo el loot con exito");
    return true;
}

bool add_loot(int _loot_type, CLoot *vLoot)
{

    for (int i = 0; i < MAX_LOOT; i++)
    {
        if (!vLoot[i].getLive())
        {

            FILE *p;
            fopen_s(&p, "files/loot.dat", "rb+");
            if (p == NULL)
            {
                init_loot_file(vLoot);
                return false;
            }
            vLoot[i].init(_loot_type, x_mouse + camx - 20, y_mouse + camy - 30);
            fseek(p, i * sizeof(CLoot), 0);
            fwrite(&vLoot[i], sizeof(CLoot), 1, p);
            fclose(p);
            return true;
        }
    }
    return false;
}

bool add_loot_random_xy(CLoot *vLoot, int xt, int yt)
{

    for (int i = 0; i < MAX_LOOT; i++)
    {
        if (!vLoot[i].getLive())
        {

            FILE *p;
            fopen_s(&p, "files/loot.dat", "rb+");
            if (p == NULL)
            {
                init_loot_file(vLoot);
                return false;
            }
            vLoot[i].init(rand() % 5, xt, yt);
            fseek(p, i * sizeof(CLoot), 0);
            fwrite(&vLoot[i], sizeof(CLoot), 1, p);
            fclose(p);
            return true;
        }
    }

    return false;
}

#endif // CLOOT_H_INCLUDED
