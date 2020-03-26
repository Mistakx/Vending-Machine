#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
File reading implementations:

    First way: Keep reading the file anytime we need to acess information.
     - Advantages: Doesn't use RAM to store the file because the file is kept on disk. 
     - Disadvantages: It's slower because it needs to open the file that's kept on disk anytime the program needs to acess information. Even SSDs read speed isn't as fast as RAM.

    Second way: Save the file to an array and keep it on RAM.
     - Advantages: It's faster because of the aforementioned reasons. This allows the file that's on disk to be modified without any problem since it is closed after saving the data to the array,
     - Disadvantages: Uses RAM since it needs to save the array. If the file size is too big the array will get too big to save on RAM.

    Chosen Implementation: The second. 
     - RAM usage is highly unlikely to be a problem since 1 million characters use approximately 1 megabyte of RAM.
// 
*/

/*
Since we chose the second implementation, now the program needs to save the file to an array. Once again we have two options.

    First way:
     - Get the number of lines.
     - Create an array with that many elements.
     - Save the elements to that array.

     Advantages: Better memory usage since the array's size is the same as the number of elements.
     Disadvantages: Worse processor usage since it first gets the number of lines, then does the same to add the lines to the array.


     Second way:
      - Create an array with a very large number of elements.
      - Save the elements to that array.

      Advantages: Better processor usage since it doesn't check the number of lines, and only saves the lines to the array.
      Disadvantages: Worse memory usage since the array's size is much larger than the number of elements it contains.
                     If not enough memory is allocated, there's a risk the array will be too small to save all lines.
                     If too much memory is allocated, there's going to be wasted memory for the entire execution of the program.

    Chosen implementation: The first way.
     - Since the file is only read at the program's startup, we feel it's better to take longer for the program to boot up than it is to have wasted memory
       for as long as the program is running.

    Correct Implementation: Using linked lists (which the teacher said we couldn't do) neither of these problems would ocurr. Every line could be saved to a node as it was
                            read and it would be faster than the first way, and have none of the memory problems of the second way.
                            

*/

string* file_to_array(string file_path) {  // Reads a file and returns an array with each line as an element of that array.
    // Ifstream - Read from files. Ofstream - Write to files.


	ifstream file(file_path);
    string line = "";
    int number_of_lines = 0;
    
    // Open the file to get the number of lines
    if (file.is_open()) {


        while (getline(file, line)) {
            number_of_lines++;

        } // When getline reaches the end of the file it sets an eof flag (End-of-file) on the stream.

        // string* result[number_of_lines]; // number_of_lines not known at compile time.
        string* result = new string[number_of_lines]; // Array of strings. It has to be dynamically alocated because the array size isn't known at compile time.

        file.clear(); /* This clears the eof flag. While checking the documentation we found that C++ behaviour regarding this line and the next has changed.
         C++98 - If the eofbit flag is set before the seekg call, the function fails.
         C++11 - The seekg function clears the eofbit flag, if set before the call.
         Source - http://www.cplusplus.com/reference/istream/istream/seekg/
         Conclusion: This line isn't needed in the newer versions of C++.
        */
        file.seekg(0, ios::beg); // Sets the position of the next character to be extracted from the input stream back at the beginning so we can getline again.

        while (getline(file, line)) {
            static int i = 0; // The static keyword is used for two reasons:
            // First reason: It is used so "i" is declared inside the scope of the while loop. This is to avoid "i = 0;" before the while loop. 
            //               It's good practice to keep variables inside the scope in which they're used.
            // Second reason: If we just put "i" inside of the while loop it resets back to 0 every time the loop is run, which obviously isn't the intended behaviour.
            result[i] = line;
            i++;
        }

        file.close();
        return result;

    } else cout << file_path << "is being used by another process." << endl; 




    

}




