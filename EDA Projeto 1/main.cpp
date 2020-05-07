#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "employee.h"
#include "client.h"

using namespace std;

int main(int argc, char* argv[]) {

    locale::global(locale("English")); 
    srand(time(NULL)); 
    
    string products_file_path = ""; 
    string prices_file_path = "";

    if (argc > 1) {
        products_file_path = argv[1];
        prices_file_path = argv[2];
    }

    else {
        cout << endl;
        cout << "Localiza��o do ficheiro que cont�m os produtos: ";
        getline(cin, products_file_path);
        cout << endl;
        cout << "Localiza��o do ficheiro que cont�m os pre�os: " ;
        getline(cin, prices_file_path);
        cout << endl;
        system("cls");

    }

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

            cout << "Modo de utiliza��o:" << endl
                << "  1 - Funcion�rio" << endl
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
        cout << "Os ficheiros de inicializa��o da m�quina n�o foram abertos corretamente." << endl; 
        return 1;
    }

}



