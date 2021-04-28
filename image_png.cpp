//
//  image_png.cpp
//  SDL_Project
//
//  Created by Duy Kien on 4/8/21.
//

#include "image_png.hpp"

SDL_Texture* loadTexture(string path, SDL_Renderer* renderer )
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        cout << "Unable to load image " << path << " SDL_image Error: " << IMG_GetError() << endl;
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        if( newTexture == NULL )
        {
            cout << "Unable to creat texturre from " << path << " SDL_image Error: " << IMG_GetError() << endl;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}
