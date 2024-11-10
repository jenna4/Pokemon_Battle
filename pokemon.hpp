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
	pokemon();
	pokemon (const string& name, const string& type, Stats& stats, const int num_moves);
	void set_move(int indexmovearr, move& m);
	void create_charmander();
	void create_squirtle();
	void create_bulbasaur();
	void create_pidgey();
	int get_hp();
	string get_name();
	void heal();
	bool died() const;
	~pokemon(); 
	int get_attack();
	pokemon& operator=(const pokemon &other); 
	pokemon(const pokemon &other);
	int prompt_move_heal();
	void d_move();
	int prompt_move();
};

#endif
