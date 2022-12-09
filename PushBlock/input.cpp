#include "input.h"
#include "GameData.h"
#include <iostream>
char indata;
int UserX = (int)GameData::FindPlayer('x');
int UserY = (int)GameData::FindPlayer('y');
int UserX_Backup = UserX;
int UserY_Backup = UserY;

int input::plloinit()
{
	UserX = (int)GameData::FindPlayer('x');
	UserY = (int)GameData::FindPlayer('y');
	UserX_Backup = UserX;
	UserY_Backup = UserY;
	return 0;
}
int input::UserIn()
{
	std::cin >> indata;
	if (indata == 'w') 
	{
		if (GameData::WallCheck(UserX, UserY,indata) == 1 || GameData::BoxWallCheck(UserX, UserY, 'w') == 'w' || GameData::TwoBoxCheck(UserX, UserY, 'w') == "oou")
		{
			return 0;
		}
		GameData::BoxCheck(UserX, UserY, 'w');
		GameData::InData(UserX, UserY, ' ');
		GameData::InData(UserX, UserY - 1, 'p');
		UserY -= 1;
		GameData::PlayerInGoalCheck(UserX, UserY);
	}
	else if (indata == 'a')
	{
		if (GameData::WallCheck(UserX, UserY,indata) == 1 || GameData::BoxWallCheck(UserX, UserY, 'a') == 'a' || GameData::TwoBoxCheck(UserX, UserY, 'a') == "ool")
		{
			return 0;
		}
		GameData::BoxCheck(UserX, UserY, 'a');
		GameData::InData(UserX, UserY, ' ');
		GameData::InData(UserX - 1, UserY, 'p');
		UserX -= 1;
		GameData::PlayerInGoalCheck(UserX, UserY);
	}
	else if (indata == 's')
	{
		if (GameData::WallCheck(UserX, UserY,indata) == 1 || GameData::BoxWallCheck(UserX,UserY,'s') == 's' || GameData::TwoBoxCheck(UserX, UserY, 's') == "ood")
		{
			return 0;
		}
		GameData::BoxCheck(UserX, UserY, 's');
		GameData::InData(UserX, UserY, ' ');
		GameData::InData(UserX, UserY + 1, 'p');
		UserY += 1;
		GameData::PlayerInGoalCheck(UserX, UserY);
	}
	else if (indata == 'd')
	{
		if (GameData::WallCheck(UserX, UserY,indata) == 1 || GameData::BoxWallCheck(UserX, UserY, 'd') == 'd' || GameData::TwoBoxCheck(UserX, UserY, 'd') == "oor")
		{
			return 0;
		}
		GameData::BoxCheck(UserX, UserY, 'd');
		GameData::InData(UserX, UserY, ' ');
		GameData::InData(UserX + 1, UserY, 'p');
		UserX += 1;
		GameData::PlayerInGoalCheck(UserX, UserY);
	}
	else if (indata == 'r')
	{
		GameData::InData(UserX, UserY, ' ');
		UserX = UserX_Backup;
		UserY = UserY_Backup;
		GameData::InData(UserX, UserY, 'p');
		GameData::reset();
	}
	GameData::ClearCheck();
	GameData::GoalPointRebuild();
	return 0;
}
