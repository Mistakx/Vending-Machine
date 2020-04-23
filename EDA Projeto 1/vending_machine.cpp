#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "vending_machine.h"

using namespace std;

//! ------------------------ Vending Machine Operations ------------------------

void initialize_vending_machine(Vending_machine* vending_machine, Products* initialization_products, Prices prices) {

	cout << "Initializing Vending Machine..." << endl; // !Debug

	// Initializes the vending_machine size.
	vending_machine->size = rand() % 4 + 9; // Generates a random number between 9 and 12 (including both)
	cout << "Vending Machine Size: " << vending_machine->size << endl << endl; // !Debug

	// Initializes the vending_machine coins.
	for (int i = 0; i < 6; i++) {

		vending_machine->cash_box[i] = rand() % 11 + 10; // Generates a random number between 10 and 20 (including both)
		//cout << vending_machine->coins[i] << endl; // !Debug

	}

	// Initializes each vending_machine sort.
	vending_machine->slots = new Slot[vending_machine->size]; // The vending machine is an array of slots.
	for (int i = 0; i < vending_machine->size; i++) {

		initialize_slot(&vending_machine->slots[i], i, initialization_products, prices);

	}

	// !Debug: Prints the remaining products that were not used in the initialization.
	//cout << "Remaining Products: " << endl; // Debug
	//print_array(initialization_products->array, initialization_products->lenght); // Debug
	//cout << endl; // Debug





}

void clean_vending_machine(Vending_machine* vending_machine) {

	for (int i = 0; i < vending_machine->size; i++) {

		clean_slot(&vending_machine->slots[i]);

	}

}

void print_slots(Vending_machine vending_machine) {
	
	cout << endl;

	cout << left 
		<< setw(10) << "Slot" 
		<< setw(25) << "Produto" 
		<< setw(10) << "Pre�o" 
		<< setw(15) << "Quantidade " 
		<< "Capacidade" 
		<< endl;

	cout << "--------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < vending_machine.size; i++) {

		print_slot(vending_machine.slots[i]);

	}

	cout << "--------------------------------------------------------------------------------" << endl;

}

void print_cashbox(Vending_machine vending_machine) {

	cout << "----------------------- Cash Box -----------------------" << endl << endl;

	cout << "2 euros: " << vending_machine.cash_box[5] << endl;
	cout << "1 euro: " << vending_machine.cash_box[4] << endl;
	cout << "50 c�ntimos: " << vending_machine.cash_box[3] << endl;
	cout << "20 c�ntimos: " << vending_machine.cash_box[2] << endl;
	cout << "10 c�ntimos: " << vending_machine.cash_box[1] << endl;
	cout << "5 c�ntimos: " << vending_machine.cash_box[0] << endl << endl;

	cout << "----------------------- Cash Box -----------------------" << endl << endl;

}

void refresh_console(Vending_machine vending_machine) {

	system("cls");
	print_slots(vending_machine);
	print_cashbox(vending_machine);

}

void check_funds(Vending_machine vending_machine) {

	if (vending_machine.cash_box[5] < 4) { cout << "Existem apenas " << vending_machine.cash_box[5] << "moedas de 2 euros."; }
	if (vending_machine.cash_box[4] < 4) { cout << "Existem apenas " << vending_machine.cash_box[5] << "moedas de 1 euro."; }
	if (vending_machine.cash_box[3] < 4) { cout << "Existem apenas " << vending_machine.cash_box[5] << "moedas de 50 c�ntimos."; }
	if (vending_machine.cash_box[2] < 4) { cout << "Existem apenas " << vending_machine.cash_box[5] << "moedas de 20 c�ntimos."; }
	if (vending_machine.cash_box[1] < 4) { cout << "Existem apenas " << vending_machine.cash_box[5] << "moedas de 10 c�ntimos."; }
	if (vending_machine.cash_box[0] < 4) { cout << "Existem apenas " << vending_machine.cash_box[5] << "moedas de 5 c�ntimos."; }
}

void save_vending_machine(Vending_machine vending_machine, string file_path) {
	// The save file is organized in a way that it is easy to be read by both a human and a computer.
	// Each slot is separated by a space, and it's values are always saved in the same order.
	// The order being: Slot Letter, Slot Capacity, Current Number of Products, Product Name, Slot Price.
	// Each line contains a string explaining what the value that follows it represents. 
	// While the file ends up being bigger, we believe the added readability is important, and the added file size is negligible.

    ofstream file(file_path);
    
    if (file.is_open()) {

		file << "Vending Machine Size: " << vending_machine.size << endl << endl;

		for (int i = 0; i < vending_machine.size; i++) { // For each array
		
			file << "Slot Letter: " << vending_machine.slots[i].letter << endl;
			file << "Slot Capacity: " << vending_machine.slots[i].capacity << endl;
			file << "Current Number of Products: " << vending_machine.slots[i].quantity << endl;
			file << "Product Name: " << vending_machine.slots[i].product << endl;
			file << "Slot Price: " << vending_machine.slots[i].price << endl;
			file << endl;

		}


        file.close();

		system(("attrib +r " + file_path).c_str()); // Changes the file to read only. Only works on windows. 
		
		// TODO: Cross platform this.
		// The system function argument requires a C style string, C++ strings are different. Therefore c_str() is used.
		// Reference 1: https://stackoverflow.com/questions/4907805/using-variables-in-system-function-c
		// Reference 2: https://stackoverflow.com/questions/7416445/what-is-use-of-c-str-function-in-c



    }
	
	else cout << "Ocorreu um problema ao tentar abrir \"" << file_path << "\"." << endl << "O ficheiro n�o existe ou est� a ser usado por outro processo." << endl << endl;

}

void load_vending_machine(string file_path, Vending_machine* vending_machine ) {

	ifstream file(file_path);

    if (file.is_open()) {

        string line = "";

		// Reads the first line (where the machine size is located), and loads the machine size to the value read.
		getline(file, line);
		vending_machine->size = stoi(line.substr(22));
		vending_machine->slots = new Slot[vending_machine->size];

		cout << "Loaded machine size: " << vending_machine->size << endl << endl; // !Debug

		// Reads and then loads each slot.
		for (int i = 0; i < vending_machine->size; i++) {
			getline(file, line); // The first line is always a space that separates each slot.
			getline(file, line); // Slot letter.
			vending_machine->slots[i].letter = line[13];
			getline(file, line); // Slot capacity.
			vending_machine->slots[i].capacity = stoi(line.substr(15));
			getline(file, line); // Current number of products.
			vending_machine->slots[i].quantity = stoi(line.substr(28));
			getline(file, line); // Product name.
			vending_machine->slots[i].product = line.substr(14);
			getline(file, line); // Slot price.
			vending_machine->slots[i].price = stof(line.substr(12));

		}

        file.close();
    }

	else cout << "Ocorreu um erro ao tentar abrir \"" << file_path << "\"." << endl << "O ficheiro n�o existe ou est� a ser usado por outro processo." << endl << endl;

}