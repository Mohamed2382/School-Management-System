#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/* Define a linked list node to hold a student record */
struct ListNode {
    struct Student data;
    struct ListNode* next;
};

/* Define a linked list to store student records */
struct ListNode* head = NULL;
int num_students = 0;

/* Function to display the main menu and read the user's choice. */
int MAIN_MENU(int *choice) {
    printf("\nMenu:\n");
    printf("1. New Student\n");
    printf("2. Delete Student\n");
    printf("3. Student List\n");
    printf("4. Edit Student\n");
    printf("5. Rank Students by CS Score\n");
    printf("6. Update Student CS Score\n");
    printf("7. Find Student By First Name\n");
    printf("8. Total Student\n");
    printf("9. Exit\n");
    printf("Enter your choice (1-9): ");
    scanf("%d", choice);

    if (*choice >= 1 && *choice <= 9) {
        switch (*choice) {
            case 1:
                NEW_STUDENT();
                break;
            case 2:
                DELETE_STUDENT();
                break;
            case 3:
                STUDENT_LIST();
                break;
            case 4:
                STUDENT_EDIT();
                break;
            case 5:
                RANK_STUDENT();
                break;
            case 6:
                STUDENT_SCORE();
                break;
            case 7:
                FIND_STUDENT_BY_FIRST_NAME();
                break;
            case 8:
                printf("Total number of students: %d\n", TOTAL_STUDENTS());
                break;
            case 9:
                printf("Thank you for using the Student Management System!\n");
                return 0;
        }
        return 1;
    } else {
        *choice = -1;
        return 1;
    }
}


/* Function to add a new student to the linked list. */
void NEW_STUDENT() {
    if (num_students == 100) {
        printf("Error: Maximum number of students reached.\n");
        return;
    }

    /* Create a new student node and read their details from the user. */
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }

    printf("Enter student name: ");
    scanf(" %[^\n]", new_node->data.name);
    printf("Enter date of birth: ");
    scanf(" %[^\n]", new_node->data.dob);
    printf("Enter student ID: ");
    scanf(" %[^\n]", new_node->data.ID);
    printf("Enter address: ");
    scanf(" %[^\n]", new_node->data.address);
    printf("Enter phone number: ");
    scanf(" %[^\n]", new_node->data.phone);
    printf("Enter computer science score: ");
    scanf("%f", &new_node->data.cs_score);

    /* Add the new student node to the linked list and increment the number of students. */
    new_node->next = head;
    head = new_node;
    num_students++;

    printf("Student account created successfully!\n");
}

