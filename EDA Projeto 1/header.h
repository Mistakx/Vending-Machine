#include <iostream>

using namespace std;

// Globals


//___________________________________________________________________
struct slot {

	char slot_letter = '@'; // I need to initialize to something, why not something that is going to catch my eye if anything goes wrong?
	int slot_capacity = 0;
	string product_name = "";
	int current_number_of_products = 0;
	float slot_price = 0;


};
struct product {

	string product_name = "";
	string profuct_manufacturer = "";
	float product_price = 0;

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
slot* vending_machine_initialization();

//___________________________________________________________________
void slot_initialization(slot slot_to_initialize, int slot_position);
char slot_letter(int slot_position);

//___________________________________________________________________
products products_to_struct(string file_path);
prices prices_to_struct(string file_path);

