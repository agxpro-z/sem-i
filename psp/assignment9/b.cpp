/*
    Q2. Every circle has a center and a radius. Given the radius, we can determine the
        circle’s area and circumference. Given the center, we can determine its position
        in the x-y plane. The center of the circle is a point in the x-y plane. Design a
        class, circleType, that can store the radius and center of the circle. Because the
        center is a point in the x-y plane and you designed the class to capture the
        properties of a point in Question 1 you must derive the class circleType from the
        class pointType. You should be able to perform the usual operations on the circle,
        such as setting the radius, printing the radius, calculating and printing the area
        and circumference, and carrying out the usual operations on the center. Also, write
        a program to test various operations on a circle.
*/

#include <cmath>
#include <iostream>

using namespace std;

const double PIE = 3.1415;

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

class circleType : public pointType {
    double r;
  public:
    circleType() : r(0) {}
    circleType(double radius) : r(radius) {}
    circleType(double x, double y, double radius) : pointType(x, y), r(radius) {}

    bool isCentreOrigin() {
        return isOrigin();
    }

    double area() {
        return PIE * pow(r, 2);
    }

    double circumference() {
        return 2 * PIE * r;
    }

    void changeR(int radius) {
        r = radius;
    }

    double getR() {
        return r;
    }
};

int main() {
    cout << "Enter circle center points and radius: ";
    double x, y, r;
    cin >> x >> y >> r;
    circleType c(x, y, r);
    cout << "Area: " << c.area() << '\n';
    cout << "Circumference: " << c.circumference() << '\n';
    cout << "Center: " << c << '\n';

    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter circle center points and radius: 3 5 8
Area: 201.056
Circumference: 50.264
Center: (3, 5)

Test 2:
Enter circle center points and radius: 4 6 10
Area: 314.15
Circumference: 62.83
Center: (4, 6)

Test 3:
Enter circle center points and radius: 12 34 56
Area: 9851.74
Circumference: 351.848
Center: (12, 34)

*/