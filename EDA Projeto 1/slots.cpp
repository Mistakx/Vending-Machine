#include <iostream>
#include "header.h"
using namespace std;

void print_slot(Slot slot_to_print) { // !Debug Function

	cout << "Slot Letter: " << slot_to_print.letter << endl;
	cout << "Slot Capacity: " << slot_to_print.capacity << endl;
	cout << "Current Number of Products: " << slot_to_print.current_number_of_products << endl;
	cout << "Product Name: " << slot_to_print.product_name << endl;
	cout << "Slot Price: " << slot_to_print.price << endl;
	cout << endl;

}

void slot_initialization(Slot* slot_to_initialize, int slot_position, Products* initialization_products, Prices text_prices) {

	slot_to_initialize->letter = position_to_letter(slot_position); // Initializes the slot with it's corresponding letter.
	slot_to_initialize->capacity = rand() % 6 + 5; // Initializes the slot with a random capacity (between 5 and 10 (including both))
	slot_to_initialize->current_number_of_products = slot_to_initialize->capacity; // The slot starts full of products.
	slot_to_initialize->product_name = choose_random_product(initialization_products); // Choose a random product to place on the slot from the remaining products.
	slot_to_initialize->price = text_prices.array[rand() % text_prices.lenght]; // The slot starts with a random price chosen from the prices.txt file.
		
}

char position_to_letter(int slot_position) { // Converts a slot position to it's corresponding letter.
	// I already know the next 10 minutes are going to be boring doing this function.

	switch (slot_position) {

	case 0: return 'A';
	case 1: return 'B';
	case 2: return 'C';
	case 3: return 'D';
	case 4: return 'E';
	case 5: return 'F';
	case 6: return 'G';
	case 7: return 'H';
	case 8: return 'I';
	case 9: return 'J';
	case 10: return 'K';
	case 11: return 'L';
	case 12: return 'M';
	case 13: return 'N';
	case 14: return 'O';
	case 15: return 'P';
	case 16: return 'Q';
	case 17: return 'R';
	case 18: return 'S';
	case 19: return 'T';
	case 20: return 'U';
	case 21: return 'V';
	case 22: return 'W';
	case 23: return 'X';
	case 24: return 'Y';
	case 25: return 'Z';
	default: cout << "Houston, we've had a problem."; // Just like the explosion on Apollo 13, this default should never happen.

	}

}

