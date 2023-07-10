/*
    Q7. Write a program to check whether a triangle is valid or not, when the
        three angles of the triangle are entered through the keyboard. A triangle
        is valid if the sum of all the three angles is equal to 180 degrees.
*/

#include <iostream>

using namespace std;

int main() {
    double a, b, c;
    cout << "Enter all the angles of a triangle: ";
    cin >> a >> b >> c;

    if (a + b + c == 180)
        cout << "Entered triangle is valied.\n";
    else
        cout << "Entered triangle is not valid.\n";

    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter all the angles of a triangle: 100 20 60
Entered triangle is valied.

Test 2:
Enter all the angles of a triangle: 99.1 20.5 60.4
Entered triangle is valied.

Test 3:
Enter all the angles of a triangle: 99.1 20.5 60.3
Entered triangle is not valid.

*/