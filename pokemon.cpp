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


pokemon::pokemon (const string& name, const string& type, Stats& stats, const int num_moves) {
    this->name = name;
    this->type = type;
    this->stats = stats;
    this->hp = stats.starting_hp;
    this->num_moves = num_moves;

    this->move_arr = new move[num_moves];
}

move scratch("Scratch", "normal", 3, 10000);
move ember("Ember", "fire", 5, 3);
move watergun("Water gun", "water", 5, 3);
move vinewhip("Vine whip", "grass", 5, 3);
move wingattack("Wing attack", "flying", 5, 3);

pokemon create_charmander() {
    Stats charmander_stats = {6, 4, 18};
    pokemon charmander("Charmander", "fire", charmander_stats, 2);

    charmander.set_move(0, scratch);
    charmander.set_move(1, ember);
    return charmander;
}

pokemon create_squirtle() {
    Stats squirtle_stats = {4, 6, 22};
    pokemon squirtle("Squirtle", "water", squirtle_stats, 2);

    squirtle.set_move(0, scratch);
    squirtle.set_move(1, watergun);
    return squirtle;
}

pokemon create_bulbasaur() {
    Stats bulbasaur_stats = {5, 5, 20};
    pokemon bulbasaur("Bulbasaur", "grass", bulbasaur_stats, 2);

    bulbasaur.set_move(0, scratch);
    bulbasaur.set_move(1, vinewhip);
    return bulbasaur;
}

pokemon create_pidgey() {
    Stats pidgey_stats = {4, 4, 18};
    pokemon pidgey("Pidgey", "flying", pidgey_stats, 2);

    pidgey.set_move(0, scratch);
    pidgey.set_move(1, wingattack);
    return pidgey;
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
    delete[] move_arr;
    move_arr = nullptr;
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
