#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

class button_zero
{
public:
    int x, y;
    int l, h;
    int siz;
    string st;
button_zero(int _x, int _y, int _l, int _h, string _st, int _siz)
{
    x = _x;
    y = _y;
    l = _l;
    h = _h;
    st = _st;
    siz = _siz;
}
};

class button_active : public button_zero
{
public:
    button_active(int _x, int _y, int _l, int _h, string _st, int _siz) : button_zero(_x, _y, _l, _h, _st, _siz)
    {}
bool is_in (int px, int py)
{
    bool ret = 0;
    if ((px>x) && (px<x+l) && (py>y) && (py<y+h))
        ret = 1;
    return ret;
}
} ;

#endif // BUTTON_H_INCLUDED
