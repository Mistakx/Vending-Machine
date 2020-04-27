#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "vending_machine.h"

using namespace std;

//! ------------------------ Vending Machine Operations ------------------------

void initialize_vending_machine(Vending_machine* vending_machine, Products* initialization_products, Prices prices) {

	cout << "A inicializar a máquina de vendas..." << endl;

	// Initializes the vending_machine size.
	vending_machine->size = rand() % 4 + 9; // Generates a random number between 9 and 12 (including both)

	// Initializes the vending_machine coins.
	for (int i = 0; i < 6; i++) {

		vending_machine->cash_box[i] = rand() % 11 + 10; // Generates a random number between 10 and 20 (including both)

	}

	// Initializes each vending_machine sort.
	vending_machine->slots = new Slot[vending_machine->size]; // The vending machine is an array of slots.
	for (int i = 0; i < vending_machine->size; i++) {

		initialize_slot(&vending_machine->slots[i], i, initialization_products, prices);

	}

	// !Debug: Prints the remaining products that were not used in the initialization.
	//cout << "Remaining Products: " << endl; // Debug
	//print_array(initialization_products->array, initialization_products->lenght); // Debug
	//cout << endl; // Debug





}

void clean_vending_machine(Vending_machine* vending_machine) {

	for (int i = 0; i < vending_machine->size; i++) {

		clean_slot(&vending_machine->slots[i]);

	}

}

void print_slots(Vending_machine vending_machine) {
	
	cout << endl;

	//! Reference: https://pt.wikipedia.org/wiki/Lista_de_abreviaturas
	cout << left << setw(12) << "  Slot" << setw(26) << "Produto" << setw(11) << "Preço" << setw(12) << "Quant." << "Capac." << endl;

	cout << " ------------------------------------------------------------------" << endl;

	for (int i = 0; i < vending_machine.size; i++) {

		print_slot(vending_machine.slots[i]);

	}

	cout << " ------------------------------------------------------------------" << endl;


}

void print_cashbox(Vending_machine vending_machine) {

	cout << " ------------------------- Caixa -------------------------" << endl

		<< "| 2 euros   1 euro   50 cent   20 cent   10 cent   5 cent |" << endl
		<< "| " << setw(10) << vending_machine.cash_box[5] << setw(9) << vending_machine.cash_box[4] << setw(10) << vending_machine.cash_box[3] 
		<< setw(10) << vending_machine.cash_box[2] << setw(10) << vending_machine.cash_box[1] << setw(7) << vending_machine.cash_box[0] << "|" << endl
		
		<< " ---------------------------------------------------------" << endl << endl;

}

void refresh_console(Vending_machine vending_machine) {

	system("cls");
	print_slots(vending_machine);
	print_cashbox(vending_machine);

}

void check_funds(Vending_machine vending_machine) { 
	// !Noted: Improvement in case of 1 coin left

	bool low_on_funds = false;

	if (vending_machine.cash_box[5] == 0) {
		cout << "Não existem moedas de 2 euros." << endl;
		low_on_funds = true;
	} 
	else if (vending_machine.cash_box[5] == 1) {
		cout << "Existe apenas uma moeda de 2 euros." << endl;
		low_on_funds = true;
	}
	else if (vending_machine.cash_box[5] < 4) {
		cout << "Existem apenas " << vending_machine.cash_box[5] << " moedas de 2 euros." << endl;
		low_on_funds = true;
	}

	if (vending_machine.cash_box[4] == 0) {
		cout << "Não existem moedas de 1 euro." << endl;
		low_on_funds = true;
	}
	else if (vending_machine.cash_box[4] == 1) {
		cout << "Existe apenas uma moeda de 1 euro." << endl;
		low_on_funds = true;
	}
	else if (vending_machine.cash_box[4] < 4) {
		cout << "Existem apenas " << vending_machine.cash_box[4] << " moedas de 1 euro." << endl; 
		low_on_funds = true; 
	}

	if (vending_machine.cash_box[3] == 0) {
		cout << "Não existem moedas de 50 cêntimos." << endl;
		low_on_funds = true;
	}
	else if (vending_machine.cash_box[3] == 1) {
		cout << "Existe apenas 1 moeda de 50 cêntimos." << endl;
		low_on_funds = true;
	}
	else if (vending_machine.cash_box[3] < 4) { 
		cout << "Existem apenas " << vending_machine.cash_box[3] << " moedas de 50 cêntimos." << endl;
		low_on_funds = true;
	}

	if (vending_machine.cash_box[2] == 0) {
		cout << "Não existem moedas de 20 cêntimos." << endl;
		low_on_funds = true;
	}
	else if (vending_machine.cash_box[2] == 1) {
		cout << "Existe apenas 1 moeda de 20 cêntimos." << endl;
		low_on_funds = true;
	}
	else if (vending_machine.cash_box[2] < 4) { 
		cout << "Existem apenas " << vending_machine.cash_box[2] << " moedas de 20 cêntimos." << endl; 
		low_on_funds = true;
	}

	if (vending_machine.cash_box[1] == 0) {
		cout << "Não existem moedas de 10 cêntimos." << endl;
		low_on_funds = true;
	}
	else if (vending_machine.cash_box[1] == 1) {
		cout << "Existe apenas 1 moeda de 10 cêntimos." << endl;
		low_on_funds = true;
	}
	else if (vending_machine.cash_box[1] < 4) { 
		cout << "Existem apenas " << vending_machine.cash_box[1] << " moedas de 10 cêntimos." << endl; 
		low_on_funds = true;
	}

	if (vending_machine.cash_box[0] == 0) {
		cout << "Não existem moedas de 5 cêntimos." << endl;
		low_on_funds = true;
	}
	else if (vending_machine.cash_box[0] == 1) {
		cout << "Existe apenas 1 moeda de 5 cêntimos." << endl;
		low_on_funds = true;
	}
	else if (vending_machine.cash_box[0] < 4) { 
		cout << "Existem apenas " << vending_machine.cash_box[5] << " moedas de 5 cêntimos." << endl; 
		low_on_funds = true;
	}

	if (low_on_funds) { system("Pause"); }

}

