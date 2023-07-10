/*
    Q2. Write a program for addition of two complex numbers using friend function
        (use constructor function to initialize data members of complex class).
*/

#include <iostream>

using namespace std;

class Complex {
    int real;
    int imaginary;

  public:
    Complex(int a = 0, int b = 0) : real(a), imaginary(b) {
    }

    void print() {
        cout << real << (imaginary < 0 ? " - " : " + ") << abs(imaginary) << 'i';
    }

    friend Complex add(const Complex &c1, const Complex& c2);
    static int abs(int a) { return (a < 0 ? -a : a); }
    static Complex resolveInput(int a, char c, string s);
};

Complex add(const Complex& c1, const Complex& c2) {
    return Complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
}

Complex Complex::resolveInput(int a, char c, string s) {
    s.pop_back(); // remove 'i'
    // make imaginary +ve/-ve based on middle character
    return Complex(a, (c == '-' ? -stoi(s) : stoi(s)));
}

int main() {
    Complex c1, c2;

    int a; char c; string s;
    cout << "Enter a complex no. in the form a + bi: ";
    cin >> a >> c >> s;
    c1 = Complex::resolveInput(a, c, s);

    cout << "Enter another complex no. in the form a + bi: ";
    cin >> a >> c >> s;
    c2 = Complex::resolveInput(a, c, s);

    Complex c3(add(c1, c2));

    // print in the form of equation
    cout << "(";
    c1.print();
    cout << ") + (";
    c2.print();
    cout << ") = ";
    c3.print();
    cout << endl;

    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter a complex no. in the form a + bi: 1 + 2i
Enter another complex no. in the form a + bi: 2 + 3i
(1 + 2i) + (2 + 3i) = 3 + 5i

Test 2:
Enter a complex no. in the form a + bi: 1 - 2i
Enter another complex no. in the form a + bi: 1 + 2i
(1 - 2i) + (1 + 2i) = 2 + 0i

Test 3:
Enter a complex no. in the form a + bi: 1 - 2i
Enter another complex no. in the form a + bi: 1 - 2i
(1 - 2i) + (1 - 2i) = 2 - 4i

Test 4:
Enter a complex no. in the form a + bi: -1 - 2i
Enter another complex no. in the form a + bi: -1 - 2i
(-1 - 2i) + (-1 - 2i) = -2 - 4i

*/