#pragma once

class Cell;

class Grid
{
	public:
		i16 w;
		i16 h;

		v2i16 start;
		v2i16 end;

		void Draw();
		i16 GetValue(v2i16 pos);
		void push_back(vector<Cell> newVect);

		vector<vector<Cell>> grid;

		/*
		si i16 == 0, case vide
		si i16 == 1, mur
		*/
};