void save_vending_machine(Vending_machine vending_machine, string file_path) {
	// The save file is organized in a way that it is easy to be read by both a human and a computer.
	// Each slot is separated by a space, and it's values are always saved in the same order.
	// The order being: Slot Letter, Slot Capacity, Current Number of Products, Product Name, Slot Price.
	// Each line contains a string explaining what the value that follows it represents. 
	// While the file ends up being bigger, we believe the added readability is important, and the added file size is negligible.

	ofstream file(file_path);

	if (file.is_open()) {

		file << "Vending Machine Size: " << vending_machine.size << endl
			<< "Cash Box - 2 euros: " << vending_machine.cash_box[5] << endl
			<< "Cash Box - 1 euro: " << vending_machine.cash_box[4] << endl
			<< "Cash Box - 50 cents: " << vending_machine.cash_box[3] << endl
			<< "Cash Box - 20 cents: " << vending_machine.cash_box[2] << endl
			<< "Cash Box - 10 cents: " << vending_machine.cash_box[1] << endl
			<< "Cash Box - 5 cents: " << vending_machine.cash_box[0] << endl
			<< endl;

		for (int i = 0; i < vending_machine.size; i++) {

			file << "Slot Letter: " << vending_machine.slots[i].letter << endl;
			file << "Slot Capacity: " << vending_machine.slots[i].capacity << endl;
			file << "Current Number of Products: " << vending_machine.slots[i].quantity << endl;
			file << "Product Name: " << vending_machine.slots[i].product << endl;
			file << "Slot Price: " << vending_machine.slots[i].price << endl;
			file << endl;

		}


		file.close();

		system(("attrib +r " + file_path).c_str()); // Changes the file to read only. Only works on windows. 

		// TODO: Cross platform this.
		// The system function argument requires a C style string, C++ strings are different. Therefore c_str() is used.
		// Reference 1: https://stackoverflow.com/questions/4907805/using-variables-in-system-function-c
		// Reference 2: https://stackoverflow.com/questions/7416445/what-is-use-of-c-str-function-in-c

		cout << "A máquina foi gravada em \"" << file_path << "\"." << endl;
		system("pause");

	}

	else {
		cout << "Ocorreu um problema ao tentar abrir \"" << file_path << "\"."
		<< endl << "A localização é inválida ou o ficheiro está a ser usado por outro processo." << endl;
		system("pause");
	}
}

void load_vending_machine(string file_path, Vending_machine* vending_machine ) {

	ifstream file(file_path);

    if (file.is_open()) {

        string line = "";

		// Reads the first line (where the machine size is located), and loads the machine size to the value read.
		getline(file, line);
		vending_machine->size = stoi(line.substr(22));
		vending_machine->slots = new Slot[vending_machine->size];

		// Loads the coins.
		getline(file, line);
		vending_machine->cash_box[5] = stoi(line.substr(20));
		getline(file, line);
		vending_machine->cash_box[4] = stoi(line.substr(19));
		getline(file, line);
		vending_machine->cash_box[3] = stoi(line.substr(21));
		getline(file, line);
		vending_machine->cash_box[2] = stoi(line.substr(21));
		getline(file, line);
		vending_machine->cash_box[1] = stoi(line.substr(21));
		getline(file, line);
		vending_machine->cash_box[0] = stoi(line.substr(20));

		// Reads and then loads each slot.
		for (int i = 0; i < vending_machine->size; i++) {
			getline(file, line); // The first line is always a space that separates each slot.
			getline(file, line); // Slot letter.
			vending_machine->slots[i].letter = line[13];
			getline(file, line); // Slot capacity.
			vending_machine->slots[i].capacity = stoi(line.substr(15));
			getline(file, line); // Current number of products.
			vending_machine->slots[i].quantity = stoi(line.substr(28));
			getline(file, line); // Product name.
			vending_machine->slots[i].product = line.substr(14);
			getline(file, line); // Slot price.
			vending_machine->slots[i].price = stof(line.substr(12));

		}

        file.close();

		cout << "A máquina \"" << file_path << "\" foi carregada." << endl;
		system("Pause");


    }

	else {
		cout << "Ocorreu um erro ao tentar abrir \"" << file_path << "\"." << endl << "O ficheiro não existe ou está a ser usado por outro processo." << endl;
		system("Pause");
	}

}