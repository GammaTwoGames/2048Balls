#ifndef INC_2048BALLS_VEC2D_H
#define INC_2048BALLS_VEC2D_H

template <class T>
class Vec2d {
public:
    T x, y;

    Vec2d(T x, T y) {
        this->x = x;
        this->y = y;
    }
};

#endif //INC_2048BALLS_VEC2D_H
