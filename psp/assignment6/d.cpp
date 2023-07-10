/*
    Q4. Create a structure for calender date with day, month and year. Find
        if given two days are equal, or which is earlier. Write a function
        to add days to the date structure to form the new date. Assume no
        leap year.
*/

#include <iostream>
#include <string>

using namespace std;

//
// Part 1 of the code also used in previous question as a header file.
//
/*
 * Date module to perform some basic date operations

 # Functionalities
  * parse(string str) - takes date in string form spearated by almost anything
                        and returns in Date form. Eg. 22 10 2022 or 22/10/2022
                        Usage: Date d = Date::parse(string);

                        Note: If invalid date is entered 'Invalid Date.' will
                        be printed on the screen and object will be initialized
                        with default date '1/1/2000'

  * print() - Prints date from the Date object. Also supports separater (optional)
              Usage: d.print('.')
              Output: 22.10.2022

  * getDate() - Same as print but instead returns date in the form of string

  * compare - compares two dates and return -1, 0, 1
                -1 if first date comes before second (d1 < d2)
                 0 if both dates are equal           (d1 = d2)
                 1 if first date comes after second  (d1 > d2)
              Usage: Date::compare(d1, d2);

  * addDays() / subtractDays() - adds and subtracts n days from the current date
                                 and returns new date
                                 Usage: d = d.addDays(10)
                                  or    d = d.subtractDays(5)

  * daysBetween() - returns how many days are two dates apart, return int
                    Usage: Date::daysBetween(d1, d2)
                    output is always positive
 */
struct Date {
    int day;
    int month;
    int year;

    // Initialize date using date constructor
    // check date and print invalid for invalid date.
    Date(int d=1, int m=1, int y=2000) {
        if (isDateValid(d, m, y)) {
            day = d;
            month = m;
            year = y;
        } else {
            day = 1;
            month = 1;
            year = 2000;
            cout << "Invalid Date.\n";
        }
    }

    // Print date from object
    void print(char sep='-') {
        cout << day << sep << month << sep << year << endl;
    }

    // Print date
    static void print(Date d, char sep='-') {
        cout << d.day << sep << d.month << sep << d.year << endl;
    }

    // Return date string
    string getDate(char sep='-') {
        return (to_string(day) + sep + to_string(month) + sep + to_string(year));
    }

    // Check for leap year
    static bool isLeapYear(int y) {
        return ((y % 4 == 0) && (y % 100 != 0));
    }

    // Check date validity
    static bool isDateValid(int d, int m, int y) {
        if (isYValid(y) && isMValid(m)) {
            if (m == 1 || m == 3 || m == 5 || m == 7
                || m == 8 || m == 10 || m == 12)
                    return (d <= 31 && d > 0);
            else if (m == 4 || m == 6 || m == 9 || m == 11)
                return (d <= 30 && d > 0 );
            else if (m == 2)
                return (isLeapYear(y) ? (d <= 29 && d > 0) : (d <= 28 && d > 0));
            else return false;
        } else return false;
    }

    // Check month validity
    static bool isMValid(int m) {
        return (m > 0 && m <= 12);
    }

    // Check year validity
    static bool isYValid(int y) {
        return y > 0;
    }

    // Returns no. of days in current month of the date
    int daysInMonth(Date d) {
            if (d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7
                || d.month == 8 || d.month == 10 || d.month == 12)
                return 31;
            else if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11)
                return 30;
            else
                return (isLeapYear(d.year) ? 29 : 28);
    }

    // Adds n days to the current date and returns new Date
    Date addDays(int days) {
        // create copy of current date before adding
        Date d = {day, month, year};

        while (days != 0) {
            // find remaining days until next month
            int days_remaining = daysInMonth(d) - d.day;

            // increment month if added days are greated than
            // the days remaining until next month
            if (days > days_remaining) {
                days -= days_remaining;
                if (d.month == 12) {
                    ++d.year;
                    d.month = 1;
                    d.day = 1;
                    --days; // reducd days by one as days starts form 1 not zero
                } else {
                    ++d.month;
                    d.day = 1;
                    --days; // reducd days by one as days starts form 1 not zero
                }
            } else {
                d.day += days;
                days = 0;
            }
        }
        return d;
    }

    // Subtracts n days from the current date and returns new Date
    Date subtractDays(int days) {
        // create copy of current date before subtracting
        Date d = {day, month, year};

        while (days != 0) {
            // find days remaining until previous month
            int days_remaining = d.day;

            // decrement month if subtracted days are greated than
            // the days remaining until previous month
            if (days >= days_remaining) {
                days -= days_remaining;
                if (d.month == 1) {
                    --d.year;
                    d.month = 12;
                    d.day = 31; // It's always decenmber
                } else {
                    --d.month;
                    d.day = daysInMonth(d);
                }
            } else {
                d.day -= days;
                days = 0;
            }
        }
        return d;
    }

    // Returns days between two dates
    static int daysBetween(Date d1, Date d2) {
        int daysCount = 0;
        if (Date::compare(d1, d2) == 1) {
            while (Date::compare(d1, d2) != 0) {
                d2 = d2.addDays(1);
                ++daysCount;
            }
        } else if (Date::compare(d1, d2) == -1) {
            while (Date::compare(d1, d2) != 0) {
                d1 = d1.addDays(1);
                ++daysCount;
            }
        } else { return 0; }
        return daysCount;
    }

    // Parse date string and return struct Date
    static Date parse(string str) {
        string d = "", m = "", y = "";
        short val = 0;
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] >= 48 && str[i] <= 57) {
                if (val == 0)
                    d += str[i];
                else if (val == 1)
                    m += str[i];
                else
                    y += str[i];
            } else {
                ++val;
            }
        }
        return {stoi(d), stoi(m), stoi(y)};
    }

    // Compares date without checking validity
    // returns -1 if d1 < d2, 0 if d1 = d2, 1 if d1 > d2
    static int compare(Date d1, Date d2) {
        if (d1.year > d2.year)
            return 1;
        else if (d1.year < d2.year)
            return -1;
        else {
            if (d1.month > d2.month)
                return 1;
            else if (d1.month < d2.month)
                return -1;
            else {
                if (d1.day < d2.day)
                    return -1;
                else if (d1.day > d2.day)
                    return 1;
                else return 0;
            }
        }
    }
};
// Part 1 end

