
#include <iostream>
using namespace std;

struct Employee {
    int id;
    string name, department;
    float salary;
};

Employee e[50];
int n = 0;

// 1. Enter Employee Records
void addEmployee() {
    cout << "\nHow many employees do you want to add? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter Employee ID: ";
        cin >> e[i].id;

        cout << "Enter Name: ";
        cin >> e[i].name;

        cout << "Enter Department: ";
        cin >> e[i].department;

        cout << "Enter Salary: ";
        cin >> e[i].salary;
    }

    cout << "\nEmployee Records Added Successfully!\n";
}

// 2. Search by ID
void searchByID() {
    int id, found = 0;

    cout << "\nEnter Employee ID: ";
    cin >> id;

    for (int i = 0; i < n; i++) {
        if (e[i].id == id) {
            cout << "\nEmployee Found!";
            cout << "\nID: " << e[i].id;
            cout << "\nName: " << e[i].name;
            cout << "\nDepartment: " << e[i].department;
            cout << "\nSalary: " << e[i].salary;
            found = 1;
            break;
        }
    }

    if (found == 0)
        cout << "\nEmployee Not Found!";
}

// 3. Search by Name
void searchByName() {
    string name;
    int found = 0;

    cout << "\nEnter Employee Name: ";
    cin >> name;

    for (int i = 0; i < n; i++) {
        if (e[i].name == name) {
            cout << "\nEmployee Found!";
            cout << "\nID: " << e[i].id;
            cout << "\nName: " << e[i].name;
            cout << "\nDepartment: " << e[i].department;
            cout << "\nSalary: " << e[i].salary;
            found = 1;
            break;
        }
    }

    if (found == 0)
        cout << "\nEmployee Not Found!";
}

// Main Function
int main() {
    int choice;

    do {
        cout << "\n\n===== LINEAR SEARCH MODULE =====\n";
        cout << "1. Enter Employee Records\n";
        cout << "2. Search Employee by ID\n";
        cout << "3. Search Employee by Name\n";
        cout << "4. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: searchByID(); break;
            case 3: searchByName(); break;
            case 4: cout << "\nThank You!\n"; break;
            default: cout << "\nInvalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}

