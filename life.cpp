//
//  life.cpp
//  SDL_Project
//
//  Created by Duy Kien on 4/26/21.
//

#include "life.hpp"

void Mang_Life(life Life[], float n)
{
    int m = 0;
    for(int i = 0; i < n; i++)
    {
        Life[i].x = 20 + m;
        Life[i].y = 40;
        m+= 40;
    }
}
