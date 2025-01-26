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

int prompt_pokemon1_backup(int poke1, int poke2) {
	int choice;
	do {
		cout << "Trainer 1: Choose your backup Pokemon:" << endl;
		 if (poke1 != 1 || poke2 != 1) {
            cout << "1. Charmander" << endl;
        }
        if (poke1 != 2 || poke2 != 2) {
            cout << "2. Squirtle" << endl;
        }
        if (poke1 != 3 || poke2 != 3) {
            cout << "3. Bulbasaur" << endl;
        }
        if (poke1 != 4 || poke2 != 4) {
            cout << "4. Pidgey" << endl;
        }

        cout << endl << "Your choice: ";
        cin >> choice;
        cout << endl;


		if(choice < 1 || choice > 4) {
			cout << "Invalid option, try again" << endl;
		}
	} while(choice < 1 || choice > 4);

	//convert chocie to match pokemon nubmerbing thing
	// translates menu choice to match orginal pokemon nubmering
	if (poke1 == 1) {
		choice += 1;
	} else if (poke1 == 2 && choice > 1) {
		choice += 1;
	} else if (poke1 == 3 && choice == 3) {
		choice = 4;
	}
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

int prompt_pokemon2_backup(int poke2, int poke1, int poke1_backup) {
	int choice;
		cout << "Trainer 2: Your backup Pokemon is ";

		if (poke2 != 1 || poke1 != 1 || poke1_backup != 1) {
			cout << "Charmander" << endl;
		} else if (poke2 != 2 || poke1 != 2 || poke1_backup != 2) {
			cout << "Squritle" << endl;
		} else if (poke2 != 3 || poke1 != 3 || poke1_backup != 3) {
			cout << "Bulbasaur" << endl;
		} else if (poke2 != 4 || poke1 != 4 || poke1_backup != 4) {
			cout << "Pidgey" << endl;
		}
		return choice;
}