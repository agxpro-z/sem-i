#include <iostream>
#include <string>

using namespace std;

/*
 * Method to fill dates in the given 2D calendar array.
 * Function takes array of 25x21, begining of the day,
 * starting row and column and number of dates to fill.
 */
int fill_date(int calendar[25][21], int day, int row, int col, int days) {
    int d = 1; // Always start date from 1.
    int wday = day % 7; // Fix starting day in case.

    // Start filling dates.
    for (int i = row; i < row + 6; i++) {
        for (int j = col; j < col + 7; j++) {
            // Skip n starting days in case.
            if (wday > 0) {
                wday--;
                continue;
            }

            // Fill dates and return if all dates are filled.
            if (d > days) return j % 7;
            calendar[i][j] = d;
            d++;
        }
    }
    return 0;
}

/*
 * Method to print calendar made of 2D array.
 */
void printCalendar(int calendar[25][21], int year) {
    char week_days[] = {'S', 'M', 'T', 'W', 'T', 'F', 'S'};
    string months[] = {"        JANUARY       \t       FEBRUARY       \t        MARCH       \n",
                    "         APRIL        \t         MAY          \t         JUNE       \n",
                    "         JULY         \t        AUGUST        \t       SEPTEMBER     \n",
                    "        OCTOBER       \t       NOVEMBER       \t       DECEMBER      \n"};

    // Calendar header including provided year.
    cout<<"                              -- "<<year<<" --"<<endl;

    // Print finalized calendar
    for (int i = 0; i < 25; i++) {
        if (i == 0 || i == 6 || i == 12 || i == 18) {
            cout<<endl;

            // Print months name.
            if (i == 0) cout<<months[0];
            else if (i == 6) cout<<months[1];
            else if (i == 12) cout<<months[2];
            else if (i == 18) cout<<months[3];

            // Print Week days.
            for (int i = 0; i < 3; i++) {
                for (int i = 0; i < 7; i++) {
                    cout<<"  "<<week_days[i];
                }
                cout<<"\t";
            }
            cout<<endl;
        }

        for (int j = 0; j < 21; j++) { // Print 3 months of calendar.
            if (j == 7 || j == 14) cout<<"\t";
            if (calendar[i][j] < 10) {
                if (calendar[i][j] == 0) cout<<"   ";
                else cout<<"  "<<calendar[i][j];
            } else cout<<" "<<calendar[i][j];
        }
        cout<<endl;
    }
}

int getRow(int i) {
    int row;
    if (i == 1 || i == 2 || i == 3) row = 0;
    else if (i == 4 || i == 5 || i == 6) row = 6;
    else if (i == 7 || i == 8 || i == 9) row = 12;
    else if (i == 10 || i == 11 || i == 12) row = 18;
    return row;
}

/*
 * Method to make a proper calendar of given year and starting day.
 */
void make_calendar() {
    int calendar[25][21] = {0};
    int year, wday, row, col, days;

    cout<<"Enter year: ";
    cin>>year;

    cout<<"Select begining day: \n";
    cout<<"  0. Sunday\n";
    cout<<"  1. Monday\n";
    cout<<"  2. Tuesday\n";
    cout<<"  3. Wednesday\n";
    cout<<"  4. Thursday\n";
    cout<<"  5. Friday\n";
    cout<<"  6. Saturday\n";
    cout<<": ";
    cin>>wday;

    // Making each month seperately
    for (int i = 1; i <= 12; i++) {
        if (i == 1 || i == 3 || i == 5 || i == 7
                || i == 8 || i == 10 || i == 12) {
            days = 31;
        } else if (i == 2) {
            if (year % 100 == 0) days = 28;
            else if (year % 4 == 0) days = 29;
            else days = 28;
        } else {
            days = 30;
        }

        if (i == 1 || i == 4 || i == 7 || i == 10) {
            col = 0;
            row = getRow(i);
        } else if (i == 2 || i == 5 || i == 8 || i == 11) {
            col = 7;
            row = getRow(i);
        } else if (i == 3 || i == 6 || i == 9 || i == 12) {
            col = 14;
            row = getRow(i);
        }

        wday = fill_date(calendar, wday, row, col, days); // Fill calendar month by month.
    }
    printCalendar(calendar, year);
}

