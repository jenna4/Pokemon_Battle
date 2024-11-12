#ifndef MOVE_HPP
#define MOVE_HPP
#include <iostream>
#include <string> 
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;



class move {
	// TODO
private:
		string name;
		string type;
		int damage;
		int num_uses;	

public: 
		/*********************************************************************
		** Function: move()
		** Description: The default constructor for the move class.
		** Parameters: none 
		** Pre-Conditions: the move class needs to be defined 
		** Post-Conditions: A move object is created with default values.
		*********************************************************************/ 
		// default 
		move();

		/*********************************************************************
		** Function: move(string mname, string mtype, int damage, int num_uses)
		** Description: The non default constructor for the move class
		** Parameters: string mname, string mtype, int damage, int num_uses
		** Pre-Conditions: the move class needs to be defined 
		** Post-Conditions: a move object is created with the name, type, and number of uses set to the values provided by user.
		*********************************************************************/ 
		//non default 
		move(string mname, string mtype, int damage, int num_uses);

		/*********************************************************************
		** Function: set_name()
		** Description: sets the name of the move object to the specified string value 
		** Parameters: const string& n
		** Pre-Conditions: A move object must exist
		** Post-Conditions: the name of the move object is updated to value passed through parameter 
		*********************************************************************/ 
		void set_name(const string& n);

		/*********************************************************************
		** Function: settype()
		** Description: sets the type of the move object to the specified string value
		** Parameters: const string& t
		** Pre-Conditions: a move object must exist 
		** Post-Conditions: the type of the mvoe object is updated 
		*********************************************************************/ 
		void settype(const string& t);

		/*********************************************************************
		** Function: create_move()
		** Description: initializes the attributes of the move object with provided values
		** Parameters: string name, string type, int dmg, int uses
		** Pre-Conditions: a move object exist
		** Post-Conditions: the move object will have its attributes set to the values provided by parameters
		*********************************************************************/ 
		void create_move(string name, string type, int dmg, int uses);

		/*********************************************************************
		** Function: has_uses
		** Description: checks if the move still has uses 
		** Parameters: none
		** Pre-Conditions: a move object must exist and be initalized 
		** Post-Conditions: returns a boolen indicating if the move has uses left or not 
		*********************************************************************/ 
		bool has_uses() const;

		/*********************************************************************
		** Function: use_move
		** Description: if there are still remianing uses for a move, it decreases the num of uses by 1 when move is used 
		** Parameters:  none 
		** Pre-Conditions: a move object must exist and be initialized 
		** Post-Conditions: decreases the number of uses for the certain move 
		*********************************************************************/ 
		void use_move();

		/*********************************************************************
		** Function: get_name()
		** Description: returns the name of the move 
		** Parameters: none
		** Pre-Conditions: a move object must exist and be initialized 
		** Post-Conditions: returns the name of the move as a string 
		*********************************************************************/ 
		string get_name() const;

		/*********************************************************************
		** Function: getdamage()
		** Description: returns the damage of the move
		** Parameters: none
		** Pre-Conditions: a move object must exist and be initialized 
		** Post-Conditions: returns the damage of the move as a int
		*********************************************************************/ 
		int getdamage() const;

		/*********************************************************************
		** Function: get_remaining_numuses()
		** Description: returns the remaining number of uses for the move
		** Parameters: none
		** Pre-Conditions: a move object must exist and be initialized
		** Post-Conditions: returns the remaining number of uses for the move as an int
		*********************************************************************/ 
		int get_remaining_numuses() const;

		/*********************************************************************
		** Function: gettype()
		** Description: returns the type of the move
		** Parameters: none 
		** Pre-Conditions: a move object must exist and be initialized 
		** Post-Conditions: returns the type of the move as an string 
		*********************************************************************/ 
		string gettype();

		/*********************************************************************
		** Function: type_interaction()
		** Description: calculates the effectiveness of a move's type against the opponent pokemon move type
		** Parameters: string& oppokemon
		** Pre-Conditions: a move object has to exist 
		** Post-Conditions: returns a double based on the types of move
		*********************************************************************/ 
		double type_interaction(string& oppokemon) const;

		/*********************************************************************
		** Function: display_move()
		** Description: displays the name of the move with the number of uses remianing for the move 
		** Parameters: none
		** Pre-Conditions: a move object must exist 
		** Post-Conditions: prints the name and the number of remining uses of a move
		*********************************************************************/ 
		void display_moves();
};

#endif
