#include <iostream>
#include "files.h"

using namespace std;

struct Slot {

	char letter = 0; // The letter of the slot
	string product = "Vazio"; // The product that is currently in the slot.
	float price = 0; // The current price of the slot.
	int quantity = 0; // The number of products currently in the slot.
	int capacity = 0; // The maximum capacity of the slot.
};

void initialize_slot(Slot* slot_to_initialize, int slot_position, Products* products, Prices* prices);

void print_slot(Slot slot);

void clean_slot(Slot* slot);





