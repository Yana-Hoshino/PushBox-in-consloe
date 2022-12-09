#include <iostream>
#include <windows.h>
#include "GameData.h"
#include "input.h"
#include "draw.h"

int main()
{
	//std::string a = GameData::FindBox(2);
	//std::cout << a;
	//while (1) {}
	draw::DrawMap();
	while (GameData::WinCheck())
	{
		input::UserIn();
		system("cls");
		draw::DrawMap();
	}
	std::cout << "You Win!" << std::endl;
	std::cout << "Thanks for your play" << std::endl;
	Sleep(2000);
}
