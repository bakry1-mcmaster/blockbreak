#include "ball.hpp"

class brick
{
    private:
        SDL_Rect* brickRectangle;
        int health;
        int detectiontolerance;
    
    public:
        brick();
        ~brick();

        void collisionProcessing(ball* r);
        void brickBreak();

        int getHealth();

        SDL_Rect* getBrick();


};