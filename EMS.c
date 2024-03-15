#include <stdio.h>

#define MAX_EMPLOYEES 100
FILE *file;
struct Emp {
    int id;
    char name[50];
    char designation[50];
    char qualification[50];
    char joiningDate[15];
    int age;
};

struct Emp employees[MAX_EMPLOYEES];
int count = 0;

void addEmp() {
    if (count < MAX_EMPLOYEES) {
            file=fopen("EMP.txt","a");
        printf("Enter employee ID: ");
        scanf("%d", &employees[count].id);

        printf("Enter employee name: ");
        scanf("%s", employees[count].name);

        printf("Enter employee designation: ");
        scanf("%s", employees[count].designation);

        printf("Enter employee qualification: ");
        scanf("%s", employees[count].qualification);

        printf("Enter employee joining date (DD/MM/YYYY): ");
        scanf("%s", employees[count].joiningDate);

        printf("Enter employee age: ");
        scanf("%d", &employees[count].age);


        printf("Employee added successfully!\n");
        fprintf(file, "%d%s%s%s%s%d\n", employees[count].id, employees[count].name, employees[count].designation, employees[count].qualification, employees[count].joiningDate, employees[count].age);
count++;
fclose(file);
    }
    else
    {
        printf("Maximum limit reached!\n");
    }
}

void updateEmp() {
    int empId, i;

    printf("Enter employee ID to update: ");
    scanf("%d", &empId);

    for (i = 0; i < count; i++) {
        if (employees[i].id == empId) {
            printf("Enter updated employee name: ");
            scanf("%s", employees[i].name);

            printf("Enter updated employee designation: ");
            scanf("%s", employees[i].designation);

            printf("Enter updated employee qualification: ");
            scanf("%s", employees[i].qualification);

            printf("Enter updated employee joining date (DD/MM/YYYY): ");
            scanf("%s", employees[i].joiningDate);

            printf("Enter updated employee age: ");
            scanf("%d", &employees[i].age);

            printf("Employee details updated successfully!\n");
            return;
        }
    }

    printf("Employee not found!\n");
}

void deleteEmp() {
    int empId, i, j;

    printf("Enter employee ID to delete: ");
    scanf("%d", &empId);

    for (i = 0; i < count; i++) {
        if (employees[i].id == empId) {
            for (j = i; j < count - 1; j++) {
                employees[j] = employees[j + 1];
            }

            count--;
            printf("Employee deleted successfully!\n");
            return;
        }
    }

    printf("Employee not found!\n");
}

void showAllEmp() {
    int i;

    if (count == 0) {
        printf("No employees found!\n");
        return;
    }

    printf("Employee details:\n");
    for (i = 0; i < count; i++) {
        printf("ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Qualification: %s\n", employees[i].qualification);
        printf("Joining Date: %s\n", employees[i].joiningDate);
        printf("Age: %d\n", employees[i].age);
        printf("--------------------------\n");
    }
}


int main() {
    int choice;

    do {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Update Employee\n");
        printf("3. Delete Employee\n");
        printf("4. Show All Employees\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmp();
                break;
            case 2:
                updateEmp();
                break;
            case 3:
                deleteEmp();
                break;
            case 4:
                showAllEmp();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

