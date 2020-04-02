#include <iostream>
#include "header.h"
using namespace std;


void print_array(string* array, int lenght) {

	for (int i = 0; i < lenght; i++) {

		cout << array << "[" << i << "]: " << array[i] << endl;

	}

} // DEBUG

products* delete_product(products* struct_to_delete_from, int* index_to_delete) { // Returns the same struct with a chosen array element removed.

	products new_struct;
	// The new struct array size is one less because one element was removed.
	new_struct.array = new string[(struct_to_delete_from->lenght) - 1]; 
	new_struct.lenght = (struct_to_delete_from->lenght) - 1;

	
	// Adds the elements that are located before the element that's going to be deleted, to the new array.
	for (int i = 0; i < *index_to_delete; i++) {

		new_struct.array[i] = struct_to_delete_from->array[i];

	}


	// Adds the elements that are located after the element that's going to be deleted, to the new array.
	for (int i = (*index_to_delete + 1); i < struct_to_delete_from->lenght; i++) {

		new_struct.array[i - 1] = struct_to_delete_from->array[i];

	}


	new_struct.lenght = struct_to_delete_from->lenght - 1;


	return &new_struct;

}

string choose_random_product(products* products_to_choose_from) { // Chooses random product from a struct, then removes that product from the struct.
	

	int random_product_index = rand() % products_to_choose_from->lenght; // Generates a random number between 0 and the number of products still available (including both).
	string chosen_product_name = products_to_choose_from->array[random_product_index]; // Chooses a product from the initialization_products array.
	
	*products_to_choose_from = *delete_product(products_to_choose_from, &random_product_index);

	return chosen_product_name;	
	

}





