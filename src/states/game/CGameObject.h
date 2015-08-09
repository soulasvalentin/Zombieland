#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED

/**
    ************************
    * CLASS CGAMEOBJECT
    ************************

    Detalles:
        - Clase madre con variables y métodos para objetos
*/

class CPhysicalObject{

protected:
    float x,y;
    float xa,ya;
    bool live;
    bool is_col;

public:



    void update_ant();

    // Setters & Getters
    void setX(float _x){x = _x;}
    void setY(float _y){y = _y;}
    void setAnt();
    void setLive(bool _live){live = _live;}
    void setIs_col(bool _is_col){is_col = _is_col;}

    float getX(){return x;}
    float getY(){return y;}
    bool  getLive(){return live;}
    bool  getIs_col(){return is_col;}
};


void CPhysicalObject::update_ant(){

    xa = x;
    ya = y;
}

void CPhysicalObject::setAnt(){

    x = xa;
    y = ya;
}

#endif // GAMEOBJECT_H_INCLUDED
