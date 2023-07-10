/*
    Q7. Let's see the C++ program to show the Sum of n number of odd natural
        numbers by using the different type of constructors.
*/

#include <iostream>

using namespace std;

class SumOFOddNumbers {
    int n;

  public:
    // Default constructor
    SumOFOddNumbers() : n(0) {
    }

    // Parameterized constructor
    SumOFOddNumbers(int a) : n(a){
    }

    // Copy constructor
    SumOFOddNumbers(const SumOFOddNumbers& s) {
        cout << "copy\n";
        n = s.n;
    }

    void setNum(int num);
    int getSum();
};

void SumOFOddNumbers::setNum(int a) {
    n = a;
}

int SumOFOddNumbers::getSum() {
    int sum = 0, num = 1;
    for (int i = 0; i < n; i++) {
        sum += num;
        num += 2;
    }
    return sum;
}

int main() {
    cout << "Enter n: ";
    int n;
    cin >> n;

    // Try to call copy constructor
    SumOFOddNumbers s = n;

    cout << "Sum of first " << n << " odd natural no. is " << s.getSum() << '\n';

    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter n: 1
Sum of first 1 odd natural no. is 1

Test 2:
Enter n: 6
Sum of first 6 odd natural no. is 36

Test 3:
Enter n: 10
Sum of first 10 odd natural no. is 100

*/