#include <iostream>
#include <conio.h>

int main(){
	char ch;
	std::cout<<"Run"<<std::endl;

	while(1){
		std::cout << "IN LOOP(ESC=EXIT)" << std::endl;
		ch=_getch();
		if(ch==27){
			std::cout<<"ESC";
			break;}
	}
	return 0;
}

