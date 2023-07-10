/*
    Q9. Given three points (x1, y1), (x2, y2) and (x3, y3), write a program to
        check if all the three points fall on one straight line.
*/

#include <iostream>

using namespace std;

double getTraingleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    return (((x1 - x2) * (y2 - y3)) - ((x2 - x3) * (y1 - y2)));
}

void print(bool b) {
    if (b)
        cout << "All three points fall on a straight line.\n";
    else
        cout << "Points doesn't fall on a straight line.\n";
}

int main() {
    double x1, x2, x3, y1, y2, y3;
    cout << "Enter first coordinate: ";
    cin >> x1 >> y1;
    cout << "Enter second coordiante: ";
    cin >> x2 >> y2;
    cout << "Enter third coordinate: ";
    cin >> x3 >> y3;

    print(getTraingleArea(x1, y1, x2, y2, x3, y3) == 0);

    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter first coordinate: 1 2
Enter second coordiante: 1 4 
Enter third coordinate: 1 5
All three points fall on a straight line.

Test 2:
Enter first coordinate: 1 3 
Enter second coordiante: 1 4
Enter third coordinate: 2 4
Points doesn't fall on a straight line.

Test 3:
Enter first coordinate: 12.1 23
Enter second coordiante: 12.1 90
Enter third coordinate: 12.1 0
All three points fall on a straight line.

*/