#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED

class CInventory
{

private:
    /// MONEDA
    int credits;

    /// ARMAS
    bool weapons[4];
    int weapon_damage[4];
    int weapon_mag_size[4];
    double weapon_fire_rate[4];
    double weapon_reload_time[4];

    int actual_weap;

    /// MUNICIONES
    int ammunition[4];

public:
    void init();

    /// CREDITOS
    void show_info();
    void add_credits(int add) { credits += add; }
    int getCredits() { return credits; }

    /// ARMAS
    void show_weapons_mouseover(int x, int y); /// Muestra las armas si es que el usuario las tiene
    void show_actualweapon();                  /// Muestra el arma actual
    void select_weapon(int x, int y);          /// Cambia el arma con un mouseover
    void aquire_weapon(int weap);
    int getActual_weap() { return actual_weap; }
    void setActual_weap(int actual_weap_aux) { actual_weap = actual_weap_aux; }
    void setWeapon_damage(int _weap, int aux) { weapon_damage[_weap] = aux; }
    void setWeapon_mag_size(int _weap, int aux) { weapon_mag_size[_weap] = aux; }
    void setWeapon_fire_rate(int _weap, double aux) { weapon_fire_rate[_weap] = aux; }
    void setWeapon_reload_time(int _weap, double aux) { weapon_reload_time[_weap] = aux; }

    bool getWeapon(int _WEAP) { return weapons[_WEAP]; }
    bool *getWeapons() { return weapons; }
    int getWeapon_damage(int _weap) { return weapon_damage[_weap]; }
    int getWeapon_mag_size(int _weap) { return weapon_mag_size[_weap]; }
    float getWeapon_fire_rate(int _weap) { return weapon_fire_rate[_weap]; }
    float getWeapon_reload_time(int _weap) { return (float)weapon_reload_time[_weap]; }
    int getWeapon_damage() { return weapon_damage[actual_weap]; }
    int getWeapon_mag_size() { return weapon_mag_size[actual_weap]; }
    float getWeapon_fire_rate() { return weapon_fire_rate[actual_weap]; }
    float getWeapon_reload_time() { return (float)weapon_reload_time[actual_weap]; }

    /// MUNICIONES
    void show_ammunition_by_actual_weapon(bool reloading); /// Muestra las municiones disponibles del arma actual
    void ammunition_edit(int weapon, int cant);            /// Suma 'CANT' municiones al vector de municiones
    int getAmmunition(int _weap) { return ammunition[_weap]; }
    int getAmmunition() { return ammunition[actual_weap]; }

    void show_debug_info();

    CInventory operator=(const CInventory);
};

void CInventory::init()
{

    //-------------------------------
    //  SE INICIALIZAN LAS ARMAS DEL INVENTARIO DEL USUARIO
    //-------------------------------

    weapons[PISTOL] = true;
    weapons[SHOTGUN] = false;
    weapons[UZI] = false;
    weapons[ASSAULT] = false;

    //-------------------------------
    //  INICIALIZO EL DA�O DE LAS ARMAS
    //-------------------------------

    weapon_damage[PISTOL] = 20;
    weapon_damage[SHOTGUN] = 60;
    weapon_damage[UZI] = 30;
    weapon_damage[ASSAULT] = 40;

    //-------------------------------
    //  INICIALIZO EL TAMA�O DEL CARTUCHO
    //-------------------------------

    weapon_mag_size[PISTOL] = 9;
    weapon_mag_size[SHOTGUN] = 2;
    weapon_mag_size[UZI] = 25;
    weapon_mag_size[ASSAULT] = 20;

    //-------------------------------
    //  INICIALIZO EL TIEMPO ENTRE DISPAROS
    //-------------------------------

    weapon_fire_rate[PISTOL] = 0.5;
    weapon_fire_rate[SHOTGUN] = 0.8;
    weapon_fire_rate[UZI] = 0.15;
    weapon_fire_rate[ASSAULT] = 0.25;

    //-------------------------------
    //  INICIALIZO EL TIEMPO DE RECARGA
    //-------------------------------

    weapon_reload_time[PISTOL] = 2;
    weapon_reload_time[SHOTGUN] = 4;
    weapon_reload_time[UZI] = 3;
    weapon_reload_time[ASSAULT] = 3;

    //-------------------------------
    //  INICIALIZO EL ARMA ACTUAL
    //-------------------------------

    actual_weap = PISTOL;

    //-------------------------------
    //  INICIALIZO MUNICIONES
    //-------------------------------

    ammunition[PISTOL] = 60;
    ammunition[SHOTGUN] = 10;
    ammunition[UZI] = 30;
    ammunition[ASSAULT] = 30;

    //-------------------------------
    //  INICIALIZO CREDITOS
    //-------------------------------

    credits = 100;
}

