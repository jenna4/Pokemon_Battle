#include <iostream>

#include "startup.hpp"

using std::cout;
using std::cin;
using std::endl;

int prompt_first_pokemon() {
	int choice;
	do {
		cout << "Trainer 1: Which pokemon would you like?" <<
			endl;
		cout << "1. Charmander" << endl;
		cout << "2. Squirtle" << endl;
		cout << "3. Bulbasaur" << endl;
		cout << "4. Pidgey" << endl;
		cout << endl << "Your choice: ";
		cin >> choice;

		cout << endl;

		if (choice < 1 || choice > 4) {
			cout << "Invalid option!" <<
				endl << endl;
		}
	} while(choice < 1 || choice > 4);
	return choice;
}

int prompt_second_pokemon(int blacklisted_pokemon) {
	int choice;
	do {
		cout << "Trainer 2: Which pokemon would you like?" <<
			endl;

		if (blacklisted_pokemon == 1) {
			cout << "1. Squirtle" << endl;
			cout << "2. Bulbasaur" << endl;
			cout << "3. Pidgey" << endl;
		} else if (blacklisted_pokemon == 2) {
			cout << "1. Charmander" << endl;
			cout << "2. Bulbasaur" << endl;
			cout << "3. Pidgey" << endl;
		} else if (blacklisted_pokemon == 3) {
			cout << "1. Charmander" << endl;
			cout << "2. Squirtle" << endl;
			cout << "3. Pidgey" << endl;
		} else {
			cout << "1. Charmander" << endl;
            cout << "2. Squirtle" << endl;
            cout << "3. Bulbasaur" << endl;
		}

		cout << endl << "Your choice: ";
		cin >> choice;

		cout << endl;

		if (choice < 1 || choice > 3) {
			cout << "Invalid option!" <<
				endl << endl;
		}
	} while(choice < 1 || choice > 3);

	// Convert their entered choice to the following legend:
	// 1 = Charmander
	// 2 = Squirtle
	// 3 = Bulbasaur
	// if (blacklisted_pokemon == 1) {
	// 	choice = choice + 1;
	// } else if (blacklisted_pokemon == 2) {
	// 	if (choice == 2) {
	// 		choice = 3;
	// 	}
	// } else if (blacklisted_pokemon == 3) {

	// }
	 if (blacklisted_pokemon == 1) { // Charmander is blacklisted
        choice = choice + 1; 
    } else if (blacklisted_pokemon == 2) { // Squirtle is blacklisted
        if (choice == 1) choice = 1;
        else choice += 1; 
    } else if (blacklisted_pokemon == 3) { // Bulbasaur is blacklisted
        if (choice == 1) choice = 1;
        else if (choice == 2) choice = 2;
        else choice = 4; // Pidgey
    } else if (blacklisted_pokemon == 4) { // Pidgey is blacklisted
        choice = choice; 
    }

	return choice;
}
