#ifndef HPP_SYSTEM
#define HPP_SYSTEM

#include <array>
#include <allegro5/allegro.h>
#include "vector2.hpp"
#include "color.hpp"

class Config
{
  public:
    Vector2<int> dims;
    SafeColor bgColor;
    float fps;
    Config(){};
};

class System
{
  public:
    Config conf;
    System();              // Doesn't call init, have to call it yourself after setting conf
    System(Config inConf); // Calls init
    void init();
    bool exit;
    bool redraw;
    std::array<bool, 4> mouseButtons{false};
    std::array<bool, ALLEGRO_KEY_MAX> keys{false};
    Vector2<int> mousePos;
    void runEvents();
    ~System();

  private:
    ALLEGRO_DISPLAY *disp;
    ALLEGRO_EVENT_QUEUE *evQueue;
    ALLEGRO_TIMER *fpsTimer;
};

#endif // HPP_SYSTEM