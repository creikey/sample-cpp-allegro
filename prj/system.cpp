#include "system.hpp"
#include "error.hpp"

void System::init()
{
    if (!al_init())
    {
        INITERROR("al_init");
    }
    if (!al_install_keyboard())
    {
        INITERROR("al_install_keyboard");
    }
    if (!al_install_mouse())
    {
        INITERROR("al_install_mouse");
    }
    disp = al_create_display(conf.dims.x, conf.dims.y);
    if (!disp)
    {
        INITERROR("al_create_display", conf.dims.toString());
    }
    evQueue = al_create_event_queue();
    if (!evQueue)
    {
        INITERROR("al_create_event_queue");
    }
    fpsTimer = al_create_timer(1.0 / conf.fps);
    if (!fpsTimer)
    {
        INITERROR("al_create_timer", std::to_string(1.0 / conf.fps));
    }
    al_register_event_source(evQueue, al_get_display_event_source(disp));
    al_register_event_source(evQueue, al_get_timer_event_source(fpsTimer));
    al_register_event_source(evQueue, al_get_keyboard_event_source());
    al_register_event_source(evQueue, al_get_mouse_event_source());
    al_start_timer(fpsTimer);
    al_clear_to_color(conf.bgColor.al_c());
    al_flip_display();
    redraw = false;
    exit = false;
}

void System::runEvents()
{
    ALLEGRO_EVENT ev;
    al_wait_for_event(evQueue, &ev);
    do
    {
        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            exit = true;
            return;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            keys[ev.keyboard.keycode] = true;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            keys[ev.keyboard.keycode] = false;
        }
        else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            mousePos.x = ev.mouse.x;
            mousePos.y = ev.mouse.y;
        }
        else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            ev.mouse.button -= 1;
            if (ev.mouse.button > mouseButtons.size())
            {
                throw(MouseButtonError(ev.mouse.button, mouseButtons.size()));
            }
            else
            {
                mouseButtons[ev.mouse.button] = true;
            }
        }
        else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        {
            ev.mouse.button -= 1;
            if (ev.mouse.button > mouseButtons.size())
            {
                throw(MouseButtonError(ev.mouse.button, mouseButtons.size()));
            }
            else
            {
                mouseButtons[ev.mouse.button] = false;
            }
        }
        else if (ev.type == ALLEGRO_EVENT_TIMER)
        {
            if (ev.timer.source == fpsTimer)
            {
                redraw = true;
            }
        }
    } while (al_get_next_event(evQueue, &ev));
}

System::System(Config inConf) : conf(inConf)
{
    init();
}
System::System(){};
System::~System()
{
    al_destroy_display(disp);
    al_destroy_timer(fpsTimer);
    al_destroy_event_queue(evQueue);
}