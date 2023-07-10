/*
    Q3. Write a program to find the sum of all the elements of an array
        using pointers.
*/

#include <iostream>

using namespace std;

int main() {
    int val;
    cout << "Enter no. of values: ";
    cin >> val;

    // Dynamically allocate array of user defined size.
    int* arr = new int[val], sum = 0;

    // Iterate through array and take input form user.
    for (int i = 0; i < val; ++i) {
        cin >> arr[i];
    }

    // Add all the values of array and store in sum.
    for (int i = 0; i < val; ++i) {
        sum += arr[i];
    }

    cout << "Sum = " << sum << endl;

    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter no. of values: 4
12
13
14
15
Sum = 54

Test 2:
Enter no. of values: 2
1
2
Sum = 3

Test 3:
Enter no. of values: 5
1
2
3
4
5
Sum = 15

*/