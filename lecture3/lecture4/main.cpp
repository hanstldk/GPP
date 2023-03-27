#include <iostream>
#include <conio.h>

int main(){
	char ch;
	std::cout<<"루프를 도는 중입니다.";

	while(1){
		ch=_getch();
	        std::cout<<"루프를 도는 중입니다.";
		if(ch==27){
			std::cout<<"ESC키를 눌렀군요. 루프를 빠져나갑니다";
			break;}
	}
	return 0;
}

