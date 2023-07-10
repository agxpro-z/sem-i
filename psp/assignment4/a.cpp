/*
    Q1. If a four-digit number is input through the keyboard, write a program
        to obtain the sum of the first and last digit of this number.
*/

#include <iostream>

using namespace std;

int getSum(int a) {
    if (a < 10 && a >= 0)
        return a;

    int last = a % 10;
    while (a > 9) {
        a /= 10;
    }
    
    return a + last;
}

int main() {
    int a;
    cout << "Enter a number: ";
    cin >> a;
    cout << "Sum of first and last digit of the number " << a << " is " << getSum(a) << '\n';
    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter a number: 10
Sum of first and last digit of the number 10 is 1

Test 2:
Enter a number: 12
Sum of first and last digit of the number 12 is 3

Test 3:
Enter a number: 123
Sum of first and last digit of the number 123 is 4

*/