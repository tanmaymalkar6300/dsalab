#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Employee {
    int employeeID;
    char name[50];
    char designation[50];
    float salary;
};

// Function to add employee information
void addEmployee() {
    fstream file("employee_data.dat", ios::binary | ios::in | ios::out | ios::app);

    Employee emp;

    cout << "Enter Employee ID: ";
    cin >> emp.employeeID;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(emp.name, 50);
    cout << "Enter Designation: ";
    cin.getline(emp.designation, 50);
    cout << "Enter Salary: ";
    cin >> emp.salary;

    // Move to the end of the file
    file.seekg(0, ios::end);

    // Write the employee record
    file.write(reinterpret_cast<char*>(&emp), sizeof(Employee));

    file.close();
}

// Function to delete employee information
void deleteEmployee() {
    int empID;
    cout << "Enter Employee ID to delete: ";
    cin >> empID;

    fstream file("employee_data.dat", ios::binary | ios::in | ios::out);

    Employee emp;

    bool found = false;

    // Search for the employee record
    while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        if (emp.employeeID == empID) {
            // Overwrite the employee record with empty data
            Employee emptyEmp;
            file.seekp(file.tellg() - sizeof(Employee));
            file.write(reinterpret_cast<char*>(&emptyEmp), sizeof(Employee));
            found = true;
            break;
        }
    }

    file.close();

    if (found) {
        cout << "Employee deleted successfully." << endl;
    } else {
        cout << "Employee not found." << endl;
    }
}

// Function to display employee information
void displayEmployee() {
    int empID;
    cout << "Enter Employee ID to display: ";
    cin >> empID;

    ifstream file("employee_data.dat", ios::binary);

    Employee emp;

    bool found = false;

    // Search for the employee record
    while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        if (emp.employeeID == empID) {
            cout << "Employee ID: " << emp.employeeID << endl;
            cout << "Name: " << emp.name << endl;
            cout << "Designation: " << emp.designation << endl;
            cout << "Salary: " << emp.salary << endl;
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Employee not found." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Display Employee" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                displayEmployee();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
