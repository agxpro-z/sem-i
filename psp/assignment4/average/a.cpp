/*
    Q1. In a class there are n number of students – each studying m subjects.
        Marks of each of the student in each of the subjects are to be read
        and class average in each subject and the average of total marks in
        all subjects to be computed.
*/

#include <iostream>

using namespace std;

int main() {
    int students, subjects;
    cout << "Enter no. of students: ";
    cin >> students;
    cout << "Enter no. of subjects: ";
    cin >> subjects;

    double* sMarks = new double[students];
    double class_average = 0;

    cout << "Enter students marks: \n";
    cout << "Student n: ";
    for (int i = 0; i < subjects; ++i)
        cout << 'm' << i + 1 << ' ';
    cout << endl;

    for (int i = 0; i < students; ++i) {
        cout << "Student " << i + 1 << ": ";
        for (int j = 0; j < subjects; ++j) {
            double t_marks = 0;
            cin >> t_marks;
            sMarks[j] += t_marks;
        }
    }

    cout << "\n\n";
    for (int i = 0; i < subjects; ++i) {
        cout << "Class average in subject " << i + 1 << " is " << sMarks[i] / students << endl;
        class_average += sMarks[i];
    }
    cout << "\nClass average is " << class_average / (students * subjects) << endl;
    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter no. of students: 10
Enter no. of subjects: 8
Enter students marks: 
Student n: m1 m2 m3 m4 m5 m6 m7 m8 
Student 1: 90 89 69 70 95 98 58 88
Student 2: 45 56 12 67 87 90 65 78
Student 3: 45 57 75 78 99 54 34 66
Student 4: 78 89 54 23 56 76 87 98
Student 5: 33 45 61 72 77 50 94 89
Student 6: 23 45 67 27 74 72 91 92
Student 7: 24 52 89 45 90 23 90 90
Student 8: 45 90 63 20 78 34 98 43  
Student 9: 12 39 98 67 56 09 56 78
Student 10: 23 67 89 0 78 56 45 66


Class average in subject 1 is 41.8
Class average in subject 2 is 62.9
Class average in subject 3 is 67.7
Class average in subject 4 is 46.9
Class average in subject 5 is 79
Class average in subject 6 is 56.2
Class average in subject 7 is 71.8
Class average in subject 8 is 78.8

Class average is 63.1375

*/