/*
    Q8. Given the length and breadth of a rectangle, write a program to find
        whether the area of the rectangle is greater than its perimeter. For
        example, the area of the rectangle with length = 5 and breadth = 4 is
        greater than its perimeter.
*/

#include <iostream>

using namespace std;

double getArea(double l, double b) {
    return l * b;
}

double getPerimeter(double l, double b) {
    return 2 * (l + b);
}

void print(bool b) {
    if (b)
        cout << "Area of the given rectangle is larger then it's perimeter.\n";
    else
        cout << "Area of the given rectangle is not larger than it's perimeter.\n";
}

int main() {
    double l, b;
    cout << "Enter length of the rectangle: ";
    cin >> l;
    cout << "Enter breadth of the rectangle: ";
    cin >> b;
    print(getArea(l, b) > getPerimeter(l, b));

    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter length of the rectangle: 1
Enter breadth of the rectangle: 2
Area of the given rectangle is not larger than it's perimeter.

Test 2:
Enter length of the rectangle: 2
Enter breadth of the rectangle: 3
Area of the given rectangle is not larger than it's perimeter.

Test 3:
Enter length of the rectangle: 5
Enter breadth of the rectangle: 5
Area of the given rectangle is larger then it's perimeter.

*/