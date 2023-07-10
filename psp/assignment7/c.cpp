/*
    Q3. Try with different constructors and definition inside & outside
        of the class (with same program).
*/

#include <iostream>

using namespace std;

class Numbers {
    int m_a = 0;
    int m_b = 0;

  public:
    // Constructor
    Numbers(int a, int b) {
        m_a = a;
        m_b = b;
    }

    // Member function having definition inside class
    int add() {
        return m_a + m_b;
    }

    // Member function declaration
    int subtract();
};

// Member function definition outside the class
int Numbers::subtract() {
    return m_a - m_b;
}

int main() {
    Numbers n(10, 20);

    cout << "12 + 15 = " << n.add() << '\n';
    cout << "12 - 15 = " << n.subtract() << '\n';

    return 0;
}

/*
        -- OUTPUT --

12 + 15 = 30
12 - 15 = -10

*/