void CInventory::show_info()
{

    //-------------------------------
    //  MUESTRA LOS CREDITOS DEL USUARIO EN EL JUEGO
    //-------------------------------

    al_draw_textf(keepcalm_med, al_map_rgb(250, 250, 250), camx + ANCHO - 10, camy + ALTO - 60, ALLEGRO_ALIGN_RIGHT, "$ %i", credits);
}

void CInventory::show_weapons_mouseover(int x, int y)
{

    //-------------------------------
    //  MUESTRA LAS ARMAS EN X,Y DEL JUGADOR
    //  SE UTILIZA UNA FUNCION DE COLISION PARA EVALUAR UN "MOUSEOVER"
    //-------------------------------

    if (weapons[PISTOL])
    {
        if (collision::boundingBox_pixel(x - 50, y - 70, x + 100, y, x_mouse, y_mouse))
            al_draw_bitmap_region(bmp_weapons, 139 * PISTOL, 43 * SELECTED, 139, 43, x - 40, y - 58, 0);
        else
            al_draw_bitmap_region(bmp_weapons, 139 * PISTOL, 43 * UNSELECTED, 139, 43, x - 40, y - 58, 0);
    }
    if (weapons[SHOTGUN])
    {
        if (collision::boundingBox_pixel(x + 60, y, x + 200, y + 65, x_mouse, y_mouse))
            al_draw_bitmap_region(bmp_weapons, 139 * SHOTGUN, 43 * SELECTED, 139, 43, x + 60, y + 12, 0);
        else
            al_draw_bitmap_region(bmp_weapons, 139 * SHOTGUN, 43 * UNSELECTED, 139, 43, x + 60, y + 12, 0);
    }
    if (weapons[UZI])
    {
        if (collision::boundingBox_pixel(x - 140, y, x, y + 65, x_mouse, y_mouse))
            al_draw_bitmap_region(bmp_weapons, 139 * UZI, 43 * SELECTED, 139, 43, x - 140, y + 12, 0);
        else
            al_draw_bitmap_region(bmp_weapons, 139 * UZI, 43 * UNSELECTED, 139, 43, x - 140, y + 12, 0);
    }
    if (weapons[ASSAULT])
    {
        if (collision::boundingBox_pixel(x - 50, y + 65, x + 100, y + 135, x_mouse, y_mouse))
            al_draw_bitmap_region(bmp_weapons, 139 * ASSAULT, 43 * SELECTED, 139, 43, x - 42, y + 75, 0);
        else
            al_draw_bitmap_region(bmp_weapons, 139 * ASSAULT, 43 * UNSELECTED, 139, 43, x - 42, y + 75, 0);
    }
}

void CInventory::show_actualweapon()
{

    //-------------------------------
    //  MUESTRA EL ARMA ACTUAL EN EL JUEGO
    //-------------------------------

    al_draw_bitmap_region(bmp_weapons, 139 * actual_weap, 43 * SELECTED, 139, 43, camx, camy + ALTO - 50, 0);
}

