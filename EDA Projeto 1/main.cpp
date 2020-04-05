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

	// TODO: Check if these should be converted to constants
	string produtos_txt = "C:\\Users\\Mistakx\\Desktop\\produtos.txt";
	string precos_txt = "C:\\Users\\Mistakx\\Desktop\\precos.txt";
	string maquina_guardada_txt = "C:\\Users\\Mistakx\\Desktop\\maquina_guardada.txt";


	// Structs to be kept as they are after being imported from the text documents.
	// These are not touched by the initialization process and remain the same for as long as the machine is running.
	Products text_products = products_to_struct(&produtos_txt);
	Prices text_prices = prices_to_struct(&precos_txt);

	// Struct used to initialize the vending machine. This varies when a product is placed, and consequently removed from
	// the struct.
	Products initialization_products = text_products;

	Vending_machine vending_machine; // Reserves memory for the Vending Machine.
	vending_machine_initialization(&vending_machine, &initialization_products, &text_prices); // Initializes the machine and saves it's adress.
	save_vending_machine(&vending_machine, &maquina_guardada_txt);
	cout << vending_machine.slots[0].letter;
	return 0;


}

// TODO: CHECK IF ALL THE DEPENDECIES ARE CORRECT!