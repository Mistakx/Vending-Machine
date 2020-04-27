#include <iostream>
#include <iomanip>
#include "vending_machine.h"

using namespace std;

bool give_change(Vending_machine* vending_machine, float change) {

	change *= 100;
	change = round(change);

	int two_euro_change = 0;
	while ((change >= 200) && (two_euro_change < vending_machine->cash_box[5])) {
		two_euro_change++;
		change -= 200;
		//change = round(change);
	}


	int one_euro_change = 0;
	while ((change >= 100) && (one_euro_change < vending_machine->cash_box[4])) {
		one_euro_change++;
		change -= 100;
		//change = round(change);

	}

	int fifty_cents_change = 0;
	while ((change >= 50) && (fifty_cents_change < vending_machine->cash_box[3])) {
		fifty_cents_change++;
		change -= 50;
		//change = round(change);

		system("Pause");
	}

	int twenty_cents_change = 0;
	while ((change >= 20) && (twenty_cents_change < vending_machine->cash_box[2])) {
		twenty_cents_change++;
		change -= 20;
		//change = round(change);

	}

	int ten_cents_change = 0;
	while ((change >= 10) && (ten_cents_change < vending_machine->cash_box[1])) {
		ten_cents_change++;
		change -= 10;
		//change = round(change);

	}

	int five_cents_change = 0;
	while ((change >= 5) && (five_cents_change < vending_machine->cash_box[0])) {
		five_cents_change++;
		change -= 5;
		//change = round(change);

	}

	//change = round(change);	
	

	// If there was enough change.
	if (change == 0) {
		vending_machine->cash_box[5] -= two_euro_change;
		vending_machine->cash_box[4] -= one_euro_change;
		vending_machine->cash_box[3] -= fifty_cents_change;
		vending_machine->cash_box[2] -= twenty_cents_change;
		vending_machine->cash_box[1] -= ten_cents_change;
		vending_machine->cash_box[0] -= five_cents_change;

		cout << " ------------------------- Troco -------------------------" << endl

			<< "| 2 euros   1 euro   50 cent   20 cent   10 cent   5 cent |" << endl
			<< "| " << setw(10) << two_euro_change << setw(9) << one_euro_change << setw(10) << fifty_cents_change << setw(10) << twenty_cents_change 
			<< setw(10) << ten_cents_change << setw(7) << five_cents_change << "|" << endl
			
			<< " ---------------------------------------------------------" << endl << endl;

		return true;
	}

	// If there wasn't enough change.
	else {
		
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

				refresh_console(*vending_machine);
				cout << "Escolheu: " << vending_machine->slots[i].product << endl;
				cout << "Preço: " << vending_machine->slots[i].price << endl << endl;
				cout << "Introduza a quantidade de moedas de 2 euros: ";
				int two_euro_coins = 0;
				cin >> two_euro_coins;
				vending_machine->cash_box[5] += two_euro_coins; // Adds the entered number of 2 euro coins to the cash box.
				total_entered += 2 * two_euro_coins;

				refresh_console(*vending_machine);
				cout << "Escolheu: " << vending_machine->slots[i].product << endl;
				cout << "Preço: " << vending_machine->slots[i].price << endl << endl;
				cout << "Introduza a quantidade de moedas de 1 euro: ";
				int one_euro_coins = 0;
				cin >> one_euro_coins;
				vending_machine->cash_box[4] += one_euro_coins; // Adds the entered number of 1 euro coins to the cash box.
				total_entered += 1 * one_euro_coins;

				refresh_console(*vending_machine);
				cout << "Escolheu: " << vending_machine->slots[i].product << endl;
				cout << "Preço: " << vending_machine->slots[i].price << endl << endl;
				cout << "Introduza a quantidade de moedas de 50 cêntimos: ";
				int fifty_cent_coins = 0;
				cin >> fifty_cent_coins;
				vending_machine->cash_box[3] += fifty_cent_coins; // Adds the entered number of 50 cents coins to the cash box.
				total_entered += 0.50 * fifty_cent_coins;

				refresh_console(*vending_machine);
				cout << "Escolheu: " << vending_machine->slots[i].product << endl;
				cout << "Preço: " << vending_machine->slots[i].price << endl << endl;
				cout << "Introduza a quantidade de moedas de 20 cêntimos: ";
				int twenty_cent_coins = 0;
				cin >> twenty_cent_coins;
				vending_machine->cash_box[2] += twenty_cent_coins; // Adds the entered number of 20 cents coins to the cash box.
				total_entered += 0.20 * twenty_cent_coins;

				refresh_console(*vending_machine);
				cout << "Escolheu: " << vending_machine->slots[i].product << endl;
				cout << "Preço: " << vending_machine->slots[i].price << endl << endl;
				cout << "Introduza a quantidade de moedas de 10 cêntimos: ";
				int ten_cent_coins = 0;
				cin >> ten_cent_coins;
				vending_machine->cash_box[1] += ten_cent_coins; // Adds the entered number of 10 cents coins to the cash box.
				total_entered += (0.10 * ten_cent_coins);

				refresh_console(*vending_machine);
				cout << "Escolheu: " << vending_machine->slots[i].product << endl;
				cout << "Preço: " << vending_machine->slots[i].price << endl << endl;
				cout << "Introduza a quantidade de moedas de 5 cêntimos: ";
				int five_cent_coins = 0;
				cin >> five_cent_coins;
				vending_machine->cash_box[0] += five_cent_coins; // Adds the entered number of 5 cents coins to the cash box.
				total_entered += (0.05 * five_cent_coins);
				refresh_console(*vending_machine);

				// If the client entered enough money.
				if (total_entered >= vending_machine->slots[i].price) {

					// If there is enough change
					if (give_change(vending_machine, (total_entered - vending_machine->slots[i].price))) {


						vending_machine->slots[i].quantity--; // Removes one product from the slot.

						// If the slot is now empty, clean it.
						if (vending_machine->slots[i].quantity == 0) {

							clean_slot(&vending_machine->slots[i]);

						}

						refresh_console(*vending_machine);

						cout << "Valor Introduzido: " << total_entered << endl << endl;

						cout << "Produto devolvido." << endl << endl;

						check_funds(*vending_machine);

					}

					else {

						refresh_console(*vending_machine);

						cout << "Valor Introduzido: " << total_entered << endl << endl;

						// Removes the entered coins
						vending_machine->cash_box[5] -= two_euro_coins;
						vending_machine->cash_box[4] -= one_euro_coins;
						vending_machine->cash_box[3] -= fifty_cent_coins;
						vending_machine->cash_box[2] -= twenty_cent_coins;
						vending_machine->cash_box[1] -= ten_cent_coins;
						vending_machine->cash_box[0] -= five_cent_coins;

						cout << "Produto não devolvido. Não existe troco suficiente." << endl;

						system("Pause");
					}
				}

				// If the client didn't enter enough money.
				else {

					// Gives back the coins the client entered in the vending machine.
					vending_machine->cash_box[5] -= two_euro_coins;
					vending_machine->cash_box[4] -= one_euro_coins;
					vending_machine->cash_box[3] -= fifty_cent_coins;
					vending_machine->cash_box[2] -= twenty_cent_coins;
					vending_machine->cash_box[1] -= ten_cent_coins;
					vending_machine->cash_box[0] -= five_cent_coins;

					refresh_console(*vending_machine);

					cout << "Não introduziu dinheiro suficiente." << endl;
					system("Pause");

				}

			}

			else {
				cout << "O slot escolhido (Slot " << chosen_slot_letter << ") está vazio." << endl;
				system("Pause");
			}

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
		break;


	case 0:
		break;

	default:
		break;
	}

}