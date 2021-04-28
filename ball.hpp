//
//  ball.hpp
//  SDL_Project
//
//  Created by Duy Kien on 4/16/21.
//

#ifndef ball_hpp
#define ball_hpp

#include "SDL_utils.hpp"
struct Ball
{
    int x;
    int y;
    int w;
    int h;
    int B_Step = 5;
    int B_turnLeft = 10;
    int B_turnRight = 10;
    SDL_Rect BallRect;
    void move()
    {
        y += B_Step;
    }
    void turnLeft()
    {
        x -= B_turnLeft;
    }
    void turnRight()
    {
        x += B_turnRight;
    }
    void Ball_Rect(SDL_Renderer* renderer)
    {
        SDL_Texture* Ball = loadTexture( "/Users/duykien/Desktop/SDL_Project/SDL_Project/ball.png", renderer );
        SDL_QueryTexture(Ball, NULL, NULL, &BallRect.w, &BallRect.h);
        BallRect.x = x;
        BallRect.y = y;
        BallRect.w = BallRect.w/5;
        BallRect.h = BallRect.h/5;
        SDL_RenderCopy(renderer, Ball, NULL, &BallRect);
        w = BallRect.w;
        h = BallRect.h;
    }
};




#endif /* ball_hpp */
