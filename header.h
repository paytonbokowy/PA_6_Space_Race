#ifndef HEADER_H
#define HEADER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include<string>
#include <Windows.h>

class Debris
{
private:
	
public:
	Debris();
	void createDebris();
	bool isOffScreen(sf::CircleShape);
	bool hitPlayer(sf::CircleShape debris, sf::CircleShape player);
	~Debris();
};

#endif