#pragma once
#include "utils.cpp"

class Grid
{
	public:
		void Draw();
		void push_back(vector<int32> newVect);

		vector<vector<int32>> grid;

		/*
		//si int32 == 0, case vide
		//si int32 == 1, mur
		*/
};

