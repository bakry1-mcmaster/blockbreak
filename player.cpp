#include "player.hpp"

player::player(SDL_Renderer* render)
{
    speed = SUPERFAST;
    speedinc = 30;
    detectiontolerance = 3;

    playerbox = new SDL_Rect;

    playerbox->w = 100;
    playerbox->h = 20;
    playerbox->x = 320;
    playerbox->y = 310;


}

player::~player()
{
    delete playerbox;
    playerbox = nullptr;
}



void player::playerKeyProcessing(SDL_Keycode x)
{
    determineSpeedInc();

    
    switch(x)
    {

        case SDLK_RIGHT:
        case SDLK_d:
            playerbox->x+=speedinc;
            break;
        
        case SDLK_LEFT:
        case SDLK_a:
            playerbox->x-=speedinc;
            break;

        default:
            break;
    }
           
}


void player::determineSpeedInc()
{
   
    switch(speed)
    {
        case SUPERSLOW:
            speedinc = 1;
            break;
        
        case SLOW:
            speedinc = 5;
            break;
        
        case NORMAL:
            speedinc = 10;
            break;
        
        case FAST:
            speedinc = 15;
            break;
        
        case SUPERFAST:
            speedinc = 30;
            break;

    }
}

void player::collisionProcessing(ball* r)
{
    // Hits from the left
    if ((r->getBallbox()->x + r->getBallbox()->w >= playerbox->x &&
        r->getBallbox()->x + r->getBallbox()->w <= playerbox->x + detectiontolerance) &&
        (r->getBallbox()->y + r->getBallbox()->h >= playerbox->y &&
        r->getBallbox()->y <= playerbox->y + playerbox->h)) 
    {
        if (r->getBalldirec() == UP_RIGHT) {
            r->setBallDirec(UP_LEFT);
        }
        if (r->getBalldirec() == DOWN_RIGHT) {
            r->setBallDirec(DOWN_LEFT);
        }
    }

    // Hits from the right
    if ((r->getBallbox()->x >= playerbox->x + playerbox->w - detectiontolerance &&
        r->getBallbox()->x <= playerbox->x + playerbox->w) &&
        (r->getBallbox()->y + r->getBallbox()->h >= playerbox->y &&
        r->getBallbox()->y <= playerbox->y + playerbox->h)) 
    {
        if (r->getBalldirec() == UP_LEFT) {
            r->setBallDirec(UP_RIGHT);
        }
        if (r->getBalldirec() == DOWN_LEFT) {
            r->setBallDirec(DOWN_RIGHT);
        }
    }

    // Hits from the top
    if ((r->getBallbox()->y + r->getBallbox()->h >= playerbox->y &&
        r->getBallbox()->y + r->getBallbox()->h <= playerbox->y + detectiontolerance) &&
        (r->getBallbox()->x + r->getBallbox()->w >= playerbox->x &&
        r->getBallbox()->x <= playerbox->x + playerbox->w)) 
    {
        if (r->getBalldirec() == DOWN_RIGHT) {
            r->setBallDirec(UP_RIGHT);
        }
        if (r->getBalldirec() == DOWN_LEFT) {
            r->setBallDirec(UP_LEFT);
        }
    }

    // Hits from the bottom
    if ((r->getBallbox()->y >= playerbox->y + playerbox->h - detectiontolerance &&
        r->getBallbox()->y <= playerbox->y + playerbox->h) &&
        (r->getBallbox()->x + r->getBallbox()->w >= playerbox->x &&
        r->getBallbox()->x <= playerbox->x + playerbox->w)) 
    {
        if (r->getBalldirec() == UP_RIGHT) {
            r->setBallDirec(DOWN_RIGHT);
        }
        if (r->getBalldirec() == UP_LEFT) {
            r->setBallDirec(DOWN_LEFT);
        }
    }
}

SDL_Rect* player::getPlayerbox()
{
    return playerbox;
}