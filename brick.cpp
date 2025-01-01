#include "brick.hpp"

brick::brick()
{
    health = 3;
    detectiontolerance = 4;

    brickRectangle = new SDL_Rect;

    brickRectangle->w = 50;
    brickRectangle->h = 10;
    brickRectangle->x = 320;
    brickRectangle->y = 50;
}

brick::~brick()
{
    delete brickRectangle;
    brickRectangle = nullptr;
}


void brick::collisionProcessing(ball* r)
{
    // Hits from the left
    if ((r->getBallbox()->x + r->getBallbox()->w >= brickRectangle->x &&
        r->getBallbox()->x + r->getBallbox()->w <= brickRectangle->x + detectiontolerance) &&
        (r->getBallbox()->y + r->getBallbox()->h >= brickRectangle->y &&
        r->getBallbox()->y <= brickRectangle->y + brickRectangle->h)) 
    {
        if (r->getBalldirec() == UP_RIGHT) {
            r->setBallDirec(UP_LEFT);
        }
        if (r->getBalldirec() == DOWN_RIGHT) {
            r->setBallDirec(DOWN_LEFT);
        }

        health--;
    }

    // Hits from the right
    if ((r->getBallbox()->x >= brickRectangle->x + brickRectangle->w - detectiontolerance &&
        r->getBallbox()->x <= brickRectangle->x + brickRectangle->w) &&
        (r->getBallbox()->y + r->getBallbox()->h >= brickRectangle->y &&
        r->getBallbox()->y <= brickRectangle->y + brickRectangle->h)) 
    {
        if (r->getBalldirec() == UP_LEFT) {
            r->setBallDirec(UP_RIGHT);
        }
        if (r->getBalldirec() == DOWN_LEFT) {
            r->setBallDirec(DOWN_RIGHT);
        }

        health--;
    }

    // Hits from the top
    if ((r->getBallbox()->y + r->getBallbox()->h >= brickRectangle->y &&
        r->getBallbox()->y + r->getBallbox()->h <= brickRectangle->y + detectiontolerance) &&
        (r->getBallbox()->x + r->getBallbox()->w >= brickRectangle->x &&
        r->getBallbox()->x <= brickRectangle->x + brickRectangle->w)) 
    {
        if (r->getBalldirec() == DOWN_RIGHT) {
            r->setBallDirec(UP_RIGHT);
        }
        if (r->getBalldirec() == DOWN_LEFT) {
            r->setBallDirec(UP_LEFT);
        }

        health--;
    }

    // Hits from the bottom
    if ((r->getBallbox()->y >= brickRectangle->y + brickRectangle->h - detectiontolerance &&
        r->getBallbox()->y <= brickRectangle->y + brickRectangle->h) &&
        (r->getBallbox()->x + r->getBallbox()->w >= brickRectangle->x &&
        r->getBallbox()->x <= brickRectangle->x + brickRectangle->w)) 
    {
        if (r->getBalldirec() == UP_RIGHT) {
            r->setBallDirec(DOWN_RIGHT);
        }
        if (r->getBalldirec() == UP_LEFT) {
            r->setBallDirec(DOWN_LEFT);
        }

        health--;
    }
}


void brick::brickBreak()
{
    if(health == 0)
    {
        brickRectangle->w = 0;
        brickRectangle->h = 0;
        brickRectangle->x = -1000;
        brickRectangle->y = -1000;
    }
}


int brick::getHealth()
{
    return health;
}

SDL_Rect* brick::getBrick()
{
    return brickRectangle;
}