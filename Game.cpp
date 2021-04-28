//
//  Game.cpp
//  SDL_Project
//
//  Created by Duy Kien on 4/8/21.
//

#include"Game.hpp"

using namespace std;
void game()
{
    TTF_Init();
    TTF_Font* gFont = TTF_OpenFont("/Users/duykien/Desktop/SDL_Project/SDL_Project/font.ttf", 20);
    string textureText = "";
    SDL_Color textColor = { 0, 0, 0 };
    SDL_Surface* textSurface = NULL;
    SDL_Texture* mTexture = NULL;
    SDL_Rect scoreBOX;
    
    SDL_Window* window;
    SDL_Renderer* renderer;
    float numberLife = 5;
    const Uint8* key = SDL_GetKeyboardState(NULL);
    initSDL(window, renderer);
    SDL_Event e;
    bool ss = true;
    int count = 0;
    int score = 0;
    
    Thanh_Do t[6];
    Mang_ThanhDo(t, 6);
    
    Ball ball;
    ball.x = 400;
    ball.y = 200;
    
    life Life[(int)numberLife];
    Mang_Life(Life, numberLife);
    
    Menu menu;
    
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Music* gMusic = Mix_LoadMUS("/Users/duykien/Desktop/SDL_Project/SDL_Project/BackSound.mp3");
    Mix_PlayMusic(gMusic, -1);
    cout << SDL_GetError() << endl;
    
    while (1)
    {
        SDL_Texture* background = loadTexture( "/Users/duykien/Desktop/SDL_Project/SDL_Project/Background.png", renderer );
        SDL_RenderCopy(renderer, background, NULL, NULL);
        menu.renderReady(renderer);
        SDL_RenderPresent(renderer);    // Xuất hiện
        if ( SDL_PollEvent(&e) == 0) continue;
        
        if (e.key.keysym.sym == SDLK_RETURN)
        {
            break;
        }
    }
    
    while(ss)
    {
        SDL_Texture* background = loadTexture( "/Users/duykien/Desktop/SDL_Project/SDL_Project/Background.png", renderer );
        SDL_RenderCopy(renderer, background, NULL, NULL);
        
        for(int i = 0; i < numberLife; i++)
        {
            Life[i].RenderLife(renderer);
        }
        score++;
        ball.Ball_Rect(renderer);
        
        t[5].renderThanh(renderer);
        t[4].renderSpikes(renderer);
        t[3].renderThanh(renderer);
        t[2].renderSpikes(renderer);
        t[1].renderThanh(renderer);
        t[0].renderSpikes(renderer);
        
        SDL_Texture* Gai = loadTexture( "/Users/duykien/Desktop/SDL_Project/SDL_Project/Gai.PNG", renderer );
        SDL_Rect GaiRect;
        SDL_QueryTexture(Gai, NULL, NULL, &GaiRect.w, &GaiRect.h);
        GaiRect.x = 0;
        GaiRect.y = 0;
        GaiRect.w = GaiRect.w * 2;
        GaiRect.h = GaiRect.h * 1.5;
        SDL_RenderCopy(renderer, Gai, NULL, &GaiRect);
        
//        SDL_RenderPresent(renderer);    // Xuất hiện
        
        //SDL_Delay(10);
        //SDL_RenderClear(renderer);
        ball.move();
        for(int i = 0; i < 6; i++)
        {
            t[i].move();
        }
        for(int i = 0; i < 6; i++)
        {
            if(t[i].y < 0)
            {
                t[i].x = rand() % 450;
                t[i].y = 720;
            }
        }
        ball.B_Step = 5;
        ball.B_turnRight = 10;
        ball.B_turnLeft = 10;
        for(int i = 5; i >= 0; i--)
        {
            if(ball.y + 40 == t[i].y && (ball.x > t[i].x - ball.w && ball.x < t[i].x + 150))
            {
                ball.B_Step = t[i].T_Step;
            }
            if(ball.y + 45 == t[i].y && (ball.x > t[i].x - ball.w && ball.x < t[i].x + 150))
            {
                ball.B_Step = 0;
            }
            if(ball.x < 5) ball.B_turnLeft = 0;
            if(ball.x > 550) ball.B_turnRight = 0;
            if(SDL_HasIntersection(&t[i].Spike_rect, &ball.BallRect) || ball.y > 760 || ball.y < 20)
            {
                count++;
                ball.B_turnLeft = 0;
                ball.B_turnRight = 0;
                if(count % 10 == 0)
                {
                    for(int j = 1; j < 6; j+= 2)
                    {
                        if(t[j].y > t[i].y)
                        {
                            ball.x = t[j].x + 150/2;
                            ball.y = t[j].y - 50;
                        }
                    }
                }
            }
        }
        
        if(ball.y == 760 || ball.y == 20)
        {
            numberLife--;
        }

        for(int i = 0; i <= 4; i+=2)
        {
            if(SDL_HasIntersection(&t[i].Spike_rect, &ball.BallRect))
            {
                numberLife -= 0.11;
                break;
            }
        }
        
        if(numberLife <= -1)
        {
            ss = false;
            menu.renderGameOver(renderer);
        }
        
        while((SDL_PollEvent(&e)) != 0)
        {
            if(e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
            {
                ss = false;
            }
        }
//        const Uint8* key = SDL_GetKeyboardState(NULL);
        if (key[SDL_SCANCODE_LEFT])
        {
            ball.turnLeft();
        }
        if (key[SDL_SCANCODE_RIGHT])
        {
            ball.turnRight();
        }
        
            textureText = to_string(score);
            textSurface = TTF_RenderText_Blended(gFont, textureText.c_str(), textColor);
            mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            scoreBOX = { SCREEN_WIDTH / 2, 40 , textSurface->w, textSurface->h };
            SDL_RenderCopy(renderer, mTexture, NULL, &scoreBOX);
        
        SDL_RenderPresent(renderer);    // Xuất hiện
        
        SDL_DestroyTexture(background);
        background = NULL;
        SDL_DestroyTexture(Gai);
        Gai = NULL;
    }
    
    waitUntilKeyPressed();
    quitSDL(window, renderer);
}
