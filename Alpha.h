#ifndef ALPHA_H
#define ALPHA_H
#include "Enemy.h"
#include"Invador.h"

class Alpha :public Invador {
public:
    Alpha()
    {
        emy.loadFromFile("img/alpha.png");
        enemy.setTexture(emy);
        enemy.setScale(0.45, 0.45);
        enemy.setPosition(-100, 0);
        enemy.setOrigin(0.45/2,0.45/2);
    }
    void attack(Bomb* b)
    {
        b->bomb.move(0, 1 * b->bomb_speed);
        if (b->bomb.getPosition().y > 700)
            b->bomb.setPosition(-200, -200);
    }
    void move(int x, int y)
    {
        enemy.move(0.5 * coming_speed, 0);
        if (enemy.getPosition().x >= 700)
            enemy.setPosition(x, y);
    }
    void Score_inc(Score * S)
    {
        S->setScore(5);
    }


    ~Alpha() {}
};



#endif