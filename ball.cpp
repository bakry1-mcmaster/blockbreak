#include "ball.hpp"

ball::ball()
{
    ballbox = new SDL_Rect;
    vx = 5;
    vy = 5;

    balldirec = DOWN_RIGHT;
    
    ballbox->h = 10;
    ballbox->w = 10;
    ballbox->x = 20;
    ballbox->y = 20;

    screenWidth = 640;
    screenLength = 360;

}


ball::~ball()
{
    delete ballbox;
    ballbox = nullptr;
}

void ball::ballmovement()
{

    if(ballbox->x <= 0 && ballbox->y > 0)
    {
        if(balldirec == DOWN_LEFT)
            balldirec = DOWN_RIGHT;
        
        else if(balldirec == UP_LEFT)
            balldirec = UP_RIGHT;
    }

    if(ballbox->x >= screenWidth && ballbox->y > 0)
    {
        if(balldirec == DOWN_RIGHT)
            balldirec = DOWN_LEFT;
        
        else if(balldirec == UP_RIGHT)
            balldirec = UP_LEFT;
    }

    if(ballbox->x > 0 && ballbox->y <= 0)
    {
        if(balldirec == UP_LEFT)
            balldirec = DOWN_LEFT;
        
        else if(balldirec == UP_RIGHT)
            balldirec = DOWN_RIGHT;
    }

    if(ballbox->x > 0 && ballbox->y >= screenLength)
    {
        if(balldirec == DOWN_LEFT)
            balldirec = UP_LEFT;
        
        else if(balldirec == DOWN_RIGHT)
            balldirec = UP_RIGHT;
    }

    switch(balldirec)
    {
        case DOWN_RIGHT:
            ballbox->x += vx;
            ballbox->y += vy;
            break;
            

        case DOWN_LEFT:
            ballbox->x -= vx;
            ballbox->y += vy;
            break;

        case UP_RIGHT:
            ballbox->x += vx;
            ballbox->y -= vy;
            break;
        
        case UP_LEFT:
            ballbox->x -= vx;
            ballbox->y -= vy;
            break;
        
        default:
            break;
    }
    
}

SDL_Rect* ball::getBallbox()
{
    return ballbox;
}


void ball::setBallDirec(direction r)
{
    balldirec = r;
}


direction ball::getBalldirec()
{
    return balldirec;
}