/*
    Q6. Design a class Car having attributes.

        PersonData Driver (an object of class done in Q#7)
        String carName
        Int carID
        String type (SUV, Wagon, Electrical etc)
        Static int count
        Const int wheels (assuming every car will have four wheels)
        Having default, overloaded, copy constructors with initializer lists and a destructor,
        Having functions addCar(), deleteCar(), updateCar(), printCar().
        In the main(), you’ll only have a pointer of size 1 at start.
        Here, you’ll have a constant object initialized explicitly like this const Car
        constantObj (Person, cName, cID, cType);

    Now, print this object at the start of the program and then print the menu.You will have a
        menu driven program to perform following functionalities.
        1. Add Car
        2. DeleteCar
        3. Update Car Attributes
        4. Print Details
        5. Print List of cars
        One thing, while printing the Driver details display only his name

            5th question is optional.
*/

#include <iostream>
#include <string>

using namespace std;

class PersonData {
  public:
    string name;
    int age;

    PersonData() : name(""), age(0) {}
    PersonData(string n) : name(n), age(0) {}
    PersonData(string n, int a) : name(n), age(a) {}
};

class CarData {
  public:
    static int cid;
    PersonData Driver;
    int carID;
    string name, type;
    int wheels;

    CarData() : Driver("", 0), carID(cid++), name(""), type(""), wheels(4) {}
    CarData(string n, string cn, string t) : Driver(n, 0), carID(cid++), name(cn), type(t), wheels(4) {}

    void update(string n, string cn, string t) {
        Driver.name = n;
        name = cn;
        type = t;
    }

    void print() {
        cout << "Driver Name: " << Driver.name << '\n';
        cout << "Car ID: " << carID << '\n';
        cout << "Car Name: " << name << '\n';
        cout << "Car Type: " << type << '\n';
        cout << "Wheels: " << wheels << "\n\n";
    }
};
int CarData::cid = 1;

class CarD {
    CarData* cd;
    int data;

  public:
    CarD() : cd(NULL), data(0) {}
    CarD(string n, string cn, string t) : cd(new CarData(n, cn, t)), data(1) {}
    ~CarD() { delete[] cd; }

    void addCar(string n, string cn, string t) {
        if (cd != NULL) {
            data++;
            CarData* new_cd = new CarData[data];
            for (int i = 0; i < data - 1; i++) {
                new_cd[i] = cd[i];
            }
            delete[] cd;
            cd = new_cd;
            new_cd = NULL;
            cd[data - 1].update(n, cn, t);
        } else {
            data++;
            cd = new CarData[data];
            cd[data - 1].update(n, cn, t);
        }
    }

    void deleteCar(int carID) {
        for (int i = 0; i < data; i++) {
            if (cd[i].carID == carID) {
                cd[i].carID = 0;
                cout << "Car deleted.\n";
                return;
            }
        }
        cout << "Car not found.";
    }

    void updateCar(int carID) {
        for (int i = 0; i < data; i++) {
            if (cd[i].carID == carID) {
                cout << "Enter Driver name: ";
                string d;
                getline(cin >> ws, d);
                cout << "Enter Car name: ";
                string c;
                getline(cin >> ws, c);
                string t;
                cout << "Enter car type: ";
                getline(cin >> ws, t);
                cd[i].update(d, c, t);
                cout << "Successfully updated\n.";
                return;
            }
        }
        cout << "Car not found.";
    }

    void printDetails(int carID) {
        for (int i = 0; i < data; i++) {
            if (cd[i].carID == carID) {
                cd[i].print();
                cout << '\n';
                return;
            }
        }
        cout << "Car not found.\n";
    }

    void printList() {
        for (int i = 0; i < data; i++) {
            if (cd[i].carID == 0) {
                continue;
            } else {
                cd[i].print();
                cout << '\n';
            }
        }
    }
};

void menu() {
    cout << "\tCar DB\n\n"
            "  1. Add car\n"
            "  2. Delete car\n"
            "  3. Update car details\n"
            "  4. Print car details\n"
            "  5. Print car list\n"
            "  0. Exit\n"
            ":> ";
}

int main() {
    CarD c;

    int input = 0;

    string dname, cname, tname;
    int cid;
    do {
        menu();
        cin >> input;

        switch (input) {
            case 1:
                cout << "Enter driver name: ";
                cin >> dname;
                cout << "Enter car name: ";
                cin >> cname;
                cout << "Enter car type: ";
                cin >> tname;
                c.addCar(dname, cname, tname);
                break;
            case 2:
                cout << "Enter car id: ";
                cin >> cid;
                c.deleteCar(cid);
                break;
            case 3:
                cout << "Enter car id: ";
                cin >> cid;
                c.updateCar(cid);
                break;
            case 4:
                cout << "Enter car id: ";
                cin >> cid;
                c.printDetails(cid);
                break;
            case 5:
                c.printList();
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

        Car DB

  1. Add car
  2. Delete car
  3. Update car details
  4. Print car details
  5. Print car list
  0. Exit
:> 1
Enter driver name: D
Enter car name: C
Enter car type: Cx

        Car DB

  1. Add car
  2. Delete car
  3. Update car details
  4. Print car details
  5. Print car list
  0. Exit
:> 1
Enter driver name: D1
Enter car name: C1
Enter car type: Cc

        Car DB

  1. Add car
  2. Delete car
  3. Update car details
  4. Print car details
  5. Print car list
  0. Exit
:> 5

Driver Name: D
Car ID: 1
Car Name: C
Car Type: Cx
Wheels: 4

Driver Name: D1
Car ID: 3
Car Name: C1
Car Type: Cc
Wheels: 4

        Car DB

  1. Add car
  2. Delete car
  3. Update car details
  4. Print car details
  5. Print car list
  0. Exit
:> 0

*/