#include "defaultobj.hpp"
#include "src/include/SDL2/SDL.h"
#include "src/include/SDL2/SDL_image.h"

enum speedLevel{SUPERSLOW, SLOW, NORMAL, FAST, SUPERFAST};

class player: public defaultobj
{

    private:
        
        speedLevel speed;
        SDL_Rect* playerbox;

    public:
        player();
        ~player();

        


};