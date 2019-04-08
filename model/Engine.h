#ifndef EGINE_H_INCLUDED
#define EGINE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>

#include "Ball.h"
#include "Vec2d.h"
#include "MyRandom.h"

class Engine {
public:
    Engine();
    void step(double time);
    void analiseMap();
    void smartPushBall();
    void initMap();
    bool getLose();
    void setLose(bool lose);
    void setGravity(Vec2d<double> g);
    int score();
    const std::vector<Ball> *getBalls();
private:
    MyRandom random;
    std::vector<Ball> balls;
    Vec2d<double> gravity;
    bool lose = false;
    const int ITERATIONS = 3;
    const double K = 5e3;
};

Engine::Engine() : gravity(0, 10) {}

void Engine::step(double time) {
    double s1, s2;
    for (int k = 0; k < ITERATIONS; k++) {
        for (auto &ball : balls) {
            ball.app(time);
            ball.low2(time, gravity.x - (ball.ux) / ITERATIONS, gravity.y - (ball.uy) / ITERATIONS);
        }
        for (int i = 0; i < balls.size(); i++)
            for (int j = 0; j < balls.size(); j++) {
                if (i != j) {
                    s1 = ((balls[i].x - balls[j].x) * (balls[i].x - balls[j].x) +
                          (balls[i].y - balls[j].y) * (balls[i].y - balls[j].y));
                    s2 = (balls[i].p + balls[j].p) * (balls[i].p + balls[j].p);
                    if (s1 < s2) {
                        balls[i].low2(time, (s2 - s1) * (balls[i].x - balls[j].x) / K,
                                         (s2 - s1) * (balls[i].y - balls[j].y) / K);
                    }
                }
            }
    }
}

void Engine::analiseMap() {
    double s1, s2;
    double xnew = 0.0, ynew = 0.0, ne = 0.0;
    int stnew = 0;

    for (int i = 0; i < balls.size(); i++)
        for (int j = 0; j < balls.size(); j++) {
            if (i != j) {
                s1 = (balls[i].x - balls[j].x) * (balls[i].x - balls[j].x) +
                      (balls[i].y - balls[j].y) * (balls[i].y - balls[j].y);
                s2 = (balls[i].p + balls[j].p) * (balls[i].p + balls[j].p);
                if ((s1 < s2) && (balls[i].st == balls[j].st)) {
                    balls[i].del = true;
                    balls[j].del = true;
                    xnew = (balls[i].x + balls[j].x) / 2;
                    ynew = (balls[i].y + balls[j].y) / 2;
                    stnew = balls[i].num + 1;
                    ne = 1;
                }
            }
        }

    for (unsigned long i = 0; i < balls.size(); i++) {
        if (balls[i].del == 1) {
            balls.erase(balls.begin() + i);
            i = balls.size() + 1;
        }
    }

    for (unsigned long i = 0; i < balls.size(); i++) {
        if (balls[i].del == 1) {
            balls.erase(balls.begin() + i);
            i = balls.size() + 1;
        }
    }

    if (ne == 1) {
        balls.emplace_back(xnew, ynew, stnew);
    }
}

void Engine::smartPushBall() {
    int ran;
    int n1, d1, n2, d2;
    n1 = 73;
    d1 = 10;
    n2 = 73;
    d2 = 10;

    std::vector<Vec2d<int>> vects;

    double s1, s2;
    int xp = 0;
    for (int i = n1; i < 800 - n1; i += d1)
        for (int j = n2; j < 800 - n2; j += d2) {
            xp = 0;
            for (auto &ball : balls) {
                s1 = (ball.x - i) * (ball.x - i) + (ball.y - j) * (ball.y - j);
                s2 = (ball.p + 70) * (ball.p + 70);
                if (s2 > s1)
                    xp = - 1;
            }
            if (xp == 0) {
                vects.emplace_back(i, j);
            }
        }
    if (!vects.empty()) {
        ran = random.iRandom(0, static_cast<int>(vects.size()));
        balls.emplace_back(vects[ran].x, vects[ran].y, random.iRandom(1, 2));
    } else {
        lose = true;
    }
}

void Engine::initMap() {
    balls.clear();
    for (int i = 1; i < 6; i++) {
        smartPushBall();
    }
}

bool Engine::getLose() {
    return lose;
}

void Engine::setLose(bool lose) {
    this->lose = lose;
}

int Engine::score() {
    int ret = 0;
    for (auto &i : balls) {
        ret += i.st;
    }
    return ret;
}

void Engine::setGravity(Vec2d<double> g) {
    this->gravity = g;
}

const std::vector<Ball> *Engine::getBalls() {
    return &balls;
}


#endif // EGINE_H_INCLUDED
