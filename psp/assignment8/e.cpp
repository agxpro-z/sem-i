/*
    Q5. Write a program to maintain the records of person with details (name and age) and
        find the eldest among them. The program must use this pointer to return the result.
*/

#include <iostream>
#include <string>

using namespace std;

struct Person {
    string name = "";
    int age = 0;
};

class Records {
    Person* person;
    int m_length;

  public:
    Records() : person(NULL), m_length(0) {}
    ~Records() { if (person != NULL) delete[] person; }

    void addPerson(string n, int a);
    const Person* findEldest();
};

void Records::addPerson(string n,  int a) {
    // Create and allocate memory for new Person
    Person* new_person;
    new_person = new Person[m_length + 1];

    // Copy all data from old person array
    for (int i = 0; i < m_length; ++i) {
        new_person[i].name = person[i].name;
        new_person[i].age = person[i].age;
    }

    // Delete old Person array
    if (person != NULL) delete[] person;
    // Copy address of newly created Person array
    person = new_person;
    // Set new_person to NULL
    new_person = NULL;

    // Add new Person
    person[m_length].name = n;
    person[m_length].age = a;
    // Increment lenght by 1
    ++m_length;
}

// find eldest person and return its address as const
const Person* Records::findEldest() {
    int age_index = 0;
    for (int i = 1; i < m_length; ++i) {
        if (person[age_index].age < person[i].age)
            age_index = i;
    }
    return &person[age_index];
}

void menu() {
    cout << "\n\n\tPerson Record\n\n"
            "1. Add person to the record\n"
            "2. Find eldest person\n"
            "0. Exit\n"
            " :> ";
}

int main() {
    Records records;

    int input = 0, age;
    string name;

    do {
        menu();
        cin >> input;
        switch (input) {
            case 1:
                cout << "Enter name: ";
                getline(cin >> ws, name);
                cout << "Enter age: ";
                cin >> age;
                records.addPerson(name, age);
                cout << "Person added\n";
                break;
            case 2:
                const Person* person;
                person = records.findEldest();
                cout << person->name << ' ' << person->age << '\n';
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

Test 1:


        Person Record

1. Add person to the record
2. Find eldest person
0. Exit
 :> 1
Enter name: Ankit
Enter age: 21
Person added


        Person Record

1. Add person to the record
2. Find eldest person
0. Exit
 :> 1
Enter name: Gourav
Enter age: 20
Person added


        Person Record

1. Add person to the record
2. Find eldest person
0. Exit
 :> 1
Enter name: AnkitGourav
Enter age: 120
Person added


        Person Record

1. Add person to the record
2. Find eldest person
0. Exit
 :> 2
AnkitGourav 120


        Person Record

1. Add person to the record
2. Find eldest person
0. Exit
 :> 0
*/