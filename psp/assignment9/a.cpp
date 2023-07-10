/*
    Q1. A point in the x-y plane is represented by its x-coordinate and y-coordinate. Design
        a class, pointType, that can store and process a point in the x-y plane. You should
        then perform operations on the point, such as setting the coordinates of the point,
        printing the coordinates of the point, returning the x-coordinate, and returning the
        y-coordinate. Also, write a program to test various operations on the point.
*/

#include <cmath>
#include <iostream>

using namespace std;

class pointType {
    double x;
    double y;

  public:
    pointType() : x(0), y(0) {}
    pointType(double a, double b) : x(a), y(b) {}

    bool isOrigin() {
        return x == 0 && y == 0;
    }

    void changeX(double a) {
        x = a;
    }

    void changeY(double a) {
        y = a;
    }

    double getX() {
        return x;
    }

    double getY() {
        return y;
    }

    void changeXY(double a, double b) {
        x = a;
        y = b;
    }

    double distanceFromOrigin() {
        return sqrt(x*x + y*y);
    }

    double distanceFromPoint(pointType& p) {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }

    friend ostream& operator<<(ostream& o, pointType& p) {
        o << "(" << p.x << ", " << p.y << ")";
        return o;
    }
};

int main() {
    cout << "Enter points: ";
    double a, b;
    cin >> a >> b;
    pointType P(a, b);
    cout << "Distance from origin is " << P.distanceFromOrigin() << '\n';
    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter points: 2  3
Distance from origin is 3.60555

Test 2:
Enter points: 4 5
Distance from origin is 6.40312

Test 3:
Enter points: 5 6
Distance from origin is 7.81025

*/