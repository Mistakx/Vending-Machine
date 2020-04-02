#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "header.h"
using namespace std;

int main() {

	srand(time(NULL)); // Initializes the random number generator time(NULL) as the seed.
	// time(NULL) is the total number of seconds that have passed since 1-Jan-1970
	// While not totally random (nothing truly is), this pseudo-random function will do because there are no security concerns with the machine's initialization.


	const string produtos_txt = "C:\\Users\\Mistakx\\Desktop\\produtos.txt";
	const string precos_txt = "C:\\Users\\Mistakx\\Desktop\\precos.txt";

	// Structs to be kept as they are after being imported from the text documents.
	// These are not touched by the initialization process and remain the same for as long as the machine is running.
	products text_products = products_to_struct(produtos_txt);
	prices text_prices = prices_to_struct(precos_txt);

	// Struct used to initialize the vending machine. This varies when a product is placed, and consequently removed from
	// the struct.
	products initialization_products = text_products;


	vending_machine_initialization(&initialization_products, &text_prices);
	return 0;


}

// TODO: CHECK IF ALL THE DEPENDECIES ARE CORRECT!