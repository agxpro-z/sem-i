/*
    Q1. Write a program to swap the values two integer members of different classes
        using friend function.
*/

#include <iostream>

using namespace std;

// Class declaration
class A;
class B;

// Class A definition
class A {
    int m_a;

  public:
    A(int a) : m_a(a) {}

    void setValue(int a) { m_a = a; }
    int getValue() { return m_a; }
    friend void swap(A& a, B& b);
};

// Class B definition
class B {
    int m_a;

  public:
    B(int a) : m_a(a) {}

    void setValue(int a) { m_a = a; }
    int getValue() { return m_a; }
    friend void swap(A& a, B& b);
};

void swap(A& a, B& b) {
    a.m_a = a.m_a ^ b.m_a;
    b.m_a = a.m_a ^ b.m_a;
    a.m_a = a.m_a ^ b.m_a;
}

int takeValue() {
    cout << "Enter a number: ";
    int a;
    cin >> a;
    return a;
}

int main() {
    A a(takeValue());
    B b(takeValue());

    cout << "\nValues before swap: \n";
    cout << "Class A: " << a.getValue() << '\n';
    cout << "Class B: " << b.getValue() << '\n';

    swap(a, b);

    cout << "\nValues after swap: \n";
    cout << "Class A:" << a.getValue() << '\n';
    cout << "Class B:" << b.getValue() << '\n';

    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter a number: 10
Enter a number: 12

Values before swap: 
Class A: 10
Class B: 12

Values after swap: 
Class A: 12
Class B: 10

*/