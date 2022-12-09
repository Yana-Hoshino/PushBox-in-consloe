#include <iostream>
#include <windows.h>
#include "GameData.h"
#include "input.h"
#include "draw.h"

int main()
{
	//int x = GameData::FindBox(2, 'x');
	//std::cout << x;
	//while (1) {}
	draw::DrawMap();
	while (GameData::isWin())
	{
		input::UserIn();
		system("cls");
		draw::DrawMap();
	}
	std::cout << "You Win!" << std::endl;
	std::cout << "Thanks for your play" << std::endl;
	Sleep(2000);
}
