//
//  life.hpp
//  SDL_Project
//
//  Created by Duy Kien on 4/26/21.
//

#ifndef life_hpp
#define life_hpp
#include <stdio.h>
#include "SDL_utils.hpp"

struct life
{
    int x;
    int y = 40;
    int w = 30;
    int h = 30;
    SDL_Rect LifeRect;
    void RenderLife(SDL_Renderer* renderer)
    {
        SDL_Texture* Life = loadTexture( "/Users/duykien/Desktop/SDL_Project/SDL_Project/Life.PNG", renderer );
        SDL_QueryTexture(Life, NULL, NULL, &LifeRect.w, &LifeRect.h);
        LifeRect.x = x;
        LifeRect.y = y;
        LifeRect.w = w;
        LifeRect.h = h;
        SDL_RenderCopy(renderer, Life, NULL, &LifeRect);
    }
};
void Mang_Life(life Life[], float n);


#endif /* life_hpp */
