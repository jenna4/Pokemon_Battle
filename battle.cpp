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

battle::battle(pokemon* p1, pokemon* p2) {
	this->pokemon1 = p1;
	this->pokemon2 = p2;
	this->turn = 1;
}

bool battle::done_battle() const {
    return pokemon1->get_hp() <= 0 || pokemon2->get_hp() <= 0;
}

// void battle::switch_turns(pokemon* attacker, pokemon* defender) {
//     int choice = attacker->prompt_move_heal();
//     if (choice == 1) { //attack
//         string move_name = attacker->prompt_move(); //pause
//     }
// }

void battle::start_battle() {
    while (!done_battle()) {
        // disdplay status func
        if (turn == 1) {
            cout << "Trainer 1's turn!" << endl;
            // heal n promt for move function
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

