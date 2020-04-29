#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "employee.h"
#include "client.h"

using namespace std;

int main() {

    cout << ("B" < "A   ") << ("AC" < "AB");
    system("PAuse");

    locale::global(locale("English")); // All future I/O and string manipulation/conversion (even the ones outside of the main function) will use the english program locale.
    // Messing with the locale has various non wanted effects on string to float conversion.
    srand(time(NULL)); // Initializes the random number generator time(NULL) as the seed.
    // time(NULL) is the total number of seconds that have passed since 1-Jan-1970
    // While not totally random (nothing truly is), this pseudo-random function will do because there are no security concerns with the machine's initialization.


    // Since the machine initialization demands that all initialized slots contain different products, products.txt needs to contain enough files for the initialization to ocurr without an error.
    string products_file_path = "C:\\Users\\Mistakx\\Desktop\\produtos.txt"; 
    string prices_file_path = "C:\\Users\\Mistakx\\Desktop\\precos.txt";

    // Structs to be kept as they are after being imported from the text documents.
    // These are not touched by the initialization process and remain the same for as long as the machine is running.
    // Both structs (products and prices) need to be passed by reference so they can be edited by the parsing functions.
    // Both file paths (products_file_path and prices_file_path) don't need to be passed by reference because they're not being edited.
    Products products;
    products_text_parsing(products_file_path, &products); // Parses the "produtos.txt" file to a struct we can work it, and saves the result to "products".
    Prices prices;
    prices_text_parsing(prices_file_path, &prices); // Parses the "precos.txt" file to a struct we can work it , and saves the result to "prices".

    if ((products.lenght != 0) and (prices.lenght != 0)) { // If the files were correctly opened.

        // Struct used to initialize the vending machine. This varies when a product is placed in a slot, and consequently removed from the struct.
        Products initialization_products = products;

        Vending_machine vending_machine; // Reserves memory for the Vending Machine.

        initialize_vending_machine(&vending_machine, &initialization_products, prices); // Initializes the vending machine.
        // Both the vending_machine and the initialization_products are going to change, so they're passed by reference.

        while (true) {

            system("cls");
            cout << endl;

            cout << "Modo de utilização:" << endl
                << "  1 - Funcionário" << endl
                << "  2 - Utilizador" << endl << endl;

            int choice = 0;
            cin >> choice;


            switch (choice)
            {

            case 1:
                employee_menu(&vending_machine);
                break;

            case 2:
                client_menu(&vending_machine);
                break;
            default:
                break;
            }

        }

        return 0;
    }
    
    else { 
        cout << "Os ficheiros de inicialização da máquina não foram abertos corretamente." << endl; 
        return 1;
    }

}

// char + number
// Improvement: Putting a space at the end of a product name counts as a different product.
// Improvement: Cache on printed products
// TODO: Make so that u can't add a slot with a number as a letter.
// TODO: check if files are correctly formatted.
// TODO: CHEck if functions dont return in all cases.
// TODO: Don't forget to ask for the File location.
// TODO: Check if client input is multiple of 5.
// TODO: Check if switch cases break.
// TODO: Allow product name to be correct even if capitalized wrong.
// TODO: Check if cin doesnt need to be getline.
// TODO: Check if parenthesis are needed when passing by reference.
// TODO: Reorganize and clear console.
// TODO: Introduce menu back options.
// TODO: Check all endl.
// TODO: Check all random number generations. 
// TODO: CHECK IF ALL THE DEPENDECIES ARE CORRECT!
// TODO: DELETE HEAP.
// TODO: Check for all dynamic initializations.
// TODO: Correctly format headers.