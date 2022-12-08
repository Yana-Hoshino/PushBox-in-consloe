#include <iostream>
#include "GameData.h"
#include "input.h"
#include "draw.h"

int main()
{
	draw::DrawMap();
	while (1)
	{
		input::UserIn();
		system("cls");
		draw::DrawMap();
	}
}
