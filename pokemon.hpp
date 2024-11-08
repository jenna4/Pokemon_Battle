#ifndef POKEMON_HPP
#define POKEMON_HPP
#include "move.hpp"
#include <iostream>
#include <string> 
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
// using namespace std;

//creat sruct for stats
struct Stats {
	int attack;
	int defense;
	int starting_hp;
};

class pokemon {
	string name;
	string type;
	Stats stats;
	int hp;
	move* move_arr; 
	int num_moves;

	public: 
	pokemon(string& name, string& type, Stats& stats, string& move_type, int damage, int uses);
	void set_move(int indexmovearr, move& m);
	~pokemon(); 
	pokemon& operator=(const pokemon &other); 
	pokemon(const pokemon &other);
	int prompt_move_heal();
	string prompt_move();
};

#endif