/* Function to delete a student from the linked list based on their ID. */
void DELETE_STUDENT() {
    char student_id[15];
    struct ListNode* current = head;
    struct ListNode* previous = NULL;

    printf("Enter the ID of the student to delete: ");
    scanf(" %[^\n]", student_id);

    /* Search for the student with the provided ID and remove them from the linked list. */
    while (current != NULL) {
        if (strcmp(current->data.ID, student_id) == 0) {
            if (previous == NULL) {
                /* The student to be deleted is the head of the linked list. */
                head = current->next;

            } else {
                previous->next = current->next;
            }

            free(current);
            num_students--;
            printf("Student account deleted successfully!\n");
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Student not found!\n");
}

/* Function to display the list of all students and their details. */
void STUDENT_LIST() {
    struct ListNode* current = head;
    printf("\nList of Students:\n");
    printf("Name\t\tDOB\t\tID\t\tAddress\t\tPhone\t\t\tCS Score\n");

    /* Loop through the linked list and print each student's information. */
    while (current != NULL) {
        struct Student student = current->data;
        printf("%s\t%s\t%s\t\t%s\t\t%s\t\t%.2f\n", student.name, student.dob, student.ID, student.address, student.phone, student.cs_score);
        current = current->next;
    }
}

/*Function to edit a student's details based on their ID.*/
void STUDENT_EDIT() {
    char student_id[15];
    printf("Enter the ID of the student to edit: ");
    scanf(" %[^\n]", student_id);

    struct ListNode* current = head;

    /* Search for the student with the provided ID and update their details. */
    while (current != NULL) {
        if (strcmp(current->data.ID, student_id) == 0) {
            printf("Student found! Enter new details:\n");
            printf("Enter student name: ");
            scanf(" %[^\n]", current->data.name);
            printf("Enter date of birth: ");
            scanf(" %[^\n]", current->data.dob);
            printf("Enter address: ");
            scanf(" %[^\n]", current->data.address);
            printf("Enter phone number: ");
            scanf(" %[^\n]", current->data.phone);
            printf("Enter computer science score: ");
            scanf("%f", &current->data.cs_score);
            printf("Student account updated successfully!\n");
            return;
        }
       // current = current->next;
    }

    printf("Student not found!\n");
}

/*Function to rank students by their computer science scores.*/
void RANK_STUDENT()
{
    int num_students = 0;
    struct ListNode* current = head;

    /* Check for empty list */
    if (head == NULL)
    {
        printf("No students to rank.\n");
        return;
    }

    /* Count the number of students */
    while (current != NULL)
    {
        num_students++;
        current = current->next;
    }

    /* Create an array of pointers to student nodes */
    struct ListNode** student_array = (struct ListNode**)malloc(num_students * sizeof(struct ListNode*));

    /* put students into student_array*/
    current = head;
    int index = 0;
    while (current != NULL)
    {
        student_array[index] = current;
        current = current->next;
        index++;
    }

    /* bubble sorting according to cs score */
    for (int i = 0; i < num_students - 1; i++)
    {
        for (int j = 0; j < num_students - i - 1; j++)
        {
            if (student_array[j]->data.cs_score < student_array[j + 1]->data.cs_score)
            {
                /* Swap the pointers */
                struct ListNode* temp = student_array[j];
                student_array[j] = student_array[j + 1];
                student_array[j + 1] = temp;
            }
        }
    }

    /* print list*/
    printf("\nRanking of Students according to CS Score:\n");
    printf("======================================================================\n");
    printf("| %-10s | %-40s | %-10s |\n", "rank", "Name", "Computer");
    printf("======================================================================\n");
    for (int i = 0; i < num_students; i++)
    {
        printf("| %-10d | %-40s | %-10.2f |\n", i + 1, student_array[i]->data.name, student_array[i]->data.cs_score);
        printf("======================================================================\n");
    }

    /* delete student_array */
    free(student_array);
}


/*Function to update the CS score for all students in the linked list.*/
void STUDENT_SCORE() {
    float new_score;
    printf("Enter the new CS score for all students: ");
    scanf("%f", &new_score);

    /* Update the CS score for all students in the linked list. */
    struct ListNode* current = head;
    while (current != NULL) {
        current->data.cs_score = new_score;
        current = current->next;
    }

    printf("CS score updated for all students!\n");
}

// Function to find a student's details by their First Name.
void FIND_STUDENT_BY_FIRST_NAME() {
    char first_name[50];
    printf("Enter the First Name of the student: ");
    scanf(" %[^\n]", first_name);

    struct ListNode* current = head;
    int found = 0;
    while (current != NULL) {
        if (strstr(current->data.name, first_name) != NULL) {
            struct Student student = current->data;
            printf("Student details for First Name %s:\n", first_name);
            printf("Name: %s\n", student.name);
            printf("Date of Birth: %s\n", student.dob);
            printf("ID: %s\n", student.ID);
            printf("Address: %s\n", student.address);
            printf("Phone: %s\n", student.phone);
            printf("Computer Science Score: %.2f\n", student.cs_score);
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("No students found with First Name %s.\n", first_name);
    }
}

// Function to find the total number of students.
int TOTAL_STUDENTS() {
    return num_students;
}

/* Function to free the allocated memory for the linked list upon program exit. */
void freeLinkedList() {
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}

