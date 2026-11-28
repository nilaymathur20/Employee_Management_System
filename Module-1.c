#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    char department[50];
    char date[30];
    float salary;
};

struct Employee e[50];
int n = 0;

// 1. Add Employee
void addEmployee() {
    if (n >= 50) {
        printf("Storage Full!\n");
        return;
    }

    int tempId;
    printf("Enter ID: ");
    scanf("%d", &tempId);

    for (int i = 0; i < n; i++) {
        if (e[i].id == tempId) {
            printf("ID already exists!\n");
            return;
        }
    }

    e[n].id = tempId;

    printf("Enter Name: ");
    scanf(" %[^\n]", e[n].name);

    printf("Enter Department: ");
    scanf(" %[^\n]", e[n].department);

    printf("Enter Salary: ");
    scanf("%f", &e[n].salary);

    printf("Enter Joining Date: ");
    scanf(" %[^\n]", e[n].date);

    n++;
    printf("Employee Added!\n");
}

// 2. Display Employees
void display() {
    if (n == 0) {
        printf("No Records Found!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\nID: %d", e[i].id);
        printf("\nName: %s", e[i].name);
        printf("\nDepartment: %s", e[i].department);
        printf("\nSalary: %.2f", e[i].salary);
        printf("\nJoining Date: %s\n", e[i].date);
    }
}

// 3. Update Employee
void update() {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (e[i].id == id) {
            printf("Enter New Name: ");
            scanf(" %[^\n]", e[i].name);

            printf("Enter New Department: ");
            scanf(" %[^\n]", e[i].department);

            printf("Enter New Salary: ");
            scanf("%f", &e[i].salary);

            printf("Enter New Date: ");
            scanf(" %[^\n]", e[i].date);

            printf("Updated Successfully!\n");
            return;
        }
    }
    printf("Employee Not Found!\n");
}

// 4. Delete Employee
void deleteEmployee() {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (e[i].id == id) {
            for (int j = i; j < n - 1; j++) {
                e[j] = e[j + 1];
            }
            n--;
            printf("Deleted Successfully!\n");
            return;
        }
    }
    printf("Employee Not Found!\n");
}

// 5. Linear Search
void linearSearch() {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (e[i].id == id) {
            printf("Employee Found: %s\n", e[i].name);
            return;
        }
    }
    printf("Not Found!\n");
}

// 6. Binary Search
void binarySearch() {
    struct Employee temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (e[j].id > e[j + 1].id) {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }

    int id, low = 0, high = n - 1;
    printf("Enter ID: ");
    scanf("%d", &id);

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (e[mid].id == id) {
            printf("Employee Found: %s\n", e[mid].name);
            return;
        } else if (e[mid].id < id) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Not Found!\n");
}

int main() {
    int choice;

    do {
        printf("\n--- EMPLOYEE MANAGEMENT SYSTEM ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Update Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Linear Search\n");
        printf("6. Binary Search\n");
        printf("7. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: display(); break;
            case 3: update(); break;
            case 4: deleteEmployee(); break;
            case 5: linearSearch(); break;
            case 6: binarySearch(); break;
            case 7: printf("Thank You!\n"); break;
            default: printf("Invalid Choice!\n");
        }
    } while (choice != 7);

    return 0;
}
