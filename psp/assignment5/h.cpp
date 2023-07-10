/*
    Q8. Write a program to read a sentence and count the number of characters
        &amp;words in that sentence.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cout << "Enter a sentence: ";
    getline(cin >> ws, s); // Take sentence as input without breaking on white spaces.

    int ccount = 0;
    int wcount = 1;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ' ')
            ++wcount;
        if (s[i] != ' ')
            ++ccount;
    }

    cout << "Entered sentence contains " << ccount << " characters and " << wcount << " words.\n";
    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter a sentence: National Institute of Technology Warangal
Entered sentence contains 37 characters and 5 words.

Test 2:
Enter a sentence: The qucik brown fox jumps over the table.
Entered sentence contains 34 characters and 8 words.

*/