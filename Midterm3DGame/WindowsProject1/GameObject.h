#pragma once
#include "KVector2.h"
#include <gdiplus.h>

class GameObject {
public:

    Image* image;
    KVector2 pos;

    GameObject(Gdiplus::Image* _image = nullptr, const KVector2& _position = KVector2::zero)
    {
        image = _image;
        pos = _position;
    }
};