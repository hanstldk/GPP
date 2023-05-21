#pragma once


#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;



namespace MuSoeun
{
    class Component //Unity MonoBehavior
    {
    public:
        void Start();
        void Update(Object& obj) {
            if (_getch() == 'a') {
                obj.posx++;
            }
        }
    };





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
                    int index = (posy * (width + 1)) + posx + 1;
                    screenbuf[index] = ch;
                    posx++;
                }
                posx -= scale;
                posy++;
            }
            posy -= scale;
        };
    };







    class Scene
    {
    public:
        int width;
        int height;
        vector<Object> objList;
        char* ScreenBuf;


        void InitScreenBuf()
        {
            ScreenBuf = new char[(width + 1) * height + 5];

            for (int i = 0; i < width; i++)
            {
                ScreenBuf[i] = '#';//윗테두리
            }
            ScreenBuf[width] = '\n';

            for (int i = 1; i < height - 1; i++)
            {
                ScreenBuf[(width + 1) * i] = '#';  // 왼쪽 테두리
                for (int j = 1; j < width; j++)
                {
                    ScreenBuf[(width + 1) * i + j] = ' ';  // 가운데 영역은 공백으로 채움
                }
                ScreenBuf[(width + 1) * (i + 1) - 2] = '#';  // 오른쪽 테두리
                ScreenBuf[(width + 1) * (i + 1) - 1] = '\n';
            }
            for (int i = (width + 1) * (height - 1); i < (width + 1) * height - 1; i++)
            {
                ScreenBuf[i] = '#';
            }

            ScreenBuf[(width + 1) * height - 1] = '\n';
            ScreenBuf[(width + 1) * height] = '\0';
        }





        void ReleaseScreenBuf()
        {
            if (ScreenBuf != nullptr)
            {
                delete(ScreenBuf);
            }
        }





        void DrawScreenBuf()
        {
            for (int i = 0;i < objList.size();i++) {
                objList[i].Render(ScreenBuf, width, objList[i].scale);
            }
            cout << ScreenBuf;
        }


        void ClearScreenBuf() //씬화면 가운데를 공백으로 초기화
        {
            for (int i = 1; i < height - 1; i++)
            {
                for (int j = 1; j < width; j++)
                {
                    ScreenBuf[(width + 1) * i + j] = ' ';
                }
                ScreenBuf[(width + 1) * (i + 1) - 2] = '#';
                ScreenBuf[(width + 1) * (i + 1) - 1] = '\n';
            }
            cout << ScreenBuf;
        }
    };
}
