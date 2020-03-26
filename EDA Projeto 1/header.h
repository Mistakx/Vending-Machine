#include <iostream>
using namespace std;

//___________________________________________________________________
struct slot {

	char slot_letter;
	int slot_capacity;
	string product_name;
	int number_of_products;


};
struct product {

	string product_name;
	string profuct_manufacturer;
	float product_price;

};

//___________________________________________________________________
slot* vending_machine_initialization();

//___________________________________________________________________
void slot_initialization(slot slot_to_initialize, int slot_position);
char slot_letter(int slot_position);

//___________________________________________________________________
string* file_to_array(string file_path);


