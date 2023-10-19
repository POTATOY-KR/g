#pragma once
#include <vector>
#include "addpoint.h"

struct node {
	int x;
	int y;
	int win = -1;
	int cp_map[21][21][4];
	int node_n = 0;
	vector<node> c_node;
};


void tree(int* a, int* b);
void get_cp_st_arr(node* n);
void no_node(int* a, int* b);