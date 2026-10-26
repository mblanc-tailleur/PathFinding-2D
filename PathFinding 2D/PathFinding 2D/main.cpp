#include "Grid.h"

int main()
{
	Grid G;

	for (int16 a = 0; a < 10; a++)
	{
		vector<int32> v;

		for (int16 b = 0; b < 10; b++)
		{
			int32 i = (a + b) % 2;

			v.push_back(i);
		}

		G.push_back(v);
	}

	G.Draw();
}