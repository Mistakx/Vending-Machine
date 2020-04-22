#include <iostream>
#include "vending_machine.h"
using namespace std;



void buy_product(Vending_machine* vending_machine) {

	print_cashbox(vending_machine); // !Debug

	char chosen_slot_letter = 0;

	cout << "Introduza o slot: ";
	// !TODO: Input sanitizing.
	cin >> chosen_slot_letter;

	cout << endl;

	for (int i = 0; i < vending_machine->size; i++) {

		if (chosen_slot_letter == vending_machine->slots[i].letter) { // Finds the slot that the client chose. 
		// !Noted: Another search algorithm could be used. But there's not enough slots to justify replacing such a simple algorithm as this one.

			// If the chosen slot is not empty.
			if (vending_machine->slots[i].current_number_of_products > 0) {

				cout << "Escolheu: " << vending_machine->slots[i].product_name << endl;
				cout << "Preço: " << vending_machine->slots[i].price << endl << endl;

				float total = 0; // The total value of the introduced coins.

				cout << "Introduza a quantidade de moedas de 2 euros: ";
				int two_euros = 0;
				cin >> two_euros;
				vending_machine->cash_box[5] += two_euros; // Adds the entered number of 2 euro coins to the cash box.
				total += 2 * two_euros;
				cout << endl;

				cout << "Introduza a quantidade de moedas de 1 euro: ";
				int one_euro = 0;
				cin >> one_euro;
				vending_machine->cash_box[4] += one_euro; // Adds the entered number of 1 euro coins to the cash box.
				total += 1 * one_euro;

				cout << "Introduza a quantidade de moedas de 50 cêntimos: ";
				int fifty_cents = 0;
				cin >> fifty_cents;
				vending_machine->cash_box[3] += fifty_cents; // Adds the entered number of 50 cents coins to the cash box.
				total += 0.50 * fifty_cents;

				cout << "Introduza a quantidade de moedas de 20 cêntimos: ";
				int twenty_cents = 0;
				cin >> twenty_cents;
				vending_machine->cash_box[2] += twenty_cents; // Adds the entered number of 20 cents coins to the cash box.
				total += 0.20 * twenty_cents;

				cout << "Introduza a quantidade de moedas de 10 cêntimos: ";
				int ten_cents = 0;
				cin >> ten_cents;
				vending_machine->cash_box[1] += ten_cents; // Adds the entered number of 10 cents coins to the cash box.
				total += (0.10 * ten_cents);

				cout << "Introduza a quantidade de moedas de 5 cêntimos: ";
				int five_cents = 0;
				cin >> five_cents;
				vending_machine->cash_box[0] += five_cents; // Adds the entered number of 5 cents coins to the cash box.
				total += (0.05 * five_cents);

				cout << "Valor Introduzido: " << total << endl << endl;

				// If the client entered enough money.
				if (total >= vending_machine->slots[i].price) {

					vending_machine->slots[i].current_number_of_products--; // Removes one product from the slot.

					// If the slot is now empty, clean it.
					if (vending_machine->slots[i].current_number_of_products == 0) {

						clean_slot( &(vending_machine->slots[i]) );

					}
	
					cout << "Produto devolvido, obrigado." << endl;

				}

				// If the client didn't enter enough money.
				else {

					// Gives back the coins he entered in the vending machine.
					vending_machine->cash_box[5] -= two_euros;
					vending_machine->cash_box[4] -= one_euro;
					vending_machine->cash_box[3] -= fifty_cents;
					vending_machine->cash_box[2] -= twenty_cents;
					vending_machine->cash_box[1] -= ten_cents;
					vending_machine->cash_box[0] -= five_cents;

					cout << "Não introduziu dinheiro suficiente." << endl;

					print_cashbox(vending_machine); // !Debug

				}

			}

			else cout << "The chosen slot is empty." << endl;

			break; // Breaks the for loop because there is only one slot that matches the chosen letter.

		}

	}
}
