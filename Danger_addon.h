
#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;

#ifndef DANGERADDON_H_
#define DANGERADDON_H_

#include "Add_ons.h"
#include "Score.h"

class Danger_addon : public Add_ons {
public:
	Danger_addon()
	{

		texture = new Texture;
		add_on = new Sprite;
		texture->loadFromFile("img/Danger_addon.png");
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
	void Score_inc(Score * S)
    {
        S->setScore(5);
    }
	~Danger_addon() {}
};

#endif
