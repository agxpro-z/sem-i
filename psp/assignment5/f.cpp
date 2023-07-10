/*
    Q6. Write a program to concatenate two strings.
*/

#include <cstring>
#include <iostream>

using namespace std;

int main() {
    char str1[] = "Hello";
    char str2[] = " world!";

    strcat(str1, str2);
    cout << str1 << endl;

    return 0;
}

/*
        -- OUTPUT --

Test 1:
Hello world!

*/