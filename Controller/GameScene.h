#ifndef GAME_SCENE_H_INCLUDED
#define GAME_SCENE_H_INCLUDED


#include "scn.h"

class GameScene {
public:
    GameScene();
    int show(sf::RenderWindow *window, MyDraw *draw, double time);
    int init();
    int getScore();
private:
    Engine engine;
    bool push_ball = false;

    Label titleLabel;
    Label swellLabel;
};

GameScene::GameScene() : titleLabel(Label(10, 10, 220, 90, "2048", 92)),
                         swellLabel(Label(350, 60, 220, 45, "doing swell", 50)) {}

int GameScene::init() {
    engine.setLose(false);
    engine.initMap();
    push_ball = false;
}

/**
 * Call on every step to show
 * @param window sf::RenderWindow
 * @param draw implementation of MyDraw
 * @return the id of the next scene to show
 */

int GameScene::show(sf::RenderWindow *window, MyDraw *draw, double time) {
    if (!engine.getLose()) {
        engine.step(time);
        engine.analiseMap();
        if (push_ball) {
            engine.smartPushBall();
            push_ball = false;
        }
    }
    std::ostringstream playerScoreString;
    playerScoreString << (engine.score() - 62);
    draw->drawBalls(engine.getBalls());
    draw->drawLabel(titleLabel, 255);
    draw->drawLabel(Label(330, 10, 220, 45, "Score: " + playerScoreString.str(), 50), 255);

    if (engine.getLose() == 0) {
        draw->drawLabel(swellLabel, 255);
    } else {
        return scn::FINISH;
    }


    sf::Event event {};
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) window->close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                return scn::MENU;
            }
            if (event.key.code == sf::Keyboard::W) {
                engine.setGravity(Vec2d<double>(0, -10));
                push_ball = true;
            }
            if (event.key.code == sf::Keyboard::S) {
                engine.setGravity(Vec2d<double>(0, 10));
                push_ball = true;
            }
            if (event.key.code == sf::Keyboard::D) {
                engine.setGravity(Vec2d<double>(10, 0));
                push_ball = true;
            }
            if (event.key.code == sf::Keyboard::A) {
                engine.setGravity(Vec2d<double>(-10, 0));
                push_ball = true;
            }

        }
    }
    return scn::GAME;
}

int GameScene::getScore() {
    return engine.score() - 62; // ?????????????????????????????????????????
}

#endif // GAME_SCENE_H_INCLUDED
