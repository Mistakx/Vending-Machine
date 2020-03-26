#include <iostream>
#include "header.h"
using namespace std;

product* slot_initialization() {

	int slot_capacity = rand() % 5 + 5; // Generates a random number between 5 and 10 (including both)

	product* pslot = new product[slot_capacity]; // Each slot is an array of products.
	return pslot; // Returns the adress of the first product.

}

