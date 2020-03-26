#include <iostream>
#include "header.h"
using namespace std;

slot* vending_machine_initialization() {

	int number_of_slots = rand() % 4 + 9; // Generates a random number between 9 and 12 (including both)


	slot* pvending_machine = new slot[number_of_slots]; // The vending machine is an array of slots.
	
	for (int i = 0; i < number_of_slots; i++) {
		slot_initialization(pvending_machine[i], i); // Vending Machine is an array of slots. Type: slot*. Each slot is a struct so there's no need to pass by reference. 
		// Thanks debugger for the help :D. Usually print debugging does the work but not this time.

	}

	return pvending_machine; // Returns the adress of the first slot.

}

