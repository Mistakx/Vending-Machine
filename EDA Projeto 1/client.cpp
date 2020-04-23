#include <iostream>
#include "vending_machine.h"
using namespace std;

bool give_change(Vending_machine* vending_machine, int total_entered) {

	cout << "HERE 1" << endl; // DEBUG

	int two_euro_change = 0;
	while ((total_entered > 2) && (vending_machine->cash_box[5] > 0)) {
		two_euro_change++;
		total_entered -= 2;
	}

	int one_euro_change = 0;
	while ((total_entered > 1) && (vending_machine->cash_box[4] > 0)) {
		one_euro_change++;
		total_entered -= 1;
	}

	int fifty_cents_change = 0;
	while ((total_entered > 0.50) && (vending_machine->cash_box[3] > 0)) {
		fifty_cents_change++;
		total_entered -= 0.50;
		cout << "HERE 2" << endl; // DEBUG
	}

	int twenty_cents_change = 0;
	while ((total_entered > 0.20) && (vending_machine->cash_box[2] > 0)) {
		twenty_cents_change++;
		total_entered -= 0.5;
	}

	int ten_cents_change = 0;
	while ((total_entered > 0.10) && (vending_machine->cash_box[1] > 0)) {
		ten_cents_change++;
		total_entered -= 0.10;
		cout << "HERE 3" << endl; // DEBUG
	}

	int five_cents_change = 0;
	while ((total_entered > 0.05) && (vending_machine->cash_box[0] > 0)) {
		five_cents_change++;
		total_entered -= 0.05;
	}

	// If there was enough change.
	if (total_entered == 0) {
		vending_machine->cash_box[5] += two_euro_change;
		vending_machine->cash_box[4] += one_euro_change;
		vending_machine->cash_box[3] += fifty_cents_change;
		vending_machine->cash_box[2] += twenty_cents_change;
		vending_machine->cash_box[1] += ten_cents_change;
		vending_machine->cash_box[0] += five_cents_change;

		cout << "--------------------- Troco ----------------------" << endl
			<< "2 euros     1 euro     50 cent     20 cent     10 cent     5 cent" << endl
			<< two_euro_change << "     " << one_euro_change << "     " << fifty_cents_change << "     " << twenty_cents_change << "     " << ten_cents_change << "     " << five_cents_change << endl;

		return true;
	}

	else {
		cout << "A máquina não tem troco suficiente." << endl;
		return false;
	}
}

void buy_product_menu(Vending_machine* vending_machine) {

	refresh_console(*vending_machine);

	cout << "Introduza o slot: ";
	char chosen_slot_letter = 0;
	// !TODO: Input sanitizing.
	cin >> chosen_slot_letter;
	chosen_slot_letter = toupper(chosen_slot_letter);
	cout << endl;

	bool slot_exists = false;

	for (int i = 0; i < vending_machine->size; i++) {

		if (chosen_slot_letter == vending_machine->slots[i].letter) { // Finds the slot that the client chose. 
		// !Noted: Another search algorithm could be used. But there's not enough slots to justify replacing such a simple algorithm as this one.

			// If the chosen slot is not empty.
			if (vending_machine->slots[i].quantity > 0) {

				cout << "Escolheu: " << vending_machine->slots[i].product << endl;
				cout << "Preço: " << vending_machine->slots[i].price << endl << endl;

				float total_entered = 0;

				cout << "Introduza a quantidade de moedas de 2 euros: ";
				int two_euros = 0;
				cin >> two_euros;
				vending_machine->cash_box[5] += two_euros; // Adds the entered number of 2 euro coins to the cash box.
				total_entered += 2 * two_euros;
				refresh_console(*vending_machine);


				cout << "Introduza a quantidade de moedas de 1 euro: ";
				int one_euro = 0;
				cin >> one_euro;
				vending_machine->cash_box[4] += one_euro; // Adds the entered number of 1 euro coins to the cash box.
				total_entered += 1 * one_euro;
				refresh_console(*vending_machine);


				cout << "Introduza a quantidade de moedas de 50 cêntimos: ";
				int fifty_cents = 0;
				cin >> fifty_cents;
				vending_machine->cash_box[3] += fifty_cents; // Adds the entered number of 50 cents coins to the cash box.
				total_entered += 0.50 * fifty_cents;
				refresh_console(*vending_machine);


				cout << "Introduza a quantidade de moedas de 20 cêntimos: ";
				int twenty_cents = 0;
				cin >> twenty_cents;
				vending_machine->cash_box[2] += twenty_cents; // Adds the entered number of 20 cents coins to the cash box.
				total_entered += 0.20 * twenty_cents;
				refresh_console(*vending_machine);


				cout << "Introduza a quantidade de moedas de 10 cêntimos: ";
				int ten_cents = 0;
				cin >> ten_cents;
				vending_machine->cash_box[1] += ten_cents; // Adds the entered number of 10 cents coins to the cash box.
				total_entered += (0.10 * ten_cents);
				refresh_console(*vending_machine);


				cout << "Introduza a quantidade de moedas de 5 cêntimos: ";
				int five_cents = 0;
				cin >> five_cents;
				vending_machine->cash_box[0] += five_cents; // Adds the entered number of 5 cents coins to the cash box.
				total_entered += (0.05 * five_cents);
				refresh_console(*vending_machine);


				cout << "Valor Introduzido: " << total_entered << endl << endl;

				// If the client entered enough money.
				if (total_entered >= vending_machine->slots[i].price) {

					// If there is enough change
					if (give_change(vending_machine, (total_entered - vending_machine->slots[i].price))) {


						vending_machine->slots[i].quantity--; // Removes one product from the slot.

						// If the slot is now empty, clean it.
						if (vending_machine->slots[i].quantity == 0) {

							clean_slot(&vending_machine->slots[i]);

						}

						cout << "Produto devolvido." << endl;

						check_funds(*vending_machine);

						system("pause");



					}

					else {
						cout << "Produto não devolvido" << endl;
						system("pause");
					}
				}

				// If the client didn't enter enough money.
				else {

					// Gives back the coins the client entered in the vending machine.
					vending_machine->cash_box[5] -= two_euros;
					vending_machine->cash_box[4] -= one_euro;
					vending_machine->cash_box[3] -= fifty_cents;
					vending_machine->cash_box[2] -= twenty_cents;
					vending_machine->cash_box[1] -= ten_cents;
					vending_machine->cash_box[0] -= five_cents;

					cout << "Não introduziu dinheiro suficiente." << endl;
					system("pause");


				}

			}

			else cout << "O slot escolhido (Slot " << chosen_slot_letter << ") está vazio." << endl;

			check_funds(*vending_machine);

			system("pause");

			slot_exists = true;

			break; // Breaks the for loop because there is only one slot that matches the chosen letter.

		}
	}

		if (slot_exists == false) {
			cout << "O slot que escolheu não existe." << endl;
			system("pause");
		}

	
}

void client_menu(Vending_machine* vending_machine) {

	refresh_console(*vending_machine);


	cout << "O que deseja fazer: " << endl
		<< "  1 - Comprar Produto" << endl
		<< "  0 - Voltar" << endl << endl;

	int choice = 0;
	cin >> choice;

	switch (choice)
	{
		
	case 1:
		buy_product_menu(vending_machine);
		client_menu(vending_machine);

	case 0:
		break;

	default:
		break;
	}

}