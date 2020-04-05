#include <iostream>
#include <fstream>
#include <string>
#include "header.h"
using namespace std;

void print_vending_machine(Vending_machine vending_machine) { // !Debug Function: Prints the Vending Machine
	for (int i = 0; i < vending_machine.size; i++) {

		print_slot(vending_machine.slots[i]);

	}

}

void print_array(string* array, int lenght) { // !Debug Function: Prints an array

	for (int i = 0; i < lenght; i++) {

		cout << array << "[" << i << "]: " << array[i] << endl;

	}

} 

void vending_machine_initialization(Vending_machine* vending_machine, Products* initialization_products, Prices text_prices) {

	cout << "Initializing Vending Machine..." << endl; // !Debug

	vending_machine->size = rand() % 4 + 9; // Generates a random number between 9 and 12 (including both)
	
	cout << "Vending Machine Size: " << vending_machine->size << endl << endl; // !Debug


	vending_machine->slots = new Slot[vending_machine->size]; // The vending machine is an array of slots.
	
	for (int i = 0; i < vending_machine->size; i++) {

		slot_initialization(&vending_machine->slots[i], i, initialization_products, text_prices); // Vending Machine is an array of slots. Type: slot*. Each slot is a struct so there's no need to pass by reference. 
		// Thanks debugger for the help :D. Usually print debugging does the work but not this time.

	}

	// !Debug: Prints the remaining products that were not used in the initialization.
	cout << "Remaining Products: " << endl; // Debug
	print_array(initialization_products->array, initialization_products->lenght); // Debug
	cout << endl; // Debug

	



}

void save_vending_machine(Vending_machine vending_machine, string save_location) { // Saves the vending machine to a chosen file location.

    ofstream file(save_location);
    
    if (file.is_open()) {

		file << "Vending Machine Size: " << vending_machine.size << endl << endl;

		for (int i = 0; i < vending_machine.size; i++) { // For each array
		
			file << "Slot Letter: " << vending_machine.slots[i].letter << endl;
			file << "Slot Capacity: " << vending_machine.slots[i].capacity << endl;
			file << "Current Number of Products: " << vending_machine.slots[i].current_number_of_products << endl;
			file << "Product Name: " << vending_machine.slots[i].product_name << endl;
			file << "Slot Price: " << vending_machine.slots[i].price << endl;
			file << endl;

		}

        file.close();

    } else cout << save_location << "is being used by another process." << endl; 




}

void load_vending_machine(string save_location, Vending_machine* vending_machine ) { // // Loads a chosen file location to a memory address reserved for a vending machine.

	ifstream file(save_location);

    if (file.is_open()) {

        string line = "";


		// Reads the first line (where the machine size is located), and loads the machine size to the value read.
		getline(file, line);
		vending_machine->size = stoi(line.substr(22));
		vending_machine->slots = new Slot[vending_machine->size];

		cout << "Loaded machine size: " << vending_machine->size << endl << endl; // Debug

		// Reads and then loads each slot.
		for (int i = 0; i < vending_machine->size; i++) {
			getline(file, line); // The first line is always a space that separates each slot.
			getline(file, line); // Slot letter.
			vending_machine->slots[i].letter = line[13];
			getline(file, line); // Slot capacity.
			vending_machine->slots[i].capacity = stoi(line.substr(15));
			getline(file, line); // Current number of products.
			vending_machine->slots[i].current_number_of_products = stoi(line.substr(28));
			getline(file, line); // Product name.
			vending_machine->slots[i].product_name = line.substr(14);
			getline(file, line); // Slot price.
			vending_machine->slots[i].price = stof(line.substr(12));

		}


        file.close();
        





    }
    else cout << save_location << "is being used by another process." << endl;



}