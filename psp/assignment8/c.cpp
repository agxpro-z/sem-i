/*
    Q3. Define a class string and overload == to compare two strings and + operator
        for concatenation of two strings.
*/

#include <iostream>
#include <string>

using namespace std;

class String {
    int m_length;
    char* m_data;

  public:
    // Constructor
    String(int a = 0) : m_length(a), m_data(NULL) {}

    // Copy constructor
    String(const String& s);

    // Destructor
    ~String() {
        if (m_data) delete[] m_data;
    }

    bool operator==(const String& s);
    String operator+(const String& s);

    void setString(char* c, int length);
    void setString(string& c, int length);
    void printString();
};

// Copy constructor
String::String(const String& s) {
    // return if provided String is empty
    if (s.m_length == 0) return;
    // delete any existing String
    if (m_data != NULL) delete[] m_data;

    // set new length and allocate char array of size length
    m_length = s.m_length;
    m_data = new char[m_length];

    // copy String
    for (int i = 0; i < m_length; ++i)
        m_data[i] = s.m_data[i];
}

void String::setString(char* c, int length) {
    if (m_data != NULL)
        delete[] m_data;
    m_data = new char[length];
    m_length = length;
    for (int i = 0; i < length; i++) {
        m_data[i] = c[i];
    }
}

void String::setString(string& c, int length) {
    if (m_data != NULL)
        delete[] m_data;
    m_data = new char[length];
    m_length = length;
    for (int i = 0; i < length; i++) {
        m_data[i] = c[i];
    }
}

void String::printString() {
    for (int i = 0; i < m_length; ++i) {
        cout << m_data[i];
    }
}

// Overload operator to check if two Strings are same
bool String::operator==(const String& s) {
    if (m_length != s.m_length) return false;
    for (int i = 0; i < m_length; ++i) {
        if (m_data[i] != s.m_data[i])
            return false;
    }
    return true;
}

// Method to concat String
String String::operator+(const String& s) {
    int length = m_length + s.m_length;
    char* c = new char[length];

    for (int i = 0; i < m_length; ++i) {
        c[i] = m_data[i];
    }
    for (int i = m_length; i < length; ++i) {
        c[i] = s.m_data[i - m_length];
    }
    String str;
    str.setString(c, length);
    return str;
}

int main() {
    string s1, s2;
    String str1, str2;

    cout << "Enter a string: ";
    getline(cin >> ws, s1);
    str1.setString(s1, s1.length());

    cout << "Enter another string: ";
    getline(cin >> ws, s2);
    str2.setString(s2, s2.length());

    str1.printString();
    cout << " and ";
    str2.printString();
    cout << " are " << (str1 == str2 ? "same" : "not same") << ".\n";

    // concat String
    String str3(str1 + str2);

    str1.printString();
    cout << " + ";
    str2.printString();
    cout << " = ";
    str3.printString();
    cout << endl;

    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter a string: Ankit 
Enter another string: Gourav
Ankit and Gourav are not same.
Ankit + Gourav = AnkitGourav

Test 2:
Enter a string: 01234
Enter another string: 56789
01234 and 56789 are not same.
01234 + 56789 = 0123456789

Test 3:
Enter a string: Hey
Enter another string: Hey
Hey and Hey are same.
Hey + Hey = HeyHey

*/