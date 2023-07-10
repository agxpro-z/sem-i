/*
    Q3. Write a function to take a floating point number as input and returns
        the same number rounded to k decimal places. Do not use any system
        defined functions. If input is 17.24578, and k = 2, the output is 17.25
        and 345.2034 is rounded as 345.20.
*/

#include <iostream>
#include <string>

using namespace std;

struct Pair {
    string s;
    float f;
};

/*
 * Method to trim floating number to n decimal places
 * num = floating number
 * d_place = no. of digits you want after decimal
 * returns in Pair form of both string and floating.
 *
 * TODO: this method doesn't supports rounding.
 */
Pair floating_precision(float num, int d_place) {
    // Convert num to string
    string floating = to_string(num);
    string num1 = floating;

    // Finding index of decimal point
    int point_at_index = 1;
    for (int i = 0; i < floating.length(); ++i) {
        if (floating[i] == '.')
            break;
        ++point_at_index;
    }

    // erasing number before decimal
    floating = floating.erase(0, point_at_index);
    // removing values after d_place
    floating = floating.erase(d_place, floating.length() - 1);

    // erasing values after decimal
    num1 = num1.erase(point_at_index, num1.length() - 1);

    // appending zeros if required
    if (d_place > floating.length()) {
        for (int i = 0; i < (d_place - floating.length()); ++i)
            floating.push_back('0');
    }

    // forming string of new number
    string new_num = num1 + floating;
    return {new_num, stof(new_num)}; // returning in Pair form
}

int main() {
    float num = 0;
    int d_place = 0;
    cout << "Enter a floating point number: ";
    cin >> num;
    cout << "Enter no. of digits after decimal: ";
    cin >> d_place;

    Pair precised = floating_precision(num, d_place);
    cout << precised.s << endl;

    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter a floating point number: 1
Enter no. of digits after decimal: 4
1.0000

Test 2:
Enter a floating point number: 0
Enter no. of digits after decimal: 5
0.00000

Test 3:
Enter a floating point number: 12.23343
Enter no. of digits after decimal: 3
12.233

*/