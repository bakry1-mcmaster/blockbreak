#define SDL_MAIN_HANDLED

#include "src/include/SDL2/SDL.h"
#include "src/include/SDL2/SDL_image.h"
#include <iostream>



using namespace std;

SDL_Window* gamewindow;
SDL_Renderer* gamerenderer;

bool gamerunning = false;


void initialize();
void InputProcessing();
void exitGame();

int main(int argc, char *argv[])
{

    initialize();

    while(!gamerunning)
    {
        InputProcessing();
        SDL_Delay(100);
    }

    return 0;
}

void initialize()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout<<"Failed to initialize. Exiting...."<< endl;
        SDL_Quit();
        return;
    }

    else
    {
        gamewindow = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
        gamerenderer = SDL_CreateRenderer(gamewindow, -1, 0);

        SDL_SetRenderDrawColor(gamerenderer, 0, 0, 255, 255);
        SDL_RenderClear(gamerenderer);
        SDL_RenderPresent(gamerenderer);

        if(gamewindow == nullptr)
        {
            cout<<"Failed to initialize. Exiting...."<< endl;
            SDL_DestroyWindow(gamewindow);
            SDL_DestroyRenderer(gamerenderer);
            SDL_Quit();
            return;
        }
    }
}

void InputProcessing()
{
    SDL_Event e;

    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_KEYDOWN)
        {
            switch(e.key.keysym.sym)
            {
                case SDLK_a:
                    exitGame();
                    break;
                
                default:
                    break;
            }
        }
    }
}

void exitGame()
{
    SDL_DestroyWindow(gamewindow);
    SDL_DestroyRenderer(gamerenderer);
    SDL_Quit();

    gamerunning = true;
}

