/*
    Q3. Create a structure for library users with name, book id, date of
        renewal. Create a list of library users and update their entries
        from user. Find out on a particular day who are the defaulters.
        Assume only one book is issued per person.
*/

#include <iostream>
#include <string>

// For Date handling
// See d.cpp for definition
//
// This suppose to be a header file but writing one specially for
// this will make this program huge and I've already written the
// next program, so I'm just going to use that here.
//
// Note: not all IDEs allow .cpp file as a header.
//
// Before using comment out the part 2 of the next code
#include "d.cpp"

using namespace std;

// Number of books library can issue
const int totalBooks = 100;

struct Book {
    string user;
    int book_id;

    // From d.cpp
    Date iDate; // issue date
    Date sDate; // submissions date

    void printInfo(Date& current) {
        cout << "Name: " << user << '\t' << "[Status: ";
        cout << (daysRemainig(current) < 0 ? "Due" : "OK") << ']' << endl;

        cout << "Book id: " << book_id << endl;
        cout << "Issue date: " << iDate.getDate() << endl;
        cout << "Submission date: " << sDate.getDate() << endl;
        cout << "Issued for " << Date::daysBetween(iDate, sDate) << " days\n";
        cout << "Days reamining: " << (daysRemainig(current) > 0 ? daysRemainig(current) : 0) << " days\n";
    }

    // Return ramining days until submission
    int daysRemainig(Date current) {
        int i = Date::compare(current, sDate);
        if (i == -1)
            return Date::daysBetween(current, sDate);
        else if (i == 1)
            return -Date::daysBetween(current, sDate);
        else
            return 0;
    }
};

void menu() {
    cout << "\n   Library\n\n"
            " 1. Issue a book\n"
            " 2. Submit a book\n"
            " 3. Check info\n"
            " 4. List all\n"
            " 0. Exit\n"
            ":> ";
}

// Return index value if book found else -1
int searchBook(Book* book, int id) {
    for (int i = 0; i < totalBooks; ++i) {
        if (book[i].book_id == id)
            return i;
    }
    return -1;
}

// Issue book 'book_id' to user 'name'
void registerBook(Book* book, Date& current, string& name, int book_id, bool new_issue) {
    cout << "Enter no. of days to issue for, max 90: ";
    int issue_days;
    cin >> issue_days;

    if (issue_days > 90) {
        cout << "Cannot issue book for more than 90 days\n";
    } else {
        int issue_index = searchBook(book, (new_issue ? 0 : book_id));
        if (issue_index == -1) {
            cout << "Not enough book to issue.\n";
        } else {
            book[issue_index].user = name;
            book[issue_index].book_id = book_id;
            if (new_issue) {
                book[issue_index].iDate = current;
                book[issue_index].sDate = current.addDays(issue_days);
                cout << "Book successfully issued for " << issue_days << " days.\n";
            } else {
                book[issue_index].sDate = book[issue_index].sDate.addDays(issue_days);
                cout << "Book successfully reissued for " << issue_days << " days.\n";
            }
        }
    }
}

// Issue book to user
void issueBook(Book* book, Date& current) {
    int book_id;
    cout << "Enter book id: ";
    cin >> book_id;

    if (book_id <= 0) {
        cout << "Invalid book id: " << book_id << endl;
        return;
    }

    string name;
    cout << "Enter your name: ";
    getline(cin >> ws, name);

    // Check if book already exist
    int book_exist = searchBook(book, book_id);

    if (book_exist == -1) {
        // Issue book if doesn't exist
        registerBook(book, current, name, book_id, true);
    } else {
        if ((book[book_exist].user == name)) {
            // Reissue book
            registerBook(book, current, name, book_id, false);
        } else {
            cout << "Book already registered to another user.\n";
        }
    }
}

void submitBook(Book* book, Date current) {
    int book_id;
    cout << "Enter book id: ";
    cin >> book_id;

    if (book_id <= 0) {
        cout << "Invalid book id: " << book_id << endl;
        return;
    }

    string name;
    cout << "Enter your name: ";
    getline(cin >> ws, name);

    // find book index
    int book_exist = searchBook(book, book_id);

    if (book_exist == -1 || book[book_exist].user != name) {
        cout << "Unable to find book issued to " << name << " with book id " << book_id << endl;
    } else {
        book[book_exist].book_id = 0;
        book[book_exist].user = "";
        cout << "Book submitted.\n";
    }
}

// Display book info
void checkBookInfo(Book* book, Date& current) {
    int book_id;
    cout << "Enter book id: ";
    cin >> book_id;

    if (book_id <= 0) {
        cout << "Invalid book id: " << book_id << endl;
        return;
    }

    string name;
    cout << "Enter your name: ";
    getline(cin >> ws, name);

    // find book index
    int book_exist = searchBook(book, book_id);

    if (book_exist != -1 && book[book_exist].user != name) {
        cout << "Unable to find book issued to " << name << " with book id " << book_id << endl;
    } else {
        cout << endl;
        book[book_exist].printInfo(current);
    }
}

