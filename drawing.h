#ifndef DRAWING_H_INCLUDED
#define DRAWING_H_INCLUDED

#include "button.h"

void drawing_balls(RenderWindow* window, vector<Ball>* balls)
{
    float x1, y1;
    float x2, y2;

    RectangleShape rectangle(sf::Vector2f(800, 800));
    rectangle.setPosition(10,110);
    rectangle.setFillColor(Color(255,255,230));
    rectangle.setOutlineThickness(10);
    rectangle.setOutlineColor(sf::Color(182, 92, 0));
    window->draw(rectangle);

    for (int i = 0; i < balls->size(); i ++)
        {
            //cout << (*balls)[i].lg_size() << endl;
            (*balls)[i].adj_size();
            CircleShape shape((*balls)[i].p);
            shape.setPosition(Vector2f(10 + (*balls)[i].x - (*balls)[i].p,110+(*balls)[i].y - (*balls)[i].p));
            shape.setFillColor(Color(255, 220 - 10*((*balls)[i].num - 4), ((100 - 30*((*balls)[i].num - 4))>0)?(100 - 30*((*balls)[i].num - 4)):0));
            window->draw(shape);

            Text chi;
            Font rita;

            ostringstream playerScoreString;
            playerScoreString << (*balls)[i].st;
            rita.loadFromFile("rita.ttf");
            chi.setFont(rita);
            //chi.setString("Boulat - Petooh");
            chi.setString("" + playerScoreString.str());
            chi.setPosition(Vector2f(10 + (*balls)[i].x + 0*(*balls)[i].p - chi.getLocalBounds().width/2,110 + (*balls)[i].y + 0*(*balls)[i].p - 10 - chi.getLocalBounds().height/2));
            chi.setFillColor(Color(0,0,0));
            window->draw(chi);
        }
}

void drawing_button(RenderWindow* window, button_zero but, int alfa)
{
    RectangleShape rectangle(sf::Vector2f(but.l, but.h));
    rectangle.setPosition(but.x,but.y);
    rectangle.setFillColor(Color(182, 92, 0));
    window->draw(rectangle);

    Font rita;
    Text chi("",rita,but.siz);

    rita.loadFromFile("rita.ttf");
    chi.setFont(rita);
    //chi.setStyle(sf::Text::Bold | sf::Text::Regular);

    chi.setString(but.st);
    chi.setPosition(Vector2f(but.x + but.l/2 - chi.getLocalBounds().width/2 - but.siz/15, but.y + but.h/2 - but.siz/3.5 - chi.getLocalBounds().height/2));
    chi.setFillColor(Color(255,255,255,alfa));
    window->draw(chi);
}

void drawing_button(RenderWindow* window, button_active but, int px, int py)
{
    RectangleShape rectangle(sf::Vector2f(but.l, but.h));
    rectangle.setPosition(but.x,but.y);
    if (but.is_in(px,py) == 0)
    {
        rectangle.setFillColor(Color(182, 92, 0));
    }
    else
    {
        rectangle.setFillColor(Color(255, 255, 255));
    }
    window->draw(rectangle);

    Font rita;
    Text chi("",rita,but.siz);

    rita.loadFromFile("rita.ttf");
    chi.setFont(rita);
    //chi.setStyle(sf::Text::Bold | sf::Text::Regular);

    chi.setString(but.st);
    chi.setPosition(Vector2f(but.x + but.l/2 - chi.getLocalBounds().width/2 - but.siz/15, but.y + but.h/2 - but.siz/3.5 - chi.getLocalBounds().height/2));
    if (but.is_in(px,py) == 0)
    {
        chi.setFillColor(Color(255,255,255));
    }
    else
    {
        chi.setFillColor(Color(182, 92, 0));
    }
    window->draw(chi);
}

#endif // DRAWING_H_INCLUDED
