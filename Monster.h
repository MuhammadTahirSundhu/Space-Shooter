#ifndef MONSTER_H
#define MONSTER_H
#include "Enemy.h"

class Monster :public Enemy {
 private:
    bool on1=true;
bool on2=false;
public:

    Monster()
    {
        emy.loadFromFile("img/monster.png");
        enemy.setTexture(emy);
        enemy.setScale(0.1, 0.1);
        enemy.setPosition(900,10);
        enemy.setOrigin(0.1/2,0.1/2);
        coming_speed=0.2;
    }

    void move(int x, int y)
    {   
        if(on1)
        {
        enemy.move(-1*coming_speed,0);
        if(enemy.getPosition().x <= 0)
        {
        on1=false;
        on2=true;
        }
        
        }
        if(on2)
        {
        enemy.move(1*coming_speed,0);
        if(enemy.getPosition().x >= 650)
        {
        on2=false;
        on1=true;}
        }
    }

    void attack(Bomb* b)
    {
        b->bomb.setPosition(enemy.getPosition().x+17,enemy.getPosition().y-35);
    }

     void Score_inc(Score * S)
    {
        S->setScore(40);
    }
    ~Monster()
    {
        
    }
};

#endif