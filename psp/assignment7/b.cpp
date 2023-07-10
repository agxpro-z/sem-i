/*
    Q2. Try with local and global objects (with same program).
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

// Global variable
Numbers num(15, 19);

int main() {
    // Local variable
    Numbers n(12, 15);

    cout << "Calling global variable...\n";
    cout << "15 + 19 = " << num.add() << '\n';
    cout << "15 - 19 = " << num.subtract() << '\n';

    cout << endl;

    cout << "Calling local variable...\n";
    cout << "12 + 15 = " << n.add() << '\n';
    cout << "12 - 15 = " << n.subtract() << '\n';

    return 0;
}

/*
        -- OUTPUT --

Calling global variable...
15 + 19 = 34
15 - 19 = -4

Calling local variable...
12 + 15 = 27
12 - 15 = -3

*/