#include <iostream>
#include <string>
#include <iomanip>
#include "employee.h"

using namespace std;

//! ------------------------ Machine Operations ------------------------

void clean_slot_menu(Vending_machine* vending_machine) {

	refresh_console(*vending_machine);

	cout << "Slot a limpar: ";
	char cleaning_slot_letter = 0;
	cin >> cleaning_slot_letter;
	cleaning_slot_letter = toupper(cleaning_slot_letter);
	cout << endl;

	bool found_slot = false;

	for (int i = 0; i < vending_machine->size; i++) {
		
		if (vending_machine->slots[i].letter == cleaning_slot_letter) {

			// If slot is already empty
			if ((vending_machine->slots[i].product == "Vazio") && (vending_machine->slots[i].price == 0) && (vending_machine->slots[i].quantity == 0)) {
				cout << "O slot " << vending_machine->slots[i].letter << " já se encontra limpo." << endl;
				system("Pause");
			}
			
			// If slot isn't already empty
			else{

				clean_slot(&vending_machine->slots[i]);

				cout << "O slot " << cleaning_slot_letter << " foi limpo." << endl;
				system("pause");
			}

			found_slot = true;

		}
		
	}
	
	if (found_slot == false) { 
		cout << "Não existe nenhum slot na posição " << cleaning_slot_letter << "." << endl;
		system("pause");
		clean_slot_menu(vending_machine);
	}

}

void change_product_price_menu(Vending_machine* vending_machine) {

	refresh_console(*vending_machine);
	cout << "Nome do produto cujo preço deseja alterar: ";
	string product_name;
	// TODO: Sanitize user input.
	cin.ignore();
	getline(std::cin, product_name);
	cout << endl;

	if (product_name != "Vazio"){

		bool product_already_in_machine = false;

		for (int i = 0; i < vending_machine->size; i++) {

			if (vending_machine->slots[i].product == product_name) { // If the product entered is in the machine.

				product_already_in_machine = true;
				break; // Only needs to find the product in one slot.
			}

		}

		if (product_already_in_machine) {

			std::cout << "Preço que deseja atribuír a " << product_name << ": ";
			float new_price = 0;
			// TODO: Sanitize user input.
			std::cin >> new_price;
			std::cout << endl;

			if (new_price >= 0) {

				// If entered value is divisible by 5 cents. Converts 0.05 euros to 5 cents to make the conversion possible.
				if ((int(new_price * 100) % 5) == 0) {

					for (int i = 0; i < vending_machine->size; i++) {

						if (vending_machine->slots[i].product == product_name) {

							vending_machine->slots[i].price = new_price;

						}
					}
				}

				else {
					cout << "Por favor introduza um valor múltiplo de 5 cêntimos." << endl;
					system("pause");
				}

			}

			else {
				cout << "Por favor introduza um preço positivo." << endl;
				system("pause");
			}

		
		}

		else {
			cout << "O produto inserido não se encontra na máquina." << endl;
			system("pause");
		}
	}

	else {
		cout << "O nome do produto não pode ser \"Vazio\"." << endl;
		system("pause");
	}



}

