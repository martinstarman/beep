#include <SDL3/SDL.h>

#include "rect.h"

Rect::Rect(float x, float y, float w, float h) : mX(x),
                                                 mY(y),
                                                 mW(w),
                                                 mH(h)
{
}

Rect::~Rect() = default;
