#include <iostream>
#include <string>
#include "vending_machine.h"

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

	// !Implementations:

	// Asking the name of the product and the new price, and then throwing an error if the product isn't in the machine.
		// Pros: Asking the product name and price before trying to change it is faster for the machine than checking if the product is there before asking the price.
		// Cons: The employee inputs the new price thinking the product is there only to be met by an error, wasting his valuable time.

	// First checks if the product exists in the machine, then asks for the new price.
		// Pros: It's faster for the employee because the machine throws an error if the product doesn't exist, thus not allowing him to introduce a new price.
		// Cons: It's negligibly slower for the machine because it has to check if the product exists first, before asking the new price.

	// !The chosen implementation was the second. 
	// It makes more sense to first check if the machine contains the chosen product before asking for the new price, since the change in the function's speed is almost null.

	refresh_console(*vending_machine);
	cout << "Nome do produto cujo preço deseja alterar: ";
	string product_name;
	// TODO: Sanitize user input.
	cin.ignore();
	getline(std::cin, product_name); // Needs to be getline because the products can have spaces in their names
	cout << endl;

	if (product_name != "Vazio"){ // !Noted: Better implementation

		bool product_already_in_machine = false;

		for (int i = 0; i < vending_machine->size; i++) {

			if (vending_machine->slots[i].product == product_name) { // If the product entered is in the machine.

				product_already_in_machine = true;
				break; // It only needs to find the product in one slot.
			}

		}

		if (product_already_in_machine) {

			std::cout << "Preço que deseja atribuír a " << product_name << ": ";
			float new_price = 0;
			// TODO: Sanitize user input.
			std::cin >> new_price;
			std::cout << endl;

			// TODO: Check if implementation is correct
			// If entered value is divisible by 5 cents. Converts 0.05 euros to 5 cents to make the conversion possible.
			if ((int(new_price * 100) % 5) == 0) {

				for (int i = 0; i < vending_machine->size; i++) {

					if (vending_machine->slots[i].product == product_name) {

						// TODO: Check if the machine has enough coins.
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
			cout << "O produto inserido não se encontra na máquina." << endl;
			system("pause");
		}
	}

	else { cout << "O nome do produto não pode ser \"Vazio\"." << endl; }



}

void add_slot_menu(Vending_machine* vending_machine) {

	refresh_console(*vending_machine);
	cout << "Letra correspondente ao slot que pretende adicionar: ";
	char letter = 0;
	// TODO: Sanitize user input.
	cin >> letter;
	letter = toupper(letter); // Allows the user to input lower case letters ('a' instead of 'A').
	cout << endl;

	bool slot_exists = false;

	for (int i = 0; i < vending_machine->size; i++) { // Checks if slot already exists
	
		if (letter == vending_machine->slots[i].letter) { // If slots exists

			slot_exists = true;

			cout << "Ocorreu um problema ao tentar adicionar um slot. O slot que introduziu já existe." << endl;
			system("Pause");

			break; // Breaks because there is only one slot with each letter, so there's no need to continue checking.

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


		vending_machine->size += 1;

		delete[] vending_machine->slots;
		vending_machine->slots = new_slots;
		vending_machine->slots[vending_machine->size-1].letter = letter;
		vending_machine->slots[vending_machine->size-1].capacity = capacity;
		

		// TODO: Sort the new machine. 
		// !Noted: The machine only needs to be sorted after the second time this function is called.
		// !	   The first time we are garanteed that the added letter, which was added at the end of the array, is sorted.
		// !	   Example: The array was initialized automatically to A B C D E, we can only add one letter besides these 5 so we are garanteed the new letter is sorted.
		// !				First time we add something: Let's say we added a Z, the new array is A B C D E Z. 
		// !				Second time we add something: If we now want to add a H. Now the array is A B C D E Z H, so we need to sort.


		// TODO: Delete old vending machine.

		
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

void print_array(string* array, int lenght) {

	for (int i = 0; i < lenght; i++) {

		if (array[i] != "") cout << array[i] << endl;

		//cout << array << "[" << i << "]: " << array[i] << endl; // !Debug Version

	}

}

void print_array(float* array, int lenght) {

	for (int i = 0; i < lenght; i++) {

		if (array[i] != 0) cout << array[i] << endl;

		//cout << array << "[" << i << "]: " << array[i] << endl; // !Debug Version

	}

}

bool is_in_array(string word, string* array, int array_lenght) {

	for (int i = 0; i < array_lenght; i++) {

		if (word == array[i]) { return true; }

	}

	return false;

}

bool is_in_array(float value, float* array, int array_lenght) {

	for (int i = 0; i < array_lenght; i++) {

		if (value == array[i]) { return true; }

	}

	return false;

}

void print_products_sorted_alphabetically(Vending_machine vending_machine) { // Sorts all of the machine's products prices.
	// Copies prices to an array, and then sorts that array.
	// This aproach is slower than sorting them directly before copying them to an array, but it's easier to code, understand, and change in the future.

	// The number of maximum unique product names that can exist, is the same as the number of slots (if each slot has an unique product).
	// While we could first check the number of unique product names before storing them to an array (to avoid allocating more space than we need to), there isn't a need to do so.
	// The machine doesn't have enough slots to warrant this memory optimization. We will simply delete the allocated array after the function runs.
	string* sorted_names = new string[vending_machine.size]{}; // Initializes the array.

	for (int i = 0; i < vending_machine.size; i++) {


		// Check if the price isn't already in the array before copying, to avoid duplication.
		if (is_in_array(vending_machine.slots[i].product, sorted_names, vending_machine.size) == false) {

			sorted_names[i] = vending_machine.slots[i].product;

		}

	}

	// TODO: Sorts all products



	// Prints prices to the console
	print_array(sorted_names, vending_machine.size);

	delete[] sorted_names;





}

void print_products_menu(Vending_machine vending_machine) {

	int option = 0;

	cout << "Imprimir produtos: " << endl;
	cout << "	1 - Por ordem alfabética." << endl;
	cout << "	2 - Por preço." << endl;
	cout << "	3 - Por quantidade disponível." << endl;

	// TODO: Sanitize inputs
	cin >> option;

	switch (option) {
	
		case 1: 
			print_products_sorted_alphabetically;
			break;

			/*
		case 2: sort_products_by_price;

		case 3: sort_products_by_quantity;
			*/
			
	default:
		break;
	}

}

//! ------------------------ Add Products ------------------------

bool add_to_fitting_empty_slot(Vending_machine* vending_machine, int adding_quantity, string adding_product){

	// Try to find an empty slot that can fit all the products.
	bool found_fitting_empty_slot = false;

	for (int i = 0; i < vending_machine->size; i++) {

		// If the found slot is empty.
		if (vending_machine->slots[i].quantity == 0) {

			// If the found slot can fit all the products.
			if (vending_machine->slots[i].capacity >= adding_quantity) {

				vending_machine->slots[i].product = adding_product;
				vending_machine->slots[i].quantity = adding_quantity;
				found_fitting_empty_slot = true;
				break; // TODO: Add explanation
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
		cout << "Perfectly balanced, as all things should be.";
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
		cout << "Perfectly balanced, as all things should be.";
		break;

	}
}


void add_products(Vending_machine* vending_machine, int slot_position, char adding_slot_letter, int adding_quantity, string adding_product) {
	
	// If the product quantity to add to the slot overfills that slot.
	if ((adding_quantity + vending_machine->slots[slot_position].quantity) > vending_machine->slots[slot_position].capacity) {

		cout << "A quantidade de produtos que tentou introduzir não cabe no slot escolhido." << endl;
		system("Pause");

		// If the machine doesn't have an empty slot that can fit all the products.
		if (add_to_fitting_empty_slot(vending_machine, adding_quantity, adding_product) == false) {

			// If the chosen slot is full
			if (vending_machine->slots[slot_position].quantity == vending_machine->slots[slot_position].capacity){
				employee_choices_full(vending_machine, slot_position, adding_slot_letter, adding_quantity, adding_product);
			}

			// If the chosen slot isn't full
			else { 
				employee_choices_not_full(vending_machine, slot_position, adding_slot_letter, adding_quantity, adding_product); 
			}

		}

	}

	// If the product quantity to add to the slot doesn't overfill the slot.
	else {
		vending_machine->slots[slot_position].product = adding_product;
		vending_machine->slots[slot_position].quantity += adding_quantity;
	}
}

void add_products_menu(Vending_machine* vending_machine) {

	refresh_console(*vending_machine);
	cout << "Slot a repor: ";
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

				if (adding_product != "Vazio"){ // !Noted: Better implementation

					refresh_console(*vending_machine);
					cout << "Número de produtos a adicionar: ";
					int adding_quantity = 0;
					cin >> adding_quantity;
					cout << endl;

					add_products(vending_machine, i, adding_slot_letter, adding_quantity, adding_product);

					// If the product already exits in the vending machine
					for (int x = 0; x < vending_machine->size; x++) {

						if (adding_product == vending_machine->slots[x].product) {
							vending_machine->slots[i].price = vending_machine->slots[x].price;
						}

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

				add_products(vending_machine, i, adding_slot_letter, adding_quantity, vending_machine->slots[i].product);

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

void employee_menu(Vending_machine* vending_machine){

	refresh_console(*vending_machine);

	cout << "Menu Funcionário:" << endl
		<< "  1 - Limpar Máquina" << endl
		<< "  2 - Limpar Slot" << endl
		<< "  3 - Repor Produto" << endl
		<< "  4 - Alterar Preço" << endl
		<< "  5 - Adicionar Slot" << endl
		<< "  6 - Adicionar Moedas" << endl
		<< "  7 - Remover Moedas" << endl
		<< "  8 - Imprimir Produtos" << endl
		<< "  9 - Imprimir Slots" << endl
		<< "  10 - Gravar Máquina" << endl
		<< "  11 - Carregar Máquina" << endl
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
		print_slots(*vending_machine);
		employee_menu(vending_machine);
		break;


	case 10:
		save_vending_machine_menu(*vending_machine);
		employee_menu(vending_machine);
		break;


	case 11:
		load_vending_machine(vending_machine);
		employee_menu(vending_machine);
		break;


	case 0:
		break;

	default:
		break;
	}

}