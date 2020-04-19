#include <iostream>
#include "files.h"

using namespace std;

struct Slot {

	char letter = 0; // The letter of each slot
	int capacity = 0; // The maximum capacity of each slot.
	string product_name = ""; // The product name that is currently in each slot.
	int current_number_of_products = 0; // The current number of products that each slot contains.
	float price = 0; // The current price of each slot.
};

void print_slot(Slot slot_to_print);
void slot_initialization(Slot* slot_to_initialize, int slot_position, Products* initialization_products, Prices text_prices);
