#include "Grid.h"

void Grid::Draw()
{
	system("cls");

	for (int16 a = 0; a < grid.size(); a++)
	{
		for (int16 b = 0; b < grid[a].size(); b++)
		{
			cout << "+---";
		}

		cout << "+";

		for (int16 b = 0; b < grid[a].size(); b++)
		{
			cout << "|";

			if (grid[a][b] == 0)
			{
				cout << "   ";
			}

			else if (grid[a][b] == 1)
			{
				cout << "XXX";
			}
		}

		cout << "|";

		cout << endl;
	}

	for (int16 b = 0; b < grid[-1].size(); b++)
	{
		cout << "+---";
	}

	cout << "+";
}

void Grid::push_back(vector<int32> newVect)
{
	grid.push_back(newVect);
}
