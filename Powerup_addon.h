#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;


#ifndef POWERUP_H_
#define POWERUP_H_

#include "Add_ons.h"

class Powerup : public Add_ons {
public:
	Powerup()
	{

		texture = new Texture;
		add_on = new Sprite;
		texture->loadFromFile("img/bolt_bronze.png");
		add_on->setTexture(*texture);
		add_on->setPosition(240, -200);
		add_on->setScale(0.7, 0.7);
	}

	void move()
	{
		if (add_on != nullptr)
		{
			add_on->move(0 * speed, 1 * speed);
			
		}
	}
	~Powerup() {}
};

#endif
