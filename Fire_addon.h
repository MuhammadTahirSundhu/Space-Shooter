#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;

#ifndef FIREADDON_H_
#define FIREADDON_H_

#include "Add_ons.h"

class Fire_addon : public Add_ons {
public:
	Fire_addon()
	{
		texture = new Texture;
		add_on = new Sprite;
		texture->loadFromFile("img/fire_addon.png");
		add_on->setTexture(*texture);
		add_on->setPosition(540, -200);
		add_on->setScale(0.9, 0.9);
	}
	void move()
	{
		if (add_on != nullptr)
		{
			add_on->move(0 * speed, 1 * speed);
			
		}
	}
	~Fire_addon() {}
};

#endif
