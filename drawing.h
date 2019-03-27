#ifndef DRAWING_H_INCLUDED
#define DRAWING_H_INCLUDED

#include "button.h"


void drawing_balls(sf::RenderWindow *window, std::vector<Ball> *balls) {
    float x1, y1;
    float x2, y2;

    sf::RectangleShape rectangle(sf::Vector2f(800, 800));
    rectangle.setPosition(10, 110);
    rectangle.setFillColor(sf::Color(255, 255, 230));
    rectangle.setOutlineThickness(10);
    rectangle.setOutlineColor(sf::Color(182, 92, 0));
    window->draw(rectangle);

    for (int i = 0; i < balls->size(); i++) {
        sf::CircleShape shape((*balls)[i].p);
        shape.setPosition(sf::Vector2f(10 + (*balls)[i].x - (*balls)[i].p, 110 + (*balls)[i].y - (*balls)[i].p));
        shape.setFillColor(sf::Color(255, 220 - 10 * ((*balls)[i].num - 4),
                                     ((100 - 30 * ((*balls)[i].num - 4)) > 0) ? (100 - 30 * ((*balls)[i].num - 4)) : 0));
        window->draw(shape);

        sf::Text chi;
        sf::Font rita;

        std::ostringstream playerScoreString;
        playerScoreString << (*balls)[i].st;
        rita.loadFromFile("rita.ttf");
        chi.setFont(rita);
        //chi.setString("Boulat - Petooh");
        chi.setString("" + playerScoreString.str());
        chi.setPosition(sf::Vector2f(10 + (*balls)[i].x + 0 * (*balls)[i].p - chi.getLocalBounds().width / 2,
                                     110 + (*balls)[i].y + 0 * (*balls)[i].p - 10 - chi.getLocalBounds().height / 2));
        chi.setFillColor(sf::Color(0, 0, 0));
        window->draw(chi);
    }
}

void drawing_button(sf::RenderWindow *window, button_zero but, int alfa) {
    sf::RectangleShape rectangle(sf::Vector2f(but.l, but.h));
    rectangle.setPosition(but.x, but.y);
    rectangle.setFillColor(sf::Color(182, 92, 0));
    window->draw(rectangle);

    sf::Font rita;
    sf::Text chi("", rita, but.siz);

    rita.loadFromFile("rita.ttf");
    chi.setFont(rita);
    //chi.setStyle(sf::Text::Bold | sf::Text::Regular);

    chi.setString(but.st);
    chi.setPosition(sf::Vector2f(but.x + but.l / 2 - chi.getLocalBounds().width / 2 - but.siz / 15,
                                 but.y + but.h / 2 - but.siz / 3.5 - chi.getLocalBounds().height / 2));
    chi.setFillColor(sf::Color(255, 255, 255, alfa));
    window->draw(chi);
}

void drawing_button(sf::RenderWindow *window, button_active but, int px, int py) {
    sf::RectangleShape rectangle(sf::Vector2f(but.l, but.h));
    rectangle.setPosition(but.x, but.y);
    if (but.is_in(px, py) == 0) {
        rectangle.setFillColor(sf::Color(182, 92, 0));
    } else {
        rectangle.setFillColor(sf::Color(255, 255, 255));
    }
    window->draw(rectangle);

    sf::Font rita;
    sf::Text chi("", rita, but.siz);

    rita.loadFromFile("rita.ttf");
    chi.setFont(rita);
    //chi.setStyle(sf::Text::Bold | sf::Text::Regular);

    chi.setString(but.st);
    chi.setPosition(sf::Vector2f(but.x + but.l / 2 - chi.getLocalBounds().width / 2 - but.siz / 15,
                                 but.y + but.h / 2 - but.siz / 3.5 - chi.getLocalBounds().height / 2));
    if (but.is_in(px, py) == 0) {
        chi.setFillColor(sf::Color(255, 255, 255));
    } else {
        chi.setFillColor(sf::Color(182, 92, 0));
    }
    window->draw(chi);
}

#endif // DRAWING_H_INCLUDED