void add_slot_menu(Vending_machine* vending_machine) {

	refresh_console(*vending_machine);
	cout << "Letra correspondente ao slot que pretende adicionar: ";
	char letter = 0;
	// TODO: Sanitize user input.
	cin >> letter;
	letter = toupper(letter); // Allows the user to input lower case letters ('a' instead of 'A').
	cout << endl;


	if ( (int(letter) > 64) && (int(letter) < 91) ) {

		bool slot_exists = false;

		for (int i = 0; i < vending_machine->size; i++) { //! Noted: Binary search could be used.

			if (letter == vending_machine->slots[i].letter) { // If slots exists

				slot_exists = true;

				cout << "O slot que introduziu já existe." << endl;
				system("Pause");

				break; // There is only one slot with each letter, so there's no need to continue checking.

			}

		}

		// If slot doesn't already exist, create a new vending machine with the new slot at the end.
		if (slot_exists == false) {

			cout << "Capacidade do novo slot (Slot " << letter << "): ";
			int capacity = 0;
			// TODO: Sanitize user input.
			cin >> capacity;
			cout << endl;

			// The new vending machine is going to be one size bigger.
			Slot* new_slots = new Slot[vending_machine->size + 1];

			// Copies the slots.
			for (int i = 0; i < vending_machine->size; i++) {
				new_slots[i] = vending_machine->slots[i];
			}

			vending_machine->size++;
			delete[] vending_machine->slots;
			vending_machine->slots = new_slots;
			vending_machine->slots[vending_machine->size - 1].letter = letter;
			vending_machine->slots[vending_machine->size - 1].capacity = capacity;


			// Sorts the new machine. 
			for (int j = 1; j < vending_machine->size; j++) {

				char letter = vending_machine->slots[j].letter;
				string product = vending_machine->slots[j].product;
				float price = vending_machine->slots[j].price;
				int quantity = vending_machine->slots[j].quantity;
				int capacity = vending_machine->slots[j].capacity;

				int i = j - 1;

				while ((i >= 0) && (vending_machine->slots[i].letter > letter)) {
					vending_machine->slots[i + 1].letter = vending_machine->slots[i].letter;
					vending_machine->slots[i + 1].product = vending_machine->slots[i].product;
					vending_machine->slots[i + 1].price = vending_machine->slots[i].price;
					vending_machine->slots[i + 1].quantity = vending_machine->slots[i].quantity;
					vending_machine->slots[i + 1].capacity = vending_machine->slots[i].capacity;
					i = i - 1;
				}

				vending_machine->slots[i + 1].letter = letter;
				vending_machine->slots[i + 1].product = product;
				vending_machine->slots[i + 1].price = price;
				vending_machine->slots[i + 1].quantity = quantity;
				vending_machine->slots[i + 1].capacity = capacity;

			}




		}

	}

	else {
		cout << "Por favor introduza uma letra entre A e Z." << endl;
		system("Pause");
	}
	
}

void add_coins_menu(Vending_machine* vending_machine) {

	int coins_to_add = 0;

	refresh_console(*vending_machine);
	cout << "Introduza a quantidade de moedas de 2 euros que deseja adicionar: ";
	cin >> coins_to_add;
	vending_machine->cash_box[5] += coins_to_add;

	refresh_console(*vending_machine);
	cout << "Introduza a quantidade de moedas de 1 euro que deseja adicionar: ";
	cin >> coins_to_add;
	vending_machine->cash_box[4] += coins_to_add;

	refresh_console(*vending_machine);
	cout << "Introduza a quantidade de moedas de 50 cêntimos que deseja adicionar: ";
	cin >> coins_to_add;
	vending_machine->cash_box[3] += coins_to_add;

	refresh_console(*vending_machine);
	cout << "Introduza a quantidade de moedas de 20 cêntimos que deseja adicionar: ";
	cin >> coins_to_add;
	vending_machine->cash_box[2] += coins_to_add;

	refresh_console(*vending_machine);
	cout << "Introduza a quantidade de moedas de 10 cêntimos que deseja adicionar: ";
	cin >> coins_to_add;
	vending_machine->cash_box[1] += coins_to_add;

	refresh_console(*vending_machine);
	cout << "Introduza a quantidade de moedas de 5 cêntimos que deseja adicionar: ";
	cin >> coins_to_add;
	vending_machine->cash_box[0] += coins_to_add;

	check_funds(*vending_machine);

}

