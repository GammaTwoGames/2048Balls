#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include "Button.h"
#include "Label.h"


class MyDraw {
public:
    MyDraw(sf::RenderWindow *renderWindow);
    void drawBalls(const std::vector<Ball> *balls);
    void drawButton(Label but, int alfa);
    void drawButton(Button but, int px, int py);

private:
    sf::RenderWindow *window;
    sf::Font rita;
};

MyDraw::MyDraw(sf::RenderWindow *renderWindow) {
    window = renderWindow;
    if (!rita.loadFromFile("rita.ttf")) {
        std::cerr << "Error: failed to load font" << std::endl;
    }
}

void MyDraw::drawBalls(const std::vector<Ball> *balls) {
    sf::RectangleShape rectangle(sf::Vector2f(800, 800));
    rectangle.setPosition(10, 110);
    rectangle.setFillColor(sf::Color(255, 255, 230));
    rectangle.setOutlineThickness(10);
    rectangle.setOutlineColor(sf::Color(182, 92, 0));
    window->draw(rectangle);

    for (auto &ball : *balls) {
        sf::CircleShape shape(ball.p);
        shape.setPosition(sf::Vector2f(10 + ball.x - ball.p, 110 + ball.y - ball.p));
        shape.setFillColor(sf::Color(255, 220 - 10 * (ball.num - 4),
                                     ((100 - 30 * (ball.num - 4)) > 0) ? (100 - 30 * (ball.num - 4)) : 0));
        window->draw(shape);

        sf::Text chi;

        std::ostringstream playerScoreString;
        playerScoreString << ball.st;
        rita.loadFromFile("rita.ttf");
        chi.setFont(rita);
        //chi.setString("Boulat - Petooh");
        chi.setString("" + playerScoreString.str());
        chi.setPosition(sf::Vector2f(10 + ball.x + 0 * ball.p - chi.getLocalBounds().width / 2,
                                     110 + ball.y + 0 * ball.p - 10 - chi.getLocalBounds().height / 2));
        chi.setFillColor(sf::Color(0, 0, 0));
        window->draw(chi);
    }
}

void MyDraw::drawButton(Label but, int alfa) {
    sf::RectangleShape rectangle(sf::Vector2f(but.l, but.h));
    rectangle.setPosition(but.x, but.y);
    rectangle.setFillColor(sf::Color(182, 92, 0));
    window->draw(rectangle);

    sf::Text chi("", rita, but.siz);

    chi.setFont(rita);
    //chi.setStyle(sf::Text::Bold | sf::Text::Regular);

    chi.setString(but.st);
    chi.setPosition(sf::Vector2f(but.x + but.l / 2 - chi.getLocalBounds().width / 2 - but.siz / 15,
                                 but.y + but.h / 2 - but.siz / 3.5 - chi.getLocalBounds().height / 2));
    chi.setFillColor(sf::Color(255, 255, 255, alfa));
    window->draw(chi);
}

void MyDraw::drawButton(Button but, int px, int py) {
    sf::RectangleShape rectangle(sf::Vector2f(but.l, but.h));
    rectangle.setPosition(but.x, but.y);
    if (but.is_in(px, py) == 0) {
        rectangle.setFillColor(sf::Color(182, 92, 0));
    } else {
        rectangle.setFillColor(sf::Color(255, 255, 255));
    }
    window->draw(rectangle);

    sf::Text chi("", rita, but.siz);

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

#endif // DRAW_H_INCLUDED
