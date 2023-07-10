/*
    Q1. Write a program that uses a class where the member functions are
        defined outside a class. (Choose any program)
*/

#include <iostream>

using namespace std;

class Numbers {
    int m_a = 0;
    int m_b = 0;

  public:
    Numbers(int a, int b) {
        m_a = a;
        m_b = b;
    }

    int add();
    int subtract();
};

int Numbers::add() {
    return m_a + m_b;
}

int Numbers::subtract() {
    return m_a - m_b;
}

int main() {
    Numbers n(12, 15);

    cout << "12 + 15 = " << n.add() << '\n';
    cout << "12 - 15 = " << n.subtract() << '\n';

    return 0;
}

/*
        -- OUTPUT --

12 + 15 = 27
12 - 15 = -3

*/