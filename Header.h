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

typedef struct debri_struct {
	int x_cor = 0;
	int y_cor = 0;
	int x_speed = 0;
	int y_speed = 0;
	sf::CircleShape obj;
}Debri_struct;
class Debris
{
private:
	sf::RenderWindow* window;
	Debri_struct d_struct[NUM_ASTROIDS];
public:
	void check_cord();
	Debri_struct* get_first_debri() { return d_struct; }
	Debris(sf::RenderWindow* w);
	void createDebris();
	bool isOffScreen(sf::CircleShape);
	bool hitPlayer(sf::CircleShape debris, sf::CircleShape player);
	~Debris();
};

#endif