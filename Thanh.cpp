//
//  Thanh.cpp
//  SDL_Project
//
//  Created by Duy Kien on 4/16/21.
//

#include "Thanh.hpp"
void Mang_ThanhDo(Thanh_Do t[], int n)
{
    int m = 0;
    for(int i = 0; i < n; i++)
    {
        t[i].x = rand() % 450;
        t[i].y = 1200 - m;
        m += 120;
    }
}