void listAllBooks(Book* book, Date& current) {
    int book_count = 0;
    for (int i = 0; i < totalBooks; ++i) {
        if (book[i].book_id == 0)
            continue;
        else {
            cout << endl;
            book[i].printInfo(current);
            ++book_count;
        }
    }

    if (book_count != 0) {
        cout << "\nDue books :- \n";
        for (int i = 0; i < totalBooks; ++i) {
            if (book[i].book_id == 0)
                continue;
            else {
                if (book[i].daysRemainig(current) < 0)
                    cout << "Name: " << book[i].user << "\t Book ID: " << book[i].book_id << endl;
            }
        }
    }

    if (book_count == 0) cout << "No books issued.\n";
}

int main() {
    // Lirary database
    // It can issue 100 books only
    Book book[totalBooks] = {"", 0, {}, {}};

    // Get current date
    cout << "Enter today's date: ";
    string d;
    cin >> d;
    Date current = Date::parse(d);

    // Start Library
    int input = 0;
    do {
        menu();
        cin >> input;

        switch (input) {
            case 1:
                issueBook(book, current);
                break;
            case 2:
                submitBook(book, current);
                break;
            case 3:
                checkBookInfo(book, current);
                break;
            case 4:
                listAllBooks(book, current);
                break;
            case 0:
                cout << "Exiting..\n";
                break;
            default:
                cout << "Invalid selection.\n";
        }
    } while (input != 0);

    return 0;
}

/*
        -- OUTPUT --

Enter today's date: 22.10.2022

   Library

 1. Issue a book
 2. Submit a book
 3. Check info
 4. List all
 0. Exit
:> 4
No books issued.

   Library

 1. Issue a book
 2. Submit a book
 3. Check info
 4. List all
 0. Exit
:> 1
Enter book id: 123
Enter your name: Ankit
Enter no. of days to issue for, max 90: 40
Book successfully issued for 40 days.

   Library

 1. Issue a book
 2. Submit a book
 3. Check info
 4. List all
 0. Exit
:> 1
Enter book id: 134
Enter your name: Gourav
Enter no. of days to issue for, max 90: -10
Book successfully issued for -10 days.

   Library

 1. Issue a book
 2. Submit a book
 3. Check info
 4. List all
 0. Exit
:> 1
Enter book id: 112
Enter your name: Ankit Gourav
Enter no. of days to issue for, max 90: 10
Book successfully issued for 10 days.

   Library

 1. Issue a book
 2. Submit a book
 3. Check info
 4. List all
 0. Exit
:> 3
Enter book id: 134
Enter your name: Ankit
Unable to find book issued to Ankit with book id 134

   Library

 1. Issue a book
 2. Submit a book
 3. Check info
 4. List all
 0. Exit
:> 3
Enter book id: 134
Enter your name: Gourav

Name: Gourav    [Status: Due]
Book id: 134
Issue date: 22-10-2022
Submission date: 12-10-2022
Issued for 10 days
Days reamining: 0 days

   Library

 1. Issue a book
 2. Submit a book
 3. Check info
 4. List all
 0. Exit
:> 4

Name: Ankit     [Status: OK]
Book id: 123
Issue date: 22-10-2022
Submission date: 1-12-2022
Issued for 40 days
Days reamining: 40 days

Name: Gourav    [Status: Due]
Book id: 134
Issue date: 22-10-2022
Submission date: 12-10-2022
Issued for 10 days
Days reamining: 0 days

Name: Ankit Gourav      [Status: OK]
Book id: 112
Issue date: 22-10-2022
Submission date: 1-11-2022
Issued for 10 days
Days reamining: 10 days

Due books :- 
Name: Gourav     Book ID: 134

   Library

 1. Issue a book
 2. Submit a book
 3. Check info
 4. List all
 0. Exit
:> 2
Enter book id: 112
Enter your name: Ankit
Unable to find book issued to Ankit with book id 112

   Library

 1. Issue a book
 2. Submit a book
 3. Check info
 4. List all
 0. Exit
:> 2
Enter book id: 112
Enter your name: Ankit Gourav
Book submitted.

   Library

 1. Issue a book
 2. Submit a book
 3. Check info
 4. List all
 0. Exit
:> 4

Name: Ankit     [Status: OK]
Book id: 123
Issue date: 22-10-2022
Submission date: 1-12-2022
Issued for 40 days
Days reamining: 40 days

Name: Gourav    [Status: Due]
Book id: 134
Issue date: 22-10-2022
Submission date: 12-10-2022
Issued for 10 days
Days reamining: 0 days

Due books :- 
Name: Gourav     Book ID: 134

   Library

 1. Issue a book
 2. Submit a book
 3. Check info
 4. List all
 0. Exit
:> 0
Exiting..

*/