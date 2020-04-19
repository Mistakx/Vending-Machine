#include <iostream>

using namespace std;

// These structs are the parsed files, so I think they should be defined in this header.
struct Products {
	string* array = 0; // The array that contains each product.
	int lenght = 0; // The array lenght.
};
struct Prices {
	float* array = 0; // The array that contains each price.
	int lenght = 0; // The array lenght.
};


void prices_text_parsing(string file_path, Prices* prices);
void products_text_parsing(string file_path, Products* products);
