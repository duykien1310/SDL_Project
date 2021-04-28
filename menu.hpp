//
//  menu.hpp
//  SDL_Project
//
//  Created by Duy Kien on 4/26/21.
//

#ifndef menu_hpp
#define menu_hpp
#include <stdio.h>
#include "SDL_utils.hpp"

struct Menu
{
    int x = 100;
    int y = 200;
    int w = 400;
    int h = 200;
    SDL_Rect Ready_rect;
    SDL_Rect GameOver_rect;

    void renderReady(SDL_Renderer* renderer)
    {
        SDL_Texture* Ready = loadTexture( "/Users/duykien/Desktop/SDL_Project/SDL_Project/PlayNow.png", renderer );
        SDL_QueryTexture(Ready, NULL, NULL, &Ready_rect.w, &Ready_rect.h);
        Ready_rect.x = x;
        Ready_rect.y = y;
        Ready_rect.w = w;
        Ready_rect.h = h;
        SDL_RenderCopy(renderer, Ready, NULL, &Ready_rect);
    }
    void renderGameOver(SDL_Renderer* renderer)
    {
        SDL_Texture* GameOver = loadTexture( "/Users/duykien/Desktop/SDL_Project/SDL_Project/GameOver.png", renderer );
        SDL_QueryTexture(GameOver, NULL, NULL, &GameOver_rect.w, &GameOver_rect.h);
        GameOver_rect.x = x;
        GameOver_rect.y = y;
        GameOver_rect.w = w;
        GameOver_rect.h = h;
        SDL_RenderCopy(renderer, GameOver, NULL, &GameOver_rect);
    }
};





#endif /* menu_hpp */
