#ifndef BOMB_H
#define BOMB_H


#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;

class Bomb {
public:
	Texture tx;
	Sprite bomb;
	float bomb_speed = 0.6;
	
	Bomb()//for alpha bomb
	{
		tx.loadFromFile("img/B2.png");
		bomb.setTexture(tx);
		bomb.setScale(0.1, 0.1);
		bomb.setPosition(-200, -200);
		bomb.setOrigin(0.1/2,0.1/2);
	}
	
	Bomb(string s)
	{
		tx.loadFromFile(s);
		bomb.setTexture(tx);
		bomb.setScale(0.5, 3.5);
		bomb.setPosition(-200, -200);
		bomb.setOrigin(0.5/2,3.5/2);
	}

	void setSprite(string s)
	{
		tx.loadFromFile(s);
		bomb.setTexture(tx);
		bomb.setScale(0.15, 0.15);
		bomb.setPosition(-200, -200);
		bomb.setOrigin(0.2/2,0.2/2);
	}
	void b_move()
	{
		bomb.move(0,-1*bomb_speed);
	}

	~Bomb(){}
};


#endif 

