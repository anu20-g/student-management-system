/*
 * Project: Student Record System
 * Language: C
 * Description: A simple console-based student record management system 
 *              using file handling in C for 1st semester mini-project.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student details
struct Student {
    int roll_no;
    char name[50];
    float marks;
};

// Function prototypes
void addStudent();
void displayStudents();
void searchStudent();
void deleteStudent();

int main() {
    int choice;

    while (1) {
        printf("\n===================================\n");
        printf("    STUDENT RECORD SYSTEM\n");
        printf("===================================\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Delete Student Record\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Exiting...\n");
            break;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("\nExiting program. Thank you!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to add a new student record to file
void addStudent() {
    FILE *fp;
    struct Student s;

    fp = fopen("students.txt", "a");
    if (fp == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &s.roll_no);
    printf("Enter Name: ");
    scanf(" %[^\n]s", s.name);
    printf("Enter Total Marks (out of 100): ");
    scanf("%f", &s.marks);

    // Save record to text file
    fprintf(fp, "%d,%s,%.2f\n", s.roll_no, s.name, s.marks);
    fclose(fp);

    printf("\nStudent record added successfully!\n");
}

// Function to display all student records
void displayStudents() {
    FILE *fp;
    struct Student s;
    int count = 0;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("\nNo records found! (File does not exist yet)\n");
        return;
    }

    printf("\n------------------------------------------------------------\n");
    printf("%-10s %-30s %-10s\n", "Roll No", "Name", "Marks");
    printf("------------------------------------------------------------\n");

    while (fscanf(fp, "%d,%49[^,],%f\n", &s.roll_no, s.name, &s.marks) == 3) {
        printf("%-10d %-30s %-10.2f\n", s.roll_no, s.name, s.marks);
        count++;
    }

    printf("------------------------------------------------------------\n");
    printf("Total records: %d\n", count);

    fclose(fp);
}

// Function to search a student record by roll number
void searchStudent() {
    FILE *fp;
    struct Student s;
    int roll, found = 0;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    while (fscanf(fp, "%d,%49[^,],%f\n", &s.roll_no, s.name, &s.marks) == 3) {
        if (s.roll_no == roll) {
            printf("\n--- Record Found ---");
            printf("\nRoll No : %d", s.roll_no);
            printf("\nName    : %s", s.name);
            printf("\nMarks   : %.2f\n", s.marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with Roll No %d not found.\n", roll);
    }

    fclose(fp);
}

// Function to delete a student record by roll number
void deleteStudent() {
    FILE *fp, *tempFp;
    struct Student s;
    int roll, found = 0;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("\nNo records found to delete!\n");
        return;
    }

    tempFp = fopen("temp.txt", "w");
    if (tempFp == NULL) {
        printf("\nError creating temporary file!\n");
        fclose(fp);
        return;
    }

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    while (fscanf(fp, "%d,%49[^,],%f\n", &s.roll_no, s.name, &s.marks) == 3) {
        if (s.roll_no == roll) {
            found = 1; // Skip writing this record to temp file
        } else {
            fprintf(tempFp, "%d,%s,%.2f\n", s.roll_no, s.name, s.marks);
        }
    }

    fclose(fp);
    fclose(tempFp);

    if (found) {
        remove("students.txt");
        rename("temp.txt", "students.txt");
        printf("\nStudent with Roll No %d deleted successfully.\n", roll);
    } else {
        remove("temp.txt");
        printf("\nStudent with Roll No %d not found.\n", roll);
    }
}
