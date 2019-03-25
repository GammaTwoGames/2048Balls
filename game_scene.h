#ifndef GAME_SCENE_H_INCLUDED
#define GAME_SCENE_H_INCLUDED

#include "change_scene.h"

using namespace sf;
using namespace std;

vector<Ball> balls;
float G = -10;
float GG = -10;
bool push_ball = 0;

void game_start()
{
    set_lose();
    create_first_balls(&balls);
    push_ball = 0;
}


void still_game(RenderWindow* window, float time)
{
    if (get_lose() == 0)
        {
            app_phys(&balls,GG,G,time);
            analise_map(&balls);
            if (push_ball == 1)
            {
                smart_push_ball(&balls);
                push_ball = 0;
            }
        }
    ostringstream playerScoreString;
    playerScoreString << (score(&balls) - 62);
    drawing_balls(window, &balls);
    drawing_button(window, button_zero(10,10,220,90,"2048", 92),255);
    drawing_button(window, button_zero(330,10,220,45,"Score:", 50),255);
    drawing_button(window, button_zero(550,10,220,45,playerScoreString.str(), 50),255);
    if (get_lose() == 0)
    {
        //drawing_button(window, button_zero(385,60,220,45,"doing swell", 50),255);
        Vector2i pixelPos = Mouse::getPosition(*window);
        Vector2f pos = window->mapPixelToCoords(pixelPos);
        drawing_button(window, button_active(385,60,220,45,"doing swell", 50),255);
    }
    else
    {
        drawing_button(window, button_zero(385,60,220,45,"ooh, fail!", 50),255);
    }


    sf::Event event;
    while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window->close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    //window->close();
                    change_scene(2);
                }
                if (event.key.code == sf::Keyboard::W)
                {
                    G = -10;
                    GG = 0;
                    push_ball = 1;
                }
                if (event.key.code == sf::Keyboard::S)
                {
                    G = 10;
                    GG = 0;
                    push_ball = 1;
                }
                if (event.key.code == sf::Keyboard::D)
                {
                    G = 0;
                    GG = 10;
                    push_ball = 1;
                }
                if (event.key.code == sf::Keyboard::A)
                {
                    G = 0;
                    GG = -10;
                    push_ball = 1;
                }

            }
            if (event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
                if (event.key.code == Mouse::Left)//а именно левая
                {
                    //game_start();
                    //change_scene(0);
                }
        }
        window->setMouseCursorVisible(1);
}

#endif // GAME_SCENE_H_INCLUDED
