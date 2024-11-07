// TODO Implement member functions of the pokemon class
#include "pokemon.hpp"
#include <iostream>
#include <string> 
#include <fstream>
#include <cmath>


// pokemon::pokemon (int size) {
// this->num_moves = size;
// this->move_arr = new move [size];
// }

pokemon::pokemon (string& name, string& type, Stats& stats, string& move_type, int damage, int uses) {
    this->name = name;
    this->type = type;
    this->stats = stats;
    this->hp = stats.starting_hp;
    this->num_moves = num_moves;

    this->move_arr = new move[num_moves];
}

pokemon::~pokemon() {
    delete[] move_arr;
    move_arr = nullptr;
}

int pokemon::prompt_move_heal() {
    int mhchoice;
    cout << "Would you like to 1) use a move, or 2) heal?: ";
    cin >> mhchoice;
    return mhchoice;
}

string pokemon::prompt_move() {
    string move_choice;
    cout << "Which move would you like to use?";
    for (int i = 0; i < this->num_moves; i++) {
        this->move_arr[i].display_moves();
    }
}


pokemon& pokemon::operator=(const pokemon &other) {
    if (this != &other) {
        delete[] move_arr;
        num_moves = other.num_moves;
        move_arr = new move[num_moves];
        for (int i = 0; i < num_moves; i++) {
            move_arr[i] = other.move_arr[i];
        }
    }
    return *this;
}

pokemon::pokemon(const pokemon &other) {
    num_moves = other.num_moves;

    move_arr = new move[num_moves];

    for (int i = 0; i < num_moves; i++) {
        move_arr[i] = other.move_arr[i];
    }
    // pokemon p1;
	// p1.prompt_move();
}
