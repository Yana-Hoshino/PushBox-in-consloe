#pragma once
#include <string>
class GameData
{
public:
	static int InData(int x, int y, char IN);
	static int OutData();
	static char WallCheck(int x, int y);
	static int BoxCheck(int x, int y, char point);
	static char BoxWallCheck(int x, int y, char point);
	static std::string TwoBoxCheck(int x, int y, char point);
private:
	const static int mapsizeX = 20;
	const static int mapsizeY = 10;
	char _map[mapsizeY][mapsizeX] = 
					{	{"###################"},
						{"#    p            #"},
						{"# oo              #"},
						{"#                 #"},
						{"#                 #"},
						{"#                 #"},
						{"#                 #"},
						{"#                 #"},
						{"###################"}
					};
};

