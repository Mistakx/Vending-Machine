#include <iostream>
using namespace std;


//___________________________________________________________________
// Structs


struct Slot {

	char letter = '@'; // I need to initialize to something else than an empty, why not something that is going to catch my eye if anything goes wrong?
	int capacity = 0; // The maximum capacity of each slot.
	string product_name = ""; // The product name that is currently in each slot.
	int current_number_of_products = 0; // The current number of products that each slot contains.
	float price = 0; // The current price of each slot.
};
struct Vending_machine {
	Slot* slots = 0; // The machine itself is an array of slots.
	int size = 0; // The number of slots the machine contains.
};
struct Product {

	string name = "";
	string manufacturer = "";
	float price = 0;

};
struct Products {
	string* array = 0; // The array that contains each product.
	int lenght = 0; // The array lenght.
};
struct Prices {
	float* array = 0; // The array that contains each price.
	int lenght = 0; // The array lenght.
};

//___________________________________________________________________
// employee.cpp
void clean_slot(Slot* slot);
void clean_vending_machine(Vending_machine* vending_machine);
void change_product_price(Vending_machine* vending_machine);
void add_slot(Vending_machine* vending_machine);
int letter_to_position(char letter);


//___________________________________________________________________
// vending_machine.cpp
void print_vending_machine(Vending_machine vending_machine);
void vending_machine_initialization(Vending_machine* vending_machine, Products* initialization_products, Prices text_prices);
void save_vending_machine(Vending_machine vending_machine, string save_location);
void load_vending_machine(string save_location, Vending_machine* vending_machine);


//___________________________________________________________________
// slots.cpp
void print_slot(Slot slot_to_print);
void slot_initialization(Slot* slot_to_initialize, int slot_position, Products* initialization_products, Prices text_prices);
char position_to_letter(int slot_position);

//___________________________________________________________________
// products.cpp 
string choose_random_product(Products* products_to_choose_from);

//___________________________________________________________________
// files.cpp
Products products_to_struct(string file_path);
Prices prices_to_struct(string file_path);


void print_array(string* array, int lenght);