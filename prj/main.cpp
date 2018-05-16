#include <iostream>
#include <allegro5/allegro.h>
#include <exception>

#include "system.hpp"
#include "color.hpp"
#include "vector2.hpp"

int main(int argc, char **argv)
{
    Config gameConf;
    gameConf.dims = Vector2<int>(500, 500);
    gameConf.bgColor = SafeColor(220, 220, 220);
    gameConf.fps = 30.0;
    System *sys;
    try
    {
        sys = new System(gameConf);
    }
    catch (std::exception &err)
    {
        std::cerr << "ERROR: " << err.what() << std::endl;
        return 1;
    }
    while (true)
    {
        try
        {
            sys->runEvents();
        }
        catch (std::exception &err)
        {
            std::cerr << "Event Error: " << err.what() << std::endl;
        }
        if (sys->exit)
        {
            break;
        }
        if (sys->redraw)
        {
        };
    }
    std::cout << "Done!" << std::endl;
    delete sys;
}