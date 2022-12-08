#include "input.h"
#include "GameData.h"
#include <iostream>
char indata;
int UserX = 5;
int UserY = 1;
int input::UserIn()
{
	std::cin >> indata;
	if (indata == 'w') 
	{
		if (GameData::WallCheck(UserX, UserY) == 'U' || GameData::WallCheck(UserX, UserY) == '9' || GameData::WallCheck(UserX, UserY) == '7' || GameData::BoxWallCheck(UserX, UserY, 'w') == 'w')
		{
			return 0;
		}
		GameData::BoxCheck(UserX, UserY, 'w');
		GameData::InData(UserX, UserY, ' ');
		GameData::InData(UserX, UserY - 1, 'p');
		UserY -= 1;
	}
	else if (indata == 'a')
	{
		if (GameData::WallCheck(UserX, UserY) == 'L' || GameData::WallCheck(UserX, UserY) == '7' || GameData::WallCheck(UserX, UserY) == '1' || GameData::BoxWallCheck(UserX, UserY, 'a') == 'a')
		{
			return 0;
		}
		GameData::BoxCheck(UserX, UserY, 'a');
		GameData::InData(UserX, UserY, ' ');
		GameData::InData(UserX - 1, UserY, 'p');
			UserX -= 1;
	}
	else if (indata == 's')
	{
		if (GameData::WallCheck(UserX, UserY) == 'D' || GameData::WallCheck(UserX, UserY) == '3' || GameData::WallCheck(UserX, UserY) == '1'|| GameData::BoxWallCheck(UserX,UserY,'s') == 's')
		{
			return 0;
		}
		GameData::BoxCheck(UserX, UserY, 's');
		GameData::InData(UserX, UserY, ' ');
		GameData::InData(UserX, UserY + 1, 'p');
		UserY += 1;
	}
	else if (indata == 'd')
	{
		if (GameData::WallCheck(UserX, UserY) == 'R' || GameData::WallCheck(UserX, UserY) == '9' || GameData::WallCheck(UserX, UserY) == '3' || GameData::BoxWallCheck(UserX, UserY, 'd') == 'd')
		{
			return 0;
		}
		GameData::BoxCheck(UserX, UserY, 'd');
		GameData::InData(UserX, UserY, ' ');
		GameData::InData(UserX + 1, UserY, 'p');
		UserX += 1;
	}
	return 0;
}
