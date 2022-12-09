#include "input.h"
#include "GameData.h"
#include <iostream>
char indata;
int UserX = (int)GameData::FindPlayer()[0] - '0';
int UserY = (int)GameData::FindPlayer()[1] - '0';
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
		UserX = 5;
		UserY = 2;
		GameData::InData(UserX, UserY, 'p');
		GameData::reset();
	}
	GameData::GoalPointRebuild();
	return 0;
}
