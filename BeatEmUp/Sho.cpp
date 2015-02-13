#include "Sho.h"
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<Iostream>

using namespace std;

Sho::Sho(SDL_Renderer* renderer)
{
    sho_standing.push_back(IMG_LoadTexture(renderer,"Sho/standing/1.png"));
    sho_standing.push_back(IMG_LoadTexture(renderer,"Sho/standing/2.png"));
    sho_standing.push_back(IMG_LoadTexture(renderer,"Sho/standing/3.png"));
    sho_standing.push_back(IMG_LoadTexture(renderer,"Sho/standing/4.png"));

    SDL_QueryTexture(sho_standing[0], NULL, NULL, &rect.w, &rect.h);
    rect.x = 100;
    rect.y = 250;

    frame = 0;
    animacion_sho = 0;
}

void Sho::draw(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, sho_standing[animacion_sho], NULL, &rect);
    if(frame%300==0)
    {
        animacion_sho++;
        if(animacion_sho>=sho_standing.size())
            animacion_sho=0;
    }
    frame++;
}

void Sho::act()
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    if(currentKeyStates[SDL_SCANCODE_UP]&& rect.y>-37)
    {
        rect.y--;
        cout<<rect.y<<endl;
    }

    if(currentKeyStates[SDL_SCANCODE_LEFT] && rect.x>-41)
    {
        rect.x--;
        cout<<rect.x<<endl;
    }

    if(currentKeyStates[SDL_SCANCODE_DOWN]&& rect.y<332 )
    {
        cout<<rect.y<<endl;
        rect.y++;
    }

    if(currentKeyStates[SDL_SCANCODE_RIGHT] && rect.x<845)
    {
        cout<<rect.x<<endl;
        rect.x++;
    }
}


Sho::~Sho()
{
    //dtor
}
