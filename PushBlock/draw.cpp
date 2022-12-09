#include "draw.h"
#include "GameData.h"
#include <iostream>
int draw::DrawMap()
{
	GameData::OutData();
	std::cout << "Use wasd to control the move,press r to reset, P is you , please take all the o to \".\".\n";
	return 0;
}