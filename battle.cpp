// TODO Implement member functions of the battle class
#include <iostream>
#include <string> 
#include <cmath>
#include <cstdlib>
#include "battle.hpp"
// prompt user for move

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
    cout << "----------------" << endl;
    cout << pokemon1->get_name() << " HP: " << pokemon1->get_hp() << " / " << pokemon1->get_starthp() << endl;
    cout << pokemon2->get_name() << " HP: " << pokemon2->get_hp() << " / " << pokemon2->get_starthp() << endl;
    cout << "----------------" << endl;
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

// int battle::test_dmove() {
//     int movep1 = pokemon1->prompt_move();
//     return movep1;
// }

// calculations
double random_multiplier() {
    double random_double = rand();
    double random_zero_to_one = random_double / RAND_MAX;
    return 0.8 + (random_zero_to_one * 0.4); // generate rand num from 0-0.4 and adds 0.8 so return any value from 0.8-1.2
}

int random_critical() {
    int chance = rand() % 10; // 10 percnet chance, generate num from 0-9
    if (chance == 0) {
        return 3; //10% randomyl deal 3x damage, called critical hit
    } else {
        return 1; // 90%
    }
}

int battle::calc_damage(pokemon* attacker, pokemon* defender, int move_index) {
    int attack = attacker->get_attack();
    int defense = defender->get_defense();
    int base_damage = attacker->get_move(move_index).getdamage();

    string move_type = attacker->get_move(move_index).gettype();
    string def_type = defender->get_type();

    double t_interaction = attacker->get_move(move_index).type_interaction(def_type);
    double rand_multi = random_multiplier();
    int rand_crit = random_critical();

    double total_damage = (static_cast<double>(attack) / defense) * t_interaction * base_damage * rand_multi * rand_crit;
    // rounding up to int
    int final_damage = static_cast<int>(ceil(total_damage));
    cout << endl;
    cout << "Performing damage calculation..." << endl;
    cout << "Type Effectiveness: " << t_interaction << endl;
    cout << "Random Damage Multiplier: " << rand_multi << endl;
    cout << "Critcal Hit: " << rand_crit << endl;
    cout << "Total Damage: " << final_damage << endl;
    cout << endl;
    return final_damage;
}

void battle::who_wins() {
    if (pokemon1->get_hp() > 0) {
        cout << endl;
        cout << pokemon2->get_name() << " has fainted!" << endl;
        cout << pokemon1->get_name() << " wins the battle!" << endl;
        cout << endl;
    } else if (pokemon2->get_hp() > 0) {
        cout << endl;
        cout << pokemon1->get_name() << " has fainted!" << endl;
        cout << pokemon2->get_name() << " wins the battle!" << endl;
        cout << endl;
    } else {
        cout << "It is a tie!" << endl;
    }
}

void battle::perform_attack(pokemon* attacker, pokemon* defender) {
    int move_index;

    while (true) {
        // subtracting 1 to match zero-based index
        move_index = attacker->prompt_move() - 1;

        // check if selected move has remianinng uses
        if (attacker->get_move(move_index).has_uses()){
            int damage = calc_damage(attacker, defender, move_index);
            attacker->get_move(move_index).use_move();
            defender->take_damage(damage);
            break;
        } else {
            cout << "No remaining uses for " << attacker->get_move(move_index).get_name() << endl;
        }
    }
}

void battle::try_heal(pokemon* healer) {
    while (true) {
        if (healer->has_heal()) {
            healer->heal();
            healer->use_heal();
            cout << endl;
            cout << healer->get_name() << " used a heal potion!" << endl;
            cout << endl;
            break;
        } else {
            cout << healer->get_name() << " has no heal potions left. Please choose a different option" << endl;
            int action = healer->prompt_move_heal();
            if (action == 1) {
                if (turn == 1) {
                    perform_attack(pokemon1, pokemon2);
                } else {
                    perform_attack(pokemon2, pokemon1); 
                }
                break; //exit loop after perfomring attack
            }
        }
    }
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
                perform_attack(pokemon1, pokemon2);
            } else {
                try_heal(pokemon1);
            }
            turn = 2; 
        } else {
            cout << "Trainer 2's turn!" << endl;
            int action = pokemon2->prompt_move_heal();

            if (action == 1) {
                perform_attack(pokemon2, pokemon1);
                // int move_index = pokemon2->prompt_move() - 1;
                // int damage = calc_damage(pokemon2, pokemon1, move_index);
                // pokemon1->take_damage(damage);
            } else {
                try_heal(pokemon2);
            }
            turn = 1; 
        }
    }
    // delcare winner
    who_wins();
}


// way to calculate damage done by move 

// apply damage to opps pokemon

// if damage is greater than hp 

// healing potion 

