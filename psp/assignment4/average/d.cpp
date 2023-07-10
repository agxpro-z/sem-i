/*
    Q4. Use functions to write a program to implement integer calculator
        with functions add, subtract, multiply, quotient, modulus, exponent.
        Provide proper user interface.
*/

#include <iostream>
#include <cmath>

using namespace std;

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
float d(int a, int b) { return float(a) / b; }
int mod(int a, int b) { return a % b; }
int exp(int a, int b) { return pow(a, b); }

void menu() {
    int a = 0, b = 0;
    char c;
    while (true) {
        cout << "\n\n\tInteger Calculator\n"
                " Enter values in the form 1 + 2,\n"
                " Supports +, -, *, /, %, ^, 0 to exit : ";

        cin >> a;
        if (a == 0)
            break;
        cin >> c >> b;
        switch (c) {
            case '+':
                cout << a << " + " << b << " = " << add(a, b) << endl;
                break;
            case '-':
                cout << a << " - " << b << " = " << sub(a, b) << endl;
                break;
            case '*':
                cout << a << " * " << b << " = " << mul(a, b) << endl;
                break;
            case '/':
                cout << a << " / " << b << " = " << d(a, b) << endl;
                break;
            case '%':
                cout << a << " % " << b << " = " << mod(a, b) << endl;
                break;
            case '^':
                cout << a << " ^ " << b << " = " << exp(a, b) << endl;
                break;
            default:
                cout << "Invalid operation. Press enter to continue.";
                break;
        }
    }
    cout << "Exiting..\n";
}

int main() {
    menu();
    return 0;
}