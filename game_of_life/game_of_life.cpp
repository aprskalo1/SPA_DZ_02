#include <iostream>
#include <ctime>
#include "game_of_life.h"
using namespace std;

game_of_life::game_of_life()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = slucajna_vrijednost25();
		}
	}
}

bool game_of_life::slucajna_vrijednost()
{
	return rand() % (1 - 0 + 1) + 0;
}

bool game_of_life::slucajna_vrijednost25()
{
	int x = slucajna_vrijednost();
	x = x << 1;
	x = x ^ slucajna_vrijednost();
	return (x > 0) ? 0 : 1;
}

void game_of_life::kopiraj_arr()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			int hv = 0;

			if (j < 39) hv += _generacija[i][j + 1];
			if (j > 0) hv += _generacija[i][j - 1];

			if (i < 19) hv += _generacija[i + 1][j];
			if (i > 0) hv += _generacija[i - 1][j];

			if (j < 39 && i < 19) hv += _generacija[i + 1][j + 1];
			if (j > 0 && i < 19) hv += _generacija[i + 1][j - 1];

			if (i > 0 && j < 39) hv += _generacija[i - 1][j + 1];
			if (i > 0 && j > 0) hv += _generacija[i - 1][j - 1];

			//cout << hv << " ";

			if (_generacija[i][j] == 1)
			{
				if (hv == 2 || hv == 3)
				{
					_sljedeca_generacija[i][j] = 1;
				}
				else
				{
					_sljedeca_generacija[i][j] = 0;
				}

				if (hv < 2 || hv > 3)
				{
					_sljedeca_generacija[i][j] = 0;
				}
				else
				{
					_sljedeca_generacija[i][j] = 1;
				}
			}

			if (_generacija[i][j] == 0)
			{
				if (hv == 3)
				{
					_sljedeca_generacija[i][j] = 1;
				}
				else
				{
					_sljedeca_generacija[i][j] = 0;
				}
			}
		}
		//cout << endl;
	}
	kopiraj_arr();
}

void game_of_life::iscrtaj()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (_generacija[i][j] == 0) cout << "-";
			if (_generacija[i][j] == 1) cout << "*";
		}
		cout << endl;
	}
}
