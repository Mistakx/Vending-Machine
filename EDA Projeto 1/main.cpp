#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "employee.h"
#include "client.h"

using namespace std;

int main() {

    locale::global(locale("English")); 
    srand(time(NULL)); 
    

    // Since the machine initialization demands that all initialized slots contain different products, products.txt needs to contain enough files for the initialization to ocurr without an error.
    string products_file_path = "C:\\Users\\Mistakx\\Desktop\\produtos.txt"; 
    string prices_file_path = "C:\\Users\\Mistakx\\Desktop\\precos.txt";


    Products* products = new Products;
    products_text_parsing(products_file_path, products); // Parses the "produtos.txt" file to a struct we can work it, and saves the result to "products".
    Prices* prices = new Prices;
    prices_text_parsing(prices_file_path, prices); // Parses the "precos.txt" file to a struct we can work it , and saves the result to "prices".

    if ((products->lenght != 0) and (prices->lenght != 0)) { // If the files were correctly opened.

        Vending_machine vending_machine;

        initialize_vending_machine(&vending_machine, products, prices);
        delete products;
        delete prices;

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
// TODO: CHEck if functions dont return in all cases.
// TODO: Don't forget to ask for the File location.
// TODO: Check if cin doesnt need to be getline
// TODO: Check all random number generations. 