void CInventory::select_weapon(int x, int y)
{

    //-------------------------------
    //  SELECCIONA EL ARMA AL SOLTAR LA TECLA "TAB"
    //  LA SELECCION SE EVALUA CON COLISION Y "MOUSEOVER"
    //-------------------------------

    if (collision::boundingBox_pixel(x - 50, y - 70, x + 100, y, x_mouse, y_mouse))
        actual_weap = PISTOL;

    if (weapons[SHOTGUN] && collision::boundingBox_pixel(x + 60, y, x + 200, y + 65, x_mouse, y_mouse))
        actual_weap = SHOTGUN;

    if (weapons[UZI] && collision::boundingBox_pixel(x - 140, y, x, y + 65, x_mouse, y_mouse))
        actual_weap = UZI;

    if (weapons[ASSAULT] && collision::boundingBox_pixel(x - 50, y + 65, x + 100, y + 135, x_mouse, y_mouse))
        actual_weap = ASSAULT;
}

void CInventory::aquire_weapon(int weap)
{

    //-------------------------------
    //  OBTIENE EL ARMA QUE RECIBE COMO PARAMETRO
    //-------------------------------

    weapons[weap] = true;
}

void CInventory::show_ammunition_by_actual_weapon(bool reloading)
{

    //-------------------------------
    //  MUESTRA LAS MUNICIONES DEL ARMA ACTUAL
    //  MUESTRA "0" CON CARTUCHO LLENO (ARREGLAR)
    //-------------------------------

    /*al_draw_textf(keepcalm_med,al_map_rgb(50,50,50),camx+173,camy+ALTO-30,ALLEGRO_ALIGN_RIGHT,
                  "%i",int(ammunition[actual_weap]/weapon_mag_size[actual_weap]));

    al_draw_textf(keepcalm24,al_map_rgb(50,50,50),camx+175,camy+ALTO-50,0,
                  "/%i",ammunition[actual_weap]-(int(ammunition[actual_weap]/weapon_mag_size[actual_weap])*weapon_mag_size[actual_weap]));*/

    al_draw_textf(keepcalm_med, al_map_rgb(250, 250, 250), camx + 173, camy + ALTO - 30, ALLEGRO_ALIGN_RIGHT,
                  "%i", int(ammunition[actual_weap] / weapon_mag_size[actual_weap]));
    if (!reloading)
        al_draw_textf(keepcalm24, al_map_rgb(250, 250, 250), camx + 175, camy + ALTO - 50, 0,
                      "/%i", ammunition[actual_weap] % weapon_mag_size[actual_weap]);
    else
        al_draw_text(keepcalm24, al_map_rgb(250, 250, 250), camx + 175, camy + ALTO - 50, 0, "/0");
}

void CInventory::ammunition_edit(int weapon, int cant)
{

    //-------------------------------
    //  AGREGA O RESTA MUNICIONES QUE RECIBE POR PARAMETRO, EN EL ARMA CORRESPONDIENTE
    //-------------------------------

    ammunition[weapon] += cant;
}

void CInventory::show_debug_info()
{

    //-------------------------------
    //  MUESTRA EL ARMA ACTUAL
    //-------------------------------

    al_draw_text(keepcalm12, al_map_rgb(250, 250, 250), camx + 5, camy + 200, 0, WEAP_t[actual_weap]);
}

CInventory CInventory::operator=(const CInventory aux)
{

    for (int i = 0; i < 4; i++)
    {

        this->weapons[i] = aux.weapons[i];
        this->weapon_damage[i] = aux.weapon_damage[i];
        this->weapon_mag_size[i] = aux.weapon_mag_size[i];
        this->weapon_fire_rate[i] = aux.weapon_fire_rate[i];
        this->weapon_reload_time[i] = aux.weapon_reload_time[i];
        this->ammunition[i] = aux.ammunition[i];
    }
    this->actual_weap = aux.actual_weap;
    this->credits = aux.credits;

    return *this;
}

#endif // INVENTORY_H_INCLUDED
