/*
    Q4. Write a program to sort 5 string words stored in an array of pointers.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s[5];

    cout << "Enter 5 words: ";
    for (int i = 0; i < 5; ++i)
        cin >> s[i];

    for (int i = 0; i < 4; ++i) {
        for (int i = 0; i < 4; ++i) {
            if (s[i] > s[i + 1]) {
                string tmp = s[i];
                s[i] = s[i + 1];
                s[i + 1] = tmp;
            }
        }
    }

    cout << "\nSorted list:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "  " << s[i] << endl;
    }
    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter 5 words: asd
dsf
zxf
wf
qasf

Sorted list:
  asd
  dsf
  qasf
  wf
  zxf

Test 2:
Enter 5 words: popdf
skf
zsf
dgskd
asfk

Sorted list:
  asfk
  dgskd
  popdf
  skf
  zsf

*/