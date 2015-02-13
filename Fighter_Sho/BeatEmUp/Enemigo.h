//
//  Enemigo.h
//  Fighter_Sho
//
//  Created by David Chavarria on 2/6/15.
//  Copyright (c) 2015 David Chavarria. All rights reserved.
//

#ifndef __Fighter_Sho__Enemigo__
#define __Fighter_Sho__Enemigo__

#include <stdio.h>
#include<SDL2/SDL.h>
#include<SDL2_image/SDL_image.h>
#include <vector>
using namespace std;

class Enemigo
{
public:
    vector<SDL_Texture*>fps_standing;
    SDL_Rect rect;
    int frame;
    int animacion_fps;
    
    Enemigo(SDL_Renderer* renderer);
    void draw(SDL_Renderer* renderer);
    void act();
    
    virtual ~Enemigo();
protected:
private:
};
#endif /* defined(__Fighter_Sho__Enemigo__) */
