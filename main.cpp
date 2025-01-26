/******************************************************
** Program: main.cpp
** Author: Jenna Rivera
** Date: 11/11/2024
** Description: implement a simplified version of a single pokemon battle where each
** trainer has a single pokemon.
** Input: pokemon for trainer 1, pokemon for trainer 2, move or heal, what move
** Output: take turns till one of the pokemons reach 0 hp
******************************************************/
#include <iostream>
#include <string> 
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
#include "startup.hpp"
#include "battle.hpp"


int main() {
	int trainer_1_pokemon_choice = prompt_first_pokemon();
	int trainer_2_pokemon_choice = prompt_second_pokemon(
		trainer_1_pokemon_choice
	);

	int t1_backup = prompt_pokemon1_backup(trainer_1_pokemon_choice, trainer_1_pokemon_choice);
	int t2_backup = prompt_pokemon2_backup(trainer_2_pokemon_choice, trainer_1_pokemon_choice, t1_backup);

	battle b;

	b.set_up_pokemon(trainer_1_pokemon_choice, trainer_2_pokemon_choice, t1_backup, t2_backup);
	b.start_battle();
}
