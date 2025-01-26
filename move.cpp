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
        this->name = " ";
        this->type = " ";
        this->damage = 0;
        this->num_uses = 0;
    }

move::move(string n, string t, int d, int u) {
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

void move::create_move(string name, string type, int dmg, int uses) {
    this->name = name;
    this->type = type;
    this->damage = dmg;
    this->num_uses = uses;
}

bool move::has_uses() const {
    return num_uses > 0;
}

void move::use_move() {
    if (num_uses > 0) {
        num_uses--;
    } else {
        cout << "No remaining moves for " << name << "!" << endl;
    }
}

string move::get_name() const {
    return this->name;
}

int move::getdamage() const {
        return this->damage;
    }

int move::get_remaining_numuses() const {
        return this->num_uses;
    }

string move::gettype() {
    return this->type;
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


void move::display_moves() {
   cout << this->name << " (" << this->num_uses << " uses remaining)" << endl;
}

