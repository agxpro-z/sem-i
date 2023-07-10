/*
    Q10. Given the coordinates (x, y) of a center of a circle and its radius,
        write a program which will determine whether a given point lies inside
        the circle, on the circle or outside the circle.
*/

#include <iostream>
#include <cmath>

using namespace std;

// Returns distance of a point from origin
double pointDistance(double x, double y) {
    return sqrt(x*x + y*y);
}

void print(double r, double d) {
    if (r < d)
        cout << "Point is outside the circle.\n";
    else if (r > d)
        cout << "Point is inside the circle.\n";
    else
        cout << "Point is on the circle.\n";
}

int main() {
    double radius, x, y;
    cout << "Enter radius of the circle: ";
    cin >> radius;

    cout << "Enter coordinates of a point: ";
    cin >> x >> y;

    print(radius, pointDistance(x, y));

    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter radius of the circle: 5
Enter coordinates of a point: 4 3
Point is on the circle.

Test 2:
Enter radius of the circle: 8
Enter coordinates of a point: 5 6
Point is inside the circle.

Test 3:
Enter radius of the circle: 12
Enter coordinates of a point: 23 45
Point is outside the circle.

*/