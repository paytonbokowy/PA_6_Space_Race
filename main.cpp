#include "header.h"

int main(int argc, char const* argv[])
{
    int score1 = 0, score2 = 0;
    float dx = 0.0, dy = 0.0, speed = 5;
    bool first_time = true, end = false;
    //Create Window
    sf::RenderWindow window(sf::VideoMode(600, 700), "Space Race SFML C++");
    window.setFramerateLimit(30);

    //Create Font (display score)
    sf::Font font;
    font.loadFromFile("Tuffy.ttf");

    //Create title
    sf::Text Title("", font);
    Title.setFont(font);
    Title.setString("*** Space Race ***");
    Title.setCharacterSize(30);
    Title.setFillColor(sf::Color::White);
    Title.setPosition(175, 50);
    //Create Rules
    sf::Text Rules("", font);
    Rules.setFont(font);
    Rules.setString("\t2 players will race through the asteroids\nWhoever gets through safely the most times\n\t\t\tbefore the timer runs out wins!");
    Rules.setCharacterSize(30);
    Rules.setFillColor(sf::Color::White);
    Rules.setPosition(10, 100);

    //sets player 1 score
    sf::Text text1("", font);
    text1.setFont(font);
    text1.setString(std::to_string(score1));
    text1.setCharacterSize(30);
    text1.setFillColor(sf::Color::Blue);
    text1.setPosition(150, 600);

    //set player 2 score
    sf::Text text2("", font);
    text2.setFont(font);
    text2.setString(std::to_string(score2));
    text2.setCharacterSize(30);
    text2.setFillColor(sf::Color::Red);
    text2.setPosition(452, 600);

    //Create a circle to represent player 1
    sf::CircleShape player1(10.f);
    player1.setFillColor(sf::Color::Blue);
    player1.setPosition(150, 550);

    //Create a circle to represent player 2
    sf::CircleShape player2(10.f);
    player2.setFillColor(sf::Color::Red);
    player2.setPosition(450, 550);

    //creates the line to divide the screen
    sf::RectangleShape divider(sf::Vector2f(5, 800));
    divider.setFillColor(sf::Color::White);
    divider.setPosition(300, 0);
    //Sets a clock
    sf::Clock clock;
    int countdown = 30; //sets countdown to 30
    //sets the text for the timer
    sf::Text timerText;
    timerText.setFont(font);
    timerText.setString(std::to_string(countdown));
    timerText.setPosition(550, 0);
    timerText.setCharacterSize(30);
    //Creates the winner
    sf::Text Winner("", font);
    Winner.setFont(font);
    Winner.setString("");
    Winner.setCharacterSize(40);
    Winner.setFillColor(sf::Color::White);
    Winner.setPosition(200, 100);
    //While the window is open...
    while (window.isOpen())
    {
        //Get ball and Player coordinates
        sf::Vector2f player1_pos = player1.getPosition();
        sf::Vector2f player2_pos = player2.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            player1.move(0, -5); //moves player 1 up to the top
            if (player1_pos.y == 0) //if player 1 hits the top of the screen
            {
                player1.setPosition(150, 550); //resets player 1
                score1++; //score increases
                text1.setString(std::to_string(score1)); //changes the score on the screen
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player1.move(0, 5); //moves player 1 down the screen
            if (player1_pos.y > 550) //if player 1 hits the bottom of the screen
            {
                player1.setPosition(150, 550); //resets player 1
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::I))
        {
            player2.move(0, -5); //moves player 2 up the screen
            if (player2_pos.y == 0) //if player 2 hits the top of the screen
            {
                player2.setPosition(450, 550); //resets player 2
                score2++; //increases score
                text2.setString(std::to_string(score2)); //updates player 2 score to the screen
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        {
            player2.move(0, 5); //moves player 2 down the screen
            if (player2_pos.y > 550) //if player 2 hits the bottom of the screen
            {
                player2.setPosition(450, 550); //resets player 2
            }
        }

        int timer = clock.getElapsedTime().asSeconds(); //get the time in seconds

        if (countdown == 0)
        {
            timerText.setString("End");
            Sleep(3000);
            if (score1 > score2) //player 1 wins
            {
                Winner.setString("Player 1 wins!");
            }
            else if (score2 > score1) //player 2 wins
            {
                Winner.setString("Player 2 wins!");
            }
            else //tie
            {
                Winner.setString("It was a tie!");
            }
            end = true;
        }
        else if (countdown < 0) //just in case timer keeps running
        {
            timerText.setString("End");
        }

        if (timer > 0)
        {
            countdown--; //decrease the coutdown
            timerText.setString(std::to_string(countdown)); //update the timer on the screen
            clock.restart(); //returns the time that has elapsed
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }

        if (first_time == true)
        {
            window.clear();
            window.draw(Title);
            window.draw(Rules); //display rules and title for the first time
            window.display();
            Sleep(5000);
            first_time = false;
        }
        //renders all the objects to the screen
        window.clear();
        window.draw(player1);
        window.draw(player2);
        window.draw(divider);
        window.draw(text1);
        window.draw(text2);
        window.draw(timerText);
        window.display();
        
        if (end == true) //displays the winner if it is the end of the game
        {
            window.clear();
            window.draw(Winner);
            window.display();
            Sleep(10000);
            window.close();
        }
    } 

    return 0;
}