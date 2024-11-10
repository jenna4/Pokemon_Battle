// TODO Implement member functions of the battle class
#include <iostream>
#include <string> 
#include "battle.hpp"
// prompt user for move
int prompt_move_heal() {
    int mhchoice;
    cout << "Would you like to 1) use a move, or 2) heal?: ";
    cin >> mhchoice;
    return mhchoice;
}

// string prompt_move() {
//     string move_choice;
//     cout << "Which move would you like to use?";
// }

battle::battle() {
	this->pokemon1 = nullptr;
	this->pokemon2 = nullptr;
	this->turn = 1;
}

battle::battle(pokemon* p1, pokemon* p2) {
	this->pokemon1 = p1;
	this->pokemon2 = p2;
	this->turn = 1;
}

battle::~battle() {
    delete pokemon1;
    delete pokemon2;
    pokemon1 = nullptr;
    pokemon2 = nullptr;
}
void battle::set_up_pokemon(int choice1, int choice2) {

    this->pokemon1 = new pokemon();
    if (choice1 == 1) {
        pokemon1->create_charmander();
    } else if (choice1 == 2) {
        pokemon1->create_squirtle();
    } else if (choice1 == 3){
        pokemon1->create_bulbasaur();
    } else if (choice1 == 4) {
        pokemon1->create_pidgey();
    }

    this->pokemon2 = new pokemon();
    if (choice2 == 1) {
        pokemon2->create_charmander();
    } else if (choice2 == 2) {
        pokemon2->create_squirtle();
    } else if (choice2 == 3){
        pokemon2->create_bulbasaur();
    } else if (choice2 == 4) {
        pokemon2->create_pidgey();
    }

    cout << pokemon1->get_name() << " | " << pokemon2->get_name() << endl;

}

void battle::display_status() const {
    cout << pokemon1->get_name() << " HP: " << pokemon1->get_hp() << " / " << pokemon1->get_starthp() << endl;
    cout << pokemon2->get_name() << " HP: " << pokemon2->get_hp() << " / " << pokemon2->get_starthp() << endl;
}

bool battle::done_battle() const {
    return pokemon1->get_hp() <= 0 || pokemon2->get_hp() <= 0;
}

// void battle::switch_turns(pokemon* attacker, pokemon* defender) {
//     int choice = attacker->prompt_move_heal();
//     if (choice == 1) { //attack
//         string move_name = attacker->prompt_move(); 
//         attacker->
//     }
// }

int battle::test_dmove() {
    int movep1 = pokemon1->prompt_move();
    return movep1;
}

void battle::start_battle() {
    while (!done_battle()) {
        // disdplay status func
        display_status();
        if (turn == 1) {
            cout << "Trainer 1's turn!" << endl;
            // heal n promt for move function
            int action = pokemon1->prompt_move_heal();
            if (action == 1) {
                int movep1 = pokemon1->prompt_move();
            }
            turn = 2; 
        } else {
            cout << "Trainer 2's turn!" << endl;
            turn = 1; 
        }
    }
    // delcare winner
}


// way to calculate damage done by move 

// apply damage to opps pokemon

// if damage is greater than hp 

// healing potion 

