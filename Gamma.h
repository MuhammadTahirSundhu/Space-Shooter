#ifndef GAMMA_H
#define GAMMA_H

#include"Invador.h"

class Gamma :public Invador {
public:
    Gamma()
    {
        emy.loadFromFile("img/gama.png");
        enemy.setTexture(emy);
        enemy.setScale(0.3, 0.3);
        enemy.setPosition(900, 2 * (enemy.getGlobalBounds().height) - 10);
         enemy.setOrigin(0.3/2,0.3/2);

    }
    void attack(Bomb* b)
    {
        b->bomb.move(0, 1 * b->bomb_speed);
        if (b->bomb.getPosition().y > 700)
            b->bomb.setPosition(-200, -200);
    }
    void move(int x, int y)
    {
        enemy.move(-0.5 * coming_speed, 0);
        if (enemy.getPosition().x <= 0)
            enemy.setPosition(x, y);
    }

    void Score_inc(Score * S)
    {
        S->setScore(5);
    }
    ~Gamma() {}
};


#endif