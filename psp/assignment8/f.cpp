/*
    Q6. Write a C++ program to count the number of persons inside a bank, by increasing
        count whenever a person enters a bank, using an increment(++) operator overloa-
        ding function, and decrease the count whenever a person leaves the bank using a
        decrement(--) operator overloading function inside a class.
*/

#include <iostream>

using namespace std;

class Bank {
    int persons;

  public:
    Bank() : persons(0) {}

    int getPersons() {
        return persons;
    }

    Bank& operator++(int) {
        persons++;
        return *this;
    }

    Bank& operator--(int) {
        persons--;
        return *this;
    }
};

void menu(Bank& bank) {
    cout << "\n\tBank\t[" << bank.getPersons() << " Person inside]\n\n";
    cout << "1. A person goes inside\n"
            "2. A person comes out\n"
            "0. Exit\n"
            " :> ";
}

int main() {
    Bank bank;
    int input = 0;
    do {
        menu(bank);
        cin >> input;
        switch (input) {
            case 1:
                bank++;
                break;
            case 2:
                if (bank.getPersons() == 0) {
                    cout << "No one is inside.\n";
                } else {
                    bank--;
                }
                break;
            case 0:
            default:
                break;
        }
    } while (input != 0);

    return 0;
}

/*
        -- OUTPUT --


        Bank    [0 Person inside]

1. A person goes inside
2. A person comes out
0. Exit
 :> 1

        Bank    [1 Person inside]

1. A person goes inside
2. A person comes out
0. Exit
 :> 1

        Bank    [2 Person inside]

1. A person goes inside
2. A person comes out
0. Exit
 :> 1

        Bank    [3 Person inside]

1. A person goes inside
2. A person comes out
0. Exit
 :> 2

        Bank    [2 Person inside]

1. A person goes inside
2. A person comes out
0. Exit
 :> 2

        Bank    [1 Person inside]

1. A person goes inside
2. A person comes out
0. Exit
 :> 2

        Bank    [0 Person inside]

1. A person goes inside
2. A person comes out
0. Exit
 :> 2
No one is inside.

        Bank    [0 Person inside]

1. A person goes inside
2. A person comes out
0. Exit
 :> 0
*/