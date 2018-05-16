#ifndef HPP_COLOR
#define HPP_COLOR

#include <allegro5/allegro.h>

class SafeColor {
    public:
    float r;
    float g;
    float b;
    SafeColor(float inR, float inG, float inB): r(inR), g(inG), b(inB) {};
    SafeColor(): r(0), g(0), b(0) {};
    ALLEGRO_COLOR al_c() { return al_map_rgb(r,g,b); };
};

#endif // HPP_COLOR