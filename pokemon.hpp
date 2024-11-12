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
	int heal_remain;
	move* move_arr; 
	int num_moves;

	public: 

	/*********************************************************************
	** Function:pokemon()
	** Description: the default constructor for the pokemon class. initializes a pokemon object with default values
	** Parameters: none
	** Pre-Conditions: class be created
	** Post-Conditions: creates pokemon object that has default vlaues
	*********************************************************************/ 
	pokemon();

	/*********************************************************************
	** Function: pokemon()
	** Description: the nondefault constructor initializes a pokemon object with the provided value
	** Parameters: const string& name, const string& type, Stats& stats, const int num_moves
	** Pre-Conditions: class needs to be created  
	** Post-Conditions: the pokemon object is initialized with specified values
	*********************************************************************/ 
	pokemon (const string& name, const string& type, Stats& stats, const int num_moves);

	/*********************************************************************
	** Function: set_move()
	** Description: assigns a move object to a specific position in the pokemon's move array
	** Parameters: int indexmovearr, move& m
	** Pre-Conditions: class be created 
	** Post-Conditions: the move object is assigned to the corresponding position in the move array
	*********************************************************************/ 
	void set_move(int indexmovearr, move& m);

	/*********************************************************************
	** Function: create_charmander()
	** Description: creates a charmander pokemon by setting attributes. initializes the pokemon with two moves
	** Parameters: none
	** Pre-Conditions: the pokemon object needs to exist
	** Post-Conditions: the charmander pokemon is created with specific attributes
	*********************************************************************/ 
	void create_charmander();

	/*********************************************************************
	** Function: create_squirtle()
	** Description: creates a squirtle pokemon by setting attributes. initializes the pokemon with two moves 
	** Parameters: none 
	** Pre-Conditions: the pokemon object needs to exist
	** Post-Conditions: the squirtle pokemon is created with specific attributes 
	*********************************************************************/ 
	void create_squirtle();

	/*********************************************************************
	** Function: create_bulbasaur()
	** Description: creates a bulbasaur pokemon by setting attributes. initializes the pokemon with two moves 
	** Parameters: none
	** Pre-Conditions: pokemon object must exist
	** Post-Conditions: the bulbasaur pokemon is created with specific attributes 
	*********************************************************************/ 
	void create_bulbasaur();

	/*********************************************************************
	** Function: create_pidgey
	** Description: creates a pidgey pokemon by setting attributes. initializes the pokemon with two moves 
	** Parameters: none
	** Pre-Conditions: pokemon object must exist 
	** Post-Conditions: the pidgey pokemon is created with specific attributes
	*********************************************************************/ 
	void create_pidgey();

	/*********************************************************************
	** Function: get_move()
	** Description: allows access to a move object
	** Parameters: int index
	** Pre-Conditions: move object must exist
	** Post-Conditions: returns a reference to the move at the specified index
	*********************************************************************/ 
	move& get_move(int index);

	/*********************************************************************
	** Function: get_hp()
	** Description: retrieves the current HP of the pokemon. allows access to pokemon's health status 
	** Parameters: none
	** Pre-Conditions: pokemon object must exist and have hp member initialized
	** Post-Conditions: return current value of pokemon's hp
	*********************************************************************/ 
	int get_hp();

	/*********************************************************************
	** Function: get_name()
	** Description: allows access to the name of pokemon 
	** Parameters: none
	** Pre-Conditions: pokemon object must exist 
	** Post-Conditions: returns the name of the pokemon
	*********************************************************************/ 
	string get_name();

	/*********************************************************************
	** Function: get_type()
	** Description: allows access to the type of pokemon
	** Parameters: none
	** Pre-Conditions: pokemon object must exist
	** Post-Conditions: returns the type of the pokemon
	*********************************************************************/ 
	string get_type();

	/*********************************************************************
	** Function: get_starthp()
	** Description: allows access to the starting hp of pokemon
	** Parameters: none
	** Pre-Conditions: pokemon object must exist
	** Post-Conditions: returns the starting hp of the pokemon as an int
	*********************************************************************/ 
	int get_starthp();

	/*********************************************************************
	** Function: take_damage()
	** Description: reduces the pokemon's hp by the specified damage amount 
	** Parameters: int damage
	** Pre-Conditions: pokemon object must exist
	** Post-Conditions: pokemon's hp is reduced by the specified damage amount
	*********************************************************************/ 
	void take_damage(int damage);

	/*********************************************************************
	** Function: heal()
	** Description: heals the pokemon by 10 hp, doesnt go past starting hp
	** Parameters: none
	** Pre-Conditions: pokemon object must exist
	** Post-Conditions: pokemon's hp is increased by 10, cannot exceed max hp
	*********************************************************************/ 
	void heal();

	/*********************************************************************
	** Function: died() const
	** Description: checks if the pokemon's hp is 0 or less
	** Parameters: none
	** Pre-Conditions: pokemon object must exist 
	** Post-Conditions: returns a bool
	*********************************************************************/ 
	bool died() const;

	/*********************************************************************
	** Function: ~pokemon()
	** Description: destructor for the pokemon class. frees memory
	** Parameters: none
	** Pre-Conditions: memory must exist
	** Post-Conditions: the memory for move_arr is deallocated and the pointer is set to nullptr
	*********************************************************************/ 
	~pokemon(); 

	/*********************************************************************
	** Function: has_heal()
	** Description: checks if the pokemon has any heal potions remianing
	** Parameters: none
	** Pre-Conditions: pokemon must exist
	** Post-Conditions: returns a bool indicating whether the pokemon has healing potions left
	*********************************************************************/ 
	bool has_heal() const;

	/*********************************************************************
	** Function: use_heal
	** Description: decreases the number of healing potions everytime used 
	** Parameters: none
	** Pre-Conditions: pokemon must exist
	** Post-Conditions: decreases the number of healing potions 
	*********************************************************************/ 
	void use_heal();

	/*********************************************************************
	** Function: get_attack()
	** Description: retrieves the attack stat of the pokemon
	** Parameters: none
	** Pre-Conditions: stats must be initalized 
	** Post-Conditions: returns the attack value of the pokemon
	*********************************************************************/ 
	int get_attack();

	/*********************************************************************
	** Function: get_defense()
	** Description: retrieves the defense stat of the pokemon
	** Parameters: none
	** Pre-Conditions: stats must be initalized  
	** Post-Conditions: returns the defense value of the pokemon
	*********************************************************************/ 
	int get_defense();

	/*********************************************************************
	** Function: pokemon& operator=(const pokemon &other)
	** Description: assignment operator 
	** Parameters: const pokemon &other
	** Pre-Conditions: other object must be properly initialized 
	** Post-Conditions: current objects is assigned the values from the other object
	*********************************************************************/ 
	pokemon& operator=(const pokemon &other); 

	/*********************************************************************
	** Function: pokemon()
	** Description: copy constructor for the pokemon class
	** Parameters: const pokemon &other
	** Pre-Conditions: other object must be initalized properly
	** Post-Conditions: a new pokemon object is created as a deep copy of other
	*********************************************************************/ 
	pokemon(const pokemon &other);

	/*********************************************************************
	** Function: prompt_move_heal()
	** Description: prompts the user if they want to use a move or heal, with error handling 
	** Parameters: none
	** Pre-Conditions: user must exist 
	** Post-Conditions: returns the choice as an int 
	*********************************************************************/ 
	int prompt_move_heal();

	/*********************************************************************
	** Function: d_move()
	** Description: displays the list of moves available to the pokemon 
	** Parameters: none
	** Pre-Conditions: the move_arr must be initialized
	** Post-Conditions: prints the move's name and remianing uses
	*********************************************************************/ 
	void d_move();

	/*********************************************************************
	** Function: prompt_move()
	** Description: prompts the user which move they want to use
	** Parameters: none
	** Pre-Conditions: user must exist 
	** Post-Conditions: returns user's choice as an int
	*********************************************************************/ 
	int prompt_move();
};

#endif
