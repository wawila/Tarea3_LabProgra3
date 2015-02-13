//
//  FPS_SQR.h
//  Fighter_Sho
//
//  Created by David Chavarria on 2/6/15.
//  Copyright (c) 2015 David Chavarria. All rights reserved.
//

#ifndef __Fighter_Sho__FPS_SQR__
#define __Fighter_Sho__FPS_SQR__

#include <stdio.h>
#include<SDL2/SDL.h>
#include<SDL2_image/SDL_image.h>
#include <vector>
using namespace std;

class FPS_SQR
{
public:
    vector<SDL_Texture*>fps_standing;
    SDL_Rect rect;
    int frame;
    int animacion_fps;
    FPS_SQR(SDL_Renderer* renderer);
    void draw(SDL_Renderer* renderer);
    void act();
    virtual ~FPS_SQR();
protected:
private:
};




#endif /* defined(__Fighter_Sho__FPS_SQR__) */
