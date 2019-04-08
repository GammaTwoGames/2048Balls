#ifndef INC_2048BALLS_FINISHSCENE_H
#define INC_2048BALLS_FINISHSCENE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "scn.h"
#include "../View/MyDraw.h"

class FinishScene {
public:
    FinishScene();
    int show(sf::RenderWindow *window, MyDraw *draw, double totalTime);
    void setScore(int score);
private:
    int score;
    Label label;
};

FinishScene::FinishScene() : label(410 - 10, 460 - 10, 20, 20, "", 50) {}

/**
 * Call on every step to show
 * @param window sf::RenderWindow
 * @param draw implementation of MyDraw
 * @return the id of the next scene to show
 */
int FinishScene::show(sf::RenderWindow *window, MyDraw *draw, double totalTime) {
    label.st = "You fail! \nYour score is " + std::to_string(score) + "!!!";
    draw->drawLabel(label, (int) (50.0 * totalTime));
    window->setMouseCursorVisible(false);
    if (totalTime > 5) {
        window->setMouseCursorVisible(true);
        return scn::MENU;
    }
    return scn::FINISH;
}

void FinishScene::setScore(int score) {
    this->score = score;
}

#endif //INC_2048BALLS_FINISHSCENE_H
