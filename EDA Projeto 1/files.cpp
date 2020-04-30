#include <iostream>
#include <fstream>
#include <string>
#include "files.h"

using namespace std;

void prices_text_parsing(string file_path, Prices* prices) {

    ifstream file(file_path);
    
    if (file.is_open()) {

        string line = "";

        while (getline(file, line)) {
            prices->lenght++; // Number of lines of the prices array.

        } // When getline reaches the end of the file it sets an eof flag (End-of-file) on the stream.

        prices->array = new float[prices->lenght];

        file.clear(); // This clears the eof flag. 
        file.seekg(0, ios::beg); // Sets the position of the next character to be extracted from the input stream back at the beginning so we can use getline again.

        int i = 0;
        while (getline(file, line)) {
            prices->array[i] = stof(line); // Converts line to float before adding to array.
            i++;
        }

        file.close();

    } 

    else { 
        cout << "Ocorreu um erro ao tentar abrir \"" << file_path << "\"." << endl << "O ficheiro não existe, ou está a ser usado por outro processo." << endl << endl; 
    }




    

}

void products_text_parsing(string file_path , Products* products) {

    ifstream file(file_path);

    if (file.is_open()) {

        string line = "";
            
        while (getline(file, line)) {
            products->lenght++; // Number of lines of the products array.
        } // When getline reaches the end of the file it sets an eof flag (End-of-file) on the stream.

        products->array = new string[products->lenght];

        file.clear(); // This clears the eof flag.
        file.seekg(0, ios::beg); // Sets the position of the next character to be extracted from the input stream back at the beginning so we can use getline again.

        int i = 0;
        while (getline(file, line)) {
            products->array[i] = line;
            i++;
        }
        file.close();

    }

    else {
        cout << "Ocorreu um erro ao tentar abrir \"" << file_path << "\"." << endl << "O ficheiro não existe, ou está a ser usado por outro processo." << endl << endl;
    }



}


