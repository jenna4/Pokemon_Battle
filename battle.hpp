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

// public:
	//constructor 
	battle(pokemon* p1, pokemon* p2);
	//start battle function 
	void start_battle();
	bool done_battle() const;
	void switch_turns(pokemon* attacker, pokemon* defender);
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
