/*
    Q6. A five-digit number is entered through the keyboard. Write a program to
        obtain the reversed number and to determine whether the original and
        reversed numbers are equal or not.
*/

#include <iostream>

using namespace std;

int reverse(int num) {
    int rev = 0, tmp;
    while (num > 0) {
        tmp = num % 10;
        rev = rev * 10 + tmp;
        num /= 10;
    }
    return rev;
}
void cmpAndPrint(int orig, int rev) {
    cout << "The number " << orig << " and it's reverse " << rev;
    cout << " are " << ((orig == rev) ? "same." : "not same.") << '\n';
}

int main() {
    int a;
    cout << "Enter a number: ";
    cin >> a;
    cmpAndPrint(a ,reverse(a));
    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter a number: 333
The number 333 and it's reverse 333 are same.

Test 2:
Enter a number: 100
The number 100 and it's reverse 1 are not same.

Test 3:
Enter a number: 345
The number 345 and it's reverse 543 are not same.

*/