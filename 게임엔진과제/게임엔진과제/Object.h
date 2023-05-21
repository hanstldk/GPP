#pragma once


#include <vector>
#include "Component.h"


using namespace std;

class Component;

class Object
{
public:
    int posx;
    int posy;
    int scale;
    char ch;
    vector<Component> cpnList;


    Object(int x, int y, int sca, char c) {
        posx = x;
        posy = y;
        scale = sca;
        ch = c;
    }


    void Render(char* screenbuf, int width, int scale) {

        for (int i = 0; i < scale;i++) {
            for (int i = 0; i < scale;i++) {
                int index = ((posy+1) * (width + 1)) + posx + 1;
                screenbuf[index] = ch;
                posx++;
            }
            posx -= scale;
            posy++;
        }
        posy -= scale;
    };
};
