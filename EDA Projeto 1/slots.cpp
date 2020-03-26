#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;



void slot_initialization(slot slot_to_initialize, int slot_position) {

	int slot_capacity = rand() % 6 + 5; // Generates a random number between 5 and 10 (including both)

	slot_to_initialize.slot_letter = slot_letter(slot_position);
	slot_to_initialize.slot_capacity = slot_capacity;
	

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
