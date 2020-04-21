#include <iostream>
#include <string>
#include "vending_machine.h"

using namespace std;

//! ------------------------ Machine Operations ------------------------



void clean_vending_machine(Vending_machine* vending_machine) { // Cleans every slot in the machine.

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

	std::cout << "Nome do produto cujo preço deseja alterar: ";
	// TODO: Sanitize user input.
	std::getline(std::cin, product_name); // Needs to be getline because the products can have spaces in their names.

	for (int i = 0; i < vending_machine->size; i++) {

		if (vending_machine->slots[i].product_name == product_name) { // If the product entered is in the machine.

			product_already_in_machine = true;
			break; // It only needs to find the product in one slot.
		}

	}

	if (product_already_in_machine) {

		std::cout << "Preço que deseja atribuír a " << product_name << ": ";
		float new_price = 0;
		// TODO: Sanitize user input.
		std::cin >> new_price;
		std::cout << endl;

		// TODO: Check if implementation is correct
		// If entered value is divisible by 5 cents. Converts 0.05 euros to 5 cents to make the conversion possible.
		if ((int(new_price * 100) % 5) == 0) {

			for (int i = 0; i < vending_machine->size; i++) {

				if (vending_machine->slots[i].product_name == product_name) {

					// TODO: Check if the machine has enough coins.
					vending_machine->slots[i].price = new_price;

				}
			}
		}
		else std::cout << "Por favor introduza um valor múltiplo de 5 cêntimos." << endl;

	}
	else std::cout << "O produto inserido não se encontra na máquina." << endl;

}

Vending_machine* add_slot(Vending_machine* vending_machine) { // Tries to add a new slot with a given letter to the machine. If a slot with the same letter already exists, show an error.

	std::cout << "Letra correspondente ao slot que pretende adicionar: ";
	char letter = 0;
	// TODO: Sanitize user input.
	std::cin >> letter;
	letter = toupper(letter); // Changes the entered letter to uppercase.

	bool slot_exists = false;

	for (int i = 0; i < vending_machine->size; i++) { // Checks if slot already exists
	
		if (letter == vending_machine->slots[i].letter) { // If slots exists

			slot_exists == true;

			std::cout << "Ocorreu um problema ao tentar adicionar um slot. O slot que introduziu já existe." << endl;

			break; // Breaks because there is only one slot with each letter, so there's no need to continue checking.

		}

	}
	
	// If slot doesn't already exist, create a new vending machine with the new slot at the end.
	if (slot_exists == false) { 
		
		std::cout << "Capacidade do novo slot (Slot " << letter << "): ";
		int capacity = 0;
		// TODO: Sanitize user input.
		std::cin >> capacity;

		// The new vending machine is going to be one size bigger.
		Vending_machine* new_vending_machine = new Vending_machine[vending_machine->size + 1];
		
		// Copies the size and adds one.
		new_vending_machine->size = vending_machine->size + 1;

		// Copies the cash box.
		new_vending_machine->cash_box[0] = vending_machine->cash_box[0];
		new_vending_machine->cash_box[1] = vending_machine->cash_box[1];
		new_vending_machine->cash_box[2] = vending_machine->cash_box[2];
		new_vending_machine->cash_box[3] = vending_machine->cash_box[3];
		new_vending_machine->cash_box[4] = vending_machine->cash_box[4];
		new_vending_machine->cash_box[5] = vending_machine->cash_box[5];

		// Copies the slots.
		for (int i = 0; i < vending_machine->size; i++) {
			new_vending_machine->slots[i] = vending_machine->slots[i];
		}

		// TODO: Sort the new machine. 
		// !Noted: The machine only needs to be sorted after the second time this function is called.
		// !	   The first time we are garanteed that the added letter, which was added at the end of the array, is sorted.
		// !	   Example: The array was initialized automatically to A B C D E, we can only add one letter besides these 5 so we are garanteed the new letter is sorted.
		// !				First time we add something: Let's say we added a Z, the new array is A B C D E Z. 
		// !				Second time we add something: If we now want to add a H. Now the array is A B C D E Z H, so we need to sort.


		// TODO: Delete old vending machine.
		return new_vending_machine;
		
	}

}

void add_coins(Vending_machine* vending_machine) {

	int coins_to_add = 0;

	cout << "Introduza a quantidade de moedas de 2 euros que deseja adicionar: ";
	cin >> coins_to_add;
	vending_machine->cash_box[5] += coins_to_add;

	cout << "Introduza a quantidade de moedas de 1 euro que deseja adicionar: ";
	cin >> coins_to_add;
	vending_machine->cash_box[4] += coins_to_add;

	cout << "Introduza a quantidade de moedas de 50 cêntimos que deseja adicionar: ";
	cin >> coins_to_add;
	vending_machine->cash_box[3] += coins_to_add;

	cout << "Introduza a quantidade de moedas de 20 cêntimos que deseja adicionar: ";
	cin >> coins_to_add;
	vending_machine->cash_box[2] += coins_to_add;

	cout << "Introduza a quantidade de moedas de 10 cêntimos que deseja adicionar: ";
	cin >> coins_to_add;
	vending_machine->cash_box[1] += coins_to_add;

	cout << "Introduza a quantidade de moedas de 5 cêntimos que deseja adicionar: ";
	cin >> coins_to_add;
	vending_machine->cash_box[0] += coins_to_add;

	print_cashbox(vending_machine);

}

