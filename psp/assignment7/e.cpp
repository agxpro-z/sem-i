/*
    Q5. Write a program in C++ to convert a decimal number into binary without
        using an array and using the constructor and destructor.
*/

#include <iostream>

using namespace std;

class DecToBin {
    // Pointer member variable
    int* dec;

  public:
    // Constructor
    DecToBin(int a) {
        // Dynamically allocate memory for dec and initialize value
        dec = new int(a);
    }

    // Destructor
    ~DecToBin() {
        // Cleanup allocated memory
        delete dec;
    }

    int printDecimal() {
        cout << *dec;
    }

    void printBinary() {
        printBinary(*dec);
        cout << endl;
    }

  private:
    // Print binary format of decimal
    // make it private so cannot be called from outside the class
    void printBinary(int d) {
        if (d == 0) return;
        int b = d % 2;
        printBinary(d / 2);
        cout << b;
    }
};

int main() {
    cout << "Enter a number: ";
    int a;
    cin >> a;

    DecToBin d(a);

    // cout << "Decimal = ";
    // d.printDecimal();
    // cout << '\n';

    cout << "Binary = ";
    d.printBinary();

    return 0;
}

/*
        -- OUTPUT --

Enter a number: 15
Binary = 1111

Enter a number: 10
Binary = 1010

*/