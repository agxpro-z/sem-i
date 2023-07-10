/*
    Q3. Every cylinder has a base and height, wherein the base is a circle. Design a class,
        cylinderType, that can capture the properties of a cylinder and perform the usual
        operations on the cylinder. Derive this class from the class circleType designed in
        Question 2. Some of the operations that can be performed on a cylinder are as follows:
        calculate and print the volume, calculate and print the surface area, set the height,
        set the radius of the base, and set the center of the base. Also, write a program to
        test various operations on a cylinder.
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

class cylinderType : public circleType {
    double h;
  public:
    cylinderType() : h(0) {}
    cylinderType(double height) : h(height) {}
    cylinderType(double radius, double height) : circleType(radius), h(height) {}
    cylinderType(double x, double y, double radius, double height) : circleType(x, y, radius), h(height) {}

    bool isBaseOrigin() {
        return isCentreOrigin();
    }

    void changeH(double height) {
        h = height;
    }

    double getH() {
        return h;
    }

    double surfaceArea() {
        return 2 * PIE * getR() * h;
    }

    double totalSufaceArea() {
        return 2 * PIE * getR() * (h + getR());
    }

    double volume() {
        return PIE * getR() * getR() * h;
    }
};

int main() {
    cout << "Enter cylinder base origin: ";
    double x, y;
    cin >> x >> y;
    cout << "Enter radius of the cylinder: ";
    double r;
    cin >> r;
    cout << "Enter height of the cylinder: ";
    double h;
    cin >> h;
    cylinderType cyl(x, y, r, h);
    cout << "Surface area " << cyl.surfaceArea() << '\n';
    cout << "Total surface area " << cyl.totalSufaceArea() << '\n';
    cout << "Volume " << cyl.volume() << '\n';
    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter cylinder base origin: 3 4
Enter radius of the cylinder: 5
Enter height of the cylinder: 6
Surface area 188.49
Total surface area 345.565
Volume 471.225

Test 2:
Enter cylinder base origin: 4 5
Enter radius of the cylinder: 56
Enter height of the cylinder: 56
Surface area 19703.5
Total surface area 39407
Volume 551698

Test 3:
Enter cylinder base origin: 12 23
Enter radius of the cylinder: 34
Enter height of the cylinder: 45
Surface area 9612.99
Total surface area 16876.1
Volume 163421

*/