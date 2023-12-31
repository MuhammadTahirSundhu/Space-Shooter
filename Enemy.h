#ifndef ENEMY_H
#define ENEMY_H



#include <SFML/Graphics.hpp>
#include<string.h>
#include "Bomb.h"
#include "Score.h"
using namespace sf;

class Enemy {
public:
    Texture emy;
    Sprite enemy;
    float coming_speed = 0.1;
    Enemy()
    {  
    }
    virtual void attack(Bomb* b) = 0;
    virtual void Score_inc(Score * S) = 0;
    virtual void move(int x,int y) {}
    virtual ~Enemy(){}
};


#endif 
