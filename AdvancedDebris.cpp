#include "AdvancedDebris.h"

Advanced::Advanced()
{
}

Advanced::Advanced(sf::RenderWindow* w)
{
	window = w;
}

void Advanced::createDebris() //just ideas right now... not sure how to implement it yet
{
    int rand_x = 0, rand_y = 0;
    srand(time(NULL));
    //create the debris balls
    for (int i = 0; i < NUM_ADVANCED; i++)//iteratea 30 times
    {
        debris_struct new_struct;
        //randomnize where the debris starts at and the speed
        int y_cord = rand() % 700;
        int x_cord = rand() % 600;
        do
        {
            rand_x = rand() % 8 + (-3);
            rand_y = rand() % 8 + (-3);
        } while (rand_x == 0 || rand_y == 0);
        //make object
        sf::CircleShape obj(7.f);
        obj.setFillColor(sf::Color::Yellow);
        obj.setPosition(x_cord, y_cord);
        //set values in struct
        a_struct[i] = { x_cord,y_cord,rand_x ,rand_y,obj };
    }
}

debris_struct* Advanced::get_first_debris()
{
    return a_struct;
}

void Advanced::check_cord(sf::CircleShape player1, sf::CircleShape player2, int* p1Reset, int* p2Reset) 
{
    //loop to see if an astroid si out of bounds or hits a player
    for (int i = 0;i < NUM_ADVANCED;i++) {
        if (a_struct[i].x_cor < 0)
            a_struct[i].x_cor = 600;
        if (a_struct[i].x_cor > 600)
            a_struct[i].x_cor = 0;
        if (a_struct[i].y_cor < 0)
            a_struct[i].y_cor = 700;
        if (a_struct[i].y_cor > 700)
            a_struct[i].y_cor = 0;

        //sets  player var to 1 if it is hit
        if (hitPlayer(a_struct[i].obj, player1))
        {
            *p1Reset = 1;
            break;
        }
        if (hitPlayer(a_struct[i].obj, player2))
        {
            *p2Reset = 1;
            break;
        }
    }
}
