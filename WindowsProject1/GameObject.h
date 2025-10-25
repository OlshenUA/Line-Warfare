#pragma once
#include "KVector2.h"
#include <gdiplus.h>
#include <memory>  // 추가 필요

class GameObject {
public:

    std::shared_ptr<Gdiplus::Image> image;
    KVector2 pos;

    GameObject(std::shared_ptr<Gdiplus::Image> _image = nullptr, const KVector2& _position = KVector2::zero)
        : image(_image), pos(_position) {
    }
};
