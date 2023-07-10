/*
    Q1. Create a structure for complex number, do addition and multiplication
    of two complex numbers.
*/

#include <iostream>
#include <string>

using namespace std;

struct Complex {
    int real;
    int imaginary;

    static int abs(int a) { return (a < 0 ? -a : a); }

    void print() {
        cout << real << (imaginary < 0 ? " - " : " + ") << abs(imaginary) << 'i';
    }

    static void print(Complex c) {
        cout << c.real << (c.imaginary < 0 ? " - " : " + ") << abs(c.imaginary) << 'i';
    }

    Complex add(Complex c) {
        return {real + c.real, imaginary + c.imaginary};
    }

    /*
     * (a + bi)(c + di) = ac + cbi + adi - bd
     *                  = (ac - bd) + (cb + ad)i
     * where, a = real, b = imaginary
     *        c = c.real, d = c.imaginary
     */
    Complex multiply(Complex c) {
        return {((real * c.real) - (imaginary * c.imaginary)),
                ((c.real * imaginary) + (real * c.imaginary))};
    }
};

Complex resolveInput(int a, char c, string s) {
    s.pop_back(); // remove 'i'
    // make imaginary +ve/-ve based on middle character
    return {a, (c == '-' ? -stoi(s) : stoi(s))};
}

int main() {
    Complex c1, c2;

    int a; char c; string s;
    cout << "Enter a complex no. in the form a + bi: ";
    cin >> a >> c >> s;
    c1 = resolveInput(a, c, s);

    cout << "Enter another complex no. in the form a + bi: ";
    cin >> a >> c >> s;
    c2 = resolveInput(a, c, s);

    // Print sum
    cout << '(';
    c1.print();
    cout << ") + (";
    c2.print();
    cout << ") = (";
    Complex::print(c1.add(c2));
    cout << ")\n";

    // Print product
    cout << '(';
    c1.print();
    cout << ") x (";
    c2.print();
    cout << ") = (";
    Complex::print(c1.multiply(c2));
    cout << ")\n";

    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter a complex no. in the form a + bi: 0 + 1i 
Enter another complex no. in the form a + bi: 0 - 1i
(0 + 1i) + (0 - 1i) = (0 + 0i)
(0 + 1i) x (0 - 1i) = (1 + 0i)

Test 2:
Enter a complex no. in the form a + bi: 1 - 2i
Enter another complex no. in the form a + bi: 2 + 3i
(1 - 2i) + (2 + 3i) = (3 + 1i)
(1 - 2i) x (2 + 3i) = (8 - 1i)

Test 3:
Enter a complex no. in the form a + bi: 8 + 4i
Enter another complex no. in the form a + bi: 6 + 3i
(8 + 4i) + (6 + 3i) = (14 + 7i)
(8 + 4i) x (6 + 3i) = (36 + 48i)

*/