#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <windows.h>
#include <thread>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
#define MSIZE 19
struct aiset {
	int maxdepth;
	int firstweight;
	int secondweight;
	int threeweight;
	int fourweight;
	int tfweight;
	int maxtime;
};
struct setting {
	int listnum;
	bool debug;
	int time;
	int size;
	aiset ai;
};
struct logogame {
	int aistone;
	int manystone[2];
	double fulltime[2];
	int aiwin;
	int aitime;
	int stonelist[MSIZE*MSIZE][3];
	int stonelcnt;
};
int addpoint(int* stone, int* point);
int check_rule(int ptx, int pty, int omap[MSIZE + 2][MSIZE + 2][4]);
void get_st_arr();
void resetpoint();
extern vector<logogame> gamefull;
extern logogame insertlog;
extern fstream gameout;
extern fstream out;
extern setting gameset;
extern int map[MSIZE + 2][MSIZE + 2][4];
extern int stone_pos[126][11];
extern int point_pos[126][11];
extern bool turn, pvp, ckturn, endchk, waitchk;
extern int i, j, k, l;