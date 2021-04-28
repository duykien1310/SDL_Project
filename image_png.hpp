//
//  image_png.hpp
//  SDL_Project
//
//  Created by Duy Kien on 4/8/21.
//

#ifndef image_png_hpp
#define image_png_hpp

#include "SDL_utils.hpp"
using namespace std;
//Loads individual image as texture
SDL_Texture* loadTexture(string path, SDL_Renderer* renderer );

#endif /* image_png_hpp */
