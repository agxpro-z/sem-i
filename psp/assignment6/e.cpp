/*
    Q5. Create a structure for student with rollno, name, marks for 4 subjects.
        Create an list of students using array.
        a) calculate average for each student and print along with rollno
        b) sort the array by total marks and print the same with rollno in sorted order
*/

#include <iostream>
#include <string>

using namespace std;

// Total students in the class
const int totalStudents = 60;

struct Student {
    int rollno;
    string name;
    float marks[4];
    float average;

    void print() {
        cout << rollno << '\t' << name << '\t';
        cout << marks[0] << '\t' << marks[1] << '\t';
        cout << marks[2] << '\t' << marks[3] << '\t';
        cout << average << endl;
    }
};

void sort(Student* student, bool rollno_wise_sorting) {
    // sorting using selection sort
    for (int i = 0; i < totalStudents - 1; ++i) {
        for (int j = i; j < totalStudents; ++j) {
            if (rollno_wise_sorting) {
                if (student[i].rollno > student[j].rollno) {
                    Student s = student[i];
                    student[i] = student[j];
                    student[j] = s;
                }
            } else {
                if (student[i].average < student[j].average) {
                    Student s = student[i];
                    student[i] = student[j];
                    student[j] = s;
                }
            }
        }
    }
}

void menu() {
    cout << "\n   Marks Sheet\t\n"
            " 1. Enter student marks\n"
            " 2. Print all student marks\n"
            " 3. Print all student marks wise\n"
            " 0. Exit\n"
            ":> ";
}

void takeInput(Student* student) {
    for (int i = 0; i < totalStudents; ++i) {
        if (student[i].rollno != 0) {
            continue;
        } else {
            cout << "Enter student roll no.: ";
            cin >> student[i].rollno;
            cout << "Enter student name: ";
            getline(cin >> ws, student[i].name);
            cout << "Enter 4 subject marks: ";
            cin >> student[i].marks[0] >> student[i].marks[1];
            cin >> student[i].marks[2] >> student[i].marks[3];
            student[i].average = (student[i].marks[0] + student[i].marks[1]
                                    + student[i].marks[2] + student[i].marks[3]) / 4;
            break; // get back to menu after taking marks of 1 student
        }
    }
}

void printStudents(Student* student, bool rollno_wise_sorting) {
    // Sort list roll no. wise before printing
    sort(student, rollno_wise_sorting);

    // Print header
    cout << "\nR.no\tName\tS1\tS2\tS3\tS4\tAvg\n";

    // Start print list
    for (int i = 0; i < totalStudents; ++i) {
        if (student[i].rollno == 0)
            continue;
        else {
            student[i].print();
        }
    }
    cout << endl;
}

int main() {
    // Student database
    Student student[totalStudents] = {0, "", {0, 0, 0, 0}};

    int input = 0;
    do {
        menu();
        cin >> input;

        switch (input) {
            case 1:
                takeInput(student);
                break;
            case 2:
                // Print roll no wise
                printStudents(student, true);
                break;
            case 3:
                // Print marks wise
                printStudents(student, false);
                break;
            case 0:
                cout << "Exiting..\n";
                break;
            default:
                cout << "Invalid selection.\n";
        }
    } while (input != 0);

    return 0;
}

/*
        -- OUTPUT --

   Marks Sheet
 1. Enter student marks
 2. Print all student marks
 3. Print all student marks wise
 0. Exit
:> 1
Enter student roll no.: 10
Enter student name: A
Enter 4 subject marks: 19 19 20 18

   Marks Sheet
 1. Enter student marks
 2. Print all student marks
 3. Print all student marks wise
 0. Exit
:> 1
Enter student roll no.: 23
Enter student name: B 
Enter 4 subject marks: 12 15 16 14

   Marks Sheet
 1. Enter student marks
 2. Print all student marks
 3. Print all student marks wise
 0. Exit
:> 1
Enter student roll no.: 17
Enter student name: C
Enter 4 subject marks: 13 11 18 19

   Marks Sheet
 1. Enter student marks
 2. Print all student marks
 3. Print all student marks wise
 0. Exit
:> 
1
Enter student roll no.: 45
Enter student name: D
Enter 4 subject marks: 15 18 14 8

   Marks Sheet
 1. Enter student marks
 2. Print all student marks
 3. Print all student marks wise
 0. Exit
:> 1
Enter student roll no.: 5
Enter student name: E
Enter 4 subject marks: 15 16 15 19

   Marks Sheet
 1. Enter student marks
 2. Print all student marks
 3. Print all student marks wise
 0. Exit
:> 2

R.no    Name    S1      S2      S3      S4      Avg
5       E       15      16      15      19      16.25
10      A       19      19      20      18      19
17      C       13      11      18      19      15.25
23      B       12      15      16      14      14.25
45      D       15      18      14      8       13.75


   Marks Sheet
 1. Enter student marks
 2. Print all student marks
 3. Print all student marks wise
 0. Exit
:> 3

R.no    Name    S1      S2      S3      S4      Avg
10      A       19      19      20      18      19
5       E       15      16      15      19      16.25
17      C       13      11      18      19      15.25
23      B       12      15      16      14      14.25
45      D       15      18      14      8       13.75


   Marks Sheet
 1. Enter student marks
 2. Print all student marks
 3. Print all student marks wise
 0. Exit
:> 0
Exiting..

*/