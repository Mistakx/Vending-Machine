#include <iostream>
#include "header.h"
using namespace std;

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

	char letter = '@';
	int capacity = 0;

	cout << "Letra correspondente ao slot que pretende adicionar: ";
	// TODO: Sanitize user input.
	cin >> letter;
	letter = toupper(letter); // Changes the entered letter to uppercase.
	cout << "Capacidade do novo slot (Slot " << letter << "): ";
	// TODO: Sanitize user input.
	cin >> capacity;





}

int letter_to_position(char letter) { // Converts a slot's letter to it's corresponding position.
	// LOL I have to do this again but in reverse?
	// LOL even worse apparently I can't use a string as a case. Thanks a lot C++.


	if (letter == 'A') return 0;
	else if (letter == 'B') return 1;
	else if (letter == 'C') return 2;
	else if (letter == 'D') return 3;
	else if (letter == 'E') return 4;
	else if (letter == 'F') return 5;
	else if (letter == 'G') return 6;
	else if (letter == 'H') return 7;
	else if (letter == 'I') return 8;
	else if (letter == 'J') return 9;
	else if (letter == 'K') return 10;
	else if (letter == 'L') return 11;
	else if (letter == 'M') return 12;
	else if (letter == 'N') return 13;
	else if (letter == 'O') return 14;
	else if (letter == 'P') return 15;
	else if (letter == 'Q') return 16;
	else if (letter == 'R') return 17;
	else if (letter == 'S') return 18;
	else if (letter == 'T') return 19;
	else if (letter == 'U') return 20;
	else if (letter == 'V') return 21;
	else if (letter == 'W') return 22;
	else if (letter == 'X') return 23;
	else if (letter == 'Y') return 24;
	else if (letter == 'Z') return 25;


	else cout << "You were the Chosen One! It was said that you would destroy the Sith, not join them!"; 
	// Like Anakin becoming Darth Vader, this should never happen if the user inputs were correctly sanitized.

}

