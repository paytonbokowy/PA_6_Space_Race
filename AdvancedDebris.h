#include "header.h"
#define NUM_ADVANCED 10

class Advanced : public Debris
{
private:
	debris_struct a_struct[NUM_ADVANCED];
	sf::RenderWindow* window;
public:
	Advanced();
	Advanced(sf::RenderWindow* w);
	virtual void createDebris();
	virtual debris_struct* get_first_debris();
	virtual void check_cord(sf::CircleShape player1, sf::CircleShape player2, int* p1Reset, int* p2Reset);
	~Advanced();
};