void remove_coins_menu(Vending_machine* vending_machine){ // Removes coins as the employee enters them, instead of removing them all at once.
	// This implementation is simpler and saves memory because we only need to save on variable to RAM.

	int coins_to_remove = 0;

	refresh_console(*vending_machine);
	cout << "Introduza a quantidade de moedas de 2 euros que deseja remover: ";
	cin >> coins_to_remove;
	cout << endl;
	if ((vending_machine->cash_box[5] - coins_to_remove) >= 0) {
		vending_machine->cash_box[5] -= coins_to_remove;
	}
	else { 
		cout << "A máquina não tem " << coins_to_remove << " moedas de 2 euros." << endl; 
		system("Pause");
	}

	refresh_console(*vending_machine);
	cout << "Introduza a quantidade de moedas de 1 euro que deseja remover: ";
	cin >> coins_to_remove;
	cout << endl;
	if ((vending_machine->cash_box[4] - coins_to_remove) >= 0) {
		vending_machine->cash_box[4] -= coins_to_remove;
	}
	else { 
		cout << "A máquina não tem " << coins_to_remove << " moedas de 1 euro." << endl;
		system("Pause");
	}

	refresh_console(*vending_machine);
	cout << "Introduza a quantidade de moedas de 50 cêntimos que deseja remover: ";
	cin >> coins_to_remove;
	cout << endl;
	if ((vending_machine->cash_box[3] - coins_to_remove) >= 0) {
		vending_machine->cash_box[3] -= coins_to_remove;
	}
	else {
		cout << "A máquina não tem " << coins_to_remove << " moedas de 50 cêntimos." << endl;
		system("Pause");
	}

	refresh_console(*vending_machine);
	cout << "Introduza a quantidade de moedas de 20 cêntimos que deseja remover: ";
	cin >> coins_to_remove;
	cout << endl;
	if ((vending_machine->cash_box[2] - coins_to_remove) >= 0) {
		vending_machine->cash_box[2] -= coins_to_remove;
	}
	else {
		cout << "A máquina não tem " << coins_to_remove << " moedas de 20 cêntimos." << endl;
		system("Pause");
	}

	refresh_console(*vending_machine);
	cout << "Introduza a quantidade de moedas de 10 cêntimos que deseja remover: ";
	cin >> coins_to_remove;
	cout << endl;
	if ((vending_machine->cash_box[1] - coins_to_remove) >= 0) {
		vending_machine->cash_box[1] -= coins_to_remove;
	}
	else {
		cout << "A máquina não tem " << coins_to_remove << " moedas de 10 cêntimos." << endl;
		system("Pause");
	}

	refresh_console(*vending_machine);
	cout << "Introduza a quantidade de moedas de 5 cêntimos que deseja remover: ";
	cin >> coins_to_remove;
	cout << endl;
	if ((vending_machine->cash_box[0] - coins_to_remove) >= 0) {
		vending_machine->cash_box[0] -= coins_to_remove;
	}
	else {
		cout << "A máquina não tem " << coins_to_remove << " moedas de 5 cêntimos." << endl;
		system("Pause");
	}

	check_funds(*vending_machine);
}

//! ------------------------ Sorting ------------------------

bool vending_machine_is_empty(Vending_machine vending_machine) {

	for (int i = 0; i < vending_machine.size; i++) {

		if (vending_machine.slots[i].quantity != 0) { return false; }

	}

	return true;
}

void print_array(string* array, int lenght) {

	cout << " ---------------------------" << endl;

	for (int i = 0; i < lenght; i++) {

		if (array[i] != "") {
			cout << "| "<< setw(26) << array[i] << "|" << endl;
		}
		

	}

	cout << " ---------------------------" << endl;

}

bool is_in_array(string word, string* array, int array_lenght) {

	for (int i = 0; i < array_lenght; i++) {

		if (word == array[i]) { return true; }

	}

	return false;

}

bool is_in_array(string product, Slot* array, int array_lenght) {

	for (int i = 0; i < array_lenght; i++) {

		if (product == array[i].product) { return true; }

	}

	return false;

}

