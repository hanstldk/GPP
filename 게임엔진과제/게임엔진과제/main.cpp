#include <iostream>
#include <vector>

#include "Object.h"
#include "Scene.h"


int main()
{
    int is_Game_Running = 0;
        Scene s1;
        int wid;
        int hei;
        cout << "화면의 가로크기를 입력하세요:";
        cin >> wid;
        s1.width = wid;
        cout << "화면의 세로크기를 입력하세요:";
        cin >> hei;
        s1.height = hei;   
        s1.InitScreenBuf();

        int posX;
        int posY;
        int scale;
        char ch;


        cout << "첫번째 오브젝트의 x좌표,y좌표,크기,표현될 문자를 입력하세요:";
        
        cin >> posX;
        cin >> posY;
        cin >> scale;
        cin >> ch;
        Object obj1(posX, posY, scale, ch);

        cout << "두번째 오브젝트의 x좌표,y좌표,크기,표현될 문자를 입력하세요:";
        cin >> posX;
        cin >> posY;
        cin >> scale;
        cin >> ch;
        Object obj2(posX, posY, scale,ch);

        cout << "세번째 오브젝트의 x좌표,y좌표,크기,표현될 문자를 입력하세요:";
        cin >> posX;
        cin >> posY;
        cin >> scale;
        cin >> ch;
        Object obj3(posX, posY, scale, ch);
 
        s1.objList.push_back(obj1);
        s1.objList.push_back(obj2);
        s1.objList.push_back(obj3);

        is_Game_Running = 1;

        while (is_Game_Running) {
            s1.DrawScreenBuf();
        }
  
        
    return 0;
}