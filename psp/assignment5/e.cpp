/*
    Q5. Write a program to compare two strings/
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s[2];
    cout << "Enter a string: ";
    cin >> s[0];
    cout << "Enter another string: ";
    cin >> s[1];

    if (s[0] > s[1])
        cout << s[0] << " is greater than " << s[1] << endl;
    else
        cout << s[1] << " is greater than " << s[0] << endl;

    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter a string: abcd
Enter another string: acdf
acdf is greater than abcd

Test 2:
Enter a string: banana
Enter another string: apple
banana is greater than apple

*/