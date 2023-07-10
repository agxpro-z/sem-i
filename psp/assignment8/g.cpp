/*
    Q7. Write a program to accept the student detail such as name and 3 different marks
        by get_data() method and display the name and average of marks using display()
        method. Define a friend class for calculating the average of marks using the
        method marrk_avg().
*/

#include <iostream>
#include <string>

using namespace std;

class Student {
    string name;
    float m1, m2, m3;

  public:
    Student() : name(""), m1(0), m2(0), m3(0) {}

    void get_data();
    void display();
    friend float mark_avg(Student& s);
};

void Student::get_data() {
    cout << "Enter student name: ";
    string name;
    getline(cin >> ws, name);
    cout << "Enter 3 subject marks: ";
    cin >> m1 >> m2 >> m3;
}

void Student::display() {
    cout << "Student name: " << name << '\n';
    cout << "Sub1 marks: " << m1 << '\n';
    cout << "Sub2 marks: " << m2 << '\n';
    cout << "Sub3 marks: " << m3 << '\n';
}

float mark_avg(Student& s) {
    return s.m1 + s.m2 + s.m3;
}

int main() {
    Student student;

    student.get_data();
    student.display();
    cout << "Average: " << mark_avg(student) << '\n';

    return 0;
}

/*
        -- OUTPUT --

Enter student name: Test student
Enter 3 subject marks: 12 15 18
Student name: 
Sub1 marks: 12
Sub2 marks: 15
Sub3 marks: 18
Average: 45

*/