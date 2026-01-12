#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct Vehicle {
    int id;
    char type[20];
    char model[30];
    char brand[30];
    int year;
    int engineCC;

    int seatCount;
    int gearCount;
    char routeNumber[20];
};

struct Vehicle vehicles[MAX];
int count = 0;

/* function declarations */
void showMenu();
void addNewVehicle();
void showVehicles();
void searchVehicle();
void updateVehicle();


int main() {
    int choice;

    while (1) {
        showMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNewVehicle();
                break;
            case 2:
                showVehicles();
                break;
            case 3:
                searchVehicle();
                break;
            case 4:
                updateVehicle();
                break;
            case 0:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}


void showMenu() {
    printf("\n===== Vehicle Management System =====\n");
    printf("1. Add New Vehicle\n");
    printf("2. Show All Vehicles\n");
    printf("3. Search Vehicle\n");
    printf("4. Update Vehicle\n");
    printf("0. Exit\n");
}


void addNewVehicle() {
    struct Vehicle v;
    int i, duplicate = 0;

    if (count >= MAX) {
        printf("Vehicle limit reached!\n");
        return;
    }

    printf("Enter Vehicle ID: ");
    scanf("%d", &v.id);

    // unique ID check
    for (i = 0; i < count; i++) {
        if (vehicles[i].id == v.id) {
            duplicate = 1;
            break;
        }
    }

    if (duplicate) {
        printf("Vehicle ID already exists!\n");
        return;
    }

    printf("Enter Vehicle Type (car/bike/bus/truck): ");
    scanf("%s", v.type);

    printf("Enter Model Name: ");
    scanf("%s", v.model);

    printf("Enter Brand: ");
    scanf("%s", v.brand);

    printf("Enter Year of Manufacture: ");
    scanf("%d", &v.year);

    printf("Enter Engine Capacity (cc): ");
    scanf("%d", &v.engineCC);

    /* optional fields */
    if (strcmp(v.type, "car") == 0) {
        printf("Enter Seat Count: ");
        scanf("%d", &v.seatCount);
    } 
    else if (strcmp(v.type, "bike") == 0) {
        printf("Enter Gear Count: ");
        scanf("%d", &v.gearCount);
    } 
    else if (strcmp(v.type, "bus") == 0) {
        printf("Enter Route Number: ");
        scanf("%s", v.routeNumber);
    }

    vehicles[count] = v;
    count++;

    printf("Vehicle added successfully!\n");
}


void showVehicles() {
    int i;

    if (count == 0) {
        printf("No vehicles available.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        printf("\n--- Vehicle %d ---\n", i + 1);
        printf("ID: %d\n", vehicles[i].id);
        printf("Type: %s\n", vehicles[i].type);
        printf("Model: %s\n", vehicles[i].model);
        printf("Brand: %s\n", vehicles[i].brand);
        printf("Year: %d\n", vehicles[i].year);
        printf("Engine: %dcc\n", vehicles[i].engineCC);

        if (strcmp(vehicles[i].type, "car") == 0)
            printf("Seats: %d\n", vehicles[i].seatCount);
        else if (strcmp(vehicles[i].type, "bike") == 0)
            printf("Gears: %d\n", vehicles[i].gearCount);
        else if (strcmp(vehicles[i].type, "bus") == 0)
            printf("Route: %s\n", vehicles[i].routeNumber);
    }
}


void searchVehicle() {
    int option, id, found = 0;
    char key[30];
    int i;

    printf("\nSearch By:\n");
    printf("1. Vehicle ID\n");
    printf("2. Vehicle Type or Model\n");
    printf("Enter option: ");
    scanf("%d", &option);

    if (option == 1) {
        printf("Enter Vehicle ID: ");
        scanf("%d", &id);

        for (i = 0; i < count; i++) {
            if (vehicles[i].id == id) {
                printf("\nVehicle Found:\n");
                printf("ID: %d\n", vehicles[i].id);
                printf("Type: %s\n", vehicles[i].type);
                printf("Model: %s\n", vehicles[i].model);
                printf("Brand: %s\n", vehicles[i].brand);
                printf("Year: %d\n", vehicles[i].year);
                printf("Engine: %dcc\n", vehicles[i].engineCC);
                found = 1;
                break;
            }
        }

        if (!found)
            printf("Vehicle not found.\n");
    }
    else if (option == 2) {
        printf("Enter Type or Model: ");
        scanf("%s", key);

        for (i = 0; i < count; i++) {
            if (strcmp(vehicles[i].type, key) == 0 ||
                strcmp(vehicles[i].model, key) == 0) {

                printf("\nID: %d | %s | %s | %s | %d | %dcc\n",
                       vehicles[i].id,
                       vehicles[i].type,
                       vehicles[i].model,
                       vehicles[i].brand,
                       vehicles[i].year,
                       vehicles[i].engineCC);
                found = 1;
            }
        }

        if (!found)
            printf("No matching vehicle found.\n");
    }
    else {
        printf("Invalid option.\n");
    }
}


void updateVehicle() {
    int id, i, choice, found = 0;

    printf("Enter Vehicle ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (vehicles[i].id == id) {
            found = 1;

            printf("\nCurrent Info:\n");
            printf("1. Brand: %s\n", vehicles[i].brand);
            printf("2. Model: %s\n", vehicles[i].model);
            printf("3. Year: %d\n", vehicles[i].year);
            printf("4. Engine CC: %d\n", vehicles[i].engineCC);
            printf("Choose field to update: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter new Brand: ");
                    scanf("%s", vehicles[i].brand);
                    break;
                case 2:
                    printf("Enter new Model: ");
                    scanf("%s", vehicles[i].model);
                    break;
                case 3:
                    printf("Enter new Year: ");
                    scanf("%d", &vehicles[i].year);
                    break;
                case 4:
                    printf("Enter new Engine CC: ");
                    scanf("%d", &vehicles[i].engineCC);
                    break;
                default:
                    printf("Invalid choice.\n");
                    return;
            }

            printf("Vehicle updated successfully!\n");
            return;
        }
    }

    if (!found)
        printf("Vehicle ID not found.\n");
}
