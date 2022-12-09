#include "GameData.h"
#include "Maps.h"
#include "input.h"
#include <iostream>
#include <sstream>
GameData MainData;
Maps map;
int MapNum = 0;
int Boxx1 = GameData::FindBox(1,'x');
int Boxy1 = GameData::FindBox(1,'y');
int Boxx2 = GameData::FindBox(2,'x');
int Boxy2 = GameData::FindBox(2,'y');
int Boxx1_Backup = Boxx1;
int Boxy1_Backup = Boxy1;
int Boxx2_Backup = Boxx2;
int Boxy2_Backup = Boxy2;
int goal1x = GameData::FindGoal(1, 'x');
int goal1y = GameData::FindGoal(1, 'y');
int goal2x = GameData::FindGoal(2, 'x');
int goal2y = GameData::FindGoal(2, 'y');

int GameData::init() {
	Boxx1 = GameData::FindBox(1, 'x');
	Boxy1 = GameData::FindBox(1, 'y');
	Boxx2 = GameData::FindBox(2, 'x');
	Boxy2 = GameData::FindBox(2, 'y');
	Boxx1_Backup = Boxx1;
	Boxy1_Backup = Boxy1;
	Boxx2_Backup = Boxx2;
	Boxy2_Backup = Boxy2;
	goal1x = GameData::FindGoal(1, 'x');
	goal1y = GameData::FindGoal(1, 'y');
	goal2x = GameData::FindGoal(2, 'x');
	goal2y = GameData::FindGoal(2, 'y');
	 return 0;
}

int GameData::InData(int x, int y, char IN)
{
	MainData._map[y][x] = IN;
	return 0;
}

int GameData::OutData()
{
	for (int y = 0; y < mapsizeY; y++)
	{
		for (int x = 0; x < mapsizeX; x++)
		{
			std::cout << MainData._map[y][x];
		}
		std::cout << std::endl;
	}
	return 0;
}

int GameData::BoxCheck(int x, int y, char point)
{
	if (y == Boxy1 && x + 1 ==Boxx1 && point == 'd')
	{
		GameData::InData(Boxx1, Boxy1, ' ');
		GameData::InData(Boxx1 + 1, Boxy1, 'o');
		Boxx1++;
		GameData::BoxInGoalCheck(Boxx1, Boxy1);
	}
	else if (y == Boxy1 && x - 1 == Boxx1 && point == 'a')
	{
		GameData::InData(Boxx1, Boxy1, ' ');
		GameData::InData(Boxx1 - 1, Boxy1, 'o');
		Boxx1--;
		GameData::BoxInGoalCheck(Boxx1, Boxy1);
	}
	else if (y - 1 == Boxy1 && x == Boxx1 && point == 'w')
	{
		GameData::InData(Boxx1, Boxy1, ' ');
		GameData::InData(Boxx1, Boxy1 - 1, 'o');
		Boxy1--;
		GameData::BoxInGoalCheck(Boxx1, Boxy1);
	}
	else if (y + 1 == Boxy1 && x == Boxx1 && point == 's')
	{
		GameData::InData(Boxx1, Boxy1, ' ');
		GameData::InData(Boxx1, Boxy1 + 1, 'o');
		Boxy1++;
		GameData::BoxInGoalCheck(Boxx1, Boxy1);
	}
	else if (y == Boxy2 && x + 1 == Boxx2 && point == 'd')
	{
		GameData::InData(Boxx2, Boxy2, ' ');
		GameData::InData(Boxx2 + 1, Boxy2, 'o');
		Boxx2++;
		GameData::BoxInGoalCheck(Boxx2, Boxy2);
	}
	else if (y == Boxy2 && x - 1 == Boxx2 && point == 'a')
	{
		GameData::InData(Boxx2, Boxy2, ' ');
		GameData::InData(Boxx2 - 1, Boxy2, 'o');
		Boxx2--;
		GameData::BoxInGoalCheck(Boxx2, Boxy2);
	}
	else if (y - 1 == Boxy2 && x == Boxx2 && point == 'w')
	{
		GameData::InData(Boxx2, Boxy2, ' ');
		GameData::InData(Boxx2, Boxy2 - 1, 'o');
		Boxy2--;
		GameData::BoxInGoalCheck(Boxx2, Boxy2);
	}
	else if (y + 1 == Boxy2 && x == Boxx2 && point == 's')
	{
		GameData::InData(Boxx2, Boxy2, ' ');
		GameData::InData(Boxx2, Boxy2 + 1, 'o');
		Boxy2++;
		GameData::BoxInGoalCheck(Boxx2, Boxy2);
	}
	else
	{
		return 0;
	}
	return 0;
}

