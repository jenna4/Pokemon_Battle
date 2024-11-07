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
		// default 
		move();

		//non default 
		move(string mname, string mtype, int damage, int num_uses);

		void set_name(const string& n);
		void settype(const string& t);
		void move::use_move();
		// void setdamage(int d);
		// void setnumuses(int u);
		// string getname() const;
		// string gettype() const;
		int getdamage() const;
		int move::get_remaining_numuses() const;
		double move::type_interaction(string& oppokemon) const;
		void display_moves();
};

#endif
