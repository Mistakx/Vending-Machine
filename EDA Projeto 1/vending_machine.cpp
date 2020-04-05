#include <iostream>
#include <fstream>
#include <string>
#include "header.h"
using namespace std;


void vending_machine_initialization(Vending_machine* vending_machine, Products* initialization_products, Prices* text_prices) {

	cout << "Initializing Vending Machine..." << endl; // Debug

	vending_machine->size = rand() % 4 + 9; // Generates a random number between 9 and 12 (including both)
	
	cout << "Vending Machine Size: " << vending_machine->size << endl << endl; // Debug


	vending_machine->slots = new Slot[vending_machine->size]; // The vending machine is an array of slots.
	
	for (int i = 0; i < vending_machine->size; i++) {

		slot_initialization(&vending_machine->slots[i], i, initialization_products, text_prices); // Vending Machine is an array of slots. Type: slot*. Each slot is a struct so there's no need to pass by reference. 
		// Thanks debugger for the help :D. Usually print debugging does the work but not this time.

	}

	print_array(initialization_products->array, initialization_products->lenght); //DEBUG

	



}

void save_vending_machine(Vending_machine* vending_machine, string* save_location) {

    ofstream file(*save_location);
    
    if (file.is_open()) {

		file << "Vending Machine Size: " << vending_machine->size << endl << endl;

		for (int i = 0; i < vending_machine->size; i++) { // For each array
		
			file << "Slot Letter: " << vending_machine->slots[i].letter << endl;
			file << "Slot Capacity: " << vending_machine->slots[i].capacity << endl;
			file << "Current Number of Products: " << vending_machine->slots[i].current_number_of_products << endl;
			file << "Product Name: " << vending_machine->slots[i].product_name << endl;
			file << "Slot Price: " << vending_machine->slots[i].price << endl;
			file << endl;

		}

        file.close();

    } else cout << *save_location << "is being used by another process." << endl; 




}

void load_vending_machine() {


}