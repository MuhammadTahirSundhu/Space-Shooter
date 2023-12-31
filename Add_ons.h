#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;

#ifndef ADDONS_H_
#define ADDONS_H_

class Add_ons {
public:
	Texture* texture;
	Sprite* add_on;
	float speed = 0.05;
	Add_ons()
	{
		texture = nullptr;
		add_on = nullptr;
	}
	virtual void move() = 0;

	virtual ~Add_ons() {}
};

#endif
