#include "ball.hpp"

enum speedLevel{SUPERSLOW, SLOW, NORMAL, FAST, SUPERFAST};

class player
{

    private:
        
        speedLevel speed;
        int speedinc;
        SDL_Rect* playerbox;
        int detectiontolerance;

    public:
        player(SDL_Renderer* render);
        ~player();

        void playerKeyProcessing(SDL_Keycode x);
        void determineSpeedInc();
        void collisionProcessing(ball* r);
        SDL_Rect* getPlayerbox();

        


};