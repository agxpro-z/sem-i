/*
    Q4. If a five-digit number is input through the keyboard, write a program to
        print a new number by adding one to each of its digits. For example if the
        number that is input is 12391 then the output should be displayed as 23402.
*/

#include <iostream>

using namespace std;

void printNewNum(int a) {
    if (a == 0)
        return;

    int num = a % 10;
    printNewNum(a / 10);
    if (num == 9)
        cout << 0;
    else
        cout << num + 1;
}

int main() {
    cout << "Enter a number: ";
    int num;
    cin >> num;
    cout << "New number is: ";
    printNewNum(num);
    cout << '\n';

    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter a number: 45643
New number is: 56754

Test 2:
Enter a number: 78906
New number is: 89017

Test 3:
Enter a number: 12391
New number is: 23402

*/