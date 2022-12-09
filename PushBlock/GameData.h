#pragma once
#include <string>
class GameData
{
public:
	static int InData(int x, int y, char IN);
	static int OutData();
	static int reset();
	static char WallCheck(int x, int y, char point);
	static int BoxCheck(int x, int y, char point);
	static char BoxWallCheck(int x, int y, char point);
	static std::string TwoBoxCheck(int x, int y, char point);
	static int PlayerInGoalCheck(int x, int y);
	static int BoxInGoalCheck(int x, int y);
	static int GoalPointRebuild();
	static int ClearCheck();
	static int FindPlayer(char xy);
	static int FindBox(int Num, char xy);
	static int FindGoal(int Num, char xy);
	static int ChangeMap(int MapNum);
	static int init();
	static int isWin();
private:
	const static int mapsizeX = 20;
	const static int mapsizeY = 10;
	char _map[mapsizeY][mapsizeX] = 
					{	{"###################"},
		                {"#                 #"},
						{"# oo p            #"},
						{"#   ##  #         #"},
						{"# #   ..###########"},
						{"#   ##            #"},
						{"#                 #"},
						{"#                 #"},
						{"#                 #"},
						{"###################"},
					};
};

