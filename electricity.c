
#include <stdio.h>

#define FILE_NAME "bills.txt"

struct Customer {
    int id;
    char name[50];
    float units;
    float amount;
};

float calculateBill(float units) {
    float bill = 0;

    if (units <= 100) {
        bill = units * 3;
    }
    else if (units <= 200) {
        bill = (100 * 3) + ((units - 100) * 5);
    }
    else {
        bill = (100 * 3) + (100 * 5)
               + ((units - 200) * 7);
    }

    return bill + 50;
}

void addCustomer() {
    struct Customer c, temp;
    FILE *fp;
    int found = 0;

    printf("\nEnter Customer ID: ");
    scanf("%d", &c.id);

    fp = fopen(FILE_NAME, "r");

    if (fp != NULL) {
        while (fscanf(fp, "%d|%49[^|]|%f|%f\n",
                      &temp.id, temp.name,
                      &temp.units, &temp.amount) == 4) {
            if (temp.id == c.id) {
                found = 1;
                break;
            }
        }
        fclose(fp);
    }

    if (found) {
        printf("Customer ID already exists.\n");
        return;
    }

    printf("Enter Customer Name: ");
    scanf(" %49[^\n]", c.name);

    printf("Enter Units Consumed: ");
    scanf("%f", &c.units);

    if (c.units < 0) {
        printf("Invalid units.\n");
        return;
    }

    c.amount = calculateBill(c.units);

    fp = fopen(FILE_NAME, "a");

    if (fp == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    fprintf(fp, "%d|%s|%.2f|%.2f\n",
            c.id, c.name, c.units, c.amount);

    fclose(fp);

    printf("\nBill Generated Successfully!\n");
    printf("Customer: %s\n", c.name);
    printf("Units: %.2f\n", c.units);
    printf("Total Bill: Rs. %.2f\n", c.amount);
}

void displayBills() {
    struct Customer c;
    FILE *fp = fopen(FILE_NAME, "r");
    int found = 0;

    if (fp == NULL) {
        printf("\nNo billing records found.\n");
        return;
    }

    printf("\n========== CUSTOMER BILLS ==========\n");

    while (fscanf(fp, "%d|%49[^|]|%f|%f\n",
                  &c.id, c.name,
                  &c.units, &c.amount) == 4) {

        printf("\nCustomer ID: %d\n", c.id);
        printf("Name: %s\n", c.name);
        printf("Units: %.2f\n", c.units);
        printf("Bill Amount: Rs. %.2f\n", c.amount);

        found = 1;
    }

    if (!found) {
        printf("No records available.\n");
    }

    fclose(fp);
}

void searchCustomer() {
    struct Customer c;
    int searchID;
    int found = 0;

    FILE *fp = fopen(FILE_NAME, "r");

    if (fp == NULL) {
        printf("No billing records found.\n");
        return;
    }

    printf("\nEnter Customer ID: ");
    scanf("%d", &searchID);

    while (fscanf(fp, "%d|%49[^|]|%f|%f\n",
                  &c.id, c.name,
                  &c.units, &c.amount) == 4) {

        if (c.id == searchID) {
            printf("\nCustomer Found!\n");
            printf("ID: %d\n", c.id);
            printf("Name: %s\n", c.name);
            printf("Units: %.2f\n", c.units);
            printf("Bill: Rs. %.2f\n", c.amount);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Customer not found.\n");
    }

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n===== ELECTRICITY BILLING SYSTEM =====\n");
        printf("1. Generate New Bill\n");
        printf("2. Display All Bills\n");
        printf("3. Search Customer Bill\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        switch (choice) {
            case 1:
                addCustomer();
                break;

            case 2:
                displayBills();
                break;

            case 3:
                searchCustomer();
                break;

            case 4:
                printf("Billing system closed.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
