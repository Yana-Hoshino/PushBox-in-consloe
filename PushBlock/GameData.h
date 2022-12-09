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
	static int WinCheck();
	static std::string FindPlayer();
	static std::string FindBox(int Num);
	static std::string FindGoal(int Num);
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
						{"###################"}
					};
};

