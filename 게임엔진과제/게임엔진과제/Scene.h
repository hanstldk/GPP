#pragma once
#include <iostream>
#include <vector>
#include "Object.h"


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
            ScreenBuf[i] = '#';//���׵θ�
        }
        ScreenBuf[width] = '\n';

        for (int i = 1; i < height - 1; i++)
        {
            ScreenBuf[(width + 1) * i] = '#';  // ���� �׵θ�
            for (int j = 1; j < width; j++)
            {
                ScreenBuf[(width + 1) * i + j] = ' ';  // ��� ������ �������� ä��
            }
            ScreenBuf[(width + 1) * (i + 1) - 2] = '#';  // ������ �׵θ�
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


    void ClearScreenBuf()
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
