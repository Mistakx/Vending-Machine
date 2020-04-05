#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;

void print_slot(Slot slot_to_print) {

	cout << "Slot Letter: " << slot_to_print.letter << endl;
	cout << "Slot Capacity: " << slot_to_print.capacity << endl;
	cout << "Current Number of Products: " << slot_to_print.current_number_of_products << endl;
	cout << "Product Name: " << slot_to_print.product_name << endl;
	cout << "Slot Price: " << slot_to_print.price << endl;
	cout << endl;

}

void slot_initialization(Slot* slot_to_initialize, int slot_position, Products* initialization_products, Prices* text_prices) {

	slot_to_initialize->letter = slot_letter(slot_position); // Initializes the slot with it's corresponding letter.
	slot_to_initialize->capacity = rand() % 6 + 5; // Initializes the slot with a random capacity (between 5 and 10 (including both))
	slot_to_initialize->current_number_of_products = slot_to_initialize->capacity; // The slot starts full of products.
	slot_to_initialize->product_name = choose_random_product(initialization_products); // Choose a random product to place on the slot from the remaining products.
	slot_to_initialize->price = text_prices->array[rand() % text_prices->lenght]; // The slot starts with a random price chosen from the prices.txt file.
	
	//print_slot(slot_to_initialize); // Debug
	
}

char slot_letter(int slot_position) { // I already know the next 10 minutes are going to be boring doing this function.

	switch (slot_position) {

	case 0: return 'a';
	case 1: return 'b';
	case 2: return 'c';
	case 3: return 'd';
	case 4: return 'e';
	case 5: return 'f';
	case 6: return 'g';
	case 7: return 'h';
	case 8: return 'i';
	case 9: return 'j';
	case 10: return 'k';
	case 11: return 'l';
	case 12: return 'm';
	case 13: return 'n';
	case 14: return 'o';
	case 15: return 'p';
	case 16: return 'q';
	case 17: return 'r';
	case 18: return 's';
	case 19: return 't';
	case 20: return 'u';
	case 21: return 'v';
	case 22: return 'w';
	case 23: return 'x';
	case 24: return 'y';
	case 25: return 'z';
	default: cout << "Houston, we've had a problem."; // Just like the explosion on Apollo 13, this default should never happen.

	}

}