int main() {
    make_calendar();
    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter year: 2022
Select begining day: 
  0. Sunday
  1. Monday
  2. Tuesday
  3. Wednesday
  4. Thursday
  5. Friday
  6. Saturday
: 6
                              -- 2022 --

        JANUARY                FEBRUARY                 MARCH       
  S  M  T  W  T  F  S     S  M  T  W  T  F  S     S  M  T  W  T  F  S
                    1           1  2  3  4  5           1  2  3  4  5
  2  3  4  5  6  7  8     6  7  8  9 10 11 12     6  7  8  9 10 11 12
  9 10 11 12 13 14 15    13 14 15 16 17 18 19    13 14 15 16 17 18 19
 16 17 18 19 20 21 22    20 21 22 23 24 25 26    20 21 22 23 24 25 26
 23 24 25 26 27 28 29    27 28                   27 28 29 30 31      
 30 31                                                               

         APRIL                   MAY                     JUNE       
  S  M  T  W  T  F  S     S  M  T  W  T  F  S     S  M  T  W  T  F  S
                 1  2     1  2  3  4  5  6  7              1  2  3  4
  3  4  5  6  7  8  9     8  9 10 11 12 13 14     5  6  7  8  9 10 11
 10 11 12 13 14 15 16    15 16 17 18 19 20 21    12 13 14 15 16 17 18
 17 18 19 20 21 22 23    22 23 24 25 26 27 28    19 20 21 22 23 24 25
 24 25 26 27 28 29 30    29 30 31                26 27 28 29 30      
                                                                     

         JULY                   AUGUST                 SEPTEMBER     
  S  M  T  W  T  F  S     S  M  T  W  T  F  S     S  M  T  W  T  F  S
                 1  2        1  2  3  4  5  6                 1  2  3
  3  4  5  6  7  8  9     7  8  9 10 11 12 13     4  5  6  7  8  9 10
 10 11 12 13 14 15 16    14 15 16 17 18 19 20    11 12 13 14 15 16 17
 17 18 19 20 21 22 23    21 22 23 24 25 26 27    18 19 20 21 22 23 24
 24 25 26 27 28 29 30    28 29 30 31             25 26 27 28 29 30   
 31                                                                  

        OCTOBER                NOVEMBER                DECEMBER      
  S  M  T  W  T  F  S     S  M  T  W  T  F  S     S  M  T  W  T  F  S
                    1           1  2  3  4  5                 1  2  3
  2  3  4  5  6  7  8     6  7  8  9 10 11 12     4  5  6  7  8  9 10
  9 10 11 12 13 14 15    13 14 15 16 17 18 19    11 12 13 14 15 16 17
 16 17 18 19 20 21 22    20 21 22 23 24 25 26    18 19 20 21 22 23 24
 23 24 25 26 27 28 29    27 28 29 30             25 26 27 28 29 30 31
 30 31                                                               
                                                                     


Test 2:
Enter year: 2023
Select begining day: 
  0. Sunday
  1. Monday
  2. Tuesday
  3. Wednesday
  4. Thursday
  5. Friday
  6. Saturday
: 0
                              -- 2023 --

        JANUARY                FEBRUARY                 MARCH       
  S  M  T  W  T  F  S     S  M  T  W  T  F  S     S  M  T  W  T  F  S
  1  2  3  4  5  6  7              1  2  3  4              1  2  3  4
  8  9 10 11 12 13 14     5  6  7  8  9 10 11     5  6  7  8  9 10 11
 15 16 17 18 19 20 21    12 13 14 15 16 17 18    12 13 14 15 16 17 18
 22 23 24 25 26 27 28    19 20 21 22 23 24 25    19 20 21 22 23 24 25
 29 30 31                26 27 28                26 27 28 29 30 31   
                                                                     

         APRIL                   MAY                     JUNE       
  S  M  T  W  T  F  S     S  M  T  W  T  F  S     S  M  T  W  T  F  S
                    1        1  2  3  4  5  6                 1  2  3
  2  3  4  5  6  7  8     7  8  9 10 11 12 13     4  5  6  7  8  9 10
  9 10 11 12 13 14 15    14 15 16 17 18 19 20    11 12 13 14 15 16 17
 16 17 18 19 20 21 22    21 22 23 24 25 26 27    18 19 20 21 22 23 24
 23 24 25 26 27 28 29    28 29 30 31             25 26 27 28 29 30   
 30                                                                  

         JULY                   AUGUST                 SEPTEMBER     
  S  M  T  W  T  F  S     S  M  T  W  T  F  S     S  M  T  W  T  F  S
                    1           1  2  3  4  5                    1  2
  2  3  4  5  6  7  8     6  7  8  9 10 11 12     3  4  5  6  7  8  9
  9 10 11 12 13 14 15    13 14 15 16 17 18 19    10 11 12 13 14 15 16
 16 17 18 19 20 21 22    20 21 22 23 24 25 26    17 18 19 20 21 22 23
 23 24 25 26 27 28 29    27 28 29 30 31          24 25 26 27 28 29 30
 30 31                                                               

        OCTOBER                NOVEMBER                DECEMBER      
  S  M  T  W  T  F  S     S  M  T  W  T  F  S     S  M  T  W  T  F  S
  1  2  3  4  5  6  7              1  2  3  4                    1  2
  8  9 10 11 12 13 14     5  6  7  8  9 10 11     3  4  5  6  7  8  9
 15 16 17 18 19 20 21    12 13 14 15 16 17 18    10 11 12 13 14 15 16
 22 23 24 25 26 27 28    19 20 21 22 23 24 25    17 18 19 20 21 22 23
 29 30 31                26 27 28 29 30          24 25 26 27 28 29 30
                                                 31                  
                                                                     



Test 3:
Enter year: 2024
Select begining day: 
  0. Sunday
  1. Monday
  2. Tuesday
  3. Wednesday
  4. Thursday
  5. Friday
  6. Saturday
: 1
                              -- 2024 --

        JANUARY                FEBRUARY                 MARCH       
  S  M  T  W  T  F  S     S  M  T  W  T  F  S     S  M  T  W  T  F  S
     1  2  3  4  5  6                 1  2  3                    1  2
  7  8  9 10 11 12 13     4  5  6  7  8  9 10     3  4  5  6  7  8  9
 14 15 16 17 18 19 20    11 12 13 14 15 16 17    10 11 12 13 14 15 16
 21 22 23 24 25 26 27    18 19 20 21 22 23 24    17 18 19 20 21 22 23
 28 29 30 31             25 26 27 28 29          24 25 26 27 28 29 30
                                                 31                  

         APRIL                   MAY                     JUNE       
  S  M  T  W  T  F  S     S  M  T  W  T  F  S     S  M  T  W  T  F  S
     1  2  3  4  5  6              1  2  3  4                       1
  7  8  9 10 11 12 13     5  6  7  8  9 10 11     2  3  4  5  6  7  8
 14 15 16 17 18 19 20    12 13 14 15 16 17 18     9 10 11 12 13 14 15
 21 22 23 24 25 26 27    19 20 21 22 23 24 25    16 17 18 19 20 21 22
 28 29 30                26 27 28 29 30 31       23 24 25 26 27 28 29
                                                 30                  

         JULY                   AUGUST                 SEPTEMBER     
  S  M  T  W  T  F  S     S  M  T  W  T  F  S     S  M  T  W  T  F  S
     1  2  3  4  5  6                 1  2  3     1  2  3  4  5  6  7
  7  8  9 10 11 12 13     4  5  6  7  8  9 10     8  9 10 11 12 13 14
 14 15 16 17 18 19 20    11 12 13 14 15 16 17    15 16 17 18 19 20 21
 21 22 23 24 25 26 27    18 19 20 21 22 23 24    22 23 24 25 26 27 28
 28 29 30 31             25 26 27 28 29 30 31    29 30               
                                                                     

        OCTOBER                NOVEMBER                DECEMBER      
  S  M  T  W  T  F  S     S  M  T  W  T  F  S     S  M  T  W  T  F  S
        1  2  3  4  5                    1  2     1  2  3  4  5  6  7
  6  7  8  9 10 11 12     3  4  5  6  7  8  9     8  9 10 11 12 13 14
 13 14 15 16 17 18 19    10 11 12 13 14 15 16    15 16 17 18 19 20 21
 20 21 22 23 24 25 26    17 18 19 20 21 22 23    22 23 24 25 26 27 28
 27 28 29 30 31          24 25 26 27 28 29 30    29 30 31            
                                                                     
                                                   
*/