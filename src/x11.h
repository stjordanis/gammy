#ifndef _WIN32
#ifndef X11_H
#define X11_H

#include <X11/Xlib.h>
#undef None //Needed to avoid build error with qurl.h
#include <cstdint>
#include <vector>

class X11
{
    Display* dsp;

    Screen* scr;
    Window root;

    int ramp_sz;
    int scr_num;
    std::vector<uint16_t> init_ramp;

    unsigned w, h;

    void fillRamp(uint16_t*& ramp, int amount, int temp);

public:
    X11();

    unsigned getWidth();
    unsigned getHeight();

    void getX11Snapshot(uint8_t* buf);
    void setXF86Brightness(int scrBr, int temp);
    void setInitialGamma(bool set_previous);

    ~X11();
};

#endif // X11_H
#endif