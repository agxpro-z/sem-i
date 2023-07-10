/*
    Q9. Write a program to demonstrate the use of static data members.
*/

#include <iostream>

using namespace std;

class StaticDemo {
    static int m_s;

  public:
    void setValue(int a) {
        m_s = a;
    }

    int getValue() {
        return m_s;
    }
};
int StaticDemo::m_s = 0;

int main() {
    // Create two objects
    StaticDemo sd1;
    StaticDemo sd2;

    // Set different values to both
    sd1.setValue(4);
    sd2.setValue(8);

    // Print their values
    cout << sd1.getValue() << endl;
    cout << sd2.getValue() << endl;

    return 0;
}

/*
        -- OUTPUT --

8
8

output is showing that static variables are between all the instances of the class.

*/