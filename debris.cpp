#include "header.h"
Debris::Debris()
{
    window->getDefaultView();
    this->d_struct[NUM_ASTROIDS] = { 0 };
}

Debris::Debris(sf::RenderWindow* w)
{
    window = w;//inits the window in the class
}

debris_struct* Debris::get_first_debris()
{
    return d_struct;
}

void Debris::createDebris() //just ideas right now... not sure how to implement it yet
{
    int rand_x = 0, rand_y = 0;
    srand(time(NULL));
    //create the debris balls
    for (int i = 0; i < NUM_ASTROIDS; i++)//iteratea 30 times
    {
        debris_struct new_struct;
        //randomnize where the debris starts at and the speed
        int y_cord = rand() % 700;
        int x_cord = rand() % 600;
        do
        {
            rand_x = rand() % 6 + (-3);
            rand_y = rand() % 6 + (-3);
        } while (rand_x == 0 || rand_y == 0);

        //make object
        sf::CircleShape obj(5.f);
        obj.setFillColor(sf::Color::Green);
        obj.setPosition(x_cord, y_cord);
        //set values in struct
        d_struct[i] = { x_cord,y_cord,rand_x ,rand_y,obj };
    }
}

bool Debris::hitPlayer(sf::CircleShape debris, sf::CircleShape player)
{
    sf::Vector2f debris_pos = debris.getPosition();
    sf::Vector2f player_pos = player.getPosition();

    if ((player_pos.x >= debris_pos.x - 10 && player_pos.x <= debris_pos.x + 10) && (player_pos.y >= debris_pos.y - 10 && player_pos.y <= debris_pos.y + 10)) 
    {
        player.setPosition(150, 550);
        return true;
    }
    else
        return false;
}

void Debris::check_cord(sf::CircleShape player1, sf::CircleShape player2, int* p1Reset, int* p2Reset) {

    //loop to see if an astroid si out of bounds or hits a player
    for (int i = 0;i < NUM_ASTROIDS;i++) {
        if (d_struct[i].x_cor < 0)
            d_struct[i].x_cor = 600;
        if (d_struct[i].x_cor > 600)
            d_struct[i].x_cor = 0;
        if (d_struct[i].y_cor < 0)
            d_struct[i].y_cor = 700;
        if (d_struct[i].y_cor > 700)
            d_struct[i].y_cor = 0;

        //sets  player var to 1 if it is hit
        if (hitPlayer(d_struct[i].obj, player1)) 
        {
            *p1Reset = 1;
            break;
        }
        if (hitPlayer(d_struct[i].obj, player2)) 
        {
            *p2Reset = 1;
            break;
        }
    }
}

Debris::~Debris()
{
    window->close();
}
