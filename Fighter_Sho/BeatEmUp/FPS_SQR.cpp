//
//  FPS_SQR.cpp
//  Fighter_Sho
//
//  Created by David Chavarria on 2/6/15.
//  Copyright (c) 2015 David Chavarria. All rights reserved.
//

#include "FPS_SQR.h"
#include<SDL2/SDL.h>
#include<SDL2_image/SDL_image.h>
#include<Iostream>

using namespace std;

FPS_SQR::FPS_SQR(SDL_Renderer* renderer)
{
    fps_standing.push_back(IMG_LoadTexture(renderer,"/Users/DavidChavarria/Documents/Proyectos XCode/Lab_Sho/Fighter_Sho/BeatEmUp/FPS_0000_Azul.png"));
    fps_standing.push_back(IMG_LoadTexture(renderer,"/Users/DavidChavarria/Documents/Proyectos XCode/Lab_Sho/Fighter_Sho/BeatEmUp/FPS_0001_Verde.png"));
    fps_standing.push_back(IMG_LoadTexture(renderer,"/Users/DavidChavarria/Documents/Proyectos XCode/Lab_Sho/Fighter_Sho/BeatEmUp/FPS_0002_Rojo.png"));
    
    SDL_QueryTexture(fps_standing[0], NULL, NULL, &rect.w, &rect.h);
    rect.x = 900;
    rect.y = 5;
    
    frame = 0;
    animacion_fps = 0;
}

void FPS_SQR::draw(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, fps_standing[animacion_fps], NULL, &rect);
    if(frame%50==0)
    {
        animacion_fps += 1;
        if(animacion_fps>=fps_standing.size())
            animacion_fps=0;
    }
    frame++;
}


void FPS_SQR::act()
{
}


FPS_SQR::~FPS_SQR()
{
    //dtor
}
