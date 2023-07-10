/*
    Q5. Design a class named Person with the following member variables:
          • FirstName
          • LastName
          • Address
          • City
          • State
          • Zip
          • PhoneNo
          • Struct DOB (day, month, year)
        Having a private constructor.
        Write the appropriate accessor (getter) and mutator (setter) functions for these
        member variables.
        In the main() function, create an array of objects of user defined size by calling
        a static function for making objects.
        Input data of all the persons and then display it by using a display function.
*/

#include <iostream>
#include <string>

using namespace std;

class Person {
    string firstName, lastName, address, city, state;
    long long int zip, phoneNo;

    // DOB struct
    struct DOB {
        int day, month, year;
    } dob;

    Person() {}

  public:
    string getFirstName() {
        return firstName;
    }

    void setFirstName(string name) {
        firstName = name;
    }

    string getLastName() {
        return lastName;
    }

    void setLastName(string name) {
        lastName = name;
    }

    string getAddress() {
        return address;
    }

    void setAddress(string name) {
        address = name;
    }

    string getCity() {
        return city;
    }

    void setCity(string name) {
        city = name;
    }

    string getState() {
        return state;
    }

    void setState(string name) {
        state = name;
    }

    long long int getPhoneNo() {
        return phoneNo;
    }

    void setPhoneNo(long long int n) {
        phoneNo = n;
    }

    long long int getZip() {
        return zip;
    }

    void setZip(long long int n) {
        zip = n;
    }

    void setDay(int a) {
        dob.day = a;
    }

    void setMonth(int a) {
        dob.month = a;
    }

    void setYear(int a) {
        dob.year = a;
    }

    string getDOB() {
        return (to_string(dob.day) + "-" + to_string(dob.month) + "-" + to_string(dob.year));
    }

    void setDOB() {
        int d, m, y;
        cout << "DOB: \n";
        cout << "Enter day: ";
        cin >> d;
        cout << "Enter month: ";
        cin >> m;
        cout << "Enter year: ";
        cin >> y;
        setDay(d);
        setMonth(m);
        setYear(y);
    }

    void display() {
        cout << "Name: " << firstName << " " << lastName << '\n';
        cout << "DOB: " << getDOB() << '\n';
        cout << "Address: " << address << '\n';
        cout << "City: " << city << '\n';
        cout << "State: " << state << '\n';
        cout << "Zip Code: " << zip << '\n';
        cout << "Phone no.: " << phoneNo << '\n' << '\n';
    }

    static Person* person(int n) {
        return new Person[n];
    }
};

int main() {
    cout << "Enter no. of entries: ";
    int n;
    cin >> n;

    Person* p = Person::person(n);

    for (int i = 0; i < n; i++) {
        cout << "Person" << i + 1 << ": \n";
        string s;
        cout << "Enter first name: ";
        getline(cin >> ws, s);
        p[i].setFirstName(s);
        cout << "Enter last name: ";
        getline(cin >> ws, s);
        p[i].setLastName(s);
        cout << "Enter";
        p[i].setDOB();
        cout << "Enter address: ";
        getline(cin >> ws, s);
        p[i].setAddress(s);
        cout << "Enter city: ";
        getline(cin >> ws, s);
        p[i].setCity(s);
        cout << "Enter state: ";
        getline(cin >> ws, s);
        p[i].setState(s);
        cout << "Enter zip code: ";
        long long int in;
        cin >> in;
        p[i].setZip(in);
        cout << "Enter phone no.: ";
        cin >> in;
        p[i].setPhoneNo(in);
    }

    for (int i = 0; i < n; i++) {
        cout << "\nPerson" << i + 1 << '\n';
        p[i].display();
        cout << '\n';
    }

    return 0;
}

/*
        -- OUTPUT --

Enter no. of entries: 2
Person1: 
Enter first name: Aa
Enter last name: Bb
EnterDOB: 
Enter day: 1
Enter month: 1
Enter year: 2004
Enter address: Unknown
Enter city: Cityy
Enter state: Stat
Enter zip code: 456
Enter phone no.: 124552354

Person2: 
Enter first name: Cc
Enter last name: Dd
EnterDOB: 
Enter day: 2
Enter month: 3
Enter year: 2006
Enter address: Unknown
Enter city: Cit
Enter state: Stat
Enter zip code: 879
Enter phone no.: 3543446532

Person1
Name: Aa Bb
DOB: 1-1-2004
Address: Unknown
City: Cityy
State: Stat
Zip Code: 456
Phone no.: 124552354

Person2
Name: Cc Dd
DOB: 2-3-2006
Address: Unknown
City: Cit
State: Stat
Zip Code: 879
Phone no.: 3543446532

*/