char GameData::WallCheck(int x, int y, char point)
{
	if (MainData._map[y][x + 1] == '#' && point == 'd')
	{
		return 1;
	}
	else if (MainData._map[y][x - 1] == '#'&& point == 'a')
	{
		return 1;
	}
	else if (MainData._map[y + 1][x] == '#' && point == 's')
	{
		return 1;
	}
	else if (MainData._map[y - 1][x] == '#' && point == 'w')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char GameData::BoxWallCheck(int x, int y, char point)
{
	if (MainData._map[y + 1][x] == 'o' && MainData._map[y + 2][x] == '#' && point == 's')
	{
		return 's';
	}
	else if (MainData._map[y - 1][x] == 'o' && MainData._map[y - 2][x] == '#' && point == 'w')
	{
		return 'w';
	}
	else if (MainData._map[y][x + 1] == 'o' && MainData._map[y][x + 2] == '#' && point == 'd')
	{
		return 'd';
	}
	else if (MainData._map[y][x - 1] == 'o' && MainData._map[y][x - 2] == '#' && point == 'a')
	{
		return 'a';
	}
	else
	{
		return 0;
	}
}

std::string GameData::TwoBoxCheck(int x, int y, char point)
{
	if (MainData._map[y + 1][x] == 'o' && MainData._map[y + 2][x] == 'o' && point == 's')
	{
		return "ood";
	}
	else if (MainData._map[y - 1][x] == 'o' && MainData._map[y - 2][x] == 'o' && point == 'w')
	{
		return "oou";
	}
	else if (MainData._map[y][x + 1] == 'o' && MainData._map[y][x + 2] == 'o' && point == 'd')
	{
		return "oor";
	}
	else if (MainData._map[y][x - 1] == 'o' && MainData._map[y][x - 2] == 'o' && point == 'a')
	{
		return "ool";
	}
	else
	{
		return "NULL";
	}
}

int GameData::PlayerInGoalCheck(int x, int y)
{
	if (x == goal1x && y == goal1y)
	{
		GameData::InData(x, y, 'P');
	}
	if (x == goal2x && y == goal2y)
	{
		GameData::InData(x, y, 'P');
	}
	return 0;
}

int GameData::BoxInGoalCheck(int x, int y)
{
	if (x == goal1x && y == goal1y)
	{
		GameData::InData(x, y, 'O');
	}
	if (x == goal2x && y == goal2y)
	{
		GameData::InData(x, y, 'O');
	}
	return 0;
}

int GameData::GoalPointRebuild()
{
	if (MainData._map[goal1y][goal1x] != 'P' && MainData._map[goal1y][goal1x] != 'O')
	{
		GameData::InData(goal1x,goal1y, '.');
	}
	if (MainData._map[goal2y][goal2x] != 'P' && MainData._map[goal2y][goal2x] != 'O')
	{
		GameData::InData(goal2x, goal2y, '.');
	}
	return 0;
}

int GameData::ClearCheck()
{
	if (MainData._map[goal1y][goal1x] == 'O' && MainData._map[goal2y][goal2x] == 'O' )
	{

		GameData::ChangeMap();
		GameData::init();
		input::plloinit();
		GameData::OutData();
	}
	return 0;
}

int GameData::isWin()
{
	if (MapNum == 3)
	{
		return 0;
	}
	return 1;
}

int GameData::reset()
{
	GameData::InData(Boxx1, Boxy1, ' ');
	GameData::InData(Boxx2, Boxy2, ' ');
	Boxx1 = Boxx1_Backup;
	Boxy1 = Boxy1_Backup;
	Boxx2 = Boxx2_Backup;
	Boxy2 = Boxy2_Backup;
	GameData::InData(Boxx1, Boxy1, 'o');
	GameData::InData(Boxx2, Boxy2, 'o');
	return 0;
}

int GameData::FindPlayer(char xy)
{
	int y = 0;
	int x = 0;
	for (y = 0; y < mapsizeY; y++)
	{
		for (x = 0; x < mapsizeX; x++)
		{
			if (MainData._map[y][x] == 'p')
			{
				break;
			}
		}
		if (MainData._map[y][x] == 'p')
		{
			break;
		}
	}
	if (xy == 'x')
		return x;
	else if (xy == 'y')
		return y;
	return 0;
}

int GameData::FindBox(int Num, char xy)
{
	int y = 0;
	int x = 0;
	for (y ; y < mapsizeY; y++)
	{
		for (x = 0; x < mapsizeX; x++)
		{
			if (MainData._map[y][x] == 'o')
			{
				break;
			}
		}
		if (MainData._map[y][x] == 'o')
		{
			break;
		}
	}
	if (Num == 2) {
	int tmp = x + 1;
	for (y ; y < mapsizeY; y++)
	{
		x = tmp;
		for (x = tmp; x < mapsizeX; x++)
		{
			if (MainData._map[y][x] == 'o')
			{
				break;
			}
		}
		tmp = 0;
		if (MainData._map[y][x] == 'o')
		{
			break;
		}
	}
	}
	if (xy == 'x')
		return x;
	else if (xy == 'y')
		return y;
	return 0;
}

int GameData::FindGoal(int Num,char xy)
{
	int y = 0;
	int x = 0;
	for (y = 0; y < mapsizeY; y++)
	{
		for (x = 0; x < mapsizeX; x++)
		{
			if (MainData._map[y][x] == '.')
			{
				break;
			}
		}
		if (MainData._map[y][x] == '.')
		{
			break;
		}
	}
	if (Num == 2) {
		int tmp = x + 1;
		for (y; y < mapsizeY; y++)
		{
			x = tmp;
			for (x = tmp; x < mapsizeX; x++)
			{
				if (MainData._map[y][x] == '.')
				{
					break;
				}
			}
			tmp = 0;
			if (MainData._map[y][x] == '.')
			{
				break;
			}
		}
	}
	if (xy == 'x')
		return x;
	else if (xy == 'y')
		return y;
	return 0;
}

int GameData::ChangeMap()
{
	MapNum++;
	if(MapNum == 1)
	for (int y = 0; y < mapsizeY; y++)
	{
		for (int x = 0; x < mapsizeX; x++)
		{
			MainData._map[y][x] = map.mp1[y][x];
		}
		std::cout << std::endl;
	}
	else if (MapNum == 2)
	for (int y = 0; y < mapsizeY; y++)
	{
		for (int x = 0; x < mapsizeX; x++)
		{
			MainData._map[y][x] = map.mp2[y][x];
		}
		std::cout << std::endl;
	}
	else if (MapNum == 3)
	for (int y = 0; y < mapsizeY; y++)
	{
		for (int x = 0; x < mapsizeX; x++)
		{
			MainData._map[y][x] = map.mp3[y][x];
		}
		std::cout << std::endl;
	}
	else if (MapNum == 4)
	for (int y = 0; y < mapsizeY; y++)
	{
		for (int x = 0; x < mapsizeX; x++)
		{
			MainData._map[y][x] = map.mp4[y][x];
		}
		std::cout << std::endl;
	}

	return 0;
}