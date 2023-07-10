/*
    Q2. There is no need to store the values – No need to use arrays –
        Assume that m is 3 and use sentinel -100 to end inputs. Output
        marks in each subject and total obtained by each student in a
        row and subject average and class average in the last row.
*/

#include <iostream>

using namespace std;

int main() {
    int studentCount = 1;
    int m1 = 0, m2 = 0, m3 = 0; // subjects
    int t1, t2, t3; // temporary mark holders

    cout << "Student n" << studentCount << ": m1 m2 m3\n";
    while (true) {
        cout << "Student " << studentCount << ": ";
        cin >> t1;
        // break if -100 is provided at the end which will be holded by t1/m1
        if (t1 == -100)
            break;

        cin >> t2 >> t3;

        m1 += t1;
        m2 += t2;
        m3 += t3;
        ++studentCount;
    }

    cout << "Average: " << m1 / studentCount << " " << m2 / studentCount;
    cout << " " << m3 / studentCount << '\n';
    cout << "Class average: " << (m1 + m2 + m3) / (studentCount * 3) << '\n';

    return 0;
}

/*
        -- OUTPUT --

Test 1:
Student n1: m1 m2 m3
Student 1: -100
Average: 0 0 0
Class average: 0

Test 2:
Student n1: m1 m2 m3
Student 1: 19 18 17
Student 2: 20 17 16
Student 3: 20 20 11
Student 4: -100
Average: 14 13 11
Class average: 13

*/