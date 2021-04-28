//
//  SDL_utils.hpp
//  SDL_Project
//
//  Created by Duy Kien on 4/8/21.
//

#ifndef SDL_utils_hpp
#define SDL_utils_hpp

#include <stdio.h>
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include "image_png.hpp"
void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);  // Hàm bão lỗi
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer); // Tạo cửa sổ
const int SCREEN_WIDTH = 600;  //  chiều rộng của cửa sổ
const int SCREEN_HEIGHT = 800;  // chiều cao của cửa sổ
const std::string WINDOW_TITLE = "Game Rapid Roll"; // Tên cửa sổ
void quitSDL(SDL_Window* window, SDL_Renderer* renderer); // Đóng cửa sổ
void waitUntilKeyPressed();
//void RenderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, int w, int h, SDL_Rect dst);

#endif /* SDL_utils_hpp */
