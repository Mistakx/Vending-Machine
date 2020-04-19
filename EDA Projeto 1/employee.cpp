#include <iostream>
#include "vending_machine.h"

using namespace std;

//! ------------------------ Machine Operations ------------------------

void clean_slot(Slot* slot) { // Cleans a slot

	slot->current_number_of_products = 0;
	slot->product_name = "";
	slot->price = 0;

}

void clean_vending_machine(Vending_machine* vending_machine) { // Cleans every slot in the machine

	for (int i = 0; i < vending_machine->size; i++) {

		clean_slot(&(vending_machine->slots[i]));

	}

		
}

void change_product_price(Vending_machine* vending_machine) { // Changes the price of a product that the vending_machine contains.
	// Changing the product price is the same as changing the price of each slot that contains that product.

	// !Implementations:

	// Asking the name of the product and the new price, and then throwing an error if the product isn't in the machine.
		// Pros: Asking the product name and price before trying to change it is faster for the machine than checking if the product is there before asking the price.
		// Cons: The employee inputs the new price thinking the product is there only to be met by an error, wasting his valuable time.

	// First checks if the product exists in the machine, then asks for the new price.
		// Pros: It's faster for the employee because the machine throws an error if the product doesn't exist, thus not allowing him to introduce a new price.
		// Cons: It's negligibly slower for the machine because it has to check if the product exists first, before asking the new price.

	// !The chosen implementation was the second. 
	// It makes more sense to first check if the machine contains the chosen product before asking for the new price, since the change in the function's speed is almost null.

	string product_name;
	bool product_already_in_machine = false;

	cout << "Nome do produto cujo preço deseja alterar: ";
	// TODO: Sanitize user input.
	cin >> product_name;

	for (int i = 0; i < vending_machine->size; i++) {

		if (vending_machine->slots[i].product_name == product_name) { // If the product entered is in the machine.

			product_already_in_machine = true;
			break; // It only needs to find the product in one slot.
		}

	}

	if (product_already_in_machine) {

		float new_price = 0;
		cout << "Preço que deseja atribuír a " << product_name << ": ";

		// TODO: Sanitize user input.
		cin >> new_price;
		cout << endl;

		for (int i = 0; i < vending_machine->size; i++) {

			if (vending_machine->slots[i].product_name == product_name) { // If the product entered is in the machine.

				// TODO: Check if the machine has enough coins.
				vending_machine->slots[i].price = new_price;

			}
		}

	}
	else cout << "O produto inserido não se encontra na máquina." << endl;

}

void add_slot(Vending_machine* vending_machine) {

	char letter = 0;
	int capacity = 0;

	cout << "Letra correspondente ao slot que pretende adicionar: ";
	// TODO: Sanitize user input.
	cin >> letter;
	letter = toupper(letter); // Changes the entered letter to uppercase.
	cout << "Capacidade do novo slot (Slot " << letter << "): ";
	// TODO: Sanitize user input.
	cin >> capacity;





}

//! ------------------------ Sorting Related Functions ------------------------

void print_array(string* array, int lenght) { // Prints an array

	for (int i = 0; i < lenght; i++) {

		if (array[i] != "") cout << array[i] << endl;

		//cout << array << "[" << i << "]: " << array[i] << endl; // !Debug Version

	}

}
void print_array(float* array, int lenght) { // Prints an array

	for (int i = 0; i < lenght; i++) {

		if (array[i] != 0) cout << array[i] << endl;

		//cout << array << "[" << i << "]: " << array[i] << endl; // !Debug Version

	}

}

bool is_in_array(string word, string* array, int array_lenght) { // Checks if a word is already in an array.

	for (int i = 0; i < array_lenght; i++) {

		if (word == array[i]) { return true; }

	}

	return false;

}
bool is_in_array(float value, float* array, int array_lenght) { // Checks if a value is already in an array.

	for (int i = 0; i < array_lenght; i++) {

		if (value == array[i]) { return true; }

	}

	return false;

}

void sort_products_alphabetically(Vending_machine* vending_machine) { // Sorts all of the machine's products prices.
	// Copies prices to an array, and then sorts that array.
	// This aproach is slower than sorting them directly before copying them to an array, but it's easier to code, understand, and change in the future.

	// The number of maximum unique product names that can exist, is the same as the number of slots (if each slot has an unique product).
	// While we could first check the number of unique product names before storing them to an array (to avoid allocating more space than we need to), there isn't a need to do so.
	// The machine doesn't have enough slots to warrant this memory optimization. We will simply delete the allocated array after the function runs.
	string* sorted_names = new string[vending_machine->size]{}; // Initializes the array.

	for (int i = 0; i < vending_machine->size; i++) {


		// Check if the price isn't already in the array before copying, to avoid duplication.
		if (is_in_array(vending_machine->slots[i].product_name, sorted_names, vending_machine->size) == false) {

			sorted_names[i] = vending_machine->slots[i].product_name;

		}

	}

	// Sorts all products



	// Prints prices to the console
	print_array(sorted_names, vending_machine->size);

	delete[] sorted_names;





}

void print_products(Vending_machine* vending_machine) {

	int option = 0;

	cout << "Imprimir produtos: " << endl;
	cout << "	1 - Por ordem alfabética." << endl;
	cout << "	2 - Por preço." << endl;
	cout << "	3 - Por quantidade disponível." << endl;

	// TODO: Sanitize inputs
	cin >> option;

	switch (option) {
	
		case 1: sort_products_alphabetically;
			/*
		case 2: sort_products_by_price;

		case 3: sort_products_by_quantity;
			*/
			
	default:
		break;
	}

}

//! ------------------------ Sorting Related Functions ------------------------

