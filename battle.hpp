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
	** Function:
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/ 
	//constructor 
	battle();

	/*********************************************************************
	** Function:
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/ 
	battle(pokemon* p1, pokemon* p2);

	/*********************************************************************
	** Function:
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/ 
	~battle();

	/*********************************************************************
	** Function:
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/ 
	int calc_damage(pokemon* attack, pokemon* defend, int move_index);

	/*********************************************************************
	** Function:
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/ 
	void display_status() const; 

	/*********************************************************************
	** Function:
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/ 
	void set_up_pokemon(int choice1, int choice2);

	/*********************************************************************
	** Function:
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/ 
	void who_wins();

	/*********************************************************************
	** Function:
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/ 
	void try_heal(pokemon* healer);

	/*********************************************************************
	** Function:
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/ 
	void perform_attack(pokemon* attacker, pokemon* defender);

	/*********************************************************************
	** Function:
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/ 
	void start_battle();

	/*********************************************************************
	** Function:
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/ 
	bool done_battle() const;

};

#endif
