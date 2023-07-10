/*
    Q7. Write a program to print the following pattern

        U N
        U N I V
        U N I V E R
        U N I V E R S I
        U N I V E R S I T Y
        U N I V E R S I
        U N I V E R
        U N I V
        U N
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string word = "UNIVERSITY";

    for (int i = 0; i < word.length(); i += 2) {
        for (int j = 0; j < i; ++j) {
            cout << word[j] << ' ';
        }
        cout << endl;
    }
    for (int i = word.length(); i > 0; i -= 2) {
        for (int j = 0; j < i; ++j) {
            cout << word[j] << ' ';
        }
        cout << endl;
    }

    return 0;
}

/*
        -- OUTPUT --

Test 1:

U N 
U N I V 
U N I V E R 
U N I V E R S I 
U N I V E R S I T Y 
U N I V E R S I 
U N I V E R 
U N I V 
U N 

*/