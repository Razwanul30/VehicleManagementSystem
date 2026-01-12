# Vehicle Management System (C Language)

## Project Overview
The Vehicle Management System is a menu-driven command-line application written in C.  
All program logic is implemented inside a single source file (`main.c`), while the code is organized using multiple functions to maintain modularity and readability.

The system manages different types of vehicles (Car, Bus, Bike, Truck, etc.) and allows users to perform various operations such as adding, searching, updating, deleting, and analyzing vehicle records.

No external database or file handling is used. All data is stored and managed manually in memory using basic C data structures.

---

## Objectives
- Implement a complete record management system in C
- Practice modular programming using functions in a single file
- Understand manual data storage using arrays and structures
- Simulate real-world CRUD operations
- Improve problem-solving and logical structuring skills

---

## Technology Stack
- Programming Language: C
- Operating System: Linux (Ubuntu)
- Compiler: GCC
- Editor/IDE: VS Code 
---

## Program Design
- Single source file: `main.c`
- Modular logic using functions
- Menu-driven infinite loop until Exit is selected
- Manual memory handling (arrays / dynamic allocation)

---

## Vehicle Data Structure
Each vehicle record contains at least:
- Vehicle ID (unique integer)
- Vehicle Type (Car, Bus, Bike, Truck, etc.)
- Model Name
- Brand / Manufacturer
- Year of Manufacture
- Engine Capacity (cc or descriptive text)

Optional fields (based on vehicle type):
- Seat Count (Car)
- Gear Count (Bike)
- Route Number (Bus)
- Color
- Fuel Type

---

## Core Functionalities

### Add New Vehicle
- Accept vehicle details from the user
- Ensure Vehicle ID uniqueness
- Store data in an internal structure
- Confirm successful insertion

### Show All Vehicles
- Display all vehicles in a readable format
- Handle empty list scenario

### Search Vehicle
- Search by Vehicle ID
- Search by Vehicle Type or Model Name
- Display full details of matching records

### Update Vehicle
- Update one or more fields using Vehicle ID
- Preserve data consistency

### Delete Vehicle
- Remove a vehicle by Vehicle ID
- Shift remaining records to maintain order

### Exit Program
- Exit the application safely

---

## Advanced Functionalities
- Multi-condition filtering
- Sorting by multiple criteria
- Duplicate detection
- Bulk delete operations
- Partial updates for matching records
- Summary statistics generation
- Grouping vehicles by category
- Dynamic array expansion
- Cloning vehicle records
- Full-text record search
- Undo last operation (Add / Update / Delete)

---

## Constraints
- All code must be written inside `main.c`
- No file handling or database usage
- Vehicle IDs must be unique
- Input validation must be handled
- Program must not terminate unless Exit is selected

---

## Compilation and Execution

```bash
gcc main.c -o vehicle
./vehicle



## Developer

**Md Razwanul Islam**  
Begum Rokeya University, Rangpur  
16th Batch
