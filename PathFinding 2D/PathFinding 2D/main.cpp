#include "utils.h"
#include "Cell.h"
#include "Grid.h"

std::random_device rd;
std::mt19937 gen(rd());

void MakeGrid(Grid* pGrid)
{
	std::uniform_int_distribution<i16> dis(0, 4);

	for (i16 a = 0; a < pGrid->h; a++)
	{
		vector<Cell> v;

		for (i16 b = 0; b < pGrid->w; b++)
		{
			Cell c;
			c.val = dis(gen);

			if (c.val < 4)
			{
				c.val = 0;
			}

			else
			{
				c.val = 1;
			}

			c.pos = { a, b };

			v.push_back(c);
		}

		pGrid->push_back(v);
	}
}

int main()
{
	Grid G;
	G.w = 12;
	G.h = 12;

	MakeGrid(&G);

	std::uniform_int_distribution<i16> sizeX(0, G.w - 1);
	std::uniform_int_distribution<i16> sizeY(0, G.h - 1);

	v2i16 startPos = { sizeY(gen), sizeX(gen) };

	while (G.GetValue(startPos) != 0)
	{
		startPos = { sizeY(gen), sizeX(gen) };
	}

	v2i16 goalPos = { sizeY(gen), sizeX(gen) };

	while ((G.GetValue(goalPos) != 0) or (goalPos == startPos))
	{
		goalPos = { sizeY(gen), sizeX(gen) };
	}


	startPos;
	goalPos;

	vector<Cell> added = {};
	vector<Cell> explored = {};

	G.start = startPos;
	G.end = goalPos;

	G.Draw();

	G.grid[startPos.x][startPos.y].BreadthFirstSearch(goalPos, &G);

	G.Draw();
}