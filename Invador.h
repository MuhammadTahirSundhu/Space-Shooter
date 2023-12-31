#ifndef INVADOR_H
#define INVADOR_H
#include"Enemy.h"


class Invador : public Enemy {
public:
    Invador()
    {
    }
    virtual void attack(Bomb* b) = 0;//for bomb move
    virtual void Score_inc(Score * S) = 0;

    virtual void move() {}//For enemy move
    virtual ~Invador() {}
};


#endif