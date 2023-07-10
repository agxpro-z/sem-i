/*
    Q7. Design a class named PersonData with the following member variables:
            •FirstName
            •LastName
            •Address
            •City
            •State
            •Zip
            •PhoneNo
        Write the appropriate accessor (getter) and mutator (setter) functions for these
        member variables.
        Next, design a class named CustomerData, which is derived from the PersonData
        class. The

        CustomerData class should have the following member variables:
            • CustomerNumber
            • MailingList
        The CustomerNumber variable will be used to hold a unique integer for each customer.
        The MailingList variable should be a bool. It will be set to true if the customer
        wishes to be on a mailing list, or false if the customer does not wish to be on a
        mailing list. Write appropriate Accessor and Mutator functions for these member
        variables. CustomerData class will have the
            • InputCustomerData member function which will Input all the data for customer.
              (use function over riding).
            • DisplayCustomerData member function which will display all the data for
              customer. (use function over riding).
        Demonstrate an object of the CustomerData class in a simple program.
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