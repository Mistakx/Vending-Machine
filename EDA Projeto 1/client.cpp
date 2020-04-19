#include <iostream>
#include "vending_machine.h"
using namespace std;

void buy_product(Vending_machine* vending_machine){

	char chosen_slot_letter = 0;

	cout << "Introduza o slot: ";
	// TODO: chosen_slot_letter sanitizing.
	cin >> chosen_slot_letter;

	// 
	for (int i = 0; i < vending_machine->size; i++) { 

		if (chosen_slot_letter == vending_machine->slots[i].letter) { // Finds the selected slot. // TODO: Check if another search algorithm could be used. Will depend if the slots are already sorted.
			cout << "Escolheu: " << vending_machine->slots[i].product_name << endl;
			
			float total = 0; // The total value of the introduced coins.

			cout << "Introduza a quantidade de moedas de 5 cêntimos: ";
			int five_cents = 0;
			cin >> five_cents;
			total += (0.05 * five_cents);
			cout << endl;

			cout << "Introduza a quantidade de moedas de 10 cêntimos: ";
			int ten_cents = 0; 
			cin >> ten_cents;
			total += (0.10 * ten_cents);
			cout << endl;

			cout << "Introduza a quantidade de moedas de 20 cêntimos: ";
			int twenty_cents = 0;
			cin >> twenty_cents;
			total += 0.20 * twenty_cents;
			cout << endl;

			cout << "Introduza a quantidade de moedas de 50 cêntimos: ";
			int fifty_cents = 0;
			cin >> fifty_cents;
			total += 0.50 * fifty_cents;
			cout << endl;

			cout << "Introduza a quantidade de moedas de 1 euro: ";
			int one_euro = 0;
			cin >> one_euro;
			total += 1 * one_euro;
			cout << endl;

			cout << "Introduza a quantidade de moedas de 2 euros: ";
			int two_euros = 0;
			cin >> two_euros;
			total += 2 * two_euros;
			cout << endl;

			cout << "Valor Introduzido: " << total;

			if (entered)


			break; // Breaks the for loop because there is only one slot that matches the chosen letter.



		}
	}
	
}