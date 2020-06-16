#ifndef HEADER_H
#define HEADER_H
#define NUM_ASTROIDS 40
#include <SFML/Graphics.hpp>
#include <iostream>
#include<string>
#include <Windows.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

struct debris_struct 
{
	int x_cor = 0;
	int y_cor = 0;
	int x_speed = 0;
	int y_speed = 0;
	sf::CircleShape obj;
};
class Debris
{
private:
	sf::RenderWindow* window;
	debris_struct d_struct[NUM_ASTROIDS];
public:
	Debris();
	Debris(sf::RenderWindow* w);
	virtual void createDebris();
	virtual void check_cord(sf::CircleShape player1, sf::CircleShape player2, int* p1Reset, int* p2Reset);
	virtual debris_struct* get_first_debris();
	bool hitPlayer(sf::CircleShape debris, sf::CircleShape player);
	~Debris();
};

#endif