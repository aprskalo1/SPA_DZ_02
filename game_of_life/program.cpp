#include <iostream>
#include <string>
#include <fstream>
#include "game_of_life.h"
#include <ctime>
using namespace std;

int main() {
	srand(time(nullptr));
	game_of_life the_game;

	bool dalje;
	do {
		system("cls");
		the_game.iscrtaj();
		the_game.sljedeca_generacija();

		cout << "Dalje (1/0): ";
		cin >> dalje;
	} while (dalje);

	return 0;
}