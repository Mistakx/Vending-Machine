#include <iostream>
#include "header.h"
using namespace std;

slot* vending_machine_initialization() {

	int number_of_slots = rand() % 4 + 9; // Generates a random number between 9 and 12 (including both)


	slot* pvending_machine = new slot[number_of_slots]; // The vending machine is an array of slots.
	return pvending_machine; // Returns the adress of the first slot.

}

