#include <iostream>
#include "slots.h"


using namespace std;

Products delete_product(Products* products, int index) { // Returns the same struct with an array element in a chosen position removed.
	// Possible Optimization: Noted that this implementation is way less efficient than using a linked list and just deleting a single node, because it has to create a whole new array.

	Products new_products;
	// The new struct array size is one less because one element was removed.
	// TODO: Delete
	new_products.array = new string[(products->lenght) - 1];
	new_products.lenght = (products->lenght) - 1;


	// Adds the elements that are located before the element that's going to be deleted, to the new array.
	for (int i = 0; i < index; i++) {

		new_products.array[i] = products->array[i];

	}

	// Adds the elements that are located after the element that's going to be deleted, to the new array.
	for (int i = (index + 1); i < products->lenght; i++) {

		new_products.array[i - 1] = products->array[i];

	}

	new_products.lenght = products->lenght - 1;


	return new_products;

}
string choose_random_product(Products* products) { // Chooses random product from a struct, then removes that product from the struct.

	if (products->lenght != 0) { // Products to choose from ends up being zero if the products.txt file doesn't contain enough products.

		int random_product_index = rand() % products->lenght; // Generates a random number between 0 and the number of products still available (including both).


		string chosen_product_name = products->array[random_product_index]; // Chooses a product from the initialization_products array.

		*products = delete_product(products, random_product_index);

		return chosen_product_name;

		// TODO: Check if a brake is needed
	}
	else 	cout << "Ocorreu um erro ao escolher um produto para introduzir na máquina." << endl << "Verifique se o ficheiro que contém os produtos tem um número de produtos suficientes." << endl;








}


void slot_initialization(Slot* slot, int slot_position, Products* initialization_products, Prices text_prices) {
	slot->letter = char(slot_position + 65); // Initializes the slot with it's corresponding letter.
	slot->product_name = choose_random_product(initialization_products); // Choose a random product to place on the slot from the remaining products.
	slot->price = text_prices.array[rand() % text_prices.lenght]; // The slot starts with a random price chosen from the prices.txt file.
	slot->capacity = rand() % 6 + 5; // Initializes the slot with a random capacity (between 5 and 10 (including both))
	slot->current_number_of_products = slot->capacity; // The slot starts full of products.

}

void print_slot(Slot slot) { // !Debug Function

	cout << "Slot " << slot.letter << endl;
	cout << "Produto: " << slot.product_name << endl;
	cout << "Preço: " << slot.price << endl;	
	cout << "Quantidade: " << slot.current_number_of_products << endl;
	cout << "Capacidade: " << slot.capacity << endl;

	cout << endl;

}

void clean_slot(Slot* slot) { // Cleans a slot

	slot->current_number_of_products = 0;
	slot->product_name = "";
	slot->price = 0;

}

