#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "header.h"
using namespace std;

const string produtos_txt = "C:\\Users\\Mistakx\\Desktop\\produtos.txt";
const string precos_txt = "C:\\Users\\Mistakx\\Desktop\\precos.txt";


int main() {

	srand(time(NULL)); // Initializes the random number generator time(NULL) as the seed.
	// time(NULL) is the total number of seconds that have passed since 1-Jan-1970
	// While not totally random (nothing truly is), this pseudo-random function will do because there are no security concerns with the machine's initialization.
	
	vending_machine_initialization();
	cout << file_to_array(produtos_txt);
	
	return 0;
	

}