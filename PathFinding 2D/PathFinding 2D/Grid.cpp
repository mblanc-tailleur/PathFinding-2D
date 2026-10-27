#include "utils.h"
#include "Grid.h"
#include "Cell.h"

void Grid::Draw()
{
	system("cls");

	for (i16 a = 0; a < h; a++)
	{
		for (i16 b = 0; b < w; b++)
		{
			cout << "+---";
		}

		cout << "+" << endl;

		for (i16 b = 0; b < w; b++)
		{
			cout << "|";

			if (grid[a][b].val == 0)
			{
				if (grid[a][b].checked == 2)
				{
					cout << GREENBACKGROUND;
				}

				if ((a == start.x) and (b == start.y))
				{
					cout << REDWRITE << "STA" << WHITEWRITE;
				}

				else if ((a == end.x) and (b == end.y))
				{
					cout << BLUEWRITE << "END" << WHITEWRITE;
				}

				else
				{
					cout << "   ";
				}

				cout << BLACKBACKGROUND;
			}

			else if (grid[a][b].val == 1)
			{
				cout << "XXX";
			}
		}

		cout << "|" << endl;
	}

	for (i16 b = 0; b < w; b++)
	{
		cout << "+---";
	}

	cout << "+";
}

i16 Grid::GetValue(v2i16 pos)
{
	return grid[pos.x][pos.y].val;
}

void Grid::push_back(vector<Cell> newVect)
{
	grid.push_back(newVect);
}
