//
// Created by Roman Malkevych on 7/20/17.
//

#ifndef RENDERCPP_KEYBOARDMOUSECONTROL_H
#define RENDERCPP_KEYBOARDMOUSECONTROL_H

#include "Window.h"
#include "Camera.h"
#include "Primitive.h"
#include <list>

class KeyboardMouseControl
{
public:
    KeyboardMouseControl();
    ~KeyboardMouseControl();
    void keyboardControl(Render &render);
};

KeyboardMouseControl::KeyboardMouseControl()
{
    return ;
}

KeyboardMouseControl::~KeyboardMouseControl()
{
    return ;
}

#endif //RENDERCPP_KEYBOARDMOUSECONTROL_H
