#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;


#ifndef LIVEADDON_H_
#define LIVEADDON_H_

#include "Add_ons.h"

class Live_addon : public Add_ons {
public:
	Live_addon()
	{

		texture = new Texture;
		add_on = new Sprite;
		texture->loadFromFile("img/life_addon.png");
		add_on->setTexture(*texture);
		add_on->setPosition(340, -200);
		add_on->setScale(0.7, 0.7);
	}

	void move()
	{
		if (add_on != nullptr)
		{
			add_on->move(0 * speed, 1 * speed);

		}
	}

	~Live_addon() {}
};

#endif
