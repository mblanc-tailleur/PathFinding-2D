#include "utils.h"
#include "Cell.h"
#include "Grid.h"

void Cell::BreadthFirstSearch(v2i16 goalPos, Grid* pGrid)
{
	for (i16 i = 0; i < pGrid->h; i++)
	{
		for (i16 j = 0; j < pGrid->w; j++)
		{
			pGrid->grid[i][j].checked = 0;
			pGrid->grid[i][j].previous = nullptr;
			pGrid->grid[i][j].next = {};
		}
	}

	vector<Cell*> added;
	vector<Cell*>* pAdded = &added;

	added.push_back(this);

	i16 step = 1;

	while (added.size() > 0)
	{
		Cell* act = added[0];

		if (act->pos == goalPos)
		{
			Cell* current = act;

			while (current->pos != pos)
			{
				current->checked = 2;
				current = current->previous;
			}

			current->checked = 2;
		}

		else
		{
			act->checked = 1;
			added.erase(added.begin());
		}

		if (CheckAdjacentCells(i16(act->pos.x - step), act->pos.y, pAdded, pGrid) == true)
		{
			added.push_back(&pGrid->grid[i16(act->pos.x - step)][act->pos.y]);
			act->next.push_back(&pGrid->grid[i16(act->pos.x - step)][act->pos.y]);
		}

		if (CheckAdjacentCells(i16(act->pos.x + step), act->pos.y, pAdded, pGrid) == true)
		{
			added.push_back(&pGrid->grid[i16(act->pos.x + step)][act->pos.y]);
			act->next.push_back(&pGrid->grid[i16(act->pos.x + step)][act->pos.y]);
		}

		if (CheckAdjacentCells(act->pos.x, i16(act->pos.y - step), pAdded, pGrid) == true)
		{
			added.push_back(&pGrid->grid[act->pos.x][i16(act->pos.y - step)]);
			act->next.push_back(&pGrid->grid[act->pos.x][i16(act->pos.y - step)]);
		}

		if (CheckAdjacentCells(act->pos.x, i16(act->pos.y + step), pAdded, pGrid) == true)
		{
			added.push_back(&pGrid->grid[act->pos.x][i16(act->pos.y + step)]);
			act->next.push_back(&pGrid->grid[act->pos.x][i16(act->pos.y + step)]);
		}

		for (i16 k = 1; k < act->next.size(); k++)
		{
			act->next[k]->previous = act;
		}
	}
}

bool Cell::CheckAdjacentCells(i16 x, i16 y, vector<Cell*>* pAdded, Grid* pGrid)
{
	if (IsCellInBounds(x, y, pGrid) == true)
	{
		if (&pGrid->grid[x][y].val == 0)
		{
			if (IsCellInVector(&pGrid->grid[x][y], pAdded) == false)
			{
				if (pGrid->grid[x][y].checked == 0)
				{
					return true;
				}
			}
		}
	}

	return false;
}

bool Cell::IsCellInBounds(i16 x, i16 y, Grid* pGrid)
{
	if (((x < 0) or (x >= pGrid->w)) or ((y < 0) or (y >= pGrid->h)))
	{
		return false;
	}

	return true;
}

bool Cell::IsCellInVector(Cell* pCell, vector<Cell*>* pVect)
{
	for (i16 i = 0; i < pVect->size(); i++)
	{
		if ((*pVect)[i]->pos == pCell->pos)
		{
			return true;
		}
	}

	return false;
}
