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


