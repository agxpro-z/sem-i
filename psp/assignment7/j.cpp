/*
    Q10. An EMPLOYEE class is to contain the following data members and member
         functions:
         Data members: EmployeeNumber (an integer),
                       EmployeeName (a string of characters),
                       BasicSalary (an integer),
                       All Allowances (an integer),
                       IT (an integer),
                       NetSalary (aninteger).

         Member functions: to read the data of an employee,
                           to calculate Net Salary and
                           to print the values of all the data members.

        (AllAllowances = 12.3% of Basic;
         Income Tax (IT) = 30% of the gross salary
         Gross Salary = basic Salary + AllAllowance
         Net Salary = Basic Salary + All Allowances - IT)

        (Write program using constructors, destructors, static data members and static Member functions)
*/

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Employee {
    static int employeeNumber;
    static double incomeTax; // 30%
    static double allAllowances; // 12.3%

    int employeeId;
    string employeeName;
    double basicSalary;
    double netSalary;

  public:
    // Default Constructor
    Employee() : employeeName(""), basicSalary(0.0), netSalary(0.0) {
        employeeId = employeeNumber;
        employeeNumber++;
    }

    Employee(string name) : employeeName(name) {
        employeeId = employeeNumber;
        basicSalary = 0.0;
        netSalary = 0.0;

        employeeNumber++;
    }

    Employee(string name, double basicSal) : employeeName(name), basicSalary(basicSal) {
        employeeId = employeeNumber;
        netSalary = 0.0;

        employeeNumber++;
    }

    void getEmployee();
    void printEmployeeData();

    static int totalEmployee();
};
// Initialize static variables
int Employee::employeeNumber = 1;
double Employee::incomeTax = 30.0;
double Employee::allAllowances = 12.3;

// Return total no. of Employee
inline int Employee::totalEmployee() {
    return employeeNumber - 1;
}

// Read employee date
void Employee::getEmployee() {
    if (employeeName != "") {
        cout << "Employee already exist.\n";
        return;
    }

    cout << "Enter employee name: ";
    getline(cin >> ws, employeeName);
    cout << "Enter basic salary: ";
    cin >> basicSalary;
}

// Display employee data
void Employee::printEmployeeData() {
    cout << fixed << setprecision(2) << endl;
    cout << "Employee ID: " << employeeId << endl;
    cout << "Employee name: " << employeeName << endl;
    cout << "Basic salary: " << basicSalary << endl;
    cout << "All allowances: " << basicSalary * allAllowances / 100 << endl;
    cout << "Income Tax: " << incomeTax << " %" << endl;
    cout << "Net Salary: " << basicSalary + (basicSalary * allAllowances / 100) - (basicSalary * incomeTax / 100) << endl;
    cout << "Gross Salary: " << basicSalary + (basicSalary * allAllowances / 100) << endl;
}

int main() {
    Employee e1("Employee 1");
    Employee e2("Employee 2", 69000);
    Employee e3;

    // take data from user
    e3.getEmployee();

    // display all employee
    e1.printEmployeeData();
    e2.printEmployeeData();
    e3.printEmployeeData();

    cout << "\nTotal no. of employee " << Employee::totalEmployee() << endl;

    return 0;
}

/*
        -- OUTPUT --

Enter employee name: Emp
Enter basic salary: 89000

Employee ID: 1
Employee name: Employee 1
Basic salary: 0.00
All allowances: 0.00
Income Tax: 30.00 %
Net Salary: 0.00
Gross Salary: 0.00

Employee ID: 2
Employee name: Employee 2
Basic salary: 69000.00
All allowances: 8487.00
Income Tax: 30.00 %
Net Salary: 56787.00
Gross Salary: 77487.00

Employee ID: 3
Employee name: Emp
Basic salary: 89000.00
All allowances: 10947.00
Income Tax: 30.00 %
Net Salary: 73247.00
Gross Salary: 99947.00

Total no. of employee 3

*/