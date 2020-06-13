#include "header.h"

Debris::Debris()
{

}

void Debris::createDebris() //just ideas right now... not sure how to implement it yet
{
    //create the debris balls
    int i = 0;
    for (i = 0; i < 30; i++)
    {
        sf::CircleShape debris(10.f);
        debris.setFillColor(sf::Color::White);
        debris.setPosition(150, 550);
    }
}

bool Debris::isOffScreen(sf::CircleShape debris)
{
    sf::Vector2f debris_pos = debris.getPosition();
    if (debris_pos.x < 0 || debris_pos.x > 600 - 8)
        return true;
    else
        return false;

    if (debris_pos.y < 0 || debris_pos.y > 700 - 8)
        return true;
    else
        return false;
}

bool Debris::hitPlayer(sf::CircleShape debris, sf::CircleShape player)
{
    sf::Vector2f debris_pos = debris.getPosition();
    sf::Vector2f player_pos = player.getPosition();

    if (player_pos.x == debris_pos.x && player_pos.y == debris_pos.y)
        return true;
    else
        return false;
}

Debris::~Debris()
{

}