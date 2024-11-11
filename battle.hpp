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
	//constructor 
	battle();
	battle(pokemon* p1, pokemon* p2);
	~battle();
	int calc_damage(pokemon* attack, pokemon* defend, int move_index);
	void display_status() const; 
	void set_up_pokemon(int choice1, int choice2);
	void who_wins();
	void try_heal(pokemon* healer);
	void perform_attack(pokemon* attacker, pokemon* defender);
	void start_battle();
	bool done_battle() const;
	void switch_turns(pokemon* attacker, pokemon* defender);
	// int test_dmove();
	//{display stats}
	//if(turn=1) {
	// calc damaage set turn = 2}
	// else if (turn = 2) {
	// calc damage set tunr =2}    // switches players turns 
	// until get winner 

	// calc damage function
	//display stats
	// declar winmner func

	// where would heal go? moves??
};

#endif
