/*
    Q2. Create a structure for Bank account with name, account number and
        balance. Create a list of account holders using array of structures
        and get input from user to populate them. Display the account details
        given the account number.
*/

#include <iostream>
#include <string>

using namespace std;

struct Bank {
    int account = 0;
    string name;
    double balance = 0;
};

void addAccount(Bank* acc_list, int& acc_exists) {
    string name;
    cout << "Enter name: ";
    getline(cin >> ws, name);
    acc_list[acc_exists].account = acc_exists + 1;
    acc_list[acc_exists].name = name;
    ++acc_exists;
    cout << "Account created.\n";
    cout << "Your account no. is " << acc_exists << endl;
}

void displayBalance(Bank* acc_list, int acc_exists) {
    int acc;
    cout << "Enter account no.: ";
    cin >> acc;
    if (acc > acc_exists) {
        cout << "Account doesn't exit.\n";
        return;
    }
    cout << "Acc. no. = " << acc_list[acc - 1].account << endl;
    cout << "Balance = " << acc_list[acc - 1].balance << endl;
}

void searchAccount(Bank* acc_list, int acc_exists) {
    int acc;
    bool account_found = false;
    int account_index = 0;
    cout << "Enter account no. ";
    cin >> acc;
    for (int i = 0; i < acc_exists; ++i) {
        if (acc_list[i].account == acc) {
            account_found = true;
            account_index = i;
            break;
        }
    }

    if (account_found) {
        cout << "Account no. = " << acc_list[account_index].account << endl;
        cout << "Account name = " << acc_list[account_index].name << endl;
        cout << "Balance = " << acc_list[account_index].balance << endl;
    } else cout << "Accout not found.\n";
}

void listAccounts(Bank* acc_list, int acc_exists) {
    if (acc_exists == 0) {
        cout << "No account exists.\n";
        return;
    }
    for (int i = 0; i < acc_exists; ++i) {
        cout << "\nAccount no. = " << acc_list[i].account << endl;
        cout << "Account name = " << acc_list[i].name << endl;
        cout << "Balance = " << acc_list[i].balance << endl;
    }
}

void creditAmount(Bank* acc_list, int acc) {
    cout << "Enter transaction amount: ";
    double am;
    cin >> am;
    acc_list[acc - 1].balance += am;
    cout << "Credited " << am << endl;
    cout << "Balance = " << acc_list[acc - 1].balance << endl;
}

void debitAmount(Bank* acc_list, int acc) {
    cout << "Enter transaction amount: ";
    double am;
    cin >> am;
    acc_list[acc - 1].balance -= am;
    cout << "Debited " << am << endl;
    cout << "Balance = " << acc_list[acc - 1].balance << endl;
}

void transaction(Bank* acc_list, int acc_exists) {
    cout << "Enter account no. ";
    int acc;
    cin >> acc;
    if (acc > acc_exists) {
        cout << "Account doesn't exits.\n";
        return;
    }

    cout << "\n1. Credit amount\n"
            "2. Debit amount\n"
            "0. Back\n"
            ":> ";
    int a;
    cin >> a;

    switch (a) {
        case 1:
            creditAmount(acc_list, acc);
            break;
        case 2:
            debitAmount(acc_list, acc);
            break;
        default:
            return;
    }
}

void menu() {
    cout << "\n   Bank Sheet\n\n"
            " 1. Add account\n"
            " 2. Display balance\n"
            " 3. Transaction\n"
            " 4. Search account\n"
            " 5. List all accounts\n"
            " 0. Exit\n"
            ":> ";
}

int main() {
    Bank acc_list[100] = {0, "", 0};
    int acc_exists = 0;
    int input = 0;

    while (true) {
        menu();
        cin >> input;
        if (input == 0)
            break;
        switch (input) {
            case 0:
                break;
            case 1:
                addAccount(acc_list, acc_exists);
                break;
            case 2:
                displayBalance(acc_list, acc_exists);
                break;
            case 3:
                transaction(acc_list, acc_exists);
                break;
            case 4:
                searchAccount(acc_list, acc_exists);
                break;
            case 5:
                listAccounts(acc_list, acc_exists);
                break;
            default:
                cout << "Invalid selection.\n";
                break;
        }
    }

    return 0;
}

/*
        -- OUTPUT --

   Bank Sheet

 1. Add account
 2. Display balance
 3. Transaction
 4. Search account
 5. List all accounts
 0. Exit
:> 1
Enter name: Ankit
Account created.
Your account no. is 1

   Bank Sheet

 1. Add account
 2. Display balance
 3. Transaction
 4. Search account
 5. List all accounts
 0. Exit
:> 1
Enter name: Gourav
Account created.
Your account no. is 2

   Bank Sheet

 1. Add account
 2. Display balance
 3. Transaction
 4. Search account
 5. List all accounts
 0. Exit
:> 3
Enter account no. 4
Account doesn't exits.

   Bank Sheet

 1. Add account
 2. Display balance
 3. Transaction
 4. Search account
 5. List all accounts
 0. Exit
:> 3
Enter account no. 1

1. Credit amount
2. Debit amount
0. Back
:> 1
Enter transaction amount: 4000
Credited 4000
Balance = 4000

   Bank Sheet

 1. Add account
 2. Display balance
 3. Transaction
 4. Search account
 5. List all accounts
 0. Exit
:> 2
Enter account no.: 1
Acc. no. = 1
Balance = 4000

   Bank Sheet

 1. Add account
 2. Display balance
 3. Transaction
 4. Search account
 5. List all accounts
 0. Exit
:> 3
Enter account no. 1

1. Credit amount
2. Debit amount
0. Back
:> 2
Enter transaction amount: 199.5
Debited 199.5
Balance = 3800.5

   Bank Sheet

 1. Add account
 2. Display balance
 3. Transaction
 4. Search account
 5. List all accounts
 0. Exit
:> 4
Enter account no. 2
Account no. = 2
Account name = Gourav
Balance = 0

   Bank Sheet

 1. Add account
 2. Display balance
 3. Transaction
 4. Search account
 5. List all accounts
 0. Exit
:> 5

Account no. = 1
Account name = Ankit
Balance = 3800.5

Account no. = 2
Account name = Gourav
Balance = 0

   Bank Sheet

 1. Add account
 2. Display balance
 3. Transaction
 4. Search account
 5. List all accounts
 0. Exit
:> 0

/*