void print_products_sorted_alphabetically(Vending_machine vending_machine) {

	string* sorted_products = new string[vending_machine.size]{}; // Initializes the array.

	for (int i = 0; i < vending_machine.size; i++) {

		// Check if the product isn't already in the array before copying, to avoid duplication.
		if (is_in_array(vending_machine.slots[i].product, sorted_products, vending_machine.size) == false) {

			sorted_products[i] = vending_machine.slots[i].product;

		}

	}

	// Sorts product names alphabetically
	for (int j = 1; j < vending_machine.size; j++) {

		string product = sorted_products[j];

		int i = j - 1;

		while ((i >= 0) && (sorted_products[i] > product)) {
			sorted_products[i + 1] = sorted_products[i];
			i = i - 1;
		}

		sorted_products[i + 1] = product;

	}


	// Prints products to the console
	refresh_console(vending_machine);
	print_array(sorted_products, vending_machine.size);
	system("Pause");

	delete[] sorted_products;





}

void print_products_sorted_by_price(Vending_machine vending_machine) {

	Slot* sorted_slots = new Slot[vending_machine.size]; // Initializes the array.

	for (int i = 0; i < vending_machine.size; i++) {

		// Check if the price isn't already in the array before copying, to avoid duplication.
		if (is_in_array(vending_machine.slots[i].product, sorted_slots, vending_machine.size) == false) {

			sorted_slots[i] = vending_machine.slots[i];

		}

	}

	// Sorts the prices
	for (int j = 1; j < vending_machine.size; j++) {

		float price = sorted_slots[j].price;
		string product = sorted_slots[j].product;

		int i = j - 1;

		while ((i >= 0) && (sorted_slots[i].price > price)) {
			sorted_slots[i + 1].product = sorted_slots[i].product;
			sorted_slots[i + 1].price = sorted_slots[i].price;
			i = i - 1;
		}

		sorted_slots[i + 1].price = price;
		sorted_slots[i + 1].product = product;

	}
	
	

	// Prints prices to the console
	refresh_console(vending_machine);

	cout << left << setw(26) << "  Produto" << "Preço" << endl
		<< " ------------------------------" << endl;
	for (int i = 0; i < vending_machine.size; i++) {

		if (sorted_slots[i].product != "Vazio") {

			cout << "| " << setw(24) << sorted_slots[i].product << setw(5) << sorted_slots[i].price << "|" << endl;

		}

	}

	cout << " ------------------------------" << endl;

	delete[] sorted_slots;
	system("Pause");


}

void print_products_sorted_by_quantity(Vending_machine vending_machine) {
	Slot* sorted_slots = new Slot[vending_machine.size]; // Initializes the array.

	// Places products in sorted slots.
	for (int i = 0; i < vending_machine.size; i++) {

		bool product_already_in_array = false;

		for (int x = 0; x < vending_machine.size; x++) {

			// If the product is already in a slot.
			if (vending_machine.slots[i].product == sorted_slots[x].product) {

				sorted_slots[x].quantity += vending_machine.slots[i].quantity;
				product_already_in_array = true;

			}

		}

		// If the price isn't already in a slot before copying.
		if (product_already_in_array == false) { sorted_slots[i] = vending_machine.slots[i]; }
	}

	// Sorts Products
	for (int j = 1; j < vending_machine.size; j++) {

		string product = sorted_slots[j].product;
		int quantity = sorted_slots[j].quantity;

		int i = j - 1;

		while ((i >= 0) && (sorted_slots[i].quantity > quantity)) {
			sorted_slots[i + 1].product = sorted_slots[i].product;
			sorted_slots[i + 1].quantity = sorted_slots[i].quantity;
			i = i - 1;
		}

		sorted_slots[i + 1].product = product;
		sorted_slots[i + 1].quantity = quantity;

	}

	// Prints sorted products
	refresh_console(vending_machine);

	cout << left << setw(26) << "  Produto" << "Quant." << endl
		<< " -------------------------------" << endl;
	for (int i = 0; i < vending_machine.size; i++) {

		if (sorted_slots[i].product != "Vazio") {

			cout << "| " << setw(24) << sorted_slots[i].product << setw(6) << sorted_slots[i].quantity << "|" << endl;

		}

	}

	cout << " -------------------------------" << endl;

	delete[] sorted_slots;
	system("Pause");

}

