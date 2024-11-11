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
		void create_move(string name, string type, int dmg, int uses);
		bool has_uses() const;
		void use_move();
		// void setdamage(int d);
		// void setnumuses(int u);
		// string getname() const;
		// string gettype() const;
		string get_name() const;
		int getdamage() const;
		int get_remaining_numuses() const;
		string gettype();
		double type_interaction(string& oppokemon) const;
		void display_moves();
};

#endif
