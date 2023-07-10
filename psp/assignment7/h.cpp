/*
    Q8. Write a program using inline function inside and outside of the
        class (accessing data members with objects and member functions)
*/

#include <iostream>

using namespace std;

class A {
    int m_a = 0;

  public:
    void setValue(int v);

    // inline by default
    int getValue() {
        return m_a;
    }
};

// Make setValue() member function inline
inline void A::setValue(int v) {
    m_a = v;
}

int main() {
    A a; // Make object a of type A
    a.setValue(10); // set value to 10
    int v = a.getValue(); // retrieve value and store in new variable s

    return 0;
}