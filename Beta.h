#ifndef BETA_H
#define BETA_H
#include "Enemy.h"
#include"Invador.h"

class Beta :public Invador {
public:
    Beta()
    {
        emy.loadFromFile("img/beta.png");
        enemy.setTexture(emy);
        enemy.setScale(0.4, 0.4);
        enemy.setPosition(900, enemy.getGlobalBounds().height - 5);
        enemy.setOrigin(0.4/2,0.4/2);

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
    ~Beta() {}
};



#endif