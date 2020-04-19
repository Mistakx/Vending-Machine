#include <iostream>
#include "slots.h"

using namespace std;


struct Vending_machine {
	Slot* slots = 0; // The machine itself is an array of slots.
	int size = 0; // The number of slots the machine contains.
	int cash_box[6]{}; // The number of coins the machine contains. This array is sorted by ascending order: 5 cents, 10 cents, 20 cents, 50 cents, 1 euro, 2 euros.
};

void print_vending_machine(Vending_machine vending_machine);
void vending_machine_initialization(Vending_machine* vending_machine, Products* initialization_products, Prices text_prices);
void save_vending_machine(Vending_machine vending_machine, string save_location);
void load_vending_machine(string save_location, Vending_machine* vending_machine);

