#pragma once
#include <vector>
#include <iostream>

using namespace std;

enum BOARD {
	EMPTY,
	KNIGHT
};

class GRID {
public:
	vector<vector<BOARD>> grid;
	int numOfKnights;
};

