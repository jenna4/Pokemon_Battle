// TODO Implement member functions of the pokemon class
#include "pokemon.hpp"
#include <iostream>
#include <string> 
#include <fstream>
#include <cmath>

pokemon::pokemon() {
    this->name = " ";
    this->type = " ";
    this->hp = 0;
    this->heal_remain = 1;
    this->num_moves = 0;
    this->move_arr = nullptr;
}
pokemon::pokemon (const string& name, const string& type, Stats& stats, const int num_moves) {
    this->name = name;
    this->type = type;
    this->stats = stats;
    this->hp = stats.starting_hp;
    this->heal_remain = 1;
    this->num_moves = num_moves;

    this->move_arr = new move[num_moves];
}

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

bool pokemon::has_heal() const {
    return heal_remain > 0;
}

void pokemon::use_heal() {
    heal_remain--;
}

int pokemon::get_attack() {
    return this->stats.attack;
}

int pokemon::get_defense() {
    return this->stats.defense;
}
//should be in battle i think
int pokemon::prompt_move_heal() {
    int mhchoice;
    do {
    cout << endl;
    cout << "Would you like to 1) use a move, or 2) heal?: ";
    cin >> mhchoice;

    if (mhchoice < 1 || mhchoice > 2) {
        cout << "Invalid input, try again" << endl;
        cout << endl;
    }

    } while (mhchoice < 1 || mhchoice > 2);
    return mhchoice;
}

int pokemon::prompt_move() {
    int choice;
    do {
    cout << endl;
    cout << "Which move would you like to use?" << endl;
    d_move();
    cout << endl;
    cout << "Your choice: ";
    cin >> choice;

    if (choice < 1 || choice > 2) {
        cout << "Invalid input, try again" << endl;
        cout << endl;
    }

    } while (choice < 1 || choice > 2);
    return choice;
}

void pokemon::d_move() {
    for (int i = 0; i < this->num_moves; i++) {
        cout << (i + 1) << ". ";
        this->move_arr[i].display_moves();
    }
}

move& pokemon::get_move(int index) {
    return move_arr[index];
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

string pokemon::get_type() {
    return type;
}

void pokemon::take_damage(int damage) {
    //reduce hp by dmaga amt
    this->hp -= damage;

    // make sure hp dont go below 0
    if (this->hp  < 0) {
        this->hp = 0;
    }
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
    if (this == &other) {
        return *this;
    }

    if (this->move_arr != nullptr) {
        delete[] this->move_arr;
        this->move_arr = nullptr;
    }

    this->name = other.name;
    this->hp = other.hp;
    this->stats = other.stats;
    this->heal_remain = other.heal_remain;

    this->num_moves = other.num_moves;
    if (this->num_moves > 0) {
        this->move_arr = new move[this->num_moves];
        for (int i = 0; i < this->num_moves; ++i) {
            this->move_arr[i] = other.move_arr[i]; 
        }
    } else {
        this->move_arr = nullptr; 
    }

    return *this;
}

//copy thing from lab
pokemon::pokemon(const pokemon &other) {
    this->name = other.name;
    this->hp = other.hp;
    this->stats = other.stats;
    this->heal_remain = other.heal_remain;

    this->num_moves = other.num_moves;
    if (this->num_moves > 0) {
        this->move_arr = new move[this->num_moves];
        for (int i = 0; i < this->num_moves; ++i) {
            this->move_arr[i] = other.move_arr[i]; 
        }
    } else {
        this->move_arr = nullptr; 
    }
    // pokemon p1;
	// p1.prompt_move();
}
