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

pokemon::pokemon() {
    this->name = " ";
    this->type = " ";
    this->hp = 0;
    this->num_moves = 0;
    this->move_arr = nullptr;
}
pokemon::pokemon (const string& name, const string& type, Stats& stats, const int num_moves) {
    this->name = name;
    this->type = type;
    this->stats = stats;
    this->hp = stats.starting_hp;
    this->num_moves = num_moves;

    this->move_arr = new move[num_moves];
}

// move* scratch = new move("Scratch", "normal", 3, 10000);
// move* ember = new move("Ember", "fire", 5, 3);
// move* watergun = new move("Water gun", "water", 5, 3);
// move* vinewhip = new move("Vine whip", "grass", 5, 3);
// move* wingattack = new move("Wing attack", "flying", 5, 3);

void pokemon::create_charmander() {
    this->name = "Charmander";
    this->type = "fire";
    this->stats = {6, 4, 18};
    this->hp = 18;
    this->num_moves = 2;
    this->move_arr = new move[this->num_moves];

    this->move_arr[0].create_move("Scratch", "normal", 3, 10000);
    this->move_arr[1].create_move("Ember", "fire", 5, 3);
}

void pokemon::create_squirtle() {
    this->name = "Squirtle";
    this->type = "water";
    this->stats = {4, 6, 22};
    this->hp = 22;
    this->num_moves = 2;
    this->move_arr = new move[this->num_moves];

    this->move_arr[0].create_move("Scratch", "normal", 3, 10000);
    this->move_arr[1].create_move("Water gun", "water", 5, 3);

}

void pokemon::create_bulbasaur() {
    this->name = "Bulbasaur";
    this->type = "grass";
    this->stats = {5, 5, 20};
    this->hp = 20;
    this->num_moves = 2;
    this->move_arr = new move[this->num_moves];

    this->move_arr[0].create_move("Scratch", "normal", 3, 10000);
    this->move_arr[1].create_move("Vine whip", "grass", 5, 3);
}

void pokemon::create_pidgey() {
    this->name = "Pidgey";
    this->type = "normal";
    this->stats = {4, 4, 18};
    this->hp = 18;
    this->num_moves = 2;
    this->move_arr = new move[this->num_moves];

    this->move_arr[0].create_move("Scratch", "normal", 3, 10000);
    this->move_arr[1].create_move("Wing attack", "flying", 5, 3);
}

void pokemon::set_move(int indexmovearr, move& m) {
    if (indexmovearr >=0 && indexmovearr < num_moves) {
    this->move_arr[indexmovearr] = m;
    }

    // create pokemon object in battle??
    // ex charmander.set_move(0, scratch);
    //    charmander.set_move(1, ember);
}
pokemon::~pokemon() {
    if (move_arr != nullptr) {
        delete[] move_arr;
        move_arr = nullptr;
    }
    
}

int pokemon::get_attack() {
    return this->stats.attack;
}

//should be in battle i think
int pokemon::prompt_move_heal() {
    int mhchoice;
    cout << "Would you like to 1) use a move, or 2) heal?: ";
    cin >> mhchoice;
    return mhchoice;
}

int pokemon::prompt_move() {
    cout << "Which move would you like to use?" << endl;
    d_move();
    int choice;
    cin >> choice;
    return choice;
}

void pokemon::d_move() {
    for (int i = 0; i < this->num_moves; i++) {
        this->move_arr[i].display_moves();
    }
}

int pokemon::get_hp() {
   return hp;
}

int pokemon::get_starthp() {
    return stats.starting_hp;
}

string pokemon::get_name() {
    return name;
}

void pokemon::heal() {
    hp = hp + 10;
    if (hp > stats.starting_hp) {
        hp = stats.starting_hp;
    }
}

bool pokemon::died() const {
    return hp <= 0;
}

// assignment thing from lab
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

//copy thing from lab
pokemon::pokemon(const pokemon &other) {
    num_moves = other.num_moves;

    move_arr = new move[num_moves];

    for (int i = 0; i < num_moves; i++) {
        move_arr[i] = other.move_arr[i];
    }
    // pokemon p1;
	// p1.prompt_move();
}
