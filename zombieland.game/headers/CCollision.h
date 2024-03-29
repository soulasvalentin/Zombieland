#ifndef COLITION_H_INCLUDED
#define COLITION_H_INCLUDED

class collision
{

public:
    static bool boundingBox_pixel(int x1, int y1, int x2, int y2, int px, int py);
    static bool boundingBox(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
    static bool boundingBox_coords(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
    static bool circle_pixel(int x1, int y1, int r1, int x2, int y2);
    static bool circle_circle(int x1, int y1, int r1, int x2, int y2, int r2);
};

//-------------------------------
//  COLISION RECTANGULO - PIXEL
//-------------------------------

bool collision::boundingBox_pixel(int x1, int y1, int x2, int y2, int px, int py)
{

    if (px + camx > x1 and px + camx < x2 and py + camy > y1 and py + camy < y2)
        return true;
    else
        return false;
}

//-------------------------------
//  COLISION RECTANGULO - RECTANGULO
//-------------------------------

bool collision::boundingBox(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{

    if (x1 < x2 + w2 and
        x1 + w1 > x2 and
        y1 < y2 + h2 and
        h1 + y1 > y2)
        return true;
    else
        return false;
}

bool collision::boundingBox_coords(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{

    w2 = w2 - x2;
    h2 = h2 - y2;

    if (x1 < x2 + w2 and
        x1 + w1 > x2 and
        y1 < y2 + h2 and
        h1 + y1 > y2)
        return true;
    else
        return false;
}

//-------------------------------
//  COLISION CIRCULO - CIRCULO
//-------------------------------

bool collision::circle_circle(int x1, int y1, int r1, int x2, int y2, int r2)
{

    float distance = sqrt(pow((float)x1 - x2, 2) + pow((float)y1 - y2, 2));

    if (distance < (r1 + r2))
        return true;
    else
        return false;
}

#endif // COLITION_H_INCLUDED