void print_products_menu(Vending_machine vending_machine) {

	int option = 0;

	refresh_console(vending_machine);

	if (vending_machine_is_empty(vending_machine) == false) {

		cout << "Imprimir produtos: " << endl;
		cout << "  1 - Por ordem alfabética." << endl;
		cout << "  2 - Por preço." << endl;
		cout << "  3 - Por quantidade disponível." << endl;

		// TODO: Sanitize inputs
		cin >> option;

		switch (option) {

		case 1:
			print_products_sorted_alphabetically(vending_machine);
			break;

		case 2:
			print_products_sorted_by_price(vending_machine);
			break;

		case 3:
			print_products_sorted_by_quantity(vending_machine);
			break;

		default:
			break;
		}
	}

	else {
		cout << "Não é possível imprimir nenhum produto pois a máquina está vazia." << endl;
		system("Pause");
	}

}

//! ------------------------ Add Products ------------------------

bool product_already_exists(Vending_machine* vending_machine, string product) {

	for (int i = 0; i < vending_machine->size; i++) {

		if (product == vending_machine->slots[i].product) { return true; }

	}

	return false;

}

bool add_to_fitting_empty_slot(Vending_machine* vending_machine, int adding_quantity, string adding_product, float price){

	// Try to find an empty slot that can fit all the products.
	bool found_fitting_empty_slot = false;

	for (int i = 0; i < vending_machine->size; i++) {

		// If the found slot is empty.
		if (vending_machine->slots[i].quantity == 0) {

			// If the found slot can fit all the products.
			if (vending_machine->slots[i].capacity >= adding_quantity) {

				vending_machine->slots[i].product = adding_product;
				vending_machine->slots[i].price = price;
				vending_machine->slots[i].quantity = adding_quantity;
				found_fitting_empty_slot = true;
				break; 

			}
		}
	}

	if (found_fitting_empty_slot) {
		cout << "Os produtos foram introduzidos num slot vazio." << endl;
		system("pause");
	}
	else {
		cout << "Não foi encontrado nenhum slot vazio com capacidade suficiente para suportar o número de produtos inseridos." << endl;
		system("Pause");

	}

	return found_fitting_empty_slot;


}

void employee_choices_not_full(Vending_machine* vending_machine, int slot_position, char adding_slot_letter, int adding_quantity, string adding_product) {

	refresh_console(*vending_machine);

	cout << "O que deseja fazer: " << endl;
	cout << "  1 - Alterar a capacidade do slot " << adding_slot_letter << " de forma a acomodar todos os produtos inseridos." << endl;
	cout << "  2 - Inserir apenas os produtos que conseguem ser inseridos tendo em conta a capacidade do slot " << adding_slot_letter << "." << endl;
	cout << "  0 - Voltar" << endl;

	int choice = 0;
	cin >> choice;

	switch (choice) {

	case 1:
		vending_machine->slots[slot_position].quantity += adding_quantity;
		vending_machine->slots[slot_position].capacity = vending_machine->slots[slot_position].quantity;
		vending_machine->slots[slot_position].product = adding_product;
		break;


	case 2:
		vending_machine->slots[slot_position].quantity = vending_machine->slots[slot_position].capacity;
		vending_machine->slots[slot_position].product = adding_product;
		break;

	case 0:
		break;

	default:
		break;

	}
}

void employee_choices_full(Vending_machine* vending_machine, int slot_position, char adding_slot_letter, int adding_quantity, string adding_product) {

	refresh_console(*vending_machine);

	cout << "O que deseja fazer: " << endl;
	cout << "  1 - Alterar a capacidade do slot " << adding_slot_letter << " de forma a acomodar todos os produtos inseridos." << endl;
	cout << "  0 - Voltar" << endl;

	int choice = 0;
	cin >> choice;

	switch (choice) {

	case 1:
		vending_machine->slots[slot_position].quantity += adding_quantity;
		vending_machine->slots[slot_position].capacity = vending_machine->slots[slot_position].quantity;
		vending_machine->slots[slot_position].product = adding_product;
		break;

	case 0:
		break;

	default:
		break;

	}
}

