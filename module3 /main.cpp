
#include <stdio.h>

struct Employee {
    int id;
    char name[50], department[50];
    float salary;
};

struct Employee e[50];
int n = 0;

// 1. Enter Employee Records
void addEmployee() {
    printf("\nHow many employees do you want to add? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter Employee ID: ");
        scanf("%d", &e[i].id);

        printf("Enter Name: ");
        scanf("%s", e[i].name);

        printf("Enter Department: ");
        scanf("%s", e[i].department);

        printf("Enter Salary: ");
        scanf("%f", &e[i].salary);
    }

    printf("\nEmployee Records Added Successfully!\n");
}

// 2. Search by ID
void searchByID() {
    int id, found = 0;

    printf("\nEnter Employee ID: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (e[i].id == id) {
            printf("\nEmployee Found!");
            printf("\nID: %d", e[i].id);
            printf("\nName: %s", e[i].name);
            printf("\nDepartment: %s", e[i].department);
            printf("\nSalary: %.2f", e[i].salary);
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("\nEmployee Not Found!");
}

// 3. Search by Name
void searchByName() {
    char name[50];
    int found = 0;

    printf("\nEnter Employee Name: ");
    scanf("%s", name);

    for (int i = 0; i < n; i++) {
        int j = 0;

        while (name[j] == e[i].name[j] && name[j] != '\0')
            j++;

        if (name[j] == '\0' && e[i].name[j] == '\0') {
            printf("\nEmployee Found!");
            printf("\nID: %d", e[i].id);
            printf("\nName: %s", e[i].name);
            printf("\nDepartment: %s", e[i].department);
            printf("\nSalary: %.2f", e[i].salary);
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("\nEmployee Not Found!");
}

// Main Function
int main() {
    int choice;

    do {
        printf("\n\n===== LINEAR SEARCH MODULE =====\n");
        printf("1. Enter Employee Records\n");
        printf("2. Search Employee by ID\n");
        printf("3. Search Employee by Name\n");
        printf("4. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: searchByID(); break;
            case 3: searchByName(); break;
            case 4: printf("\nThank You!\n"); break;
            default: printf("\nInvalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}
