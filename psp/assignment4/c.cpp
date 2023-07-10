/*
    Q3. If the total price of 15 items and the total profit earned is entered through
        the keyboard write a program to find the cost of one item.
*/

#include <iostream>

using namespace std;

void printItemPrice(double totalPrice, double totalProfit) {
    // each item price = (totalPrice - totalProfit) / 15
    double itemPrice = (totalPrice - totalProfit) / 15;
    cout << "Price of each item is " << itemPrice << endl;
}

int main() {
    double totalPrice;
    cout << "Enter total price of 15 items: ";
    cin >> totalPrice;

    double totalProfit;
    cout << "Enter total profit made: ";
    cin >> totalProfit;

    printItemPrice(totalPrice, totalProfit);

    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter total price of 15 items: 299
Enter total profit made: 13
Price of each item is 19.0667

Test 2:
Enter total price of 15 items: 345
Enter total profit made: 54
Price of each item is 19.4

Test 3:
Enter total price of 15 items: 456
Enter total profit made: 324
Price of each item is 8.8

*/