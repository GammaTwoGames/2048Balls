#ifndef INC_2048BALLS_MYRANDOM_H
#define INC_2048BALLS_MYRANDOM_H

#include <random>
#include <ctime>

class MyRandom {
public:
    float rRandom(float left, float right) {
        std::uniform_real_distribution<float> urd(left, right);
        return urd(rd);
    }

    int iRandom(int left, int right) {
        std::uniform_int_distribution<int> urd(left, right);
        return urd(rd);
    }
private:
    std::random_device rd;
};

#endif //INC_2048BALLS_MYRANDOM_H
