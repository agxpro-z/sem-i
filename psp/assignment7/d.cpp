/*
    Q4. Try with destructor (with same program)
*/

// Previously used programs doesn't require destructor for cleaning
// instead I'm implementing the same program using pointer.

#include <iostream>

using namespace std;

class Numbers {
    // Pointer member variables
    int* m_a;
    int* m_b;

  public:
    // Constructor
    Numbers(int a, int b) {
        // Dynamically allocate memory and initialize member variables
        m_a = new int(a);
        m_b = new int(b);
    }

    ~Numbers() {
        // Cleanup allocated memory
        delete m_a;
        delete m_b;
    }

    int add();
    int subtract();
};

int Numbers::add() {
    return *m_a + *m_b;
}

int Numbers::subtract() {
    return *m_a - *m_b;
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