void add_products_to_empty_slot(Vending_machine* vending_machine, int slot_position, char adding_slot_letter, int adding_quantity, string adding_product) {

	bool product_already_exists = false;
	float price = 0;

	for (int i = 0; i < vending_machine->size; i++) {

		if (adding_product == vending_machine->slots[i].product) {

			price = vending_machine->slots[i].price; // Changes the price to match the already existing product's price.
			product_already_exists = true;

		}

	}

	// If the product quantity to add to the slot overfills that slot.
	if ((adding_quantity + vending_machine->slots[slot_position].quantity) > vending_machine->slots[slot_position].capacity) {

		cout << "A quantidade de produtos que tentou introduzir não cabe no slot escolhido." << endl;
		system("Pause");

		// If the machine doesn't have an empty slot that can fit all the products.
		if (add_to_fitting_empty_slot(vending_machine, adding_quantity, adding_product, price) == false) {

			// If the chosen slot is full
			if (vending_machine->slots[slot_position].quantity == vending_machine->slots[slot_position].capacity) {
				employee_choices_full(vending_machine, slot_position, adding_slot_letter, adding_quantity, adding_product);
			}

			// If the chosen slot isn't full
			else {
				employee_choices_not_full(vending_machine, slot_position, adding_slot_letter, adding_quantity, adding_product);
			}

		}

	}

	// If the product quantity to add to the slot doesn't overfill that slot.
	else {
		vending_machine->slots[slot_position].product = adding_product;
		vending_machine->slots[slot_position].price = price;
		vending_machine->slots[slot_position].quantity += adding_quantity;
	}

}

void add_products_to_non_empty_slot(Vending_machine* vending_machine, int slot_position, char adding_slot_letter, int adding_quantity, string adding_product) {

	// If the product quantity to add to the slot overfills that slot.
	if ((adding_quantity + vending_machine->slots[slot_position].quantity) > vending_machine->slots[slot_position].capacity) {

		cout << "A quantidade de produtos que tentou introduzir não cabe no slot escolhido." << endl;
		system("Pause");

		// If the machine doesn't have an empty slot that can fit all the products.
		if (add_to_fitting_empty_slot(vending_machine, adding_quantity, adding_product, vending_machine->slots[slot_position].price) == false) {

			// If the chosen slot is full
			if (vending_machine->slots[slot_position].quantity == vending_machine->slots[slot_position].capacity) {
				employee_choices_full(vending_machine, slot_position, adding_slot_letter, adding_quantity, adding_product);
			}

			// If the chosen slot isn't full
			else {
				employee_choices_not_full(vending_machine, slot_position, adding_slot_letter, adding_quantity, adding_product);
			}

		}

	}

	// If the product quantity to add to the slot doesn't overfill that slot.
	else {
		vending_machine->slots[slot_position].product = adding_product;
		vending_machine->slots[slot_position].quantity += adding_quantity;
	}

}

