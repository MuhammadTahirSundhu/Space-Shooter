#include <SFML/Graphics.hpp>
#include<string.h>
#include "Enemy.h"
using namespace sf;

class Bullet {
public:
    Texture bullet;
    Sprite fire;
    float speed = 0.7;
    bool available = 0;
    int direction=0;
public:
    Bullet()
    {
        bullet.loadFromFile("img/laserBlue01.png");
        fire.setTexture(bullet);
        fire.setScale(0.7, 0.6);
    }
    Bullet(int x)
    {
        bullet.loadFromFile("img/fire.png");
        fire.setTexture(bullet);
        fire.setScale(0.3, 0.19);
        speed = 0.4;
    }

    bool bulletCollion(Bullet * b,Enemy** E,Score &S,int s)
    {
        for(int i=0;i<3;i++)
              for (int j = 0; j < 15; j++)
			  {
				if (E[i][j].enemy.getPosition().x != -100)
				{
					if ((E[i][j].enemy.getPosition().x + 50 >= b->fire.getPosition().x - 5) && (E[i][j].enemy.getPosition().x - 20 <= b->fire.getPosition().x + 5)
						&& (E[i][j].enemy.getPosition().y + 15 >= b->fire.getPosition().y - 10) && (E[i][j].enemy.getPosition().y - 15 <= b->fire.getPosition().y + 10))
					{
						E[i][j].enemy.setPosition(-100,0);
                        if(i==0)
                        S.setScore(10*s);
                        if(i==1)
                        S.setScore(20*s);
                        if(i==2)
                        S.setScore(30*s);


						return 1;
					}
				}
			  }
              return 0;
    }


    void move(int x)
    {
        direction=x;
        if(direction == 1)
        fire.move(0, -1*speed);
    
        if(direction == 2)
        fire.move(0.70*speed, -1*speed);
        if(direction == 2)
        fire.move(-0.70*speed, -1*speed);
        if(direction == 3)
        fire.move(0.50, -1*speed);
        if(direction == 4)
        fire.move(-0.50, -1*speed);
        if(direction == 5)
        fire.move(0.30, -1*speed);
        if(direction == 6)
        fire.move(-0.30, -1*speed);
    
    }
~Bullet()
{

}

};
//bool Bullet::available=0;
