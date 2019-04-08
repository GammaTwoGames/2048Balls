#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "Label.h"

class Button : public Label {
public:
    Button(int _x, int _y, int _l, int _h, std::string _st, int _siz) : Label(_x, _y, _l, _h, _st, _siz) {}

    bool is_in(int px, int py) {
        bool ret = 0;
        if ((px > x) && (px < x + l) && (py > y) && (py < y + h))
            ret = 1;
        return ret;
    }
};

#endif // BUTTON_H_INCLUDED
