/*
    Q5. If cost price and selling price of an item is input through the keyboard,
        write a program to determine whether the seller has made profit or incurred
        loss. Also determine how much profit he made or loss he incurred.
*/

#include <iostream>
#include <string>

using namespace std;

double getInput(bool b) {
    double a;
    cout << ((b) ? "Enter cost price: " : "Enter selling price: ");
    cin >> a;
    return a;
}

void print(double lp) {
    if (lp == 0)
        cout << "No proft or loss incurred.\n";
    else if (lp < 0)
        cout << "Loss of " << -lp << " incurred.\n";
    else
        cout << "Profit of " << lp << " is made.\n";
}

int main() {
    double cP = getInput(true);
    double sP = getInput(false);
    print(sP - cP);
    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter selling price: 100
Enter cost price: 92
Profit of 8 is made.

Test 2:
Enter cost price: 100
Enter selling price: 102
Profit of 2 is made.

Test 3:
Enter cost price: 190
Enter selling price: 199.8
Profit of 9.8 is made.

*/