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

	cout << "Qual o nome do produto cujo preço deseja alterar?" << endl;
	cin >> product_name;

	for (int i = 0; i < vending_machine->size; i++) {

		if (vending_machine->slots[i].product_name == product_name) { // If the product entered is in the machine.

			product_already_in_machine = true;
			break; // It only needs to find the product in one slot.
		}

	}

	if (product_already_in_machine) {

		float new_price = 0;
		cout << "Qual o novo preço que deseja atribuír a " << product_name << ": ";
		cin >> new_price;
		cout << endl;

		for (int i = 0; i < vending_machine->size; i++) {

			if (vending_machine->slots[i].product_name == product_name) { // If the product entered is in the machine.

				vending_machine->slots[i].price = new_price;

			}
		}

	}
	else cout << "O produto inserido não se encontra na máquina." << endl;

}