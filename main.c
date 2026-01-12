#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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
void deleteVehicle();
void filterVehicles();

/* helper */
void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

int main() {
    int choice;

    while (1) {
        showMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addNewVehicle(); break;
            case 2: showVehicles(); break;
            case 3: searchVehicle(); break;
            case 4: updateVehicle(); break;
            case 5: deleteVehicle(); break;
            case 6: filterVehicles(); break;
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
    printf("5. Delete Vehicle\n");
    printf("6. Filter Vehicles\n");
    printf("0. Exit\n");
}

void addNewVehicle() {
    struct Vehicle v;
    int duplicate = 0;

    if (count >= MAX) {
        printf("Vehicle limit reached!\n");
        return;
    }

    /* initialize */
    v.seatCount = 0;
    v.gearCount = 0;
    strcpy(v.routeNumber, "N/A");

    printf("Enter Vehicle ID: ");
    scanf("%d", &v.id);

    for (int i = 0; i < count; i++) {
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
    toLowerCase(v.type);

    if (strcmp(v.type,"car")!=0 &&
        strcmp(v.type,"bike")!=0 &&
        strcmp(v.type,"bus")!=0 &&
        strcmp(v.type,"truck")!=0) {
        printf("Invalid vehicle type!\n");
        return;
    }

    printf("Enter Model Name: ");
    scanf(" %[^\n]", v.model);

    printf("Enter Brand: ");
    scanf(" %[^\n]", v.brand);

    printf("Enter Year of Manufacture: ");
    scanf("%d", &v.year);

    printf("Enter Engine Capacity (cc): ");
    scanf("%d", &v.engineCC);

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
        scanf(" %[^\n]", v.routeNumber);
    }

    vehicles[count++] = v;
    printf("Vehicle added successfully!\n");
}

void showVehicles() {
    if (count == 0) {
        printf("No vehicles available.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\n--- Vehicle %d ---\n", i + 1);
        printf("ID: %d\nType: %s\nModel: %s\nBrand: %s\nYear: %d\nEngine: %dcc\n",
               vehicles[i].id, vehicles[i].type,
               vehicles[i].model, vehicles[i].brand,
               vehicles[i].year, vehicles[i].engineCC);

        if (strcmp(vehicles[i].type,"car")==0)
            printf("Seats: %d\n", vehicles[i].seatCount);
        else if (strcmp(vehicles[i].type,"bike")==0)
            printf("Gears: %d\n", vehicles[i].gearCount);
        else if (strcmp(vehicles[i].type,"bus")==0)
            printf("Route: %s\n", vehicles[i].routeNumber);
    }
}

void searchVehicle() {
    int option, id, found = 0;
    char key[30];

    printf("\nSearch By:\n1. Vehicle ID\n2. Type or Model\nEnter option: ");
    scanf("%d", &option);

    if (option == 1) {
        printf("Enter ID: ");
        scanf("%d", &id);

        for (int i = 0; i < count; i++) {
            if (vehicles[i].id == id) {
                printf("Found: %s %s (%d)\n",
                       vehicles[i].brand,
                       vehicles[i].model,
                       vehicles[i].year);
                found = 1;
                break;
            }
        }
    }
    else if (option == 2) {
        printf("Enter Type or Model: ");
        scanf(" %[^\n]", key);
        toLowerCase(key);

        for (int i = 0; i < count; i++) {
            char t[30], m[30];
            strcpy(t, vehicles[i].type);
            strcpy(m, vehicles[i].model);
            toLowerCase(t);
            toLowerCase(m);

            if (strcmp(t,key)==0 || strcmp(m,key)==0) {
                printf("ID:%d %s %s\n",
                       vehicles[i].id,
                       vehicles[i].brand,
                       vehicles[i].model);
                found = 1;
            }
        }
    }

    if (!found)
        printf("No matching vehicle found.\n");
}

void updateVehicle() {
    int id;
    printf("Enter Vehicle ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (vehicles[i].id == id) {
            printf("1.Brand 2.Model 3.Year 4.Engine CC\nChoice: ");
            int ch;
            scanf("%d", &ch);

            if (ch == 1) scanf(" %[^\n]", vehicles[i].brand);
            else if (ch == 2) scanf(" %[^\n]", vehicles[i].model);
            else if (ch == 3) scanf("%d", &vehicles[i].year);
            else if (ch == 4) scanf("%d", &vehicles[i].engineCC);
            else {
                printf("Invalid choice!\n");
                return;
            }

            printf("Updated successfully!\n");
            return;
        }
    }
    printf("Vehicle not found!\n");
}

void deleteVehicle() {
    int id, pos = -1;
    printf("Enter Vehicle ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (vehicles[i].id == id) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        printf("Vehicle not found!\n");
        return;
    }

    for (int i = pos; i < count-1; i++)
        vehicles[i] = vehicles[i+1];

    count--;
    printf("Vehicle deleted successfully!\n");
}

void filterVehicles() {
    int option;
    printf("\n1.Year & CC  2.Type  3.Brand\nChoice: ");
    scanf("%d", &option);

    int found = 0;

    if (option == 1) {
        int y, cc;
        printf("Year > "); scanf("%d",&y);
        printf("CC > "); scanf("%d",&cc);

        for (int i=0;i<count;i++)
            if (vehicles[i].year>y && vehicles[i].engineCC>cc) {
                printf("%d %s %s\n",
                       vehicles[i].id,
                       vehicles[i].brand,
                       vehicles[i].model);
                found = 1;
            }
    }
    else if (option == 2) {
        char type[20];
        scanf("%s", type);
        toLowerCase(type);

        for (int i=0;i<count;i++)
            if (strcmp(vehicles[i].type,type)==0) {
                printf("%d %s\n", vehicles[i].id, vehicles[i].model);
                found = 1;
            }
    }
    else if (option == 3) {
        char brand[30];
        scanf(" %[^\n]", brand);

        for (int i=0;i<count;i++)
            if (strcmp(vehicles[i].brand,brand)==0) {
                printf("%d %s\n", vehicles[i].id, vehicles[i].model);
                found = 1;
            }
    }

    if (!found)
        printf("No matching vehicles found.\n");
}
