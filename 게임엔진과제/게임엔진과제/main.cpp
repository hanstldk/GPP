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
        cout << "ȭ���� ����ũ�⸦ �Է��ϼ���:";
        cin >> wid;
        s1.width = wid;
        cout << "ȭ���� ����ũ�⸦ �Է��ϼ���:";
        cin >> hei;
        s1.height = hei;   
        s1.InitScreenBuf();

        int posX;
        int posY;
        int scale;
        char ch;


        cout << "ù��° ������Ʈ�� x��ǥ,y��ǥ,ũ��,ǥ���� ���ڸ� �Է��ϼ���:";
        
        cin >> posX;
        cin >> posY;
        cin >> scale;
        cin >> ch;
        Object obj1(posX, posY, scale, ch);

        cout << "�ι�° ������Ʈ�� x��ǥ,y��ǥ,ũ��,ǥ���� ���ڸ� �Է��ϼ���:";
        cin >> posX;
        cin >> posY;
        cin >> scale;
        cin >> ch;
        Object obj2(posX, posY, scale,ch);

        cout << "����° ������Ʈ�� x��ǥ,y��ǥ,ũ��,ǥ���� ���ڸ� �Է��ϼ���:";
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