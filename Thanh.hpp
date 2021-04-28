//
//  Thanh.hpp
//  SDL_Project
//
//  Created by Duy Kien on 4/16/21.
//

#ifndef Thanh_hpp
#define Thanh_hpp
#include "SDL_utils.hpp"
struct Thanh_Do
{
    int x;
    int y;
    int w = 150;
    int h = 15;
    const int T_Step = -5;
    SDL_Rect Thanh_rect;
    SDL_Rect Spike_rect;
    
    void renderThanh(SDL_Renderer* renderer)
    {
        SDL_Texture* Thanh = loadTexture( "/Users/duykien/Desktop/SDL_Project/SDL_Project/Bar.PNG", renderer );
        SDL_QueryTexture(Thanh, NULL, NULL, &Thanh_rect.w, &Thanh_rect.h);
        Thanh_rect.x = x;
        Thanh_rect.y = y;
        Thanh_rect.w = w;
        Thanh_rect.h = h;
        SDL_RenderCopy(renderer, Thanh, NULL, &Thanh_rect);
    }
    void renderSpikes(SDL_Renderer* renderer)
    {
        SDL_Texture* Spikes = loadTexture( "/Users/duykien/Desktop/SDL_Project/SDL_Project/Spikes.PNG", renderer );
        SDL_QueryTexture(Spikes, NULL, NULL, &Spike_rect.w, &Spike_rect.h);
        Spike_rect.x = x;
        Spike_rect.y = y;
        Spike_rect.w = w;
        Spike_rect.h = h;
        SDL_RenderCopy(renderer, Spikes, NULL, &Spike_rect);
    }
    void move()
    {
        y += T_Step;
    }
};
void Mang_ThanhDo(Thanh_Do t[], int n);
#endif /* Thanh_hpp */
