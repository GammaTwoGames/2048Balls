#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include "Button.h"
#include "Label.h"


class MyDraw {
public:
    MyDraw(sf::RenderWindow *renderWindow);
    virtual void drawBalls(const std::vector<Ball> *balls);
    virtual void drawLabel(Label label, int transparency);
    virtual void drawButton(Button but, int px, int py);

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

        sf::Text text;

        text.setFont(rita);
        text.setString("" + std::to_string(ball.st));
        text.setPosition(sf::Vector2f(10 + ball.x + 0 * ball.p - text.getLocalBounds().width / 2,
                                     110 + ball.y + 0 * ball.p - 10 - text.getLocalBounds().height / 2));
        text.setFillColor(sf::Color(0, 0, 0));
        window->draw(text);
    }
}

void MyDraw::drawLabel(Label label, int transparency) {
    sf::RectangleShape rectangle(sf::Vector2f(label.l, label.h));
    rectangle.setPosition(label.x, label.y);
    rectangle.setFillColor(sf::Color(182, 92, 0));
    window->draw(rectangle);

    sf::Text text("", rita, label.siz);

    text.setFont(rita);

    text.setString(label.st);
    text.setPosition(sf::Vector2f(label.x + label.l / 2 - text.getLocalBounds().width / 2 - label.siz / 15,
                                 label.y + label.h / 2 - label.siz / 3.5 - text.getLocalBounds().height / 2));
    text.setFillColor(sf::Color(255, 255, 255, transparency));
    window->draw(text);
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

    sf::Text text("", rita, but.siz);

    text.setFont(rita);

    text.setString(but.st);
    text.setPosition(sf::Vector2f(but.x + but.l / 2 - text.getLocalBounds().width / 2 - but.siz / 15,
                                 but.y + but.h / 2 - but.siz / 3.5 - text.getLocalBounds().height / 2));
    if (but.is_in(px, py) == 0) {
        text.setFillColor(sf::Color(255, 255, 255));
    } else {
        text.setFillColor(sf::Color(182, 92, 0));
    }
    window->draw(text);
}

#endif // DRAW_H_INCLUDED
