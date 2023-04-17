#include <iostream>

using namespace std;

class MobilePhone {
public:
    MobilePhone() {
        cout << "모바일폰을 생성" << endl;
    }
    virtual ~MobilePhone() {
        cout << "모바일폰을 소멸" << endl;
    }

    virtual void Turnon() {
        cout << "모바일폰을 켜기" << endl;
    }
    void Turnoff() {
        cout << "모바일폰을 끄기" << endl;
    }
};

class IPhone :public MobilePhone {
public:
    IPhone() {
        cout << "아이폰을 생성" << endl;
    }
    ~IPhone() {
        cout << "아이폰을 소멸" << endl;
    }

    void ApplePay() {
        cout << "애플페이" << endl;
    }
    void Siri() {
        cout << "시리" << endl;
    }
    void Turnon() {
        cout << "(❁´◡`❁)(❁´◡`❁)(❁´◡`❁)(❁´◡`❁)(❁´◡`❁)(❁´◡`❁)" << endl;
    }


};

class Galaxy :public MobilePhone {
public:
    Galaxy() {
        cout << "갤럭시을 생성" << endl;
    }
    ~Galaxy() {
        cout << "갤럭시을 소멸" << endl;
    }
    void SamsungPay() {
        cout << "삼성페이" << endl;
    }
    void Bisby() {
        cout << "빅스비" << endl;
    }
    void Turnon() {
        cout << "삼성123456" << endl;
    }

};



int main()
{
    //cout << "모바일폰 클래스"<<endl;
    //IPhone *i = new IPhone();
    //Galaxy g;

    //i->Siri();
    //g.Bisby();

    MobilePhone** mp = new MobilePhone * [2];
    mp[0] = new IPhone();
    mp[1] = new Galaxy();

    for (size_t i = 0; i < 2; i++) {
        mp[i]->Turnon();
        delete(mp[i]);
    }


}