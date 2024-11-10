// TODO Implement member functions of the move class
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
using namespace std;

 move::move() {
        // cout << "Default constructor called (move)" << endl;
        this->name = " ";
        this->type = " ";
        this->damage = 0;
        this->num_uses = 0;
    }

move::move(string n, string t, int d, int u) {
        // cout << "Non-default constructor called (move)" << endl;
        this->name = n;
        this->type = t;
        this->damage = d;
        this->num_uses = u;
    }

void move::set_name(const string& n) {
        this->name = n;
    }

void move::settype(const string& t) {
        this->type = t;
    }

// void move::setdamage(int d) {
//         this->damage = d;
//     }

// void move::setnumuses(int u) {
//         this->num_uses = u;
//     }
void move::use_move() {
    if (num_uses > 0) {
        num_uses--;
    } else {
        cout << "No remaining moves!" << endl;
    }
}


// string move::getname() const {
//         return this->name;
//     }

// string move::gettype() const {
//         return this->type;
//     }

int move::getdamage() const {
        return this->damage;
    }

int move::get_remaining_numuses() const {
        return this->num_uses;
    }

double move::type_interaction(string& oppokemon) const {
    if (this->type == "fire") {
        if (oppokemon == "grass") {
            // advantage
            return 2.0;
        } else if (oppokemon == "water" || oppokemon == "fire") {
            return 0.5; //disadvatnage
        }
    } 
    else if (this->type == "water") {
        if (oppokemon == "fire") {
            return 2.0;
        } else if (oppokemon == "grass" || oppokemon == "water") {
            return 0.5;
        }
    }
    else if (this->type == "grass") {
        if (oppokemon == "water") {
            return 2.0;
        } else if (oppokemon == "fire" || oppokemon == "grass" || oppokemon == "flying") {
            return 0.5;
        }
    }
    else if (this->type == "flying") {
        if (oppokemon == "grass") {
            return 2.0;
        } 
    }
    return 1.0;
}
// change the  num of uses they have for that move 

void move::display_moves() {
   cout << this->name << " (" << this->num_uses << " uses remaining)" << endl;
}

// default 
// move::move() : name(" "), type(" "), damage(0), num_uses(0) {
//     cout << "Move()" << endl;
// }

// //non default
// move::move(mname, mtype, damage, num_uses) : name(new string[n]), type(new string[n]), damage(n), num_uses(n) {
//     cout << "move(int)" << endl;
// }

// void move::set_name(int n, string na) {
//     name[n] = na;
// }

// string move::get_name (int n) const {
//     return name[n]; 
// }

// string* move::get_name() {
//     return this->name;
// }

// string* move::get_type() {
//     return this->type
// }

// int move::get_damage() const {
//     return this->damage;
// }

// int move::get_num_uses() const {
//     return this->num_uses;
// }

// void move::set_name(string* )
