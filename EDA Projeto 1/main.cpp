#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


int main() {

	srand(time(NULL)); // Initializes the random number generator time(NULL) as the seed.
	// time(NULL) is the total number of seconds that have passed since 1-Jan-1970
	// While not totally random (nothing truly is), this pseudo-random function will do because there are no security concerns with the machine's initialization.
	
	while (true) cout << rand() % 4 << endl;
	
	return 0;
	

}