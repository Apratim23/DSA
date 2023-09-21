#include <stdio.h>

struct Employee {
    int empId;
    char name[50];
    char designation[50];
    float basicSalary;
    float hra;
    float da;
    float grossSalary;
};

void calculateGrossSalary(struct Employee *emp) {
    float hraAmount = (emp->hra / 100) * emp->basicSalary;
    float daAmount = (emp->da / 100) * emp->basicSalary;
    emp->grossSalary = emp->basicSalary + hraAmount + daAmount;
}

int main() {
    int n;
    printf("Enter no.of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];

    for (int i = 0; i < n; ++i) {
        printf("Enter employee %d information:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);

        printf("Designation: ");
        scanf("%s", employees[i].designation);

        printf("Basic Salary: ");
        scanf("%f", &employees[i].basicSalary);

        printf("HRA %%: ");
        scanf("%f", &employees[i].hra);

        printf("DA %%: ");
        scanf("%f", &employees[i].da);

        calculateGrossSalary(&employees[i]);
    }

    printf("\nEmployee Information:\n\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Basic Salary: %.2f\n", employees[i].basicSalary);
        printf("HRA %%: %.2f%%\n", employees[i].hra);
        printf("DA %%: %.2f%%\n", employees[i].da);
        printf("Gross Salary: %.2f\n\n", employees[i].grossSalary);
    }

    return 0;
}
