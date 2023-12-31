#ifndef LIVES_H
#define LIVES_H

#include <SFML/Graphics.hpp>

class Lives{
private:

static int count;

public:
Texture lv;
Sprite lives;

Lives()
{
    count++;
    if(count == 1)
    s1(850,100);
    else if(count == 2)
    s1(810,100);
    else if(count == 3)
    s1(770,100);
}
void s1(int x,int y)
{
 lv.loadFromFile("img/life_addon.png");
 lives.setTexture(lv);
 lives.setScale(1,1);
 lives.setPosition(x,y);  
}

void setLives(int x)
{
    count=x;
}
int getLives()
{
    return count;
}

static int getCount()
{
    return count;
}

~Lives()
{
    count--;
}
};
int Lives::count=0;

#endif