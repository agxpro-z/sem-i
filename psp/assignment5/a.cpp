/*
    Q1. Program to merge two 1-D arrays.
*/

#include <iostream>

using namespace std;

int main() {
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    int arr_combined[20];

    for (int i = 0, j = 10; i < 10 && j < 20; ++i, ++j) {
        arr_combined[i] = arr1[i];
        arr_combined[j] = arr2[i];
    }

    for (int i = 0; i < 20; ++i)
        cout << arr_combined[i] << (i != 19 ? ", " : "");
    cout << endl;

    return 0;
}

/*
        -- OUTPUT --

1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20

*/