//
// Created by Roman Malkevych on 7/20/17.
//

#ifndef RENDERCPP_KEYBOARDMOUSECONTROL_H
#define RENDERCPP_KEYBOARDMOUSECONTROL_H

#include "Window.h"
#include "Camera.h"
#include "Render.h"

class KeyboardMouseControl
{
public:
    KeyboardMouseControl( Render &render);
    ~KeyboardMouseControl();
    void keyboardControl();

private:
    Render *render;
};

#endif //RENDERCPP_KEYBOARDMOUSECONTROL_H