void add_products_menu(Vending_machine* vending_machine) {

	refresh_console(*vending_machine);
	cout << "Slot a adicionar/repor: ";
	char adding_slot_letter = 0;
	cin >> adding_slot_letter;
	adding_slot_letter = toupper(adding_slot_letter);

	bool found_slot = false;

	for (int i = 0; i < vending_machine->size; i++) { // !Noted: Binary search could be used.

		// Finds the chosen slot.
		if (vending_machine->slots[i].letter == adding_slot_letter) {

			// If the chosen slot is empty.
			if (vending_machine->slots[i].quantity == 0) {

				refresh_console(*vending_machine);
				cout << "Nome do produto: ";
				string adding_product = "";
				cin.ignore();
				getline(cin, adding_product);


				if (adding_product != "Vazio") {

					refresh_console(*vending_machine);
					cout << "Número de produtos a adicionar: ";
					int adding_quantity = 0;
					cin >> adding_quantity;
					cout << endl;

					if (adding_quantity >= 0) {

						add_products_to_empty_slot(vending_machine, i, adding_slot_letter, adding_quantity, adding_product);
					}

					else {
						cout << "Introduza um número válido de produtos a adicionar." << endl;
						system("Pause");
					}

				}

				else { 
					cout << "O nome do produto não pode ser \"Vazio\" " << endl;
					system("Pause");
				}

			}

			// If the chosen slot isn't empty.
			else {

				refresh_console(*vending_machine);
				cout << "Número de produtos a repor: ";
				int adding_quantity = 0;
				cin >> adding_quantity;
				cout << endl;

				if (adding_quantity >= 0) {
					add_products_to_non_empty_slot(vending_machine, i, adding_slot_letter, adding_quantity, vending_machine->slots[i].product);
				}

				else {
					cout << "Introduza um número válido de produtos a repor." << endl;
					system("Pause");
				}


			}

			found_slot = true;
			break;

		}
	}

	if (found_slot == false) { 
		cout << "Não existe nenhum slot na posição " << adding_slot_letter << "." << endl;
		system("pause");
		add_products_menu(vending_machine);
			
	}


}

//! ------------------------ Save and Load ------------------------


void save_vending_machine_menu(Vending_machine vending_machine) {

	refresh_console(vending_machine);

	cout << "Gravar a máquina na localização: ";
	
	string save_path = "";
	cin.ignore();
	getline(cin, save_path);
	cout << endl;

	save_vending_machine(vending_machine, save_path);

}

void load_vending_machine(Vending_machine* vending_machine) {

	refresh_console(*vending_machine);

	cout << "Carregar a máquina gravada na localização: ";

	string load_path = "";
	cin.ignore();
	getline(cin, load_path);
	cout << endl;


	load_vending_machine(load_path, vending_machine);


}

//! ------------------------ Main Employee Menu ------------------------

void employee_menu(Vending_machine* vending_machine){

	refresh_console(*vending_machine);

	cout << "Menu Funcionário:" << endl
		<< "  1 - Limpar Máquina" << endl
		<< "  2 - Limpar Slot" << endl
		<< "  3 - Adicionar/Repor Produto" << endl
		<< "  4 - Alterar Preço" << endl
		<< "  5 - Adicionar Slot" << endl
		<< "  6 - Adicionar Moedas" << endl
		<< "  7 - Remover Moedas" << endl
		<< "  8 - Imprimir Produtos" << endl
		<< "  9 - Gravar Máquina" << endl
		<< "  10 - Carregar Máquina" << endl
		<< "  0 - Voltar" << endl << endl;

	int choice = 0;
	cin >> choice;

	switch (choice)
	{

	case 1: 
		clean_vending_machine(vending_machine);
		employee_menu(vending_machine);
		break;

	case 2: 
		clean_slot_menu(vending_machine);
		employee_menu(vending_machine);
		break;


	case 3: 
		add_products_menu(vending_machine);
		employee_menu(vending_machine);
		break;

	case 4:
		change_product_price_menu(vending_machine);
		employee_menu(vending_machine);
		break;


	case 5:
		add_slot_menu(vending_machine);
		employee_menu(vending_machine);
		break;


	case 6:
		add_coins_menu(vending_machine);
		employee_menu(vending_machine);
		break;


	case 7:
		remove_coins_menu(vending_machine);
		employee_menu(vending_machine);
		break;


	case 8:
		print_products_menu(*vending_machine);
		employee_menu(vending_machine);
		break;

	case 9:
		save_vending_machine_menu(*vending_machine);
		employee_menu(vending_machine);
		break;


	case 10:
		load_vending_machine(vending_machine);
		employee_menu(vending_machine);
		break;


	case 0:
		break;

	default:
		break;
	}

}