void remove_coins(Vending_machine* vending_machine){ // Removes coins as the employee enters them, instead of removing them all at once.
	// This implementation is simpler and saves memory because we only need to save on variable to RAM.

	int coins_to_remove = 0;

	cout << "Introduza a quantidade de moedas de 2 euros que deseja remover: ";
	cin >> coins_to_remove;
	vending_machine->cash_box[5] -= coins_to_remove;

	cout << "Introduza a quantidade de moedas de 1 euro que deseja remover: ";
	cin >> coins_to_remove;
	vending_machine->cash_box[4] -= coins_to_remove;

	cout << "Introduza a quantidade de moedas de 50 cêntimos que deseja remover: ";
	cin >> coins_to_remove;
	vending_machine->cash_box[3] -= coins_to_remove;

	cout << "Introduza a quantidade de moedas de 20 cêntimos que deseja remover: ";
	cin >> coins_to_remove;
	vending_machine->cash_box[2] -= coins_to_remove;

	cout << "Introduza a quantidade de moedas de 10 cêntimos que deseja remover: ";
	cin >> coins_to_remove;
	vending_machine->cash_box[1] -= coins_to_remove;

	cout << "Introduza a quantidade de moedas de 5 cêntimos que deseja remover: ";
	cin >> coins_to_remove;
	vending_machine->cash_box[0] -= coins_to_remove;

	print_cashbox(vending_machine);
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

void add_products_to_non_empty_slot(Vending_machine* vending_machine, int slot_position, int product_quantity, string product_name) {

	// If the product quantity is higher than the slot's capacity.
	if (product_quantity > vending_machine->slots[slot_position].capacity) {

		// Fills the slot
		vending_machine->slots[slot_position].current_number_of_products = vending_machine->slots[slot_position].capacity;
		product_quantity -= vending_machine->slots[slot_position].capacity;

		// Finds next empty slot to continue filling.
		for (int i = slot_position; i < vending_machine->size; i++) {

			if (vending_machine->slots[i].current_number_of_products == 0) {

				add_products_to_empty_slot(vending_machine, i, product_quantity, product_name);

			}

		}
	}

	// If the product quantity is less than the slot's capacity.
	else {

		// Adds all remaining products to the slot.
		vending_machine->slots[slot_position].current_number_of_products += product_quantity;

	}
}
	
void add_products_to_empty_slot(Vending_machine* vending_machine, int slot_position, int product_quantity, string product_name) {

	// If the product quantity is higher than the slot's capacity.
	if (product_quantity > vending_machine->slots[slot_position].capacity) {
		
		// Fills empty slot.
		vending_machine->slots[slot_position].product_name = product_name;
		vending_machine->slots[slot_position].current_number_of_products = vending_machine->slots[slot_position].capacity;
		product_quantity -= vending_machine->slots[slot_position].capacity;

		// Finds next empty slot to continue filling.
		for (int i = slot_position; i < vending_machine->size; i++) {
		
			if (vending_machine->slots[i].current_number_of_products == 0) {

				add_products_to_empty_slot(vending_machine, i, product_quantity, product_name);

			}

		}
	
	}

	// If the product quantity is less than the slot's capacity.
	else {

		// Adds all remaining products to the slot.
		vending_machine->slots[slot_position].product_name = product_name;
		vending_machine->slots[slot_position].current_number_of_products = product_quantity;

	}

	
	


}

void add_product_menu(Vending_machine* vending_machine) {

	cout << "Slot a repor: ";
	char slot_letter = 0;
	cin >> slot_letter;

	cout << "Número de produtos a repor: ";
	int product_quantity = 0;
	cin >> product_quantity;

	cout << "Nome do produto: ";
	string product_name = "";
	cin >> product_name;

	for (int i = 0; i < vending_machine->size; i++) { // !Noted: Better searching algorithm could be used.
		
		if (vending_machine->slots[i].letter == slot_letter) { 

			// If chosen slot is empty.
			if (vending_machine->slots[i].current_number_of_products == 0) {
				add_products_to_empty_slot(vending_machine, i, product_quantity, product_name);

				// If there are any remaining products.
			}

			// If chosen slot is not empty.
			else {
				add_products_to_non_empty_slot(vending_machine, i, product_quantity, product_name);

			}
		
		}

	}




}