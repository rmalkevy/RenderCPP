//
// Created by Roman Malkevych on 7/20/17.
//

#include "includes/KeyboardMouseControl.h"
#include "includes/RenderFunctions.h"

KeyboardMouseControl::KeyboardMouseControl( Render &render)
{
    this->render = &render;
    return ;
}

KeyboardMouseControl::~KeyboardMouseControl()
{
    return ;
}

int		my_key_funct(int keycode, void *mod)
{
    Render *render = (Render*)mod;
    mlx_destroy_image(render->window->getMlx(), render->window->getImage());
    if (keycode == 53)
    {
        mlx_destroy_window(render->window->getMlx(), render->window->getWin());
        exit(0);
    }
//    addition_funct(keycode, mod);
    tracingScreen(*render->window, *render->camera, *render->listObjects);
    return (0);
}


void KeyboardMouseControl::keyboardControl()
{
    //TODO зробити клас, який буде включати в себе Window, Camera, List

    mlx_hook(render->window->getWin(), 2, 5, (int (*)())my_key_funct, (void*)(this->render));
    return ;
}