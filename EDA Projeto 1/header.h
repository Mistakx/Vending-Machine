#include <iostream>
using namespace std;


//___________________________________________________________________
// Structs
struct slot {

	char letter = '@'; // I need to initialize to something, why not something that is going to catch my eye if anything goes wrong?
	int capacity = 0;
	string product_name = "";
	int current_number_of_products = 0;
	float price = 0;


};
struct product {

	string name = "";
	string manufacturer = "";
	float price = 0;

};
struct products {
	string* array = 0;
	int lenght = 0;
};
struct prices {

	float* array = 0;
	int lenght = 0;
};


//___________________________________________________________________
// vending_machine.cpp
slot* vending_machine_initialization(products* initialization_products, prices* text_prices);


//___________________________________________________________________
// slots.cpp
void slot_initialization(slot slot_to_initialize, int slot_position, products* initialization_products, prices* text_prices);
char slot_letter(int slot_position);


//___________________________________________________________________
// products.cpp 
string choose_random_product(products* products_to_choose_from);

//___________________________________________________________________
// files.cpp
products products_to_struct(string file_path);
prices prices_to_struct(string file_path);




void print_array(string* array, int lenght);