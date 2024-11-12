#ifndef BATTLE_HPP
#define BATTLE_HPP
#include "pokemon.hpp"
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class battle {

private:
	pokemon* pokemon1;
	pokemon* pokemon2;
	int turn;

public:
	/*********************************************************************
	** Function: battle()
	** Description: initializes a battle object with default values 
	** Parameters: none
	** Pre-Conditions: class needs to exist
	** Post-Conditions: a battle object is created with default values 
	*********************************************************************/ 
	//constructor 
	battle();

	/*********************************************************************
	** Function: battle(pokemon* p1, pokemon* p2)
	** Description: initializes a battle object with two given pokemon pointers
	** Parameters: pokemon* p1, pokemon* p2
	** Pre-Conditions: two pointers must exist
	** Post-Conditions: a battle object is created with p1 and p2 
	*********************************************************************/ 
	battle(pokemon* p1, pokemon* p2);

	/*********************************************************************
	** Function: ~battle()
	** Description: destructor for the battle class
	** Parameters: none
	** Pre-Conditions: pointer that points to dynamically allocated pokemon object
	** Post-Conditions: frees memory allocated for pokemon objects
	*********************************************************************/ 
	~battle();

	/*********************************************************************
	** Function: int calc_damage(pokemon* attack, pokemon* defend, int move_index)
	** Description: calculates the damage dealt by an attacking pokemon to the defending one
	** Parameters: pokemon* attack, pokemon* defend, int move_index
	** Pre-Conditions: valid pokemon pointers and an intmust exist
	** Post-Conditions: returns an integer representing the total damage the defender will take
	*********************************************************************/ 
	int calc_damage(pokemon* attack, pokemon* defend, int move_index);

	/*********************************************************************
	** Function: void display_status() const
	** Description: displays current hp over starting hp
	** Parameters: none
	** Pre-Conditions: a pokemon object must exist
	** Post-Conditions: prints both pokemon's hps
	*********************************************************************/ 
	void display_status() const; 

	/*********************************************************************
	** Function: void set_up_pokemon(int choice1, int choice2)
	** Description: initializes two pokemon objects based on user choice and creates pokemon 
	** Parameters: int choice1, int choice2
	** Pre-Conditions: two ints must exist 
	** Post-Conditions: allocates memory for pokemons and initializes them with specified pokemon
	*********************************************************************/ 
	void set_up_pokemon(int choice1, int choice2);

	/*********************************************************************
	** Function: who_wins()
	** Description: determines the winner of the battle by checking pokemon's remaining HP
	** Parameters: none
	** Pre-Conditions: pokemon objects must exist
	** Post-Conditions: prints who fainted and who won
	*********************************************************************/ 
	void who_wins();

	/*********************************************************************
	** Function: try_heal(pokemon* healer)
	** Description: tries to heal the pokemon, if no heals user is prompted to choose another option
	** Parameters: pokemon* healer
	** Pre-Conditions: a pokemon pointer needs to exist
	** Post-Conditions: if healing successful pokemon's hp goes up 10,if not user is reprompted 
	*********************************************************************/ 
	void try_heal(pokemon* healer);

	/*********************************************************************
	** Function: perform_attack(pokemon* attacker, pokemon* defender)
	** Description: allows attacking pokemon to select a move to use against a defending pokemon
	** Parameters: pokemon* attacker, pokemon* defender
	** Pre-Conditions: two pokemon pointers must exist 
	** Post-Conditions: defender pokemon's hp is reduced based on calculated damage
	*********************************************************************/ 
	void perform_attack(pokemon* attacker, pokemon* defender);

	/*********************************************************************
	** Function: start_battle()
	** Description: controls the turn based battle 
	** Parameters: none
	** Pre-Conditions: pokemon objects must exist
	** Post-Conditions: one pokemon faints and the other wins 
	*********************************************************************/ 
	void start_battle();

	/*********************************************************************
	** Function: done_battle()
	** Description: checks if the battle is still going
	** Parameters: none
	** Pre-Conditions: pokemon object must exist
	** Post-Conditions: returns a bool based on pokemon's hp
	*********************************************************************/ 
	bool done_battle() const;

};

#endif
