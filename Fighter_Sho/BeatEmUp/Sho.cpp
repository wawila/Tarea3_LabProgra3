#include "Sho.h"
#include<SDL2/SDL.h>
#include<SDL2_image/SDL_image.h>
#include<Iostream>

using namespace std;

Sho::Sho(SDL_Renderer* renderer)
{
    sho_standing.push_back(IMG_LoadTexture(renderer,"/Users/DavidChavarria/Documents/Proyectos XCode/Lab_Sho/Fighter_Sho/BeatEmUp/Sho/standing/1.png"));
    sho_standing.push_back(IMG_LoadTexture(renderer,"/Users/DavidChavarria/Documents/Proyectos XCode/Lab_Sho/Fighter_Sho/BeatEmUp/Sho/standing/2.png"));
    sho_standing.push_back(IMG_LoadTexture(renderer,"/Users/DavidChavarria/Documents/Proyectos XCode/Lab_Sho/Fighter_Sho/BeatEmUp/Sho/standing/3.png"));
    sho_standing.push_back(IMG_LoadTexture(renderer,"/Users/DavidChavarria/Documents/Proyectos XCode/Lab_Sho/Fighter_Sho/BeatEmUp/Sho/standing/4.png"));

    SDL_QueryTexture(sho_standing[0], NULL, NULL, &rect.w, &rect.h);
    rect.x = 100;
    rect.y = 250;

    frame = 0;
    animacion_sho = 0;
}

void Sho::draw(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, sho_standing[animacion_sho], NULL, &rect);
    if(frame%50==0)
    {
        animacion_sho += 1;
        if(animacion_sho>=sho_standing.size())
            animacion_sho=0;
    }
    frame++;
}

void Sho::act()
{
    int x = 1;
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    
    if(currentKeyStates[SDL_SCANCODE_LSHIFT])
    {
        x = 5;
    }
    if(currentKeyStates[SDL_SCANCODE_UP]&& rect.y>211)
    {
        rect.y -= x;
        cout<<rect.y<<endl;
        cout<<"Velocidad: "<<x<<endl;
    }

    if(currentKeyStates[SDL_SCANCODE_LEFT] && rect.x>-41)
    {
        rect.x -= x;
        cout<<rect.x<<endl;
        cout<<"Velocidad: "<<x<<endl;
    }

    if(currentKeyStates[SDL_SCANCODE_DOWN]&& rect.y<332 )
    {
        cout<<rect.y<<endl;
        rect.y += x;
        cout<<"Velocidad: "<<x<<endl;
    }

    if(currentKeyStates[SDL_SCANCODE_RIGHT] && rect.x<845)
    {
        cout<<rect.x<<endl;
        rect.x += x;
        cout<<"Velocidad: "<<x<<endl;
    }

    
    if(currentKeyStates[SDL_SCANCODE_SPACE] && rect.x<845)
    {
        if(rect.y > -37)
        for(int y = 1;
            y < 5;
            y++){
            rect.y -= 1;
        }
        
         
    }
    
}


Sho::~Sho()
{
    //dtor
}
