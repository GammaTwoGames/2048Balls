#ifndef INC_2048BALLS_LABEL_H
#define INC_2048BALLS_LABEL_H

#include <string>

class Label {
public:
    int x, y;
    int l, h;
    int siz;
    std::string st;

    Label(int _x, int _y, int _l, int _h, std::string _st, int _siz) {
        x = _x;
        y = _y;
        l = _l;
        h = _h;
        st = _st;
        siz = _siz;
    }
};

#endif //INC_2048BALLS_LABEL_H
