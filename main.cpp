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

	battle b;

	b.set_up_pokemon(trainer_1_pokemon_choice, trainer_2_pokemon_choice);
	b.start_battle();

	// TODO Use if statements to determine which pokemon was chosen by
	// each player and create respective pokemon objects with the
	// appropriate types, stats, and moves

	// TODO Create a battle object containing the two pokemon objects
	// created above, and then start the battle

}
