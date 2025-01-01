#include "src/include/SDL2/SDL.h"
#include "src/include/SDL2/SDL_image.h"

#pragma once

enum direction{UP_LEFT, DOWN_LEFT, UP_RIGHT, DOWN_RIGHT};

class ball
{
    private:
        int vx;
        int vy;
        int screenWidth;
        int screenLength;

        SDL_Rect* ballbox;
        direction balldirec;

    public:
        ball();
        ~ball();

        void ballmovement();
        SDL_Rect* getBallbox();

        void setBallDirec(direction r);
        direction getBalldirec();


};