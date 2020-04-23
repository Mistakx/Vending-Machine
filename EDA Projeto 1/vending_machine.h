#include <iostream>
#include "slots.h"

using namespace std;


struct Vending_machine {
	Slot* slots = 0; // The machine itself is an array of slots.
	int size = 0; // The number of slots the machine contains.
	int cash_box[6]{}; // The number of coins the machine contains. This array is sorted by ascending order: 5 cents, 10 cents, 20 cents, 50 cents, 1 euro, 2 euros.
};

void initialize_vending_machine(Vending_machine* vending_machine, Products* initialization_products, Prices text_prices);

void print_slots(Vending_machine vending_machine);

void print_cashbox(Vending_machine vending_machine);

void check_funds(Vending_machine vending_machine);

void clean_vending_machine(Vending_machine* vending_machine);

void save_vending_machine(Vending_machine vending_machine, string save_location);

void load_vending_machine(string save_location, Vending_machine* vending_machine);