// Part 2 start
void menu();
Date getDate();
int getDays();

int main() {
/*    string input;
    cout << "Enter a date: ";
    getline(cin >> ws, input);
    Date d1 = Date::parse(input);
    d1.print('.');
*/
    int input = 0;
    do {
        menu();
        cin >> input;

        // Declaring all the vriables used in switch case
        Date d, d1, d2;
        int c, day;

        switch (input) {
            case 1: // Comparing two dates
                d1 = getDate();
                d2 = getDate();
                c = Date::compare(d1, d2);
                if (c == -1)
                    cout << d1.getDate() << " comes earlier than " << d2.getDate() << endl;
                else if (c == 0)
                    cout << d1.getDate() << " and " << d2.getDate() << " are same.\n";
                else if (c == 1)
                    cout << d2.getDate() << " comes earlier than " << d1.getDate() << endl;
                else
                    cout << "Unable to compare.\n";
                break;
            case 2: // Adding n days to a date
                d = getDate();
                day = getDays();
                d = d.addDays(day);
                cout << "New date: " << d.getDate() << endl;
                break;
            case 3: // Subtracting n days from date
                d = getDate();
                day = getDays();
                d = d.subtractDays(day);
                cout << "New date: " << d.getDate() << endl;
                break;
            case 4: // Finding no. of days between two days
                d1 = getDate();
                d2 = getDate();
                cout << d1.getDate() << " and " << d2.getDate() << " are ";
                cout << Date::daysBetween(d1, d2) << " days apart.\n";
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

void menu() {
    cout << "\n    Date Calculator\n\n"
            " 1. Compare dates\n"
            " 2. Add days to date\n"
            " 3. Subtract days from date\n"
            " 4. Find days between two dates\n"
            " 0. Exit\n"
            ":> ";
}

Date getDate() {
    cout << "Enter date: ";
    string s;
    getline(cin >> ws, s);
    return Date::parse(s);
}

int getDays() {
    cout << "Enter no. of days: ";
    int d;
    cin >> d;
    return d;
}
// Part 2 end

/*
        -- OUTPUT --

    Date Calculator

 1. Compare dates
 2. Add days to date
 3. Subtract days from date
 4. Find days between two dates
 0. Exit
:> 1
Enter date: 22-10-2022
Enter date: 23-20-2022
Invalid Date.
1-1-2000 comes earlier than 22-10-2022

    Date Calculator

 1. Compare dates
 2. Add days to date
 3. Subtract days from date
 4. Find days between two dates
 0. Exit
:> 1
Enter date: 22-10-2022
Enter date: 23-10-2022
22-10-2022 comes earlier than 23-10-2022

    Date Calculator

 1. Compare dates
 2. Add days to date
 3. Subtract days from date
 4. Find days between two dates
 0. Exit
:> 2
Enter date: 23.10.2022
Enter no. of days: 45
New date: 7-12-2022

    Date Calculator

 1. Compare dates
 2. Add days to date
 3. Subtract days from date
 4. Find days between two dates
 0. Exit
:> 3
Enter date: 7/12/2022
Enter no. of days: 45
New date: 23-10-2022

    Date Calculator

 1. Compare dates
 2. Add days to date
 3. Subtract days from date
 4. Find days between two dates
 0. Exit
:> 4
Enter date: 23|10|2022
Enter date: 7 12 2022
23-10-2022 and 7-12-2022 are 45 days apart.

    Date Calculator

 1. Compare dates
 2. Add days to date
 3. Subtract days from date
 4. Find days between two dates
 0. Exit
:> 0
Exiting..

*/