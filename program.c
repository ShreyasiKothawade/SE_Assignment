#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float grade;
} Student;

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students, maximum reached.\n");
        return;
    }
    Student newStudent;
    printf("Enter ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter Name: ");
    scanf("%s", newStudent.name);
    printf("Enter Grade: ");
    scanf("%f", &newStudent.grade);
    students[(*count)++] = newStudent;
    printf("Student added successfully!\n");
}

void displayStudents(Student students[], int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("\nStudents List:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Grade: %.2f\n", students[i].id, students[i].name, students[i].grade);
    }
}

void sortStudents(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (students[i].grade < students[j].grade) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Students sorted by grade in descending order.\n");
}

void saveToFile(Student students[], int count) {
    FILE *file = fopen("students.txt", "w");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %.2f\n", students[i].id, students[i].name, students[i].grade);
    }
    fclose(file);
    printf("Students saved to file successfully.\n");
}

void loadFromFile(Student students[], int *count) {
    FILE *file = fopen("students.txt", "r");
    if (!file) {
        printf("No file found.\n");
        return;
    }
    while (fscanf(file, "%d %s %f", &students[*count].id, students[*count].name, &students[*count].grade) != EOF) {
        (*count)++;
    }
    fclose(file);
    printf("Students loaded from file successfully.\n");
}

void menu() {
    printf("\nStudent Management System\n");
    printf("1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Sort Students\n");
    printf("4. Save to File\n");
    printf("5. Load from File\n");
    printf("6. Exit\n");
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    loadFromFile(students, &count);

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                sortStudents(students, count);
                break;
            case 4:
                saveToFile(students, count);
                break;
            case 5:
                loadFromFile(students, &count);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
