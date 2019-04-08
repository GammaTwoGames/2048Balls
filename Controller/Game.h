#ifndef INC_2048BALLS_GAME_H
#define INC_2048BALLS_GAME_H

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <vector>

#include "../model/Engine.h"
#include "../View/MyDraw.h"
#include "GameScene.h"
#include "OpenningScene.h"
#include "MenuScene.h"
#include "FinishScene.h"

class Game {
public:
    Game();
    void run();

private:
    void manageScenes(double time);
    sf::RenderWindow *window;
    sf::Clock clock;

    MyDraw *draw;
    OpeningScene openingScene;
    MenuScene menuScene;
    GameScene gameScene;
    FinishScene finishScene;

    int currentScene = scn::OPENING;
    float totalTime = 0;

    const sf::Color BACKGROUND_COLOR = sf::Color(182, 92, 0);
};

Game::Game() {
    window = new sf::RenderWindow(sf::VideoMode(820, 920), "2048 - Balls", sf::Style::None);
    draw = new MyDraw(window);
}

/**
 * Call to start the main loop
 */
void Game::run() {
    while (window->isOpen()) {
        window->clear(BACKGROUND_COLOR);

        double time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        totalTime += time / 1e6;
        time = time / 1.8e5 * 0.6;
        time = (time > 0.5) ? 0.5 : time;

        manageScenes(time);
        window->display();
    }
}

/**
 * Show scenes in some order
 * @param time timestamp
 * @param totalTime time since the start of the game
 */
void Game::manageScenes(double time) {
    int newScene = scn::OPENING;
    if (currentScene == scn::OPENING) {
        newScene = openingScene.show(window, draw, totalTime);
    } else
    if (currentScene == scn::MENU) {
        newScene = menuScene.show(window, draw);
        if (newScene == scn::GAME)
            gameScene.init();
    } else
    if (currentScene == scn::GAME) {
        newScene = gameScene.show(window, draw, time);
        if (newScene == scn::FINISH)
            finishScene.setScore(gameScene.getScore());
    } else
    if (currentScene == scn::FINISH) {
        newScene = finishScene.show(window, draw, totalTime);
    }

    if (newScene != currentScene) {
        totalTime = 0;
        currentScene = newScene;
    }
}


#endif //INC_2048BALLS